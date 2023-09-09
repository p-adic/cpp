// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Arithmetic/Power/Constexpr/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE> inline const T& SegmentTree<T,m_T,e_T,N>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE> inline SegmentTree<T,m_T,e_T,N>::SegmentTree() : m_a() { if( m_a[0] != g_e ){ for( int j = 1 ; j < g_power2 ; j++ ){ m_a[j] = g_e; } } }

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE> inline SegmentTree<T,m_T,e_T,N>::SegmentTree( const T ( &a )[N] ) : m_a()
{

  int j_ulim = g_power + N;
  
  if( m_a[0] != g_e ){
    
    for( int j = g_power2 - 1 ; j >= j_ulim ; j-- ){

      m_a[j] = g_e;

    }

  }

  for( int i = 0 ; i < N ; i++ ){

    m_a[i | g_power] = a[i];

  }

  for( int j = g_power - 1 ; j >= 1 ; j-- ){

    int j2 = j << 1;
    m_a[j] = m_T( m_a[j2] , m_a[j2+1] );

  }

}

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE> inline const T& SegmentTree<T,m_T,e_T,N>::operator[]( const int& i ) const { return m_a[g_power + i]; }
template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE> inline const T& SegmentTree<T,m_T,e_T,N>::Get( const int& i ) const { return m_a[g_power + i]; }

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE>
T SegmentTree<T,m_T,e_T,N>::IntervalProduct( const int& i_start , const int& i_final ) 
{

  int j_min = i_start < 0 ? g_power : g_power + i_start;
  int j_ulim = i_final < N ? g_power + i_final + 1 : g_power + N;
  T answer0 = g_e;
  T answer1 = g_e;

  while( j_min < j_ulim ){

    ( j_min & 1 ) == 1 ? answer0 = m_T( answer0 , m_a[j_min++] ) : answer0;
    ( j_ulim & 1 ) == 1 ? answer1 = m_T( m_a[--j_ulim] , answer1 ) : answer1;
    j_min >>= 1;
    j_ulim >>= 1;

  }

  return m_T( answer0 , answer1 );

}

template <TEMPLATE_ARGUMENTS_FOR_SEGMENT_TREE>
void SegmentTree<T,m_T,e_T,N>::Set( const int& i , const T& n )
{

  int j = g_power + i;
  m_a[j] = n;
  
  while( ( j <<= 1 ) >= 1 ){
    
    int j2 = j << 1;
    m_a[j] = m_T( m_a[j2] , m_a[j2+1] );

  }

  return;

}
