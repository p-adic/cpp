// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/a.hpp

#pragma once
#include "../a.hpp"

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times ...)^{< \omega}を持ち閉路を持たない有向グラフである。
// を満たす場合にのみサポート。
// Gのトポロジカルソートts:N->TをO(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH> vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G );
// {Gのトポロジカルソートts:N->T,G.Enumeration_invとtsの合成:N->Nの逆写像ts_inv,
// tsによる番号付けに関する次ノード対応}を
// O(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH> tuple<vector<inner_t<ACYCLIC_GRAPH>>,vector<int>,vector<vector<int>>> TopologicalSortedGraph( ACYCLIC_GRAPH& G );
