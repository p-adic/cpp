// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/Subwalk/a.hpp

#pragma once
#include "a_macro.hpp"

// GRAPHは有向辺T->(T \times ...)^{<\omega}を持つグラフに相当する型。
// a[i]を始点とする辺の本数の総和をE_aと置く。

// O(E_a log size)でaの連続とは限らない非空部分列であって任意の隣接２成分がE_Gの定める有向辺の
// 逆向きの有向辺で結ばれるものを数え上げる。
template <typename T , typename GRAPH , typename INT> INT CountSubwalk( GRAPH& G , const vector<T>& a , const INT& dummy );

// O((size + E_a) log size)でaの連続とは限らない非空部分列であって任意の隣接２成分が
// E_Gの定める有向辺の逆向きの有向辺で結ばれるものの長さの最大値を返す。
template <typename T , typename GRAPH> int LongestSubwalk( GRAPH& G , const vector<T>& a );

// 例えば狭義単調増大部分列を扱いたい場合はx<yとx<-yが同値になるようにグラフを構築する。
// グラフを逆にすれば同じことが可能だが、上界より下界が少ない状況（x<y <=>  x|yなど）で
// 計算量が良くなる。
