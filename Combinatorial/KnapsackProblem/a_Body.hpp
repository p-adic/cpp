// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Algebra/Monoid/a_Body.hpp"
// KnapsackÇ…égÇ§ÅB
#include "Negative/Value/Costwise/a_Body.hpp"
#include "Negative/Cost/a_Body.hpp"
#include "ValueSumBound/a_Body.hpp"
#include "../../Arithmetic/Power/Constexpr/Log/a_Body.hpp"

template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsackFewCosts( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { pair<U,INT> answer = { M.One() , 0 }; auto value_max = AbstractNegativeValueCostwiseKnapsack( move( M ) , value , exceptional , cost , cost_sum_bound ); for( INT c = 0 ; c <= cost_sum_bound ; c++ ){ auto& v_c = value_max[c]; v_c != exceptional && ( answer.first < v_c || ( answer.first == v_c && c < answer.second ) ) ? answer = { move( v_c ) , c } : answer; } return answer; }
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound ) { const int N = value.size(); return Log( ll( cost_sum_bound ) ) < ll( N >> 1 ) ? AbstractValueKnapsackFewCosts( move( M ) , value , exceptional , cost , cost_sum_bound ) : AbstractNegativeBoundedValueSumKnapsack( M , AdditiveMonoid<INT>() , value , AbstractValueSumBound( M , value ) , cost , cost_sum_bound ); }
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound ) { const INT1 value_sum_bound = ValueSumBound( value ); return ll( cost_sum_bound ) < ll( value_sum_bound ) ? AbstractValueKnapsack( AdditiveMonoid<INT1>() , value , INT1( -1 ) , cost , cost_sum_bound ) : NegativeCostBoundedValueSumKnapsack( value , value_sum_bound , cost , cost_sum_bound , INT2( -1 ) ); }
