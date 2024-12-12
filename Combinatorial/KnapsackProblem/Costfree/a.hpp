// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/a.hpp

#pragma once

// N>0?max(value):0をvalue_boundと置く。

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// David Pisinger, "Linear Time Algorithms for Knapsack Problems with Bounded Weights, Journal of Algorithms", Volume 33, Issue 1, October 1999, Pages 1--14
// のアルゴリズム
// (参考：https://stackoverflow.com/questions/18821453/bounded-knapsack-special-case-small-individual-item-weight-is-small-compared-t/18949218#18949218)
// をもとに実装。
// 計算量O(N min(value_bound,2^{N/2}))で
// 価値の総和のvalue_sum_bound以下における最大値を求める。
template <typename INT> inline INT CostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound );

// 各項の選択が独立でなかったり選択に罰金や報酬がある場合は
// 最小カット計算に帰着。
