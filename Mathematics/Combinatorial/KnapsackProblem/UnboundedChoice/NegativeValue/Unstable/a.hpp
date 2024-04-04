// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/Unstable/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// NegativeValueUnboundedChoiceMulticaseUnstableKnapsack（CS,cost_sum_bound）
// https://yukicoder.me/submissions/969029（5e3,5e3）

// 以下sum_i choice_stability_num(i)をCSと置く。

// VALUEは写像Value:N^2->Nに相当する型。
// COSTは写像cost:N^2->Nに相当する型。
// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iとchoice_stable_num[i]以下の各mに対し0 <= cost(i,m)である。
// (3) N未満の各iに対し、M.One() < value(i,choice_stable_num[i])ならば
//     0 < cost(i,choice_stable_num[i])である。
// (4) 0 <= cost_sum_boundである。
// (5) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(CS * cost_sum_bound)で
// 各iに対し項目iを無制限に重複選択でき1+m回目の重複選択における項目iの
// 価値がvalue(i,min(m,choice_stable_num[i]))であり
// コストがcost(i,min(m,choice_stable_num[i]))であるとして、
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractNegativeValueUnboundedChoiceMulticaseUnstableKnapsack( COMM_MONOID M , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename INT1 , typename VALUE , typename INT2 , typename COST , typename INT3> inline vector<INT1> NegativeValueUnboundedChoiceMulticaseUnstableKnapsack( VALUE value , const INT1& exceptional , COST cost , const INT2& cost_sum_bound , const vector<INT3>& choice_stability_num );
// 計算量O(CS * cost_sum_bound)で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnstableKnapsack( COMM_MONOID M , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_stability_num );
template <typename INT1 , typename VALUE , typename INT2 , typename COST , typename INT3> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnstableKnapsack( VALUE value , const INT1& exceptional , COST cost , const INT2& cost_sum_bound , const vector<INT3>& choice_stability_num );

