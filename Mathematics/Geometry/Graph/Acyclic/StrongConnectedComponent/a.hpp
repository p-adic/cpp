// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/987407

// 有向グラフから、その強連結成分がなす非輪状有向グラフをトポロジカルソートする。
// 更にグラフを構築したい場合は各tごとに強連結成分番号を格納する（連想）配列を作り、
// Gの辺を走らせて辺をsetやunordered_setや（多重辺を許すなら）vectorで再構築するとよい。
template <typename T , typename GRAPH> vector<vector<T>> StrongConnectedComponent( GRAPH& G , const T& not_found );
