// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_FIRST_SEARCH( Breadth , push_back );

template <int V_max,list<int> E(const int&)>
void SetDepth_Body( BreadthFirstSearch<V_max,E>& bfs , const int& V , int ( &depth )[V_max] )
{

  for( int i = 0 ; i < V ; i++ ){

    depth[i] = -1;

  }

  int i = bfs.Next();
  depth[i] = 0;
  
  while( ( i = bfs.Next() ) != -1 ){

    depth[i] = depth[bfs.prev( i )] + 1;

  }

  return;

}

template <int V_max,list<int> E(const int&)>
void SetDepth( const int& V , const int& init , int ( &depth )[V_max] )
{

  BreadthFirstSearch<V_max,E> bfs{ V , init };
  SetDepth_Body( bfs , V , depth );
  return;
  
}

template <int V_max,list<int> E(const int&)>
void SetDepth( BreadthFirstSearch<V_max,E>& bfs , const int& V , const int& init , int ( &depth )[V_max] )
{

  bfs.Reset( init );
  SetDepth_Body( bfs , V , depth );
  return;

}
