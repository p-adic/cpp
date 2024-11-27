// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<bool> CostfreePresentabilityKnapsack( const vector<INT>& value , const INT& value_sum_bound )
{

  const int N = value.size();
  vector<bool> answer( value_sum_bound + 1 );
  answer[0] = true;

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i= value[i];
    assert( 0 <= value_i );

    for( INT v = value_sum_bound ; v >= value_i ; v-- ){

      answer[v] |= answer[v - value_i];

    }

  }

  return answer;

}

