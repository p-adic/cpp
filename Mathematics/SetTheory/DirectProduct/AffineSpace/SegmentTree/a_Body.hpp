// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Algebra/Monoid/a_Body.hpp"

template <typename U , typename MONOID> inline AbstractSegmentTree<U,MONOID>::AbstractSegmentTree( MONOID M , const int& size ) : AbstractSegmentTree( M , vector<U>( size , M.One() ) ) {}

template <typename U , typename MONOID> inline AbstractSegmentTree<U,MONOID>::AbstractSegmentTree( MONOID M , const vector<U>& a ) : m_M( move( M ) ) , m_size( a.size() ) , m_power( 1 ) , m_a()
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  while( m_size > m_power ){

    m_power <<= 1;

  }

  m_a.resize( m_power << 1 , m_M.One() );
  
  for( int i = 0 ; i < m_size ; i++ ){

    m_a[m_power | i] = a[i];

  }

  for( int j = m_power - 1 ; j >= 1 ; j-- ){

    int j2 = j << 1;
    m_a[j] = m_M.Product( m_a[j2] , m_a[j2+1] );

  }

}

template <typename U> template <typename...Args> inline SegmentTree<U>::SegmentTree( const U& one_U , const Args&... args ) : AbstractSegmentTree<U,MultiplicativeMonoid<U>>( MultiplicativeMonoid<U>( one_U ) , args... ) {}

template <typename U , typename MONOID> template <typename...Args> inline void AbstractSegmentTree<U,MONOID>::Initialise( const Args&... args ) { *this = AbstractSegmentTree( move( m_M ) , args... ); }

template <typename U , typename MONOID>
void AbstractSegmentTree<U,MONOID>::Set( const int& i , const U& u )
{

  assert( 0 <= i && i < m_size );
  int j = m_power | i;
  m_a[j] = u;
  
  while( ( j >>= 1 ) >= 1 ){
    
    int j2 = j << 1;
    m_a[j] = m_M.Product( m_a[j2] , m_a[j2+1] );

  }

  return;

}

template <typename U , typename MONOID> inline const U& AbstractSegmentTree<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[m_power + i]; }
template <typename U , typename MONOID> inline const U& AbstractSegmentTree<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename MONOID>
U AbstractSegmentTree<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final ) 
{

  int j_min = m_power | max( 0 , i_start );
  int j_ulim = ( m_power | min( i_final , m_size - 1 ) ) + 1;
  U answer0 = m_M.One();
  U answer1 = answer0;

  while( j_min < j_ulim ){

    ( j_min & 1 ) == 1 ? answer0 = m_M.Product( answer0 , m_a[j_min++] ) : answer0;
    ( j_ulim & 1 ) == 1 ? answer1 = m_M.Product( m_a[--j_ulim] , answer1 ) : answer1;
    j_min >>= 1;
    j_ulim >>= 1;

  }

  return m_M.Product( answer0 , answer1 );

}
