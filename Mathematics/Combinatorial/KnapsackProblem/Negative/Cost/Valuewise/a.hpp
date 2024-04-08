// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Valuewise/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) 0 <= value_sum_boundである。
// (5) exceptionalはコストの総和で表せない。
// を満たす場合にのみサポート。
// 計算量O(N * value_sum_bound)で
// 価値の総和0 <= v <= value_sum_boundごとにコストの総和の最小値を求める。
template <typename INT , typename U , typename COMM_MONOID>
vector<U> AbstractNegativeCostBoundedValueSumValuewiseKnapsack( COMM_MONOID M , const vector<INT>& value , const INT& value_sum_bound , const vector<U>& cost , const U& exceptional );
template <typename INT1 , typename INT2> inline vector<INT2> NegativeCostBoundedValueSumValuewiseKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& exceptional );
