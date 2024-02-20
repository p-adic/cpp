// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename GRAPH> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found ) : m_G( G ) , m_not_found( not_found ) , m_initialised( false ) , m_next() , m_found() , m_prev() {}
template <typename T , typename GRAPH> template <typename Arg> inline VirtualBreadthFirstSearch<T,GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found ) { Initialise( forward<Arg>( init ) ); }
template <typename T , typename GRAPH> template <typename...Args> inline BreadthFirstSearch<T,GRAPH>::BreadthFirstSearch( GRAPH& G , const T& not_found , Args&&... args ) : VirtualBreadthFirstSearch<T,GRAPH>( G , not_found , forward<Args>( args )... ) {}

template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise() { m_initialised = true; const int& V = size(); m_next.clear(); m_found = vector<bool>( V ); m_prev = vector<T>( V , m_not_found ); }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( const T& init ) { auto&& i = m_G.Enumeration_inv( init ); assert( 0 <= i && i < size() ); Initialise(); m_next.push_back( init ); m_found[i] = true; }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Initialise( list<T> inits ) { Initialise(); m_next = move( inits ); const int& V = size(); for( auto itr = m_next.begin() , end = m_next.end() ; itr != end ; itr++ ){ auto&& i = m_G.Enumeration_inv( *itr ); assert( 0 <= i && i < V ); m_found[i] = true; } }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( const T& init ) { if( m_initialised ){ const int& V = size(); auto&& i = m_G.Enumeration_inv( init ); assert( 0 <= i && i < V ); m_next.clear(); if( ! m_found[i] ){ m_next.push_back( init ); m_found[i] = true; } } else { Initialise( init ); } }
template <typename T , typename GRAPH> inline void VirtualBreadthFirstSearch<T,GRAPH>::Shift( list<T> inits ) { if( m_initialised ){ m_next.clear(); const int& V = size(); for( auto itr = m_next.begin() , end = m_next.end() ; itr != end ; itr++ ){ auto&& i = m_G.Enumeration_inv( *itr ); assert( 0 <= i && i < V ); if( ! m_found[i] ){ m_next.push_back( *itr ); m_found[i] = true; } } } else { Initialise( move( inits ) ); } }

template <typename T , typename GRAPH> inline const int& VirtualBreadthFirstSearch<T,GRAPH>::size() const noexcept { return m_G.size(); }
template <typename T , typename GRAPH> inline vector<bool>::reference VirtualBreadthFirstSearch<T,GRAPH>::found( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_found[i]; }
template <typename T , typename GRAPH> inline const T& VirtualBreadthFirstSearch<T,GRAPH>::prev( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }

template <typename T , typename GRAPH> inline T VirtualBreadthFirstSearch<T,GRAPH>::Next()
{

  if( m_next.empty() ){

    return m_not_found;

  }

  const T t_curr = m_next.front();
  m_next.pop_front();
  auto&& edge = m_G.Edge( t_curr );

  while( ! edge.empty() ){

    const T& t = edge.front();
    auto&& i = m_G.Enumeration_inv( t );
    auto&& found_i = m_found[i];

    if( ! found_i ){

      Push( m_next , t );
      m_prev[i] = t_curr;
      found_i = true;

    }

    edge.pop_front();

  }

  return t_curr;

}

template <typename T , typename GRAPH>
vector<int> VirtualBreadthFirstSearch<T,GRAPH>::GetDistance()
{

  static_assert( is_same_v<T,int> && is_same_v<GRAPH,Graph<decldecay_t( m_G.edge() )>> );
  vector<int> depth{};
  depth = vector<int>( size() , -1 );

  for( auto itr = m_next.begin() , end = m_next.end() ; itr != end ; itr++ ){

    depth[*itr] = 0;

  }
  
  int i;
  
  while( ( i = Next() ) != m_not_found ){

    int& depth_i = depth[i];
    depth_i == -1 ? depth_i = depth[prev( i )] + 1 : depth_i;

  }

  return depth;
  
}

template <typename T , typename GRAPH>
void VirtualBreadthFirstSearch<T,GRAPH>::SetConnectedComponent( vector<int>& cc_num , int& count )
{

  static_assert( is_same_v<T,int> && is_same_v<GRAPH,Graph<decldecay_t( m_G.edge() )>> );
  const int& V = size();
  cc_num = vector<int>( V , -1 );
  count = 0;

  for( int i = 0 ; i < V ; i++ ){

    if( cc_num[i] == -1 ){

      Shift( i );
      int j = Next();

      if( j != m_not_found ){

	while( j != m_not_found ){

	  // –³ŒüƒOƒ‰ƒt‚Å‚ ‚éê‡‚Íí‚ÉtrueB
	  assert( cc_num[j] == -1 );
	  cc_num[j] = count;
	  j = Next();

	}

	count++;

      }

    }

  }

  return;

}

template <typename T , typename GRAPH> inline void BreadthFirstSearch<T,GRAPH>::Push( list<T>& next , const T& t ) { next.push_back( t ); }
