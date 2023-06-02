// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/a.hpp

#pragma once
#include "../BreadthFirst/a_Macro.hpp"

DECLARATION_OF_FIRST_SEARCH( Depth );

template <int V_max,list<int> E(const int&)>
void SetReversedVertex( DepthFirstSearch<V_max,E>& dfs , const int& V , int ( &reversed_vertex )[V_max] );

template <int V_max>
void SetChildrenOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V , list<int> ( &edge )[V_max] );

template <int V_max>
void SetHeightOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V  , const int ( &reversed_vertex )[V_max] , ( &height )[V_max] );

template <int V_max>
void SetNumberOfChildrenOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] );
