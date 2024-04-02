// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/a.hpp

#pragma once

// verify:

// Knapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/968656（1e3,1e6,1e3）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_B/judge/9047312/C++17（100,1e5,1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_F/judge/9046799/C++17（100,1e4,1e9）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_H/judge/9046714/C++17（40,4e16,1e15）

// MulicaseKnapsack（N,value_sum_bound,cost_sum_bound）
// https://yukicoder.me/submissions/968206（100,1e9,1e5）


// 以下valueをNと置き、costを用いる場合はcostのサイズがNと等しいとする。

// 計算量O(N min(cost_sum_bound,value_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename INT1 , typename INT2> inline pair<INT1,INT2> Knapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// 計算量の算出にvalue_sum_boundやcost_sum_boundの大きさを使うので、INT1やINT2を抽象化しない。

