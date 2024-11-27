// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/HamiltonWalk/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/987414

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) Gは有向グラフである。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。

// Gの各頂点を一度以上通る歩道の始点となりえる頂点全体のなす配列を返す。（O(V+E)）
template <typename T , typename GRAPH> vector<T> StartPointsOfHamiltonWalk( GRAPH& G , const T& not_found );

