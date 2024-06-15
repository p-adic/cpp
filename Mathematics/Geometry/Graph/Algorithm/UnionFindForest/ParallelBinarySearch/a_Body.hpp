// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/UnionFindForest/ParallelBinarySearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename INT , typename GRAPH>
vector<INT> AbstractParallelBinaryUnionFind( GRAPH& G , const INT& v_min , const INT& v_max , const map<INT,vector<pair<T,T>>>& additional_edge , const vector<pair<T,T>>& query )
{

  static_assert( is_same_v<T,inner_t<GRAPH>> );
  assert( v_min <= v_max );
  auto begin = additional_edge.begin() , end = additional_edge.end();
  const int Q = query.size();
  const INT v_size = v_max - v_min + 1;
  vector l( Q , v_min ) , r( Q , v_max );
  
  if( ( Q >> ( v_size / ( Q + 1 ) ) ) > 0 ){

    while( l != r ){

      INITIALISE_FOR_PBUF;
      vector m( v_size , vector<int>() );

      for( int q = 0 ; q < Q ; q++ ){

	m[( ( l[q] - 1 + r[q] ) >> 1 ) - v_min].push_back( q );

      }

      for( int v = v_min ; v <= v_max ; v++ ){

	GRAFT_FOR_PBUF( v );
	
	for( auto& q : m[v - v_min] ){

	  UPDATE_FOR_PBUF( v );

	}

      }

    }

  } else {

    while( l != r ){

      INITIALISE_FOR_PBUF;
      set<pair<INT,int>> m{};

      for( int q = 0 ; q < Q ; q++ ){

	m.insert( { ( l[q] - 1 + r[q] ) >> 1 , q } );

      }

      for( auto& [m_q,q] : m ){

	GRAFT_FOR_PBUF( m_q );
	UPDATE_FOR_PBUF( m_q );

      }

    }

  }

  return r;

}

template <typename T , typename INT , typename GRAPH> inline vector<INT> ParallelBinaryUnionFind( const int& size , const INT& v_min , const INT& v_max , const map<INT,vector<pair<int,int>>>& additional_edge , const vector<pair<int,int>>& query ) { return AbstractParallelBinaryUnionFind( LinearGraph( size , 0 ) , v_min , v_max , additional_edge , query ); }
