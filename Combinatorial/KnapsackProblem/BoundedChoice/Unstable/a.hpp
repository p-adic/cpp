// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/Unstable/a.hpp

#pragma once
#include "a_Macro.hpp"

// VALUEは写像value:N^2->Nに相当する型。
// COSTは写像cost:N^2->Nに相当する型。
// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iとchoice_num_bound[i]以下の各mに対しM.One() <= value(i,m)である。
// (3) N未満の各iとchoice_num_bound[i]以下の各mに対し0 <= cost(i,m)である。
// (4) 0 <= cost_sum_boundである。
// (5) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N * cn_max * cost_sum_bound)で
// 各iに対し項目iをchoice_num_bound[i]回まで重複選択でき1+m回目の重複選択における項目iの
// 価値がvalue(i,m)でコストがcost(i,m)であるとして、コストの総和0 <= c <= cost_sum_boundごとに
// 価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2>
vector<U> AbstractValueBoundedChoiceUnstableCostwiseKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline vector<ret_t<VALUE,int,int>> BoundedChoiceUnstableCostwiseKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
// 計算量O(N * cn_max * cost_sum_bound)で
// 各iに対し項目iをchoice_num_bound[i]回まで重複選択でき1+m回目の重複選択における項目iのコストが
// cost(i,m)であるとして、コストの総和cost_sum_bound以下としてvalue_sum_bound以下での最大値を
// 求める。
template <typename U , typename COMM_MONOID , typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<U,INT1> AbstractBoundedChoiceUnstableKnapsack( COMM_MONOID M , const int& N , VALUE value , const U& exceptional , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename VALUE , typename INT1 , typename COST , typename INT2> inline pair<ret_t<VALUE,int,int>,INT1> BoundedChoiceUnstableKnapsack( const int& N , VALUE value , COST cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );

