// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <typename U , typename MONOID> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , const int& N ) : MonoidSqrtDecomposition( move( M ) , N , Sqrt( N ) ) {}
template <typename U , typename MONOID> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , const int& N , const int& N_sqrt ) : m_M( move( M ) ) , m_N( N ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( m_N_m , m_M.Zero() ) , m_b( m_N_d , m_M.Zero() ) { static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<MONOID>> ); }
template <typename U , typename MONOID> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , vector<U> a ) : MonoidSqrtDecomposition( move( M ) , move( a ) , Sqrt( a.size() ) ) {}
template <typename U , typename MONOID> inline MonoidSqrtDecomposition<U,MONOID>::MonoidSqrtDecomposition( MONOID M , vector<U> a , const int& N_sqrt ) : m_M( move( M ) ) , m_N( a.size() ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() )
{

  static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<MONOID>> );
  m_a.resize( m_N_m , m_M.One() );
  int i_min = 0;
  int i_ulim = m_N_sqrt;

  for( int d = 0 ; d < m_N_d ; d++ ){

    U& m_bd = m_b[d];
  
    for( int i = i_min ; i < i_ulim ; i++ ){

      m_bd = m_M.Product( move( m_bd ) , m_a[i] );

    }
    
    i_min = i_ulim;
    i_ulim += m_N_sqrt;

  }

}

template <typename U , typename MONOID> template <typename...Args> inline void MonoidSqrtDecomposition<U,MONOID>::Initialise( Args&&... args ) { MonoidSqrtDecomposition<U,MONOID> temp{ m_M , forward<Args>( args )... };  m_N = temp.m_N; m_N_sqrt = temp.m_N_sqrt; m_N_d = temp.m_N_d; m_N_m = temp.m_N_m; m_a = move( temp.m_a ); m_b = move( temp.m_b ); }

template <typename U , typename MONOID> inline void MonoidSqrtDecomposition<U,MONOID>::Set( const int& i , const U& u )
{
  
  const int d = i / m_N_sqrt;
  const int i_min = m_N_sqrt * d;
  const int i_ulim = i_min + m_N_sqrt;
  m_a[i] = u;
  U& m_bd = m_b[d] = m_M.Zero();

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_bd = m_M.Product( move( m_bd ) , m_a[i] );

  }

  return;

}

template <typename U , typename MONOID> inline const U& MonoidSqrtDecomposition<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_N ); return m_a[i]; }
template <typename U , typename MONOID> inline const U& MonoidSqrtDecomposition<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename MONOID> inline U MonoidSqrtDecomposition<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  U answer = m_M.One();
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Product( move( answer ) , m_b[d] );

  }

  for( int i = i_1 ; i < i_ulim ; i++ ){

    answer = m_M.Product( move( answer ) , m_a[i] );

  }

  return answer;
  
}

template <typename U , typename MONOID> template <typename F , SFINAE_FOR_SD_S> inline int MonoidSqrtDecomposition<U,MONOID>::Search( const int& i_start , const F& f ) { return Search( i_start , f , m_M.Zero() ); }
template <typename U , typename MONOID> inline int MonoidSqrtDecomposition<U,MONOID>::Search( const int& i_start , const U& u ) { return Search( i_start , [&]( const U& prod , const int& ){ return prod <= u; } ); }

template <typename U , typename MONOID> template <typename F> int MonoidSqrtDecomposition<U,MONOID>::Search_Body( const int& i_start , const F& f , U sum_temp )
{

  const int i_min = max( i_start , 0 );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int i_0 = min( d_0 * m_N_sqrt , m_N );
  
  for( int i = i_min ; i < i_0 ; i++ ){

    sum_temp = m_M.Product( move( sum_temp ) , m_a[i] );

    if( f( sum_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_0 ; d < m_N_d ; d++ ){

    U sum_next = m_M.Product( sum_temp , m_b[d] );

    if( f( sum_next , min( ( d + 1 ) * m_N_sqrt , m_N ) - 1 ) ){

      return Search_Body( d * m_N_sqrt , f , sum_temp );

    }

    sum_temp = move( sum_next );
    
  }

  return -1;

}
