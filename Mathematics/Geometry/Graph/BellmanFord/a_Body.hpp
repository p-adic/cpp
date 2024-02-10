// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../Algebra/Monoid/a_Body.hpp"

template <typename GRAPH , typename MONOID , typename U> inline AbstractBellmanFord<GRAPH,MONOID,U>::AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty ) : PointedSet<U>( infty ) , m_G( G ) , m_M( move( M ) ) { static_assert( ! is_same_v<U,int> ); }

template <typename GRAPH> inline BellmanFord<GRAPH>::BellmanFord( GRAPH& G ) : AbstractBellmanFord<GRAPH,AdditiveMonoid<>,ll>( G , AdditiveMonoid<>() , 4611686018427387904 ) {}

template <typename GRAPH , typename MONOID , typename U>
tuple<bool,vector<U>> AbstractBellmanFord<GRAPH,MONOID,U>::GetDistance( const inner_t<GRAPH>& t_start , const bool& dummy )
{

  BELLMAN_FORD_BODY( , );
  m_G.Reset();
  return { valid , move( weight ) };

}

template <typename GRAPH , typename MONOID , typename U> template <template <typename...> typename V>
tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> AbstractBellmanFord<GRAPH,MONOID,U>::GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& dummy )
{

  BELLMAN_FORD_BODY( vector<int> prev( size ) , prev[j] = i );
  vector<list<inner_t<GRAPH>>> path{};

  if( valid ){
    
    const int path_size = t_finals.size();
    path.reserve( path_size );
    
    for( auto itr = t_finals.begin() , end = t_finals.end() ; itr != end ; itr++ ){

      list<inner_t<GRAPH>> path_j{};
      const inner_t<GRAPH>& t_final = *itr;
      path_j.push_back( t_final );
      int i = m_G.Enumeration_inv( t_final );

      if( found[i] ){

	while( i != i_start ){

	  i = prev[i];
	  path_j.push_front( m_G.Enumeration( i ) );

	}

      }

      path.push_back( path_j );

    }

  }

  m_G.Reset();
  return { valid , move( weight ) , move( path ) };


}

template <typename GRAPH , typename MONOID , typename U>
tuple<bool,vector<U>,vector<list<inner_t<GRAPH>>>> AbstractBellmanFord<GRAPH,MONOID,U>::GetPath( const inner_t<GRAPH>& t_start , const bool& dummy )
{

  const int& size = m_G.size();
  vector<inner_t<GRAPH>> t_finals( size );

  for( int i = 0 ; i < size ; i++ ){

    t_finals[i] = i;

  }

  return GetPath( t_start , t_finals );

}
