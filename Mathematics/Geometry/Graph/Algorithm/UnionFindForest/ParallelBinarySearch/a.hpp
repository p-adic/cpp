// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/ParallelBinarySearch/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/988997

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) v_min <= v_max
// を満たす場合にのみサポート。

// O( ( |V_G| + |E_G| + |additional_edge| + Q + min( v_max - v_min + 1 , Q log Q ) )
//    α( |V_G| ) log( v_max - v_min + 1 ) )で
// Gの辺を長さ0としてadditional_edgeを追加した時の各[s,t] in queryのl^∞距離を求める。
template <typename T , typename INT , typename GRAPH> vector<INT> ParallelBinaryUnionFind( GRAPH& G , const INT& v_min , const INT& v_max , const map<INT,vector<pair<T,T>>>& additional_edge , const vector<pair<T,T>>& query );
template <typename T , typename INT , typename GRAPH> inline vector<INT> ParallelBinaryUnionFind( const int& size , const INT& v_min , const INT& v_max , const map<INT,vector<pair<int,int>>>& additional_edge , const vector<pair<int,int>>& query );
