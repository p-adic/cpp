// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) 0 <= value_sum_boundである。
// (4) exceptional <= cost_sum_lbound <= M.One()である。
// (5) exceptionalはコストの総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N * value_sum_bound)で
// 価値の総和0 <= v <= value_sum_boundごとにコストの総和のcost_sum_lbound以上での最小値を求める。
template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractDualMulticaseNegativeCostKnapsack( COMM_MONOID M , const int& N , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional );
template <typename INT1 , typename INT2> inline vector<INT2> DualMulticaseNegativeCostKnapsack( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_lbound , const INT2& exceptional );

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) 0 <= value_sum_boundである。
// (4) exceptionalはコストの総和で表せるいかなる値より小さい。
// を満たす場合にのみサポート。
// 計算量O(N min(value_sum_bound,2^{N/2}))で
// コストの総和cost_sum_bound以下における価値の総和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename INT , typename U , typename COMM_MONOID> inline pair<INT,U> AbstractNegativeCostKnapsack( COMM_MONOID M , const int& N , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const U& exceptional );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> NegativeCostKnapsack( const int& N , const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const INT2 exceptional );
