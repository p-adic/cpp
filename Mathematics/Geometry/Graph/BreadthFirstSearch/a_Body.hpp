// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

DEFINITION_OF_FIRST_SEARCH( Breadth , push_back );

template <list<int> E(const int&)>
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

template <list<int> E(const int&)>
void SetDepth( const int& V , const int& init , vector<int>& depth )
{

  BreadthFirstSearch<E> bfs{ V , init };
  SetDepth_Body( bfs , V , depth );
  return;
  
}

template <list<int> E(const int&)>
void SetDepth( BreadthFirstSearch<E>& bfs , const int& V , const int& init , vector<int>& depth )
{

  bfs.Reset( init );
  SetDepth_Body( bfs , V , depth );
  return;

}
