// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costwise/a.hpp

#pragma once

// verify:
// MulicaseKnapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/968878（100,1e9,1e5）

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しM.One() <= value[i]である。
// (3) N未満の各iに対し0 <= cost[i]である。
// (4) 0 <= cost_sum_boundである。
// (5) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N * cost_sum_bound)で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractValueCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// 計算量O(N * cost_sum_bound)で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename INT1 , typename INT2> inline vector<INT1> CostwiseKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound );
