// c:/Users/user/Documents/Programming/Mathematics/Game/Nim/Acyclic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Geometry/Graph/Acyclic/a_Body.hpp"

template <typename GRAPH , typename VALUE>
ret_t<VALUE,inner_t<GRAPH>> AcyclicNim( GRAPH& G , VALUE&& a )
{

  auto [ts,ts_inv,edge] = TopologicalSortedGraph( G );
  const int& size = G.size();
  vector<bool> odd( size );
  ret_t<VALUE,inner_t<GRAPH>> answer{};

  for( int i = size - 2 ; i >= 0 ; i-- ){

    auto& edge_i = edge[i];
    odd[i] = !( edge_i.empty() || odd[edge_i[0]] );

    for( auto& j : edge_i ){

      assert( odd[i] != odd[j] );

    }

    odd[i] ? answer ^= a( ts[i] ) : answer;

  }

  return answer;

}

template <typename GRAPH , typename VALUE , typename INT> inline ret_t<VALUE,inner_t<GRAPH>> AcyclicBoundedNim( GRAPH& G , VALUE&& a , INT bound ) { bound++; auto a_bounded = [&]( const inner_t<GRAPH>& t ){ return a( t ) % bound; }; return AcyclicNim( G , a_bounded ); }


// 無向木をTopologicalSortedTree(G,root)で変換する必要があるケースが多いのでをincludeする。
#include "../../../Geometry/Graph/Acyclic/UndirectedTree/a_Body.hpp"
