// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/KnapsackProblem/Negative/Value/Multicost/a.hpp

#pragma once
// verify:
// NegativeValueMulticostKnapsack（N,W,D,L）
// https://yukicoder.me/submissions/976638（5e3,5e3,2,1）


// 以下cost_sum_boundのサイズをDと置き、D>=2とする。
// max_{d=0}^{D-1} cost_sum_bound[d]をWと置く。
// max_c valid(c).size()をLと置く。
// VALIDは関数valid:N^{D-1} -> {(l,r) in N^2|l<=r}^{< omega}に相当する型。

// 入力の範囲内で要件
// (1) Mはoperator<(const U&,const U&)に関してUの全順序可換モノイド構造である。
// (2) exceptionalは価値の総和で表せない。
// (3) N未満の各iに対しcord[i]が0以上D未満である。
// (4) N未満の各iに対しcost[i]が0以上である。
// (5) D未満の各dに対し0 <= cost_sum_bound[d]である。
// (6) (0,r) in valid(0,...,0)を満たすr in Nが存在する
// を満たす場合にのみサポート。
// 計算量O(N W
//   + sum_{c in prod_{d=0}^{D-2} [0,cost_sum_bound[d]]}
//     (D + valid(c).size() log (1+cost_sum_bound[D-1])))
// 特にO(N W + W^{D-1}(D + L log (1+W)))で
// N未満の各iに対し項目iのコストをcost[i]*delta_{coord[i]} in N^Dとした時
// コストの総和(c_0,...,c_{D-1})がprod_d cost_sum_bound[d]に入りかつ
// valid(c_0,...c_{D-2})の定める区間列の和集合にc_{D-1}が属す制約下における
// 価値の総和の最大値を求める。
template <typename U , typename COMM_MONOID , typename INT1 , typename INT2 , typename VALID> U AbstractNegativeValueMulticostKnapsack( COMM_MONOID M , const vector<U>& value , const U& exceptional , const vector<INT1>& coord , const vector<INT2>& cost , const vector<INT2>& cost_sum_bound , VALID valid );
template <typename INT1 , typename INT2 , typename INT3 , typename VALID> inline INT1 NegativeValueMulticostKnapsack( const vector<INT1>& value , const INT1& exceptional , const vector<INT2>& coord , const vector<INT3>& cost , const vector<INT3>& cost_sum_bound , VALID valid );

