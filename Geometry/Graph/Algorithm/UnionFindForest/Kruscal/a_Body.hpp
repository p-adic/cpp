// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/Kruscal/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"

#include "../a_Body.hpp"

template <typename GRAPH>
list<tuple<int,int,int>> SortedEdge( GRAPH& G , const vector<pair<int,int>>& E )
{

  using PATH = decldecay_t( declval<GRAPH>().edge()(0).back() );
  using T = inner_t<GRAPH>;
  using U = decldecay_t( get<1>( declval<PATH>() ) );
  static_assert( is_same_v<T,decldecay_t( get<0>( declval<PATH>() ) )> && is_same_v<int,decldecay_t( get<2>( declval<PATH>() ) )> );
  const int& V = G.size();
  list<pair<U,int>> weight{};

  for( int i = 0 ; i < V ; i++ ){

    auto&& t = G.Enumeration( i );
    auto&& edge_i = G.Edge( t );

    for( auto& edge_ij : edge_i ){

      weight.push_back( { get<1>( edge_ij ) , get<2>( edge_ij ) } );

    }

  }

  weight.sort();
  list<tuple<int,int,int>> E_sorted{};

  for( auto& weight_n : weight ){

    int& n = weight_n.second;
    auto& [i,j] = E[n];
    E_sorted.push_back( { i , j , n } );

  }

  return E_sorted;

}

template <typename On>
pair<vector<int>,int> Kruscal( const int& V , const vector<pair<int,int>>& E , const list<tuple<int,int,int>>& E_sorted , const On& on , vector<int> answer )
{
  
  static_assert( is_invocable_r_v<bool,On,int> );
  UnionFindForest<> uff{ V };

  for( auto& n : answer ){

    auto& [i,j] = E[n];
    
    if( ! on( n ) || uff.RootOfNode( i ) == uff.RootOfNode( j ) ){

      return { {} , -1 };

    } else {
      
      uff.Graft( i , j );

    }
    
  }
  
  answer.reserve( V - 1 );

  for( auto& [i,j,n] : E_sorted ){

    if( on( n ) ){

      if( uff.RootOfNode( i ) != uff.RootOfNode( j ) ){

	uff.Graft( i , j );
	answer.push_back( n );

      }

    }

  }

  return { move( answer ) , uff.size( false ) };  

}

template <typename GRAPH> inline pair<vector<int>,int> Kruscal( GRAPH& G , const vector<pair<int,int>>& E , vector<int> answer ) { return Kruscal( G.size() , E , SortedEdge( G , E ) , [&]( const int& ) { return true; } , answer ); }

