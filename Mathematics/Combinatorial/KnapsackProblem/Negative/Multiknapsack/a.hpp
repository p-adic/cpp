// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Multiknapsack/a.hpp

#pragma once
// verify:
// NegativeBoundedValueMultiknapsack（N,K）
// https://yukicoder.me/submissions/970796（20,2）

// 以下cost_sum_boundのサイズをKと置く。

// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してUの全順序可換モノイド構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してUの全順序可換モノイド構造である。
// (3) M1.One() <= value_sum_boundである。
// (4) K未満の各kに対しM2.One() <= cost_sum_bound[k]である。
// を満たす場合にのみサポート。
// 計算量O(K(N 2^N + K^N))で
// K未満の各kに対しナップサックkの容量をcost_sum_bound[k]とした場合の価値の総和の
// value_sum_bound以下での最大値とそれを実現するコストの最小値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeBoundedValueSumMultiknapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const vector<U2>& cost_sum_bound );

template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeBoundedValueMultiknapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound );
