// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9047312/C++17（Knapsack、N<=100,value_sum_bound<=1e5,cost_sum_bound<=1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9046799/C++17（Knapsack、N<=100,value_sum_bound<=1e4,cost_sum_bound<=1e9）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9046714/C++17（Knapsack、N<=40,value_sum_bound<=4e16,cost_sum_bound<=1e15）

// 以下valueをNと置き、costを用いる場合はcostのサイズがNと等しいとする。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しcost[i]の各成分が0以上である。
// (3) N未満の各iに対しvalue[i]がM.One()以上である。
// (4) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(N * cost_sum_bound )で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和のvalue_sum_bound以下での
// 最大値を求める。
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> MulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// 計算量O(N * cost_sum_bound)で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
// 計算量O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );

