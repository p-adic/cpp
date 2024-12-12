// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/Restfree/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/1031012

// N>0?max(value):0をvalue_boundと置く。

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。

// 計算量O(N min(value_bound,2^{N/2}))で
// 項を２グループに分け、２グループの価値の総和の差であってdif_optに最も近いものを求める。
template <typename INT> inline INT CostfreeRestfreeDifferenceKnapsack( const vector<INT>& value , const INT& dif_opt = 0 );
