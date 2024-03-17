// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/953259（GetLongestWalk）

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times ...)^{< \omega}を持ち閉路を持たない有向グラフである。
// を満たす場合にのみサポート。
// GのトポロジカルソートをO(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH> vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G );

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times U)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) Mがoperator<(const U&,const U&)に関してUの順序モノイド構造である。
// を満たす場合にのみサポート。
// Gの最長歩道をO(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH , typename MONOID> pair<inner_t<MONOID>,vector<inner_t<ACYCLIC_GRAPH>>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M );
