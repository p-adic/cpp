// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/HamiltonWalk/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename GRAPH>
vector<T> StartPointsOfHamiltonWalk( GRAPH& G , const T& not_found )
{

  auto scc = StrongConnectedComponent( G , not_found );
  const int& V = G.size();

  if( scc.empty() ){

    assert( V == 0 );
    return {};

  }
  
  vector<bool> reached( V , true );
  const int size = scc.size();

  for( int i = 0 ; i < size ; i++ ){

    if( i + 1 < size ){
      
      for( auto& t : scc[i+1] ){

	reached[G.Enumeration_inv( t )] = false;

      }

    }

    bool reachable = false;

    for( auto& u : scc[i] ){

      if( reached[G.Enumeration_inv( u )] ){

	reachable = true;
	
	for( auto& t : G.Edge( u ) ){

	  reached[G.Enumeration_inv( t )] = true;

	}

      }

    }

    if( !reachable ){

      scc[0].clear();
      break;

    }

  }

  return move( scc[0] );

}

