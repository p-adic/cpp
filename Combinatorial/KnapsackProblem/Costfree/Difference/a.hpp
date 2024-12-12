// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Costfree/Difference/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1016175 (N<=40,value_bound=8e5,size_diff_bound=0)

// N>0?max(value):0をvalue_boundと置く。

// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。

// 計算量O(N + size_diff_bound value_bound^{(log_2 3)/2} log value_bound)で
// 項を少なくとも一方は非空な２グループと余りに分け、
// ２グループの要素数の差がsize_diff_bound以下である時の
// ２グループの価値の総和の差の絶対値の最小値を求める。
// https://yukicoder.me/problems/no/2918の解説をもとに実装。
template <typename INT> INT CostfreeDifferenceKnapsack( const vector<INT>& value , int size_diff_bound = 0 );
