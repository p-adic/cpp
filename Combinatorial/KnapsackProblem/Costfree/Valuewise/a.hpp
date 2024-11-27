// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Valuewise/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// 計算量O(N * value_sum_bound)で
// 価値0 <= v <= value_sum_boundごとにvがvalueの部分和で表せるか否かを判定する。
template <typename INT> inline vector<bool> CostfreePresentabilityKnapsack( const vector<INT>& value , const INT& value_sum_bound );
