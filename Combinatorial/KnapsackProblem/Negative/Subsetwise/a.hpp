// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Subsetwise/a.hpp

#pragma once


// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してUの全順序可換モノイド構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してUの全順序可換モノイド構造である。
// (3) M1.One() <= value_sum_boundである。
// (4) M2.One() <= cost_sum_boundである。
// を満たす場合にのみサポート。
// 計算量O(N 2^N)で
// [0,N)の各部分集合Sごとに、Sの要素のみから項目を選択する場合のコストの総和cost_sum_bound以下
// における価値の総和のvalue_sum_bound以下での最大値とそれを実現するコストの最小値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
vector<pair<U1,U2>> AbstractNegativeBoundedValueSumSubsetwiseKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<pair<INT1,INT2>> NegativeBoundedValueSumSubsetwiseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
