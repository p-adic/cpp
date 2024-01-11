// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_FIRST_SEARCH( Breadth , push_back );

template <typename E>
void SetDepth_Body( BreadthFirstSearch<E>& bfs , const int& V , vector<int>& depth )
{

  depth = vector<int>( V , -1 );
  int i = bfs.Next();
  depth[i] = 0;
  
  while( ( i = bfs.Next() ) != -1 ){

    depth[i] = depth[bfs.prev( i )] + 1;

  }

  return;

}

template <typename E>
void SetDepth( const int& V , E e , const int& init , vector<int>& depth )
{

  BreadthFirstSearch bfs{ V , move( e ) , init };
  SetDepth_Body( bfs , V , depth );
  return;
  
}

template <typename E>
void SetDepth( BreadthFirstSearch<E>& bfs , const int& V , const int& init , vector<int>& depth )
{

  bfs.Reset( init );
  SetDepth_Body( bfs , V , depth );
  return;

}
