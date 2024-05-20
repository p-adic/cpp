// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/BreadthFirstSearch/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename T , typename GRAPH> inline QuotientSetSearch<T,GRAPH>::QuotientSetSearch( GRAPH& G , const T& not_found ) : m_G( G ) , m_not_found( not_found ) , m_next() , m_found() , m_repr() { Initialise(); }
template <typename T , typename GRAPH> template <typename Arg> inline QuotientSetSearch<T,GRAPH>::QuotientSetSearch( GRAPH& G , const T& not_found , Arg&& init ) : QuotientSetSearch<T,GRAPH>( G , not_found ) { Initialise( forward<Arg>( init ) ); }

// MemorisationGraphだとこのEnumerationで実行時エラーとなる。
template <typename T , typename GRAPH> inline void QuotientSetSearch<T,GRAPH>::Initialise() { static_assert( is_same_v<inner_t<GRAPH>,T> && !is_same_v<GRAPH,MemorisationGraph<T,decldecay_t( m_G.edge() )>> ); const int& V = size(); m_next.clear(); m_found = vector<bool>( V ); m_repr = vector<T>( V ); for( int i = 0 ; i < V ; i++ ){ m_repr[i] = m_G.Enumeration( i ); } }
template <typename T , typename GRAPH> inline void QuotientSetSearch<T,GRAPH>::Initialise( const T& init ) { auto&& i = m_G.Enumeration_inv( init ); assert( 0 <= i && i < size() ); Initialise(); m_next.push_back( init ); }
template <typename T , typename GRAPH> inline void QuotientSetSearch<T,GRAPH>::Initialise( vector<T> inits ) { Initialise(); m_next = move( inits ); const int& V = size(); for( auto& u : m_next ){ auto&& i = m_G.Enumeration_inv( u ); assert( 0 <= i && i < V ); } }
template <typename T , typename GRAPH> inline void QuotientSetSearch<T,GRAPH>::Shift( const T& init ) { m_next = { init }; }
template <typename T , typename GRAPH> inline void QuotientSetSearch<T,GRAPH>::Shift( vector<T> inits ) { m_next = move( inits ); }

template <typename T , typename GRAPH> inline const int& QuotientSetSearch<T,GRAPH>::size() const noexcept { return m_G.size(); }
template <typename T , typename GRAPH> inline vector<bool>::reference QuotientSetSearch<T,GRAPH>::found( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); return m_found[i]; }
template <typename T , typename GRAPH> inline const T& QuotientSetSearch<T,GRAPH>::repr( const T& t ) { auto&& i = m_G.Enumeration_inv( t ); assert( 0 <= i && i < size() ); return m_repr[i]; }

template <typename T , typename GRAPH> inline T QuotientSetSearch<T,GRAPH>::Next()
{

  if( m_next.empty() ){

    return m_not_found;

  }

  const T t_curr = m_next.back();
  m_next.pop_back();
  auto&& i_curr = m_G.Enumeration_inv( t_curr );
  auto&& found_i_curr = m_found[i_curr];

  if( found_i_curr ){

    return Next();

  }

  found_i_curr = true;

  for( auto& t : m_G.Edge( t_curr ) ){

    auto&& i = m_G.Enumeration_inv( t );
    auto&& found_i = m_found[i];
    T& repr_i = m_repr[i];

    if( found_i ){

      assert( repr_i == t_curr );

    } else {
	
      assert( repr_i == t );
      found_i = true;
      repr_i = t_curr;

    }

  }

  return t_curr;

}

template <typename T , typename GRAPH>
pair<const vector<T>&,int> QuotientSetSearch<T,GRAPH>::Get()
{

  const int& V = size();
  int count = 0;
  m_next.clear();

  for( int i = 0 ; i < V ; i++ ){

    if( !m_found[i] ){

      count++;
      m_next.push_back( m_G.Enumeration( i ) );
      Next();

    }

  }

  return { m_repr , move( count ) };

}
