// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/TopologicalSort/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/953259（GetLongestWalk）

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times U)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) Mがoperator<(const U&,const U&)に関してUの順序モノイド構造である。
// を満たす場合にのみサポート。
template <typename GRAPH> list<inner_t<GRAPH>> TopologicalSort( GRAPH& G );

// 入力の範囲内で要件
// (1) Gが辺Edge:T->(T \times U)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) Mがoperator<(const U&,const U&)に関してUの順序モノイド構造である。
// を満たす場合にのみサポート。
template <typename GRAPH , typename MONOID> pair<inner_t<MONOID>,list<inner_t<GRAPH>>> GetLongestWalk( GRAPH& G , MONOID M );
