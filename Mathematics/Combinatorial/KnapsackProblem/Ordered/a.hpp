// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Ordered/a.hpp

#pragma once

// cost_boundのサイズをKと置く。
// 入力の範囲内で要件
// (1) K <= Nである。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) chosen_zeroはサイズKのbool値配列である。
// を満たす場合にのみサポート。
// 計算量O(N log_2 N)で
// 1 <= k <= K個目の選択のコスト上限をcost_bound[k-1]とし、項目0 <= i < Nのコストを
// (chosen_zero[k]?cost0:cost1)[i]とする状況で、高々K回の選択をする時の
// 価値の総和の最大値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedUnstableCostKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost0 , const vector<U2>& cost1 , const vector<bool>& chosen_zero , const vector<U2>& cost_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> OrderedUnstableCostKnapsack( const vector<INT1>& value , const vector<INT2>& cost0 , const vector<INT2>& cost1 , const vector<bool>& chosen_zero , const vector<INT2>& cost_bound );


// cost_boundのサイズをKと置く。
// (1) K <= Nである。
// (2) N未満の各iに対しvalue[i]が0以上である。
// 計算量O(N log_2 N)で
// 1 <= k <= K個目の選択のコスト上限をcost_bound[k-1]とし、高々K回の選択をする時の
// 価値の総和の最大値を求める。
template <typename U1 , typename COMM_MONOID1 , typename U2 , typename COMM_MONOID2 >
pair<U1,U2> AbstractOrderedKnapsack( COMM_MONOID1 M1 , COMM_MONOID2 M2 , const vector<U1>& value , const vector<U2>& cost , const vector<U2>& cost_bound );
template <typename INT1 , typename INT2> inline pair<INT1,INT2> OrderedKnapsack( const vector<INT1>& value , const vector<INT2>& cost , const vector<INT2>& cost_bound )x;

