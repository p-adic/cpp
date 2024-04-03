// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:

// Knapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/968875（1e3,1e6,1e3）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9055342/C++17（100,1e5,1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9055344/C++17（100,1e4,1e9）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9055346/C++17（40,4e16,1e15）

// MulicaseKnapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/968878（100,1e9,1e5）


// 以下valueをNと置き、costを用いる場合はcostのサイズがNと等しいとする。


// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してU1の全順序モノイド構造である。
// を満たす場合にのみサポート。
// 計算量O(N)で
// 価値の総和の上界を求める。
template <typename U , typename COMM_MONOID>
U AbstractValueSumBound( COMM_MONOID M , const vector<U>& value );
template <typename INT> inline INT ValueSumBound( const vector<INT>& value );


// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しM.One() <= value[i]である。
// (3) N未満の各iに対し0 <= cost[i]である。
// (4) 0 <= cost_sum_boundである。
// (5) M.One <= value_sum_boundである。
// (6) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(N * cost_sum_bound)で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractValueMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// 計算量O(N * cost_sum_bound)で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename INT1 , typename INT2> inline vector<INT1> MulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しM.One() <= value[i]である。
// (3) N未満の各iに対し0 <= cost[i]である。
// (4) 0 <= cost_sum_boundである。
// (5) M.One <= value_sum_boundである。
// (6) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(N min(cost_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractValueKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// 計算量O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// 計算量の算出にvalue_sum_boundやcost_sum_boundの大きさを使うので、INT1やINT2を抽象化しない。

