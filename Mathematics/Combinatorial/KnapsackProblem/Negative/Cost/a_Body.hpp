// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/a_Body.hpp

#pragma once
#include "a.hpp"

// AbstractNegativeCostKnapsackÇ…égÇ§ÅB
#include "MinimalCostSum/a_Body.hpp"
#include "../a_Body.hpp"
#include "../../../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsackFewValues( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional ) { pair<INT,U> answer = { 0 , M.One() }; auto cost_min = AbstractNegativeCostMulticaseMinimalCostSumKnapsack( move( M ) , value , value_sum_bound , cost , exceptional , exceptional ); for( INT v = 0 ; v <= value_sum_bound ; v++ ){ auto& c_v = cost_min[v]; c_v == exceptional || cost_sum_bound < c_v ? answer : answer = { v , move( c_v ) }; } return answer; }
template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional ) { const int N = value.size(); return Log( ll( value_sum_bound ) ) < ll( N >> 1 ) ? AbstractNegativeCostKnapsackFewValues( move( M ) , value , value_sum_bound , cost , cost_sum_bound , exceptional ) : AbstractNegativeKnapsack( AdditiveMonoid<INT>() , move( M ) , value , value_sum_bound , cost , cost_sum_bound ); }
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeCostKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const INT2& exceptional ) { return AbstractNegativeCostKnapsack( AdditiveMonoid<INT2>() , value , value_sum_bound , cost , cost_sum_bound , exceptional ); }
