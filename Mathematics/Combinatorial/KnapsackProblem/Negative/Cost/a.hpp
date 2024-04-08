// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) 0 <= value_sum_boundである。
// (4) M.One() <= cost_sum_boundである。
// (5) exceptionalはコストの総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N min(value_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostBoundedValueSumKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeCostBoundedValueSumKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const INT2& exceptional );
