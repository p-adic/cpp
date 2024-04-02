// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/a_Body.hpp

#pragma once
#include "a.hpp"

// AbstractNegativeValueKnapsackÇ…égÇ§ÅB
#include "../a_Body.hpp"
#include "../../../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractMulticaseNegativeValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& one = M.One();
  assert( !( value_sum_bound < one ) );
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    auto& cost_i = cost[i];
    assert( cost_i >= 0 );

    for( INT c = cost_sum_bound ; c >= cost_i ; c-- ){

      auto temp = M.Product( answer[c - cost_i] , value_i );

      if( !( value_sum_bound < temp ) ){
	
	assert( temp != exceptional );
	auto& answer_c = answer[c];
	answer_c = answer_c == exceptional ? move( temp ) : max( answer_c , temp );

      }
      
    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<INT1> MulticaseNegativeValueKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractMulticaseNegativeValueKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , exceptional , cost , cost_sum_bound ); }
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueKnapsackFewCosts( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractMulticaseNegativeValueKnapsack( move( M ) , value , value_sum_bound , exceptional , cost , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && ( answer.first < v_c || ( answer.first == v_c && c < answer.second ) ) ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { const int N = value.size(); return Log( ll( cost_sum_bound ) ) < ll( N >> 1 ) ? AbstractNegativeValeKnapsackFewCosts( move( M ) , value , value_sum_bound , exceptional , cost , cost_sum_bound ) : AbstractNegativeKnapsack( move( M ) , value , value_sum_bound , cost , cost_sum_bound ); }
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeValueKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractNegativeValueKnapsack( AdditiveMonoid<INT1>() , value , value_sum_bound , exceptional , cost , cost_sum_bound ); }
