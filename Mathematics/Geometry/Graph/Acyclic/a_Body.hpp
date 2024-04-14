// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Acyclic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

// template <typename T , typename PATH , typename ACYCLIC_GRAPH>
// void TopologicalSort_Body( ACYCLIC_GRAPH& G , vector<T>& answer , const PATH& t , const int& i , vector<bool>& found , int& num )
// {

//   if( !found[i] ){

//     found[i] = true;
//     auto&& edge_i = G.Edge( t );

//     for( auto& u : edge_i ){

//       TopologicalSort_Body( G , answer , u , G.Enumeration_inv( u ) , found , num );

//     }

//     answer[num--] = t;

//   }

//   return;

// }

// template <typename ACYCLIC_GRAPH>
// vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G )
// {

//   const int& size = G.size();
//   vector<inner_t<ACYCLIC_GRAPH>> answer( size );
//   vector<bool> found( size );
//   int num = size - 1;

//   for( int i = 0 ; i < size ; i++ ){

//     TopologicalSort_Body( G , answer , G.Enumeration( i ) , i , found , num );

//   }

//   return answer;

// }

template <typename ACYCLIC_GRAPH>
vector<inner_t<ACYCLIC_GRAPH>> TopologicalSort( ACYCLIC_GRAPH& G )
{

  const int& size = G.size();
  vector<inner_t<ACYCLIC_GRAPH>> answer( size );
  vector<bool> edged( size ) , fixed( size );
  int num = size - 1;

  for( int i = 0 ; i < size ; i++ ){

    if( !fixed[i] ){

      vector<vector<int>> dfs = { { i } };

      while( !dfs.empty() ){

	auto& e = dfs.back();

	if( e.empty() ){

	  dfs.pop_back();

	} else {
	  
	  const int& j = e.back();

	  if( fixed[j] ){

	    e.pop_back();

	  } else {
	  
	    auto&& t = G.Enumeration( j );

	    if( edged[j] ){

	      fixed[j] = true;
	      answer[num--] = t;
	      e.pop_back();

	    } else {

	      edged[j] = true;
	      auto&& edge_t = G.Edge( t );
	      vector<int> edge_j{};

	      for( auto& u : edge_t ){

		auto&& k = G.Enumeration_inv( u );

		if( !fixed[k] ){
		
		  edge_j.push_back( k );

		}

	      }

	      dfs.push_back( move( edge_j ) );

	    }

	  }

	}

      }

    }

  }

  return answer;

}

template <typename ACYCLIC_GRAPH>
tuple<vector<inner_t<ACYCLIC_GRAPH>>,vector<int>,vector<vector<int>>> TopologicalSortedGraph( ACYCLIC_GRAPH& G )
{

  vector<inner_t<ACYCLIC_GRAPH>> ts = TopologicalSort( G );
  const int& size = G.size();
  vector<int> ts_inv( size );
  vector<vector<int>> edge( size );

  for( int i = size - 1 ; i >= 0 ; i-- ){

    auto& t = ts[i];
    auto&& edge_t = G.Edge( t );
    auto& edge_i = edge[i];
    edge_i.reserve( edge_t.size() );

    for( auto& u : edge_t ){

      const int& j = ts_inv[G.Enumeration_inv( u )];
      edge_i.push_back( j );

    }

    ts_inv[G.Enumeration_inv( t )] = i;

  }

  return { move( ts ) , move( ts_inv ) , move( edge ) };

}
