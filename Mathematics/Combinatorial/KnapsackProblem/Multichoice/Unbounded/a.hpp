// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Unbounded/a.hpp

#pragma once

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_C/judge/9047345/C++17（UnboundedChoiceKnapsack、N=100,value[i]<=1e3,value_sum_bound<=1e9,cost[i]<=1e3,cost_sum_bound<=1e4）

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しcost[i]が0以上であり、0ならばvalue[i] = M.One()である。
// (3) N未満の各iに対しvalue[i]がM.One()以上である。
// (4) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(N + cost_sum_bound^2)で
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractUnboundedChoiceMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> UnboundedChoiceMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );
// 計算量O(N + cost_sum_bound^2)で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractUnboundedChoiceKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> UnboundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound );


// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// 計算量O(N + value_sum_bound^2)で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// 価値0 <= v <= value_sum_boundごとにvがvalueの部分和で表せるか否かを判定する。
template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
template <typename INT> inline INT UnboundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound );
