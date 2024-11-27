// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/Costfree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound )
{

  assert( 0 <= value_sum_bound );
  const int N = value.size();
  vector<bool> valid( value_sum_bound + 1 );

  for( int i = 0 ; i < N ; i++ ){

    auto& value_i = value[i];
    assert( value_i >= 0 );

    if( value_sum_bound < value_i ){

      continue;

    }
    
    valid[value_i] = true;

  }

  auto answer = valid;

  for( INT d = 1 ; d < value_sum_bound ; d++ ){

    if( !valid[d] ){

      continue;
      
    }
    
    for( INT v = d + d ; v <= value_sum_bound ; v++ ){

      answer[v] |= answer[v - d];

    }

  }

  return answer;

}

template <typename INT> inline INT UnboundedChoiceCostfreeBoundedValueSumKnapsack( const vector<INT>& value , const INT& value_sum_bound ) { INT answer = 0; auto constructible = UnboundedChoiceCostfreeConstrutibilityKnapsack( value , value_sum_bound ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ constructible[v] ? answer = v : answer; } return answer; }
