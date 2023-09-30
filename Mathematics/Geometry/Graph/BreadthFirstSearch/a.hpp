// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a.hpp

// verify: https://yukicoder.me/submissions/915732

#pragma once
#include "a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Breadth );

// (V,E)におけるinitからの深さを格納（O((initの連結成分)+(initの連結成分におけるEのサイズの合計))）
// 到達できない点は深さの代わりに-1を格納。
template <int V_max,list<int> E(const int&)>
void SetDepth( const int& V , const int& init , int ( &depth )[V_max] );
// 探索畤にbfsを初期化して流用する。
template <int V_max,list<int> E(const int&)>
void SetDepth( BreadthFirstSearch<V_max,E>& bfs , const int& V , const int& init , int ( &depth )[V_max] );
