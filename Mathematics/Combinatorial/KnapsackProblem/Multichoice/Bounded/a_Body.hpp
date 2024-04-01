// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Bounded/a_Body.hpp

#pragma once
#include "a.hpp"

// AbstractBoundedChoiceKnapsackÇ…égÇ§ÅB
#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND>
vector<U> AbstractBoundedChoiceUnstableCostMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound )
{

  static_assert( is_invocable_r_v<INT,COST,const int&,const int&> && is_invocable_v<CHOICE_NUM_BOUND,const int&> );
  const int N = value.size();
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( !( value_i < one ) );
    ll choice_num_bound_i = choice_num_bound( i );
    assert( choice_num_bound_i <= choice_num_bound_max );
    int choice_num_bound_fixed_i = int( min( choice_num_bound_i , ll( cost_sum_bound + 1 ) ) );
    INT c_min = 0;
    auto temp = answer;

    for( ll choice_num = 0 ; choice_num < choice_num_bound_fixed_i && c_min < cost_sum_bound ; choice_num++ ){

      auto&& c_i = cost( i , choice_num );
      assert( c_i >= 1 );
      c_min += c_i;

      for( INT c = cost_sum_bound ; c >= c_min ; c-- ){

	auto& answer_c = answer[c];
	auto& temp_c_i = temp[c - c_i];

	if( temp_c_i != exceptional ){
	  
	  auto& temp_c = temp[c] = M.Product( temp_c_i , value_i );
	  answer_c = answer_c == exceptional ? temp_c : max( answer_c , temp_c );

	}
	
      }

    }

  }

  return answer;

}

template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline vector<INT1> BoundedChoiceUnstableCostMulticaseKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound ) { return AbstractBoundedChoiceUnstableCostMulticaseKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , move( cost ) , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); }
template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceUnstableCostKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractBoundedChoiceUnstableCostMulticaseKnapsack( move( M ) , value , value_sum_bound , exceptional , move( cost ) , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceUnstableCostKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound ) { return AbstractBoundedChoiceUnstableCostKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , move( cost ) , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); }

template <typename U , typename INT , typename CHOICE_NUM_BOUND>
void SetIteratedItem( const int& N , const vector<U>& value , vector<U>& value_new , const vector<INT>& cost , vector<INT>& cost_new , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max )
{

  static_assert( !is_same_v<U,int> && !is_same_v<U,uint> );
  static_assert( !is_same_v<INT,int> && !is_same_v<INT,uint> );

  for( int i = 0 ; i < N ; i++ ){

    auto value_i = value[i];
    auto cost_i = cost[i];
    ll m = choice_num_bound( i );
    assert( m <= choice_num_bound_max );
    ll p = 1;

    while( p <= m ){

      m -= p;
      value_new.push_back( value_i );
      cost_new.push_back( cost_i );
      cost_i <<= 1;
      value_i <<= 1;
      p <<= 1;

    }

    if( m > 0 ){

      value_new.push_back( value[i] * m );
      cost_new.push_back( cost[i] * m );

    }

  }

  return;

}

template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline vector<U> AbstractBoundedChoiceMulticaseKnapsackFewCost( N_MODULE M , const int& N , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound ) { vector<U> value_new; vector<INT> cost_new; SetIteratedItem( N , value , value_new , cost , cost_new , move( choice_num_bound ) , choice_num_bound_max ); return AbstractMulticaseKnapsack( move( M ) , value_new , value_sum_bound , exceptional , cost_new , cost_sum_bound ); }
template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline vector<U> AbstractBoundedChoiceMulticaseKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound ) { const int N = value.size(); return N == 0 ? vector<U>( cost_sum_bound + 1 , M.One() ) : cost_sum_bound / N < Log( cost_sum_bound ) ? AbstractBoundedChoiceUnstableCostMulticaseKnapsack( move( M ) , value , value_sum_bound , exceptional , [&]( const int& i , const int& ){ return cost[i]; } , move( choice_num_bound ) , cost_sum_bound ) : AbstractBoundedChoiceMulticaseKnapsackFewCost( move( M ) , N , value , value_sum_bound , exceptional , cost , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); }
template <typename INT1 , typename INT2 , typename CHOICE_NUM_BOUND> inline vector<INT1> BoundedChoiceMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT2& cost_sum_bound ) { return AbstractBoundedChoiceMulticaseKnapsack( AdditiveGroup<INT1>() , value , value_sum_bound , cost , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); }
template <typename INT , typename CHOICE_NUM_BOUND> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT>& value , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max ) { auto value_constructed = BoundedChoiceMulticaseKnapsack( value , value_sum_bound , value , move( choice_num_bound ) , choice_num_bound_max , value_sum_bound ); vector<bool> answer( value_sum_bound + 1 ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ answer[v] = value_constructed[v] == v; } return answer; }

