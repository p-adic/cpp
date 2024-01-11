// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

// verify:
// https://yukicoder.me/submissions/942789（多点BFSによる全探索）
// https://yukicoder.me/submissions/942791（多点BFSによる連結成分取得）

#pragma once
#include "a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Breadth );

// (V,E)におけるinitからの深さを格納（O((initの連結成分)+(initの連結成分におけるEのサイズの合計))）
// 到達できない点は深さの代わりに-1を格納。
template <typename E>
void SetDepth( const int& V , E e , const int& init , vector<int>& );
// 探索畤にbfsを初期化して流用する。
template <typename E>
void SetDepth( BreadthFirstSearch<E>& bfs , const int& V , E e , const int& init , vector<int>& depth );
