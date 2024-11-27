// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:
// Knapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/976637（1e3,1e6,1e3）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9056881/C++17（100,1e5,1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9056887/C++17（100,1e4,1e9）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9056888/C++17（40,4e16,1e15）


// 以下valueのサイズをNと置き、costを用いる場合はcostのサイズがNと等しいとする。
// ValueSumBound(value)をvalue_sum_boundと置く。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しM.One() <= value[i]である。
// (3) N未満の各iに対し0 <= cost[i]である。
// (4) 0 <= cost_sum_boundである。
// (5) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N min(value_sum_bound,cost_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// 計算量O(N min(,cost_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound );

// 価値の上限が指定されている場合は
// - Costfree
// - Interval
// - Negative/Cost
// のいずれかを用いる。
