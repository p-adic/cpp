// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/a.hpp

#pragma once

// verify:
// BoundedChoiceKnapsack（N,v_max,value_sum_bound,cost_sum_bound,choice_num_bound_max）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_G/judge/9071868/C++17（100,1e3,1e9,1e4,1e4）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_I/judge/9071869/C++17（50,50,25e11,1e9,1e9）

// max_i value[i]をv_maxと置き、max_i choice_num_bound[i]をcn_maxと置く。

// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してU1の全順序N加群構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してU2の全順序N加群構造である。
// を満たす場合にのみサポート。
// 計算量O(N log_2 cn_max)で
// valueとcost重複選択なしの等価な入力データに翻訳しvalue_newとcost_newに格納する。
template <typename U1 , typename N_MODULE1 , typename U2 , typename N_MODULE2 , typename INT>
void SetIteratedItem( N_MODULE1 M1 , N_MODULE2 M2 , const int& N , const vector<U1>& value , vector<U1>& value_new , const vector<U2>& cost , vector<U2>& cost_new , const vector<INT>& choice_num_bound );

// min(max_i value[i]>0?choice_num_bound(i):0,value_sum_bound)でcn_maxを定義し直す。
// BoundedChoiceValueSumBound(value,cost_sum_bound,choice_num_bound)をvalue_sum_bound
// と置く。
// 入力の範囲内で要件
// (1) N未満の各iに対しcost[i]が0以上である。
// (2) 0 <= value_sum_boundである。
// (3) 0 <= cost_sum_boundである。
// を満たす場合にのみサポート。
// 計算量O(min(N min(value_sum_bound,cost_sum_bound,cn_max 2^{N/2}) log_2 cn_max,
//   N^2 v_max^2 log_2 v_max))で
// 各iに対し項目iをchoice_num_bound[i]回まで重複選択できるとして、コストの総和cost_sum_bound
// 以下における価値の総和のvalue_sum_bound以下での最大値を求める。
template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> BoundedChoiceKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
