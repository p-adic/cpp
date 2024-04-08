// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costwise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractValueCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound )
{

  const int N = value.size();
  assert( int( cost.size() ) == N );
  auto& one = M.One();
  vector answer( cost_sum_bound + 1 , exceptional );
  answer[0] = one;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( !( value_i < one ) );
    auto& cost_i = cost[i];
    assert( cost_i >= 0 );

    for( INT c = cost_sum_bound ; c >= cost_i ; c-- ){

      auto temp = M.Product( answer[c - cost_i] , value_i );
      assert( temp != exceptional );
      auto& answer_c = answer[c];
      answer_c = answer_c == exceptional ? move( temp ) : max( answer_c , temp );
      
    }

  }

  return answer;

}

template <typename INT1 , typename INT2> inline vector<INT1> CostwiseKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound ) { return AbstractValueCostwiseKnapsack( AdditiveMonoid<INT1>() , value , INT1( -1 ) , cost , cost_sum_bound ); }

