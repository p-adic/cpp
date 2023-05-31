// c:/Users/user/Documents/Programming/Utility/Search/BreadthFirst/a_Body.hpp

#pragma once
#include "a.hpp"

template <int V_max,list<int> E(const int&)> inline BreadthFirstSearch<V_max,E>::BreadthFirstSearch( const int& V ) : m_V( V ) , m_init() , m_next() , m_found() {}
template <int V_max,list<int> E(const int&)> inline BreadthFirstSearch<V_max,E>::BreadthFirstSearch( const int& V , const int& init ) : m_V( V ) , m_init( init ) , m_next() , m_found() { m_next.push_back( m_init ); m_found[m_init] = true; }

template <int V_max,list<int> E(const int&)> inline void BreadthFirstSearch<V_max,E>::Reset( const int& init ) { m_init = init; m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = i == m_init; } }
template <int V_max,list<int> E(const int&)> inline void BreadthFirstSearch<V_max,E>::Shift( const int& init ) { m_init = init; m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = true;} }

template <int V_max,list<int> E(const int&)> inline bool& BreadthFirstSearch<V_max,E>::Found( const int& i ) { return m_found[i]; }

template <int V_max,list<int> E(const int&)>
int BreadthFirstSearch<V_max,E>::Next()
{

  if( m_next.empty() ){

    return -1;

  }

  const int i_curr = m_next.front();
  m_next.pop_front();
  list<int> edge = E( i_curr );

  for( auto itr = edge.begin() , end = edge.end() ; itr != end ; itr++ ){

    bool& found_i = m_found[*itr];
    
    if( ! found_i ){

      m_next.push_back( *itr );
      found_i = true;

    }

  }
  
  return i_curr;

}
