// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しcost[i]が0以上である。
// (3) 0 <= cost_sum_boundである。
// (4) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N min(cost_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeValueKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );

