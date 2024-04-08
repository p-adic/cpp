// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/UnboundedValueSum/Costfree/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i] >= 0である。
// (2) 0 <= value_sum_boundである。
// を満たす場合にのみサポート。
// 計算量O(N + value_sum_bound^2)で
// 各iに対し項目iを無制限に重複選択できるとして、
// 価値0 <= v <= value_sum_boundごとにvがvalueの部分和で表せるか否かを判定する。
template <typename INT>
vector<bool> UnboundedChoiceCostfreeConstructibiilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
// 計算量O(N + value_sum_bound^2)で
// 各iに対し項目iを無制限に重複選択できるとして、
// value_sum_bound以下における価値の最大値を求める。
template <typename INT> inline INT UnboundedChoiceCostfreeBoundedValueSumKnapsack( const vector<INT>& value , const INT& value_sum_bound );
