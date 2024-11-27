// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BellmanFord/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename T , typename GRAPH , typename U , typename MONOID>
AbstractBellmanFord<T,GRAPH,U,MONOID>::AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) , m_edge()
{

  static_assert( is_same_v<T,inner_t<GRAPH>> && is_same_v<U,inner_t<MONOID>> && !is_same_v<U,int> );
  const int& size = m_G.size();

  for( int i = 0 ; i < size ; i++ ){

    auto&& edge_i = m_G.Edge( m_G.Enumeration( i ) );

    for( auto& edge_ij : edge_i ){

      m_edge.push_back( { i , m_G.Enumeration_inv( get<0>( edge_ij ) ) , get<1>( edge_ij ) } );

    }

  }

}

template <typename T , typename GRAPH> inline BellmanFord<T,GRAPH>::BellmanFord( GRAPH& G ) : AbstractBellmanFord<T,GRAPH,ll,AdditiveMonoid<>>( G , AdditiveMonoid<>() , 1e18 ) {}

template <typename T , typename GRAPH , typename U , typename MONOID>
tuple<vector<bool>,vector<U>> AbstractBellmanFord<T,GRAPH,U,MONOID>::GetDistance( const T& t_start , const bool& many_edges , int path_length )
{

  BELLMAN_FORD_BODY( , );
  return { move( valid ) , move( weight ) };

}

template <typename T , typename GRAPH , typename U , typename MONOID> template <template <typename...> typename V>
tuple<vector<bool>,vector<U>,vector<list<T>>> AbstractBellmanFord<T,GRAPH,U,MONOID>::GetPath( const T& t_start , const V<T>& t_finals , const bool& many_edges , int path_length )
{

  BELLMAN_FORD_BODY( vector<int> prev( size ) , prev[j] = i );
  vector<list<T>> path{};
  const int path_size = t_finals.size();
  path.reserve( path_size );
    
  for( auto& t_final : t_finals ){

    list<T> path_j{};
    path_j.push_back( t_final );
    int i = m_G.Enumeration_inv( t_final );

    if( found[i] && valid[i] ){

      while( i != i_start ){

	i = prev[i];
	path_j.push_front( m_G.Enumeration( i ) );

      }

    }

    path.push_back( path_j );

  }

  return { move( valid ) , move( weight ) , move( path ) };

}

template <typename T , typename GRAPH , typename U , typename MONOID>
tuple<vector<bool>,vector<U>,vector<list<T>>> AbstractBellmanFord<T,GRAPH,U,MONOID>::GetPath( const T& t_start , const bool& many_edges , int path_length )
{

  const int& size = m_G.size();
  vector<T> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals );

}
