// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a_Body.hpp

#pragma once
#include "a.hpp"

template <int V_max> inline ZeroOneBreadthFirstSearch_Body<V_max>::ZeroOneBreadthFirstSearch_Body( const int& V ) : m_V( V ) , m_init() , m_next() , m_found() , m_prev() , m_weight() { assert( m_V <= V_max ); for( int i = 0 ; i < m_V ; i++ ){ m_prev[i] = m_weight[i] -1; } }
template <int V_max> inline ZeroOneBreadthFirstSearch_Body<V_max>::ZeroOneBreadthFirstSearch_Body( const int& V , const int& init ) : ZeroOneBreadthFirstSearch_Body( V ) { m_init = init; m_next.push_back( m_init ); m_found[m_init] = 2; m_weight[m_init] = 0; }
template <int V_max,list<pair<int,bool> > E(const int&)> template <typename... Args> inline ZeroOneBreadthFirstSearch<V_max,E>::ZeroOneBreadthFirstSearch( const Args&... args ) : ZeroOneBreadthFirstSearch_Body<V_max>( args... ) {}

template <int V_max> inline void ZeroOneBreadthFirstSearch_Body<V_max>::Reset( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = 0; m_prev[i] = m_weight[i] = -1; } m_found[m_init] = 2; m_weight[m_init] = 0; }
template <int V_max> inline void ZeroOneBreadthFirstSearch_Body<V_max>::Shift( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = 2; m_weight[m_init] = 0; } }

template <int V_max> inline const int& ZeroOneBreadthFirstSearch_Body<V_max>::size() const { return m_V; }
template <int V_max> inline const int& ZeroOneBreadthFirstSearch_Body<V_max>::init() const { return m_init; }
template <int V_max> inline int& ZeroOneBreadthFirstSearch_Body<V_max>::found( const int& i ) { assert( i < m_V ); return m_found[i]; }
template <int V_max> inline const int& ZeroOneBreadthFirstSearch_Body<V_max>::prev( const int& i ) const { assert( i < m_V ); return m_prev[i]; }
template <int V_max> inline const int& ZeroOneBreadthFirstSearch_Body<V_max>::weight( const int& i ) const { assert( i < m_V ); return m_weight[i]; }

template <int V_max>
int ZeroOneBreadthFirstSearch_Body<V_max>::Next()
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
  auto edge = e( i_curr );

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

template <int V_max> inline void ZeroOneBreadthFirstSearch_Body<V_max>::SetWeight() { while( Next() != -1 ){} }
template <int V_max> inline const int& ZeroOneBreadthFirstSearch_Body<V_max>::Solve( const int& init , const int& goal ) { Reset( init ); assert( goal < m_V ); int i = Next(); while( i != -1 && i != goal ){ i = Next(); } return m_weight[goal]; }

template <int V_max,list<pair<int,bool> > E(const int&)> inline list<pair<int,bool> > ZeroOneBreadthFirstSearch<V_max,E>::e( const int& t ) { return E( t ); }
