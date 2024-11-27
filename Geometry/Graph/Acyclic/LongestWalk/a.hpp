// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/LongestWalk/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/972197（GetLongestWalk）

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times U)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) Mがoperator<(const U&,const U&)に関してUの順序モノイド構造である。
// を満たす場合にのみサポート。
// Gの最長歩道をO(|V_G|+|E_G|)で計算する。
template <typename ACYCLIC_GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<ACYCLIC_GRAPH>>> GetLongestWalk( ACYCLIC_GRAPH& G , MONOID M );
// Gが有向木の場合はDepthFirstSearchOnTree::Depthの最大値で良い。
