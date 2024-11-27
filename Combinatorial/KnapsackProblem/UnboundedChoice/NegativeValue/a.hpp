// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/UnboundedChoice/NegativeValue/a.hpp

#pragma once

// verify:
// UnboundedChoiceNegativeValueKnapsack（N,cost_sum_bound）
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DPL_1_C/judge/9054779/C++17（100,1e4）

// コストが正ならば選択回数はcost_sum_boundで抑えられ、
// 価値の総和は(max_i value[i])*cost_sum_boundで抑えられるので、
// その場合はAbstractBoundedChoiceNegativeValue(Costwise)Knapsack
// と比較して早い方を用いる。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しcost[i]が0以上であり、0ならばvalue[i] <= M.One()である。
// (3) 0 <= cost_sum_boundである。
// (4) exceptionalは価値の総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N + cost_sum_bound^2)で
// 各iに対し項目iを無制限に重複選択できるとして、
// コストの総和0 <= c <= cost_sum_boundごとに価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename INT>
vector<U> AbstractNegativeValueUnboundedChoiceCostwiseKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline vector<INT1> NegativeValueUnboundedChoiceCostwiseKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );
// 計算量O(N + cost_sum_bound^2)で
// 各iに対し項目iを無制限に重複選択できるとして、
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename U , typename COMM_MONOID , typename INT> inline pair<U,INT> AbstractNegativeValueUnboundedChoiceKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT>& cost , const INT& cost_sum_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeValueUnboundedChoiceKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& cost , const INT2& cost_sum_bound );
