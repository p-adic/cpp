// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Algebra/Monoid/a_Body.hpp"
// AbstractNegativeBoundedValueSumKnapsackÇ…égÇ§ÅB
#include "../../../../Utility/BinarySearch/a_Body.hpp"

template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeBoundedValueSumKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  const U1& one1 = M1.One();
  assert( !( value_sum_bound < one1 ) );
  const U2& one2 = M2.One();
  assert( !( cost_sum_bound < one2 ) );
  pair<U1,U2> answer = { one1 , one2 };

  if( N == 1 ){

    if( !( cost_sum_bound < cost[0] ) && !( value_sum_bound < value[0] ) ){
      
      answer = { value[0] , cost[0] };

    }

  } else if( N > 1 ){

    const int N_half_left = N >> 1;
    const int N_half_right = N - N_half_left;
    unordered_map<int,int> valuation{};

    for( int i = 0 ; i < N_half_right ; i++ ){

      valuation[1<<i] = i;

    }
    
    const int power_left = 1 << N_half_left;
    vector<pair<U2,U1>> sum_left( power_left , { one2 , one1 } );

    for( int s = 1 ; s < power_left ; s++ ){

      const int lsb = s & -s;
      const int& i = valuation[lsb];
      auto& sum_left_s = sum_left[s];
      auto& sum_left_s_minus = sum_left[s ^ lsb];
      sum_left_s.first = M2.Product( sum_left_s_minus.first , cost[i] );
      sum_left_s.second = M1.Product( sum_left_s_minus.second , value[i] );

    }

    const int power_right = 1 << N_half_right;
    vector<pair<U2,U1>> sum_right( power_right , { one2 , one1 } );

    for( int s = 1 ; s < power_right ; s++ ){

      const int lsb = s & -s;
      const int i = N_half_left + valuation[lsb];
      auto& sum_right_s = sum_right[s];
      auto& sum_right_s_minus = sum_right[s ^ lsb];
      sum_right_s.first = M2.Product( sum_right_s_minus.first , cost[i] );
      sum_right_s.second = M1.Product( sum_right_s_minus.second , value[i] );

    }

    sort( sum_right.begin() , sum_right.end() );

    for( int s = 1 ; s < power_right ; s++ ){

      sum_right[s].second = max( sum_right[s].second , sum_right[s-1].second );

    }

    for( int s = 0 ; s < power_left ; s++ ){

      auto& sum_left_s = sum_left[s];

      if( !( cost_sum_bound < sum_left_s.first ) && !( value_sum_bound < sum_left_s.second ) ){
	
	BS2( t , 0 , power_right - 1 , !( value_sum_bound < M1.Product( sum_left_s.second , sum_right[t].second ) ) && !( cost_sum_bound < M2.Product( sum_left_s.first , sum_right[t].first ) ) ? 0 : 1 , 0 );

	if( !( M1.Product( sum_left_s.second , sum_right[t].second ) < answer.first ) ){

	  auto& value_max = sum_right[t].second;
	  BS1( u , 0 , t , sum_right[u].second , value_max );
	  assert( sum_right[u].second == value_max );
	  pair<U1,U2> temp = { M1.Product( sum_left_s.second , value_max ) , M2.Product( sum_left_s.first , sum_right[u].first ) };
	  answer.first < temp.first || ( answer.first == temp.first && temp.second < answer.second ) ? answer = move( temp ) : answer;

	}

      }

    }
    
  }

  return answer;
  
}

template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractNegativeBoundedValueSumKnapsack( AdditiveMonoid<INT1>() , AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound ); }

#include "../ValueSumBound/a_Body.hpp"
