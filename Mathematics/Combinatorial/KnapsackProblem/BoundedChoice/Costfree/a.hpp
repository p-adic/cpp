// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Costfree/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// 計算量O(min(N + value_sum_bound^2,N * value_sum_bound log_2 value_sum_bound))で
// 各iに対し項目iをchoice_num_bound[i]回まで重複選択できるとして、
// 価値0 <= v <= value_sum_boundごとにvがvalueの部分和で表せるか否かを判定する。
template <typename INT1 , typename INT2> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound );
// 計算量O(min(N + value_sum_bound^2,
//   N * value_sum_bound log_2 value_sum_bound,
//   N^2 value_bound^2 log_2 value_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// 価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename INT1 , typename INT2> inline INT1 BoundedChoiceCostfreeKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& choice_num_bound );
