// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/a.hpp

#pragma once

// verify:
// NegativeRestrictiveKnapsack
// https://yukicoder.me/submissions/968223（N<=14）


// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してUの全順序可換モノイド構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してUの全順序可換モノイド構造である。
// (3) M1.One() <= value_sum_uboundである。
// (4) M2.One() <= cost_sum_uboundである。
// を満たす場合にのみサポート。
// 計算量O(N 2^{N/2})で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してUの全順序可換モノイド構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してUの全順序可換モノイド構造である。
// (3) M1.One() <= value_sum_uboundである。
// (4) cost_sum_lbound <= M2.One() <= cost_sum_uboundである。
// (5) exceptionalはvalueの部分和で表せないかまたはvalue_sum_ubound以上である。
// を満たす場合にのみサポート。
// 計算量O(N 2^N)で
// コストの総和cost_sum_lbound以上かつcost_sum_ubound以下を保ったまま遷移させる制約下で
// 価値の総和のvalue_sum_bound以下での最大値とそれを実現するコストの最小値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2>
pair<U1,U2> AbstractNegativeRestrictiveKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const U1& value_sum_ubound , const U1& exceptional , const vector<U2>& cost , const U2& cost_sum_lbound , const U2& cost_sum_ubound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeStrictRestrictiveKnapsack( const vector<INT1>& value , const INT1& value_sum_ubound , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& cost_sum_ubound );
