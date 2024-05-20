// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/DirectedForest/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename DIRECTED_FOREST>
tuple<vector<inner_t<DIRECTED_FOREST>>,vector<int>,vector<int>,vector<vector<int>>> TopologicalSortedForest( DIRECTED_FOREST& G )
{

  vector<inner_t<DIRECTED_FOREST>> ts = TopologicalSort( G );
  const int& size = G.size();
  vector<int> ts_inv( size );
  vector<int> prev( size , -1 );
  vector<vector<int>> edge( size );

  for( int i = size - 1 ; i >= 0 ; i-- ){

    auto& t = ts[i];
    auto&& edge_t = G.Edge( t );
    auto& edge_i = edge[i];
    edge_i.reserve( edge_t.size() );

    for( auto& u : edge_t ){

      const int& j = ts_inv[G.Enumeration_inv( u )];
      prev[j] = i;
      edge_i.push_back( j );

    }


    ts_inv[G.Enumeration_inv( t )] = i;

  }

  return { move( ts ) , move( ts_inv ) , move( prev ) , move( edge ) };

}

// 無向木をTopologicalSortedTree(G,root)で変換する必要があるケースが多いのでをincludeする。
#include "../UndirectedTree/a_Body.hpp"
