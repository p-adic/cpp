// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Tree/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times ...)^{< \omega}を持つ無向木である。
// を満たす場合にのみサポート。
// rootを始点とするGの有向グラフ構造をG_dirとして
// TopologicalSortedForest( G_dir )をO(|V_G|+|E_G|)で計算する。
template <typename UNDIRECTED_TREE> tuple<vector<inner_t<UNDIRECTED_TREE>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedTree( UNDIRECTED_TREE& G , const inner_t<UNDIRECTED_TREE>& root );

