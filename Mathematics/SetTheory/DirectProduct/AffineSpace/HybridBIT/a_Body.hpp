// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/HybridBIT/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int N> inline HybridBIT<T,N>::HybridBIT() : m_a() , m_fenwick() {}
template <typename T , int N> inline HybridBIT<T,N>::HybridBIT( const T ( & a )[N] ) : m_a() , m_fenwick() { operator+=( a ); }

template <typename T , int N> inline const T& HybridBIT<T,N>::operator[]( const int& i ) const { return m_a[i]; }

template <typename T , int N> inline HybridBIT<T,N>& HybridBIT<T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <typename T , int N>
void HybridBIT<T,N>::Add( const int& i , const T& n )
{
  
  m_a[i] += n;
  int j = i + 1;

  while( j <= N ){

    m_fenwick[j] += n;
    j += ( j & -j );

  }

  return;
  
}

template <typename T , int N> 
T HybridBIT<T,N>::InitialSegmentSum( const int& i_final )
{

  T sum = 0;
  int j = i_final + 1;

  while( j > 0 ){

    sum += m_fenwick[j];
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename T , int N> inline T HybridBIT<T,N>::IntervalSum( const int& i_start , const int& i_final ) { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }

