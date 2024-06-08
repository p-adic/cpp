// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/HamiltonPath/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times ...)^{< \omega}を持ち閉路を持たない有向グラフである。
// を満たす場合にのみサポート。

// Gの各頂点を重複なく経由する一意なパス（存在しない場合は空列）を返す。（O(V+E)）
template <typename ACYCLIC_GRAPH> vector<inner_t<ACYCLIC_GRAPH>> HamiltonPath( ACYCLIC_GRAPH& G );
