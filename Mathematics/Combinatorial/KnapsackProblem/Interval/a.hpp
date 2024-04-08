// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Interval/a.hpp

#pragma once

// diff_max = -1ならばdiff_maxをN - 1に置き換える。
// 入力の範囲内で要件
// (1) M1はoperator<(const U1&,const U1&)に関してU1の全順序可換群構造である。
// (2) M2はoperator<(const U2&,const U2&)に関してU2の全順序可換群構造である。
// (3) diff_min <= diff_max < Nである。
// を満たす場合にのみサポート。
// costとvalueの各成分が非負の時は計算量O(N)、一般にはO(N(diff_max - diff_min + 1))で
// 長さdiff_min以上diff_max以下のvalueの連続部分和のvalue_sum_bound以下での最大値と
// それを実現するコストの最小値を求める。
template <typename U1 , typename ABEL_GROUP1 , typename U2 , typename ABEL_GROUP2>
pair<U1,U2> AbstractIntervalKnapsack( ABEL_GROUP1 M1 , ABEL_GROUP1 M2 , const vector<U1>& value , const U1& value_sum_bound , const vector<U2>& cost , const U2& cost_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> IntervalKnapsack( const vector<INT1>& value , const INT1& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const int& diff_min = 0 , int diff_max = -1 );


// diff_max = -1ならばdiff_maxをN - 1に置き換える。
// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換群構造である。
// (2) diff_min <= diff_max < Nである。
// を満たす場合にのみサポート。
// valueの各成分が非負の時は計算量O(N)、一般にはO(N(diff_max - diff_min + 1))で
// 長さdiff_min以上diff_max以下のvalueの連続部分和のvalue_sum_bound以下での最大値を求める。
template <typename U , typename ABEL_GROUP> inline U AbstractIntervalCostfreeKnapsack( ABEL_GROUP1 M , const vector<U>& value , const U& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
template <typename INT> inline INT IntervalCostfreeKnapsack( const vector<INT>& value , const INT& value_sum_bound , const int& diff_min = 0 , int diff_max = -1 );
