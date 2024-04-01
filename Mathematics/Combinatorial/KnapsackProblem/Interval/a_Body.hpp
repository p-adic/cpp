// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/Group/a_Body.hpp"

template <typename U1 , typename ABEL_GROUP1 , typename U2 , typename ABEL_GROUP2>
pair<U1,U2> NonNegativeAbstractIntervalKnapsack( ABEL_GROUP1 M1 , ABEL_GROUP1 M2 , const int& N , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound , const int& diff_min , const int& diff_max )
{

  U1 value_sum = value[0];
  U2 cost_sum = cost[0];
  int l = 0 , l_min = diff_min - diff_max , l_max = 0 , r = 0;

  while( r < diff_min ){

    r++;
    value_sum = M2.Sum( move( value_sum ) , value[r] );
    cost_sum = M1.Sum( move( cost_sum ) , cost[r] );
    
  }

  pair<U1,U2> answer = { M1.Zero() , M2.Zero() };

  while( true ){

    const bool over = cost_sum_bound < cost_sum || value_sum_bound < value_sum;
    !over && ( answer.first < value_sum || ( answer.first == value_sum && cost_sum < answer.second ) ?  answer = { value_sum , cost_sum } : answer;
    
    if( l == ( over ? l_max : l_min ) ){

      if( ++r < N ){
	
	++l_min , ++l , ++l_max;
	value_sum = M1.Sum( move( value_sum ) , value[r] );
	cost_sum = M2.Sum( move( cost_sum ) , cost[r] );

      } else {

	break;

      }

    } else {

      value_sum = M1.Sum( move( value_sum ) , M2.Inverse( value[l] ) );
      cost_sum = M2.Sum( move( cost_sum ) , M1.Inverse( cost[l] ) );
      ++l;

    }
    
  }

  return answer;
  
}

template <typename U1 , typename ABEL_GROUP1 , typename U2 , typename ABEL_GROUP2>
pair<U1,U2> NegativeAbstractIntervalKnapsack( ABEL_GROUP1 M1 , ABEL_GROUP1 M2 , const int& N , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound , const int& diff_min , const int& diff_max )
{

  U1 value_sum = value[0];
  U2 cost_sum = cost[0];
  int l_min = diff_min - diff_max , l_max = 0 , r = 0;

  while( r < diff_min ){

    r++;
    value_sum = M1.Sum( move( value_sum ) , value[r] );
    cost_sum = M2.Sum( move( cost_sum ) , cost[r] );
    
  }

  pair<U1,U2> answer = { M1.Zero() , M2.Zero() };

  while( true ){

    U1 value_sum_prev = value_sum;
    U2 cost_sum_prev = cost_sum;

    for( int l = max( 0 , l_min ) ; l <= l_max ; l++ ){

      !( cost_sum_bound < cost_sum || value_sum_bound < value_sum ) && ( answer.first < value_sum || ( answer.first == value_sum && cost_sum < answer.second ) ) ?answer = { value_sum , cost_sum } : answer;
      value_sum = M1.Sum( move( value_sum ) , M2.Inverse( value[l] ) );
      cost_sum = M2.Sum( move( cost_sum ) , M1.Inverse( cost[l] ) );

    }

    if( ++r < N ){

      value_sum = M1.Sum( move( value_sum_prev ) , l_min < 0 ? value[r] : M1.Sum( M1.Inverse( value[l_min] ) , value[r] ) );
      cost_sum = M2.Sum( move( cost_sum_prev ) , l_min < 0 ? cost[r] : M2.Sum( M2.Inverse( cost[l_min] ) , cost[r] ) );
      ++l_min , ++l_max;

    } else {

      break;
      
    }
    
  }

  return answer;

}

template <typename U1 , typename ABEL_GROUP1 , typename U2 , typename ABEL_GROUP2>
pair<U1,U2> AbstractIntervalKnapsack( ABEL_GROUP1 M1 , ABEL_GROUP1 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound , const int& diff_min , int diff_max )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  assert( diff_min <= ( diff_max == -1 ? diff_max = N - 1 : diff_max ) );
  assert( diff_max < N );
  bool non_negative = true;
  const U1& zero1 = M1.Zero();

  for( auto& v : value ){

    non_negative &= zero1 < v;

  }

  const U2& zero2 = M2.Zero();

  for( auto& c : cost ){

    non_negative &= zero2 < c;

  }
  
  return non_negative ? NonNegativeAbstractIntervalKnapsack( move( M1 ) , move( M2 ) , N , value , value_sum_bound , cost , const_Sum_bound , diff_min , diff_max ) : NegativeAbstractIntervalKnapsack( move( M1 ) , move( M2 ) , N , value , value_sum_bound , cost , const_Sum_bound , diff_min , diff_max );

}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> IntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const int& diff_min = 0 , int diff_max ) { return AbstractIntervalKnapsack( AddiiveGroup<INT1>() , AddiiveGroup<INT2>() , value , value_sum_bound , cost , cost_sum_bound , diff_min , move( diff_max ) ); }

template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP1 M , const vector<U>& value , const U& value_sum_bound , const int& diff_min = 0 , int diff_max ) { return AbstractIntervalKnapsack( AddiiveGroup<int>() , M , value , value_sum_bound , vector<int>( value.size() ) , int( 0 ) , diff_min , move( diff_max ) ); }
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min , int diff_max ) { return AbstractIntervalCostfreeKnapsack( AddiiveGroup<INT>() , value , value_sum_bound , diff_min , move( diff_max ) ); }
