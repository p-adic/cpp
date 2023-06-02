// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/a.hpp

#pragma once
#include "../BreadthFirst/a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Depth );

// dfs.init()からの深さを計算。
template <int V_max,list<int> E(const int&)>
void SetDepth( const DepthFirstSearch<V_max,E>& dfs , ( &depth )[V_max] );

// dfs.init()からの深さ優先探索において各ノードに対しそれより前に探索される隣接ノードを計算。
template <int V_max,list<int> E(const int&)>
void SetPrev( DepthFirstSearch<V_max,E>& dfs );

// dfs.init()からの深さ優先探索の探索順の逆順を計算。
template <int V_max,list<int> E(const int&)>
void SetReversedVertex( DepthFirstSearch<V_max,E>& dfs , int ( &reversed_vertex )[V_max] );

// dfs.SetPrev()かdfs.SetReversedVertex()を呼び出してからのみ使用可能。
// dfs.init()からの深さ優先探索において各ノードに対しそれより後に探索される隣接ノード全てを計算。
template <int V_max>
void SetChildren( const DepthFirstSearch<V_max,E>& dfs , list<int> ( &edge )[V_max] );

// dfs.init()からの深さ優先探索における高さを計算。
template <int V_max>
void SetHeight( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &height )[V_max] );

// dfs.init()からの深さ優先探索において各ノードに対しそれより後に探索される隣接ノードの個数を計算。
template <int V_max>
void SetNumberOfChildren( const DepthFirstSearch<V_max,E>& dfs  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] );

// 各ノードの高さ < 2^digitの時のみサポート。
// dfs.init()からの深さ優先探索において各ノードに対しそれより前に探索される隣接ノード計算の反復合成を前計算。
template <int V_max,list<int> E(const int&),int digit = 16>
void SetDoublingAncestor( const DepthFirstSearch<V_max,E>& dfs , ( &doubling )[digit][V_max] );

// 各ノードの高さ < 2^digitの時のみサポート。
// dfs.init()からの深さ優先探索においてノードiより前に探索される隣接ノード計算をn回反復合成。
template <int V_max,int digit = 16>
void Ancestor( int i , int n , const ( &doubling )[digit][V_max] );

// 各ノードの高さ < 2^digitの時のみサポート。
// dfs.init()からの深さ優先探索においてノードi,jに対しそれより前に探索される隣接ノード計算を反復合成して得られるノードのうち反復回数が最も少ないものを計算。
template <int V_max,list<int> E(const int&),int digit = 16>
int LCA( const DepthFirstSearch<V_max,E>& dfs , int i , int j , const ( &doubling )[digit][V_max] , const ( &depth )[V_max] );
