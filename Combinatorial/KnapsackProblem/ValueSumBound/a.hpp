// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/ValueSumBound/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してU1の全順序モノイド構造である。
// を満たす場合にのみサポート。
// 計算量O(N)で
// 価値の総和の上界を求める。
template <typename U , typename COMM_MONOID>
U AbstractValueSumBound( COMM_MONOID M , const vector<U>& value );
template <typename INT> inline INT ValueSumBound( const vector<INT>& value );