template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractBoundedChoiceMulticaseKnapsack( move( M ) , value , value_sum_bound , exceptional , cost , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && answer.first < v_c ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename INT1 , typename CHOICE_NUM_BOUND , typename INT2> inline pair<INT1,INT2> BoundedChoiceKnapsackFewItems( const int& N , const vector<INT2>& value , const INT2& value_sum_bound , const vector<INT1>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound ) { vector<INT2> value_new; vector<INT1> cost_new; SetIteratedItem( N , value , value_new , cost , cost_new , move( choice_num_bound ) , choice_num_bound_max ); return Knapsack( value_new , value_sum_bound , cost_new , cost_sum_bound ); }

template <typename INT1 , typename INT2 , typename CHOICE_NUM_BOUND>
pair<INT1,INT2> BoundedChoiceKnapsackFewValues( const int& N , const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT2& cost_sum_bound )
{

  const INT1 value_sum_range = min( value_sum_bound , value_bound * value_bound * INT1( N ) );
  vector<INT1> value_new{};
  vector<INT2> cost_new{};
  vector<int> choice_num( N );
  
  for( int i = 0 ; i < N ; i++ ){

    ll choice_num_bound_i = choice_num_bound( i );
    assert( choice_num_bound_i <= choice_num_bound_max );
    choice_num[i] = int( min( choice_num_bound_i , ll( value_bound ) ) );

  }
  
  SetIteratedItem( N , value , value_new , cost , cost_new , [&]( const int& i ){ return choice_num[i]; } , choice_num_bound_max );
  auto cost_min = DualMulticaseKnapsackFewValues( value_new.size() , value_new , value_sum_range , cost_new , cost_sum_bound );

  pair<INT1,INT2> answer = { 0 , 0 };
  vector<pair<double,int>> item( N );

  for( int i = 0 ; i < N ; i++ ){

    assert( value[i] > 0 );
    item[i] = { double( cost[i] ) / value[i] , i };
    choice_num[i] = choice_num_bound( i ) - choice_num[i];

  }

  sort( item.begin() , item.end() );

  for( INT1 v = 0 ; v <= value_sum_range ; v++ ){

    if( cost_min[v] != -1 ){
      
      ll value_rest = value_sum_bound - v;
      ll cost_rest = cost_sum_bound - cost_min[v];

      for( int j = 0 ; j < N ; j++ ){

	const int& i = item[j].second;
	ll num = choice_num[i];
	num = min( num , value_rest / ll( value[i] ) );
	cost[i] > 0 ? num = min( num , cost_rest / ll( cost[i] ) ) : num;
	value_rest -= ll( value[i] ) * num;
	cost_rest -= ll( cost[i] ) * num;
	
      }

      pair<INT1,INT2> temp = { value_sum_bound - value_rest , cost_sum_bound - cost_rest };
      answer.first < temp.first || ( answer.first == temp.first && temp.second < answer.second ) ? answer = move( temp ) : answer;

    }

  }

  return answer;

}

template <typename INT1 , typename INT2 , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT2& cost_sum_bound ) { const int N = value.size(); const ll log_N = Log( N ) , log_value_bound = Log( ll( value_bound ) ) , log_cost_sum_bound = Log( ll( cost_sum_bound ) ) , log_choice_num_bound_max = Log( choice_num_bound_max ) , parameter0 = log_cost_sum_bound << 1 , parameter1 = log_N + min( ( ll( cost_sum_bound ) < ll( value_sum_bound ) ? log_cost_sum_bound : Log( ll( value_sum_bound ) ) ) , N * log_choice_num_bound_max >> 1 ) + Log( log_choice_num_bound_max ) , parameter2 = ( log_N << 1 ) + ( log_value_bound << 1 ) + Log( log_value_bound ); const int type = parameter0 < parameter1 ? parameter0 < parameter2 ? 0 : 2 : parameter1 < parameter2 ? 1 : 2; return type == 0 ? BoundedChoiceUnstableCostKnapsack( value , value_sum_bound , [&]( const int& i , const int& ){ return cost[i]; } , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ) : type == 1 ? BoundedChoiceKnapsackFewItems( N , value , value_sum_bound , cost , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ) : BoundedChoiceKnapsackFewValues( N , value , value_bound , value_sum_bound , cost , move( choice_num_bound ) , choice_num_bound_max , cost_sum_bound ); }
template <typename INT , typename CHOICE_NUM_BOUND> inline INT BoundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max ) { return BoundedChoiceKnapsack( value , value_bound , value_sum_bound , value , move( choice_num_bound ) , choice_num_bound_max , value_sum_bound ); }
