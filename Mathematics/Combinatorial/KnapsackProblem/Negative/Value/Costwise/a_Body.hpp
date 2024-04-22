// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Costwise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractNegativeValueCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    auto& cost_i = cost[i];
    assert( value_i != exceptional );
    assert( cost_i >= 0 );

    for( INT c = cost_sum_bound ; c >= cost_i ; c-- ){

      auto& answer_c_minus = answer[c - cost_i];

      if( answer_c_minus != exceptional ){
	
	auto temp = M.Product( answer_c_minus , value_i );
	assert( temp != exceptional );
	auto& answer_c = answer[c];
	answer_c = answer_c == exceptional ? move( temp ) : max( answer_c , temp );

      }
      
    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<INT1> NegativeValueCostwiseKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractNegativeValueCostwiseKnapsack( AdditiveMonoid<INT1>() , value , exceptional , cost , cost_sum_bound ); }
