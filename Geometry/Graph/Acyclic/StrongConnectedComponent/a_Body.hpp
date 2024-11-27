// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/StrongConnectedComponent/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Algorithm/DepthFirstSearch/a_Body.hpp"

template <typename T , typename GRAPH>
vector<vector<T>> StrongConnectedComponent( GRAPH& G , const T& not_found )
{

  const int& V = G.size();
  DepthFirstSearch dfs{ G , not_found };
  vector<T> rne{};
  rne.reserve( V );

  for( int i = 0 ; i < V ; i++ ){

    dfs.Shift( G.Enumeration( i ) );

    for( auto& t : dfs.GetReversedNodeEnumeration() ){

      rne.push_back( t );

    }

  }
  
  vector<vector<int>> reversed_edge( V );

  for( int i = 0 ; i < V ; i++ ){

    auto&& t = G.Enumeration( i );

    for( auto& u : G.Edge( t ) ){

      reversed_edge[G.Enumeration_inv( u )].push_back( i );

    }
    
  }

  Graph rG{ V , [&]( const int& i ) -> const vector<int>& { return reversed_edge[i]; } };
  DepthFirstSearch dfsr{ rG , -1 };
  vector<vector<T>> answer{};

  for( int n = V - 1 ; n >= 0 ; n-- ){

    int i = G.Enumeration_inv( rne[n] );
    dfsr.Shift( i );
    vector<T> temp{};

    while( ( i = dfsr.Next() ) != -1 ){

      temp.push_back( G.Enumeration( i ) );

    }

    if( !temp.empty() ){

      answer.push_back( move( temp ) );
      
    }

  }

  return answer;

}
