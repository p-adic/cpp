// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/Restfree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../ValueSumBound/a_Body.hpp"

template <typename INT> inline INT CostfreeRestfreeDifferenceKnapsack( const vector<INT>& value , const INT& dif_opt )
{
  assert( 0 <= dif_opt );
  const INT value_sum_bound = ValueSumBound( value );

  if( value_sum_bound <= dif_opt ){

    return value_sum_bound;

  }
  
  auto v = CostfreeKnapsack( value , ( value_sum_bound - dif_opt + 1 ) / 2 );
  INT answer = value_sum_bound - v * 2;

  if( answer < dif_opt ){

    v = CostfreeKnapsack( value , ( value_sum_bound - dif_opt ) / 2 );
    const INT temp = value_sum_bound - v * 2;

    if( dif_opt - answer >= temp - dif_opt ){

      answer = temp;
      
    }

  }
  
  return answer;
  
}
