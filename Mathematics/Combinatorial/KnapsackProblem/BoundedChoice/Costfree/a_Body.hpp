// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Costfree/a_Body.hpp

#pragma once
#include "a.hpp"

// BoundedChoiceCostfreeBoundedValueSumKnapsack�Ɏg���B
#include "../a_Body.hpp"

template <typename INT1 , typename INT2> inline vector<bool> BoundedChoiceCostfreeConstructibilityBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound ) { auto value_constructed = BoundedChoiceMulticaseNegativeValueBoundedValueSumKnapsack( value , value_sum_bound , INT1( -1 ) , value , value_sum_bound , choice_num_bound ); vector<bool> answer( value_sum_bound + 1 ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ answer[v] = value_constructed[v] == v; } return answer; }
template <typename INT1 , typename INT2> inline INT1 BoundedChoiceCostfreeBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound ) { return BoundedChoiceBoundedValueSumKnapsack( value , value_bound , value_sum_bound , value , value_sum_bound , choice_num_bound ); }
