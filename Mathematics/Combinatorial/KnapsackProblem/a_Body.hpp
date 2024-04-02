// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Algebra/Monoid/a_Body.hpp"
// KnapsackÇ…égÇ§ÅB
#include "Negative/Cost/a_Body.hpp"
#include "Negative/Value/a_Body.hpp"
#include "../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound ) { const int N = value.size(); return Log( N ) + Log( min( ll( cost_sum_bound ) , ll( value_sum_bound ) ) ) < ll( N >> 1 ) ? cost_sum_bound < value_sum_bound ? AbstractNegativeValueKnapsackFewCosts( AdditiveMonoid<INT1>() , value , value_sum_bound , INT1( -1 ) , cost , cost_sum_bound ) : AbstractNegativeCostKnapsackFewValues( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound , INT2( -1 ) ) : NegativeKnapsack( value , value_sum_bound , cost , cost_sum_bound ); }
