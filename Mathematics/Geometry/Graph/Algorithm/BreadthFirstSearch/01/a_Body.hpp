// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/01/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../a_Body.hpp"

template <typename T , typename GRAPH> inline ZeroOneBreadthFirstSearch<T,GRAPH>::ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found ) : m_G( G ) , m_not_found( not_found ) , m_initialised( false ) , m_next() , m_found() , m_prev() , m_weight() {}
template <typename T , typename GRAPH> template <typename Arg> inline ZeroOneBreadthFirstSearch<T,GRAPH>::ZeroOneBreadthFirstSearch( GRAPH& G , const T& not_found , Arg&& init ) : ZeroOneBreadthFirstSearch( G , not_found ) { Initialise( forward<Arg>( init ) ); }

template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::Initialise() { m_initialised = true; m_next.clear(); const int& V = size(); m_found = vector<int>( V ); m_prev = vector<T>( V , m_not_found ); m_weight = vector<int>( V , -1 ); }
template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::Initialise( const T& init ) { auto&& i = m_G.Enumeration_inv( init ); assert( 0 <= i && i < size() ); Initialise(); m_next.push_back( init ); m_found[i] = 2; m_weight[i] = 0; }
template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::Initialise( list<T> inits ) { Initialise(); m_next = move( inits ); const int& V = size(); for( auto u : m_next ){ auto&& i = m_G.Enumeration_inv( u ); assert( 0 <= i && i < V ); m_found[i] = 2; m_weight[i] = 0; } }
template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::Shift( const T& init ) { if( m_initialised ){ const int& V = size(); auto&& i = m_G.Enumeration_inv( init ); assert( 0 <= i && i < size() ); m_next.clear(); if( ! m_found[i] ){ m_next.push_back( init ); m_found[i] = 2; m_weight[i] = 0; } } else { Initialise( init ); } }
template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::Shift( list<T> inits ) { if( m_initialised ){ m_next.clear(); const int& V = size(); for( auto u : m_next ){ auto&& i = m_G.Enumeration_inv( u ); assert( 0 <= i && i < V ); if( ! m_found[i] ){ m_next.push_back( u ); m_found[i] = 2; m_weight[i] = 0; } } } else { Initialise( move( inits ) ); } }

template <typename T , typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<T,GRAPH>::size() const { return m_G.size(); }
template <typename T , typename GRAPH> inline int& ZeroOneBreadthFirstSearch<T,GRAPH>::found( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_found[i]; }
template <typename T , typename GRAPH> inline const T& ZeroOneBreadthFirstSearch<T,GRAPH>::prev( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_prev[i]; }
template <typename T , typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<T,GRAPH>::weight( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); if( !m_initialised ){ Initialise(); } return m_weight[i]; }

template <typename T , typename GRAPH> T ZeroOneBreadthFirstSearch<T,GRAPH>::Next()
{

  if( m_next.empty() ){

    return m_not_found;

  }

  const T t_curr = m_next.front();
  auto&& i_curr = m_G.Enumeration_inv( t_curr );
  m_next.pop_front();

  if( m_found[i_curr] == 3 ){

    return Next();

  }

  m_found[i_curr] = 3;
  auto&& edge = m_G.Edge( t_curr );

  for( auto& [t,weighted] : edge ){
    
    auto&& i = m_G.Enumeration_inv( t );
    int& found_i = m_found[i];

    if( weighted ){

      if( found_i < 1 ){

	m_next.push_back( t );
	m_prev[i] = t_curr;
	m_weight[i] = m_weight[i_curr] + 1;
	found_i = 1;

      }

    } else {
      
      if( found_i < 2 ){

	m_next.push_front( t );
	m_prev[i] = t_curr;
	m_weight[i] = m_weight[i_curr];
	found_i = 2;

      }

    }

  }

  return t_curr;

}

template <typename T , typename GRAPH> inline void ZeroOneBreadthFirstSearch<T,GRAPH>::SetWeight() { while( Next() != m_not_found ){} }
template <typename T , typename GRAPH> inline const int& ZeroOneBreadthFirstSearch<T,GRAPH>::GetWeight( const T& t_goal ) { auto&& i = m_G.Enumeration_inv( t_goal ); assert( 0 <= i && i < size() ); T t_next = Next(); while( t_next != m_not_found && t_next != t_goal ){ t_next = Next(); } return m_weight[i]; }
