// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename GRAPH> inline VirtualBreadthFirstSearch<GRAPH>::VirtualBreadthFirstSearch( GRAPH& G ) : m_G( G ) , m_initialised( false ) , m_next() , m_found() , m_prev() { static_assert( is_same_v<inner_t<GRAPH>,int> && is_same_v<decldec_t(declval<GRAPH>().Edge(0)),int>); }
template <typename GRAPH> inline VirtualBreadthFirstSearch<GRAPH>::VirtualBreadthFirstSearch( GRAPH& G , const int& init ) : VirtualBreadthFirstSearch<GRAPH>( G ) { Initialise( init ); }
template <typename GRAPH> template <typename...Args> inline BreadthFirstSearch<GRAPH>::BreadthFirstSearch( GRAPH& G , const Args&... args ) : VirtualBreadthFirstSearch<GRAPH>( G , args... ) {}

template <typename GRAPH> inline void VirtualBreadthFirstSearch<GRAPH>::Initialise() { m_initialised = true; const int& V = size(); m_next.clear(); m_found = vector<bool>( V ); m_prev = vector<int>( V , -1 ); }
template <typename GRAPH> inline void VirtualBreadthFirstSearch<GRAPH>::Initialise( const int& init ) { assert( ( this->init() = init ) < size() ); Initialise(); m_next.push_back( init ); m_found[init] = true; }
template <typename GRAPH> inline void VirtualBreadthFirstSearch<GRAPH>::Shift( const int& init ) { if( m_initialised ){ const int& V = size(); assert( ( this->init() = init ) < V ); m_next.clear(); if( ! m_found[init] ){ m_next.push_back( init ); m_found[init] = true; } } else { Initialise( init ); } }

template <typename GRAPH> inline const int& VirtualBreadthFirstSearch<GRAPH>::size() const noexcept { return m_G.size(); }
template <typename GRAPH> inline vector<bool>::reference VirtualBreadthFirstSearch<GRAPH>::found( const int& i ) { assert( i < size() ); if( !m_initialised ){ Initialise(); } return m_found[i]; }
template <typename GRAPH> inline const int& VirtualBreadthFirstSearch<GRAPH>::prev( const int& i ) { assert( i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }

template <typename GRAPH> inline int VirtualBreadthFirstSearch<GRAPH>::Next()
{

  if( m_next.empty() ){

    return -1;

  }

  const int i_curr = m_next.front();
  m_next.pop_front();
  auto&& edge = m_G.Edge( i_curr );

  while( ! edge.empty() ){

    const int& i = edge.front();
    auto&& found_i = m_found[i];

    if( ! found_i ){

      Push( m_next , i );
      m_prev[i] = i_curr;
      found_i = true;

    }

    edge.pop_front();

  }

  return i_curr;

}

template <typename GRAPH>
vector<int> VirtualBreadthFirstSearch<GRAPH>::GetDistance()
{

  vector<int> depth{};
  depth = vector<int>( size() , -1 );
  int i = Next();
  depth[i] = 0;
  
  while( ( i = Next() ) != -1 ){

    depth[i] = depth[prev( i )] + 1;

  }

  return depth;
  
}

template <typename GRAPH>
void VirtualBreadthFirstSearch<GRAPH>::SetConnectedComponent( vector<int>& cc_num , int& count )
{

  const int& V = size();
  cc_num = vector<int>( V , -1 );
  count = 0;

  for( int i = 0 ; i < V ; i++ ){

    if( cc_num[i] == -1 ){

      Shift( i );
      int j = Next();

      if( j != -1 ){

	while( j != -1 ){

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

template <typename GRAPH> inline void BreadthFirstSearch<GRAPH>::Push( list<int>& next , const int& i ) { next.push_back( i ); }
