// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/InitialSegment/a.hpp

#pragma once
// verify:
// CostfreeInitialSegmentDoubleKnapsack（N,N_1,N_2,N_3,V_min）
// https://yukicoder.me/submissions/978628（1817121,12,7,1e9+1,1e18）

// VALUEは関数value:N_{<N}->Nまたはその累積和に相当する型。
// sum_{i=0}^{n} value(i) > unpresentable_maxを満たす最小のn<N（存在しない時はN）をN_0と置く。

// 計算量O(cumulative?log N:N_0)で
// valueの始切片のみが選択可能である条件下でナップサック価値の最大値を実現する始切片の終端値を求める。
template <typename INT , typename VALUE> int CostfreeInitialSegmentKnapsack( const ll& N , VALUE value , const INT& value_sum_bound , const bool& cumulative = false );

// 入力の範囲内で要件
// (1) valueは単調増大する。
// (2) unpresentability_max < v <= value_sum_bound_0 + value_sum_bound_1を満たす
//     任意のvに対し、vはvalueの部分和で表せる。
// を満たす場合にのみサポート。

// min(value_sum_bound_0,value_sum_bound_1)をV_minと置き、
// value(n) > unpresentable_maxを満たす最小のn<N（存在しなければN）をN_1と置き、
// sum_{i=0}^{n} value(i) > V_minを満たす最小のn<N（存在しなければN）をN_2と置き、
// value(n) > V_minを満たす最小のn<N（存在しなければN）をN_3と置く。

// 計算量O(log N+(cumulative?0:N_0+N_2)+(N_1<=N_2?0:N_3*V_min))で
// ナップサック２つの価値上限をそれぞれvalue_sum_bound_0,value_sum_bound_1とし、
// valueの始切片のみが選択可能である条件下で、ナップサック１つの場合に帰着させる際の
// 価値の最大値を実現する始切片の終端値を求める。
template <typename INT , typename VALUE>
int CostfreeInitialSegmentDoubleKnapsack( const ll& N , VALUE value , const INT& value_sum_bound_0 , const INT& value_sum_bound_1 , const INT& unpresentable_max , const bool& cumulative );
