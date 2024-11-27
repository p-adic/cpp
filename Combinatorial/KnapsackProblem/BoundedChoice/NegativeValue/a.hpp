// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/BoundedChoice/NegativeValue/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序N加群構造である。
// (2) N未満の各iに対しcost[i]が0以上であり、0ならばvalue[i] = M.One()である。
// (3) 0 <= cost_sum_boundである。
// (4) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N * cost_sum_bound log_2 cn_max)で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline vector<U> AbstractNegativeValueBoundedChoiceCostwiseKnapsack( N_MODULE M , const vector<U>& value , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline vector<INT1> NegativeValueBoundedChoiceCostwiseKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT1>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
// 計算量O(N min(cost_sum_bound,cn_max 2^{N/2}) log_2 cn_max)で
// 各iに対し項目iをchoice_num_bound(i)回まで重複選択できるとして、コストの総和cost_sum_bound
// 以下における価値の総和の最大値とそれを実現するコストの最小値を求める。
template <typename U , typename N_MODULE , typename INT1 , typename INT2> inline pair<U,INT1> AbstractNegativeValueBoundedChoiceKnapsack( N_MODULE M , const vector<U>& value , const U& exceptional , const vector<INT1>& cost , const INT1& cost_sum_bound , const vector<INT2>& choice_num_bound );
template <typename INT1 , typename INT2 , typename INT3> inline pair<INT1,INT2> NegativeValueBoundedChoiceKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound , const vector<INT3>& choice_num_bound );
