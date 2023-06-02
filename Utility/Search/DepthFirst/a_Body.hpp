// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_FIRST_SEARCH( Depth , push_front );

template <int V_max,list<int> E(const int&)>
void SetReversedVertex( DepthFirstSearch<V_max,E>& dfs , const int& V , int ( &reversed_vertex )[V_max] )
{

  int i = V;

  while( --i != -1 ){

    reversed_vertex[i] = dfs.Next();

  }

  return;
  
}

template <int V_max>
void SetChildrenOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V , list<int> ( &edge )[V_max] )
{
  
  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( i );

    if( prev_i != -1 ){

      edge[prev_i].push_back[i];

    }

  }

  return;
  
}

template <int V_max>
void SetHeightOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V  , const int ( &reversed_vertex )[V_max] , ( &height )[V_max] )
{

  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( reversed_vertex[i] );

    if( prev_i != -1 ){

      int& height_prev_i = height[prev_i];
      const int& height_i = height[i];
      height_prev_i > height_i ? height_prev_i : height_prev_i = height_i + 1;

    }

  }

  return;

}

template <int V_max>
void SetNumberOfChildrenOfTree( const DepthFirstSearch<V_max,E>& dfs , const int& V  , const int ( &reversed_vertex )[V_max] , ( &count )[V_max] )
{

  for( int i = 0 ; i < V ; i++ ){

    const int& prev_i = dfs.prev( reversed_vertex[i] );

    if( prev_i != -1 ){

      count[prev_i] += count[i] + 1;

    }

  }

  return;

}
