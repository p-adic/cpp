// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/Unstable/Dependent/a.hpp

#pragma once

#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// NegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack（CS,cost_sum_bound）
// https://yukicoder.me/submissions/969032（5e3,5e3）

template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename INT2 , typename INT3>
class DependentItemData
{

private:
  N_MODULE m_M;
  int m_N1;
  VALUE1 m_value1;
  VALUE2 m_value2;
  const vector<INT1>* m_p_choice_stability_num1;
  const vector<INT2>* m_p_dependence;
  const vector<INT3>* m_p_init;
  const vector<INT3>* m_p_diff;

public:
  inline DependentItemData( N_MODULE M , int N1 , VALUE1 value1 , VALUE2 value2 , const vector<INT1>& choice_stability_num1 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff );
  U operator()( const int& i , const ll& m );

};

// VALUE1,2は写像value1,2:N^2->Uに相当する型。
// COST1,2は写像cost1,2:N^2->Nに相当する型。
// choice_stability_num1のサイズをN1、choice_stability_num2のサイズをN2と置き、
// initとdiffとdependenceのサイズがN2と等しいとする。

// 以下sum_i choice_stability_num1(i) + sum_i choice_stability_num2(i)をCSと置く。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序N加群構造である。
// (2) N2未満の各iに対し0 <= init[i]かつ1 <= diff[i]である。
// (3) N2未満の各iに対し0 <= dependence[i] < N1である。
// を満たす場合にのみサポート。
// 計算量O(N2)で
// 項0～N1-1が与えられていて、項dependence[j]<N1がinit[j]+m*diff[j]回選択されていないと
// 1+m回選択できない項N+jをj=0～N2-1に対し追加する。
template <typename N_MODULE , typename VALUE1 , typename VALUE2 , typename COST1 , typename COST2 , typename INT1 , typename INT2 , typename INT3>
pair<DependentItemData<ret_t<VALUE1,int,ll>,N_MODULE,VALUE1,VALUE2,INT1,INT2,INT3>,DependentItemData<ret_t<COST1,int,ll>,Module<ll,ret_t<COST1,int,ll>>,COST1,COST2,INT1,INT2,INT3>> GetDependentItemData( N_MODULE M , VALUE1 value1 , VALUE2 value2 , COST1 cost1 , COST2 cost2 , vector<INT1>& choice_stability_num1 , const vector<INT1>& choice_stability_num2 , const vector<INT2>& dependence , const vector<INT3>& init , const vector<INT3>& diff );

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序N加群構造である。
// (2) N1未満の各iとchoice_stable_num1[i]以下の各mに対し0 <= cost1(i,m)である。
// (3) N2未満の各iとchoice_stable_num2[i]以下の各mに対し0 <= cost2(i,m)である。
// (4) N1未満の各iに対し、M.One() < value1(i,choice_stable_num1[i])ならば
//     0 < cost1(i,choice_stable_num2[i])である。
// (5) N2未満の各iに対し、
//     diff[i]*value1(dependence[i],choice_stable_num1[i])と
//     value2(i,choice_stable_num2[i])の和がM.One()より大きいならば、
//     diff[i]*cost1(dependence[i],choice_stable_num1[i])と
//     cost2(i,choice_stable_num2[i])の和が正である。
// (6) 0 <= cost_sum_boundである。
// (7) exceptionalは価値の総和で表せない。
// (8) N2未満の各iに対し0 <= init[i]かつ1 <= diff[i]である。
// (9) N2未満の各iに対し0 <= dependence[i] < N1である。
// を満たす場合にのみサポート。
// 計算量O(CS * cost_sum_bound)で
// 各i<N1に対し第1種項目iを無制限に重複選択でき1+m回目の重複選択における項目iの
// 価値がvalue1(i,min(m,choice_stable_num1[i]))であり
// コストがcost1(i,min(m,choice_stable_num1[i]))であり、
// 各i<N2に対し第2種項目iを重複選択でき1+m回目の重複選択は第1種項目dependence[i]を
// init[i]+m*diff[i]回選択している場合に可能でありその際の第2種項目iの
// 価値がvalue2(i,min(m,choice_stable_num2[i]))であり
// コストがcost2(i,min(m,choice_stable_num2[i]))であるとして、
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline vector<U> AbstractNegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff );
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline vector<INT1> NegativeValueUnboundedChoiceUnstableDependentCostwiseKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff );
// 計算量O(CS * cost_sum_bound)で
// コストの総和cost_sum_bound以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename N_MODULE , typename VALUE1 , typename VALUE2 , typename INT1 , typename COST1 , typename COST2 , typename INT2 , typename INT3 , typename INT4> inline pair<U,INT1> AbstractNegativeValueUnboundedChoiceUnstableDependentKnapsack( N_MODULE M , VALUE1 value1 , VALUE2 value2 , const U& exceptional , COST1 cost1 , COST2 cost2 , const INT1& cost_sum_bound , vector<INT2>& choice_stability_num1 , const vector<INT2>& choice_stability_num2 , const vector<INT3>& dependence , const vector<INT4>& init , const vector<INT4>& diff );
template <typename INT1 , typename VALUE1 , typename VALUE2 , typename INT2 , typename COST1 , typename COST2 , typename INT3, typename INT4 , typename INT5> inline pair<INT1,INT2> NegativeValueUnboundedChoiceUnstableDependentKnapsack( VALUE1 value1 , VALUE2 value2 , const INT1& exceptional , COST1 cost1 , COST2 cost2 , const INT2& cost_sum_bound , vector<INT3>& choice_stability_num1 , const vector<INT3>& choice_stability_num2 , const vector<INT4>& dependence , const vector<INT5>& init , const vector<INT5>& diff );


