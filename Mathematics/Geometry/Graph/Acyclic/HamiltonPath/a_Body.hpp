// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/HamiltonPath/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename ACYCLIC_GRAPH>
vector<inner_t<ACYCLIC_GRAPH>> HamiltonPath( ACYCLIC_GRAPH& G )
{

  auto answer = TopologicalSort( G );
  const int V = G.size();

  for( int n = 1 ; n < V ; n++ ){

    auto& t = answer[n];
    bool found = false;

    for( auto& u : G.Edge( answer[n-1] ) ){

      found |= u == t;

    }

    if( !found ){

      answer.clear();
      break;

    }

  }

  return answer;

}
