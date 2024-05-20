// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/Tree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../DirectedForest/a_Body.hpp"

template <typename UNDIRECTED_TREE> tuple<vector<inner_t<UNDIRECTED_TREE>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedTree( UNDIRECTED_TREE& G , const inner_t<UNDIRECTED_TREE>& root )
{

  const int& size = G.size();
  using T = inner_t<UNDIRECTED_TREE>;
  vector<vector<T>> edge( size );
  vector<T> dfs{ root };

  while( !dfs.empty() ){

    const T t = dfs.back();
    dfs.pop_back();
    auto& edge_i = edge[G.Enumeration_inv( t )];
    auto&& edge_t = G.Edge( t );

    for( auto& u : edge_t ){

      auto&& j = G.Enumeration_inv( u );

      if( edge[j].empty() ){

	edge_i.push_back( u );
	dfs.push_back( u );

      }

    }

  }
  
  auto G_dir = G.GetGraph( [&]( const T& t ) -> const vector<T>& { return edge[G.Enumeration_inv( t )]; } );
  return TopologicalSortedForest( G_dir );

}
