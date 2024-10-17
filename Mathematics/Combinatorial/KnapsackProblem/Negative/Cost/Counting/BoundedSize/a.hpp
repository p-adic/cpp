// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Cost/Counting/BoundedSize/a.hpp

#pragma once

// valueとcostのサイズをNと置き、value_sum_boundの長さをQと置き、
// size_boundを[size_min,size_max]と表す。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) N未満の各iに対しvalue[i]が0以上である。
// (3) 0 <= value_sum_boundである。
// (4) M.One() <= cost_sum_boundである。
// (5) 0 <= size_min <= size_max <= Nである。
// を満たす場合にのみサポート。

// O(size_max + (size_max-size_min+1)Q(log Q + N)2^{N/2})で
// 各q<Qに対し価値の総和が閉区間value_sum_bound[q]に属しコストの総和がcost_sum_bound以下であり
// 選択数sizeが閉区間size_boundに属す選択方法の個数をanswer[size][q]に格納する。
template <typename INT , typename U , typename COMM_MONOID> vector<vector<ll>> AbstractCountingNegativeCostBoundedValueSumBoundedSizeKnapsack( COMM_MONOID M , const vector<INT>& value , const vector<pair<INT,INT>>& value_sum_bound , const vector<U>& cost , const U& cost_sum_bound , const pair<int,int>& size_bound );
template <typename INT1 , typename INT2> inline vector<vector<ll>> CountingNegativeCostBoundedValueSumBoundedSizeKnapsack( const vector<INT1>& value , const vector<pair<INT1,INT1>>& value_sum_bound , const vector<INT2>& cost , const INT2& cost_sum_bound , const pair<int,int>& size_bound );
// コストがない場合は価値をコストとみなして
// CountingNegativeCostBoundedValueSumKnapsack( value , value_sum_bound , value , value_sum_bound_max , size_bound );
// とすれば良い。
