// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/DirectedForest/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times ...)^{< \omega}を持つ有向森である。
// を満たす場合にのみサポート。
// {Gのトポロジカルソートts:N->T,G.Enumeration_invとtsの合成:N->Nの逆写像ts_inv,
// tsによる番号付けに関する親ノード対応,tsによる番号付けに関する子ノード対応}を
// O(|V_G|+|E_G|)で計算する。
template <typename DIRECTED_FOREST> tuple<vector<inner_t<DIRECTED_FOREST>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedForest( DIRECTED_FOREST& G );

