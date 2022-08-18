// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , uint D> inline AffineSpace<T,D>::AffineSpace() : m_v() {};
template <typename T , uint D> template<uint E> inline AffineSpace<T,D>::AffineSpace( const T (&v)[E] ) : m_v { Substitute<E>( v ); }
template <typename T , uint D> template<uint E> inline AffineSpace<T,D>& AffineSpace<T,D>::operator=( const AffineSpace<T,E>& x ) { Set<E>( x.m_v ); return *this; }

template <typename T , uint D> inline T& AffineSpace<T,D>::operator[]( const uint& i ) { return m_v[i]; }
template <typename T , uint D> inline const T& AffineSpace<T,D>::operator[]( const uint& i ) const { return m_v[i]; }

template <typename T , uint D> template <uint E>
void AffineSpace<T,D>::Set( const T (&v)[E] )
{

  Substitute( v );
  constexpr const uint min = E < D ? E : D;

  for( uint i = min ; i < D ; i++ ){

    m_v[i] = 0;
    
  }

  return;
  
}

template <typename T , uint D> template <uint E>
void AffineSpace<T,D>::Substitute( const T (&v)[E] )
{

  constexpr const uint min = E < D ? E : D;

  for( uint i = 0 ; i < min ; i++ ){

    m_v[i] = v[i];
    
  }

  return;
  
}
