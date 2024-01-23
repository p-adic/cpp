// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename GRAPH> inline ZeroOneBreadthFirstSearch<GRAPH>::ZeroOneBreadthFirstSearch( GRAPH& G ) : m_G( G ) , m_initialised( false ) , m_next() , m_found() , m_prev() , m_weight() { static_assert( is_same_v<inner_t<GRAPH>,int> && is_same_v<decldecay_t(declval<GRAPH>().Edge(0)),list<pair<int,bool>>> ); }
template <typename GRAPH> inline ZeroOneBreadthFirstSearch<GRAPH>::ZeroOneBreadthFirstSearch( GRAPH& G , const int& init ) : ZeroOneBreadthFirstSearch( G ) { Initialise( init ); }

template <typename GRAPH> inline void ZeroOneBreadthFirstSearch<GRAPH>::Initialise() { m_initialised = true; m_next.clear(); const int& V = size(); m_found = vector<int>( V ); m_prev = m_weight = vector<int>( V , -1 ); }
template <typename GRAPH> inline void ZeroOneBreadthFirstSearch<GRAPH>::Initialise( const int& init ) { assert( init < size() ); Initialise(); m_next.push_back( init ); m_found[init] = 2; m_weight[init] = 0; }
template <typename GRAPH> inline void ZeroOneBreadthFirstSearch<GRAPH>::Shift( const int& init ) { if( m_initialised ){ const int& V = size(); assert( init < V ); m_next.clear(); if( ! m_found[init] ){ m_next.push_back( init ); m_found[init] = 2; m_weight[init] = 0; } } else { Initialise( init ); } }

template <typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<GRAPH>::size() const { return m_G.size(); }
template <typename GRAPH> inline int& ZeroOneBreadthFirstSearch<GRAPH>::found( const int& i ) { assert( i < size() ); if( !m_initialised ){ Initialise(); } return m_found[i]; }
template <typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<GRAPH>::prev( const int& i ) { assert( i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }
template <typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<GRAPH>::weight( const int& i ) { assert( i < size() ); if( !m_initialised ){ Initialise(); } return m_weight[i]; }

template <typename GRAPH> int ZeroOneBreadthFirstSearch<GRAPH>::Next()
{

  if( m_next.empty() ){

    return -1;

  }

  const int i_curr = m_next.front();
  m_next.pop_front();

  if( m_found[i_curr] == 3 ){

    return Next();

  }

  m_found[i_curr] = 3;
  auto&& edge = m_G.Edge( i_curr );

  while( ! edge.empty() ){

    const auto& [i,weighted] = edge.front();
    int& found_i = m_found[i];

    if( weighted ){

      if( found_i < 1 ){

	m_next.push_back( i );
	m_prev[i] = i_curr;
	m_weight[i] = m_weight[i_curr] + 1;
	found_i = 1;

      }

    } else {
      
      if( found_i < 2 ){

	m_next.push_front( i );
	m_prev[i] = i_curr;
	m_weight[i] = m_weight[i_curr];
	found_i = 2;

      }

    }

    edge.pop_front();

  }

  return i_curr;

}

template <typename GRAPH> inline void ZeroOneBreadthFirstSearch<GRAPH>::SetWeight() { while( Next() != -1 ){} }
template <typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<GRAPH>::GetWeight( const int& init , const int& goal ) { Initialise( init ); assert( goal < this->size() ); int i = Next(); while( i != -1 && i != goal ){ i = Next(); } return m_weight[goal]; }
