// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Multichoice/Bounded/a.hpp

#pragma once

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_G/judge/9047304/C++17（BoundedChoiceKnapsack, N<=100,value_bound<=1e3,value_sum_bound<=1e9,cost[i]<=1e3,choice_num_bound_max<=1e4,cost_sum_bound<=1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_I/judge/9047292/C++17（BoundedChoiceKnapsack, N<=50,value_bound<=50,cost[i]<=1e9,choice_num_bound_max<=1e9,cost_sum_bound<=1e9）

// CHOICE_NUM_BOUNDは写像choice_num_bound:N->Nに相当する型。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序N加群構造である。
// (2) N未満の各iに対しcost[i]が0以上であり、0ならばvalue[i] = M.One()である。
// (3) N未満の各iに対しvalue[i]がM.One()以上である。
// (4) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(min(N + cost_sum_bound^2,N * cost_sum_bound log_2 cost_sum_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline vector<U> AbstractBoundedChoiceMulticaseKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename CHOICE_NUM_BOUND , typename INT2> inline vector<INT2> BoundedChoiceMulticaseKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , const vector<INT1>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );
// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// 計算量O(min(N + value_sum_bound^2,N * value_sum_bound log_2 value_sum_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// 価値0 <= v <= value_sum_boundごとにvがvalueの部分和で表せるか否かを判定する。
template <typename INT , typename CHOICE_NUM_BOUND> inline vector<bool> BoundedChoiceCostfreeConstructibilityKnapsack( const vector<INT>& value , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max );
// 計算量O(min(N + cost_sum_bound^2,N * cost_sum_bound log_2 cost_sum_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、コストの総和cost_sum_bound
// 以下における価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename N_MODULE , typename INT , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceKnapsack( N_MODULE M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , const vector<INT>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が1以上である。
// (2) N未満の各iに対しchoice_num_bound(i) <= choice_num_bound_maxである。
// を満たす場合にのみサポート。
// 計算量O(min(N + cost_sum_bound^2,
//   N min(cost_sum_bound,value_sum_bound,2^{(N log_2 choice_sum_bound_max)/2}) log_2 choice_sum_bound_max,
//   N^2 value_bound^2 log_2 value_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、コストの総和cost_sum_bound
// 以下における価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename INT1 , typename INT2 , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const INT1& value_bound , const INT1& value_sum_bound , const vector<INT2>& cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT2& cost_sum_bound );
// 入力の範囲内で要件
// (1) N未満の各iに対しvalue[i]が0以上である。
// を満たす場合にのみサポート。
// 計算量O(min(N + value_sum_bound^2,
//   N min(value_sum_bound,2^{N/2}) log_2 value_sum_bound,
//   N^2 value_bound^2 log_2 value_bound))で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// 価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename INT , typename CHOICE_NUM_BOUND> inline INT BoundedChoiceCostfreeKnapsack( const vector<INT>& value , const INT& value_bound , const INT& value_sum_bound , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max );


// COSTは写像cost:N^2->Nに相当する型。
// 入力の範囲内で要件
// (1) N未満の各iとchoice_num_bound(i)以下の各mに対しcost(i,m)が1以上である。
// (2) N未満の各iに対しvalue[i]がM.One()以上である。
// (3) exceptionalは価値の総和で表せないかvalue_sum_boundより大きい。
// を満たす場合にのみサポート。
// 計算量O(N * cost_sum_bound^2)で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択でき1+m回目の重複選択における項目iのコストが
// cost(i,m)であるとして、コストの総和0 <= c <= cost_sum_boundごとに
// 価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND>
vector<U> AbstractBoundedChoiceUnstableCostMulticaseKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline vector<INT1> BoundedChoiceUnstableCostMulticaseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );
// 計算量O(N * cost_sum_bound^2)で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択でき1+m回目の重複選択における項目iのコストが
// cost(i,m)であるとして、コストの総和cost_sum_bound以下としてvalue_sum_bound以下での最大値を
// 求める。
template <typename U , typename COMM_MONOID , typename INT , typename COST , typename CHOICE_NUM_BOUND> inline pair<U,INT> AbstractBoundedChoiceUnstableCostKnapsack( COMM_MONOID M , const vector<U>& value , const U& value_sum_bound , const U& exceptional , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT& cost_sum_bound );
template <typename INT1 , typename INT2 , typename COST , typename CHOICE_NUM_BOUND> inline pair<INT1,INT2> BoundedChoiceUnstableCostKnapsack( const vector<INT2>& value , const INT2& value_sum_bound , COST cost , CHOICE_NUM_BOUND choice_num_bound , const ll& choice_num_bound_max , const INT1& cost_sum_bound );

