// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/NegativeValue/a_Body.hpp

#pragma once
#include "a.hpp"

// AbstractBoundedChoiceMulticaseNegativeValueKnapsackÇ…égÇ§ÅB
#include "../a_Body.pp"
#include "../../Negative/Value/a_Body.pp"

template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline vector<U> AbstractNegativeValueBoundedChoiceMulticaseKnapsack( N_MODULE M , const vector<U>& value , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound ) { vector<U> value_new; vector<INT1> cost_new; SetIteratedItem( M , Module<int,INT1>() , N , value , value_new , cost , cost_new , choice_num_bound ); return AbstractNegativeValueMulticaseKnapsack( move( M ) , value_new , exceptional , cost_new , cost_sum_bound ); }
template <typename INT1 , typename INT2 , typename INT3> inline vector<INT1> NegativeValueBoundedChoiceMulticaseKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT1>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound ) { return AbstractNegativeValueBoundedChoiceMulticaseKnapsack( AdditiveGroup<INT1>() , value , exceptional , cost , cost_sum_bound , choice_num_bound ); }
template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline pair<U,INT1> AbstractNegativeValueBoundedChoiceKnapsack( N_MODULE M , const vector<U>& value , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound ) { vector<U> value_new; vector<INT1> cost_new; SetIteratedItem( M , Module<int,INT1>() , N , value , value_new , cost , cost_new , choice_num_bound ); return AbstractNegativeValueKnapsack( move( M ) , value_new , exceptional , cost_new , cost_sum_bound ); }
template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> NegativeValueBoundedChoiceKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound ) { return AbstractNegativeValueBoundedChoiceKnapsack( Module<int,INT1>() , value , exceptional , cost , cost_sum_bound , choice_num_bound ); }

