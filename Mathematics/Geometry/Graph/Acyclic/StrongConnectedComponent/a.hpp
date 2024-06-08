// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/987407

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) Gは有向グラフである。
// (2) not_foundはGの頂点でない。
// を満たす場合にのみサポート。

// Gの強連結成分がなす非輪状有向グラフをトポロジカルソートする。（O(V+E)）
template <typename T , typename GRAPH> vector<vector<T>> StrongConnectedComponent( GRAPH& G , const T& not_found );
// 更にグラフを構築したい場合は各tごとに強連結成分番号を格納する（連想）配列を作り、
// Gの辺を走らせて辺をsetやunordered_setや（多重辺を許すなら）vectorで再構築するとよい。
