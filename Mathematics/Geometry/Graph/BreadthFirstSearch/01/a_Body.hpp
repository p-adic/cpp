// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BreadthFirstSearch/01/a_Body.hpp

#pragma once
#include "a.hpp"

inline ZeroOneBreadthFirstSearch_Body::ZeroOneBreadthFirstSearch_Body( const int& V ) : m_V( V ) , m_init() , m_next() , m_found( m_V ) , m_prev( m_V , -1 ) , m_weight( m_V , -1 ) {}
inline ZeroOneBreadthFirstSearch_Body::ZeroOneBreadthFirstSearch_Body( const int& V , const int& init ) : ZeroOneBreadthFirstSearch_Body( V ) { assert( init < m_V ); m_init = init; m_next.push_back( m_init ); m_found[m_init] = 2; m_weight[m_init] = 0; }
template <list<pair<int,bool> > E(const int&)> template <typename... Args> inline ZeroOneBreadthFirstSearch<E>::ZeroOneBreadthFirstSearch( const Args&... args ) : ZeroOneBreadthFirstSearch_Body( args... ) {}

inline void ZeroOneBreadthFirstSearch_Body::Reset( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); m_next.push_back( m_init ); for( int i = 0 ; i < m_V ; i++ ){ m_found[i] = 0; m_prev[i] = m_weight[i] = -1; } m_found[m_init] = 2; m_weight[m_init] = 0; }
inline void ZeroOneBreadthFirstSearch_Body::Shift( const int& init ) { m_init = init; assert( m_init < m_V ); m_next.clear(); if( ! m_found[m_init] ){ m_next.push_back( m_init ); m_found[m_init] = 2; m_weight[m_init] = 0; } }

inline const int& ZeroOneBreadthFirstSearch_Body::size() const { return m_V; }
inline const int& ZeroOneBreadthFirstSearch_Body::init() const { return m_init; }
inline int& ZeroOneBreadthFirstSearch_Body::found( const int& i ) { assert( i < m_V ); return m_found[i]; }
inline const int& ZeroOneBreadthFirstSearch_Body::prev( const int& i ) const { assert( i < m_V ); return m_prev[i]; }
inline const int& ZeroOneBreadthFirstSearch_Body::weight( const int& i ) const { assert( i < m_V ); return m_weight[i]; }

inline int ZeroOneBreadthFirstSearch_Body::Next()
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

inline void ZeroOneBreadthFirstSearch_Body::SetWeight() { while( Next() != -1 ){} }
inline const int& ZeroOneBreadthFirstSearch_Body::Solve( const int& init , const int& goal ) { Reset( init ); assert( goal < m_V ); int i = Next(); while( i != -1 && i != goal ){ i = Next(); } return m_weight[goal]; }

template <list<pair<int,bool> > E(const int&)> inline list<pair<int,bool> > ZeroOneBreadthFirstSearch<E>::e( const int& t ) { return E( t ); }
