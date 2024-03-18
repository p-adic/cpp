// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a ) : m_L( move( L ) ) , m_X( move( X ) ) , m_N( a.size() ) , m_N_sqrt( Sqrt( m_N ) ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( move( a ) ) , m_b( m_N_d , m_L.Point() ) { static_assert( is_same_v<R,inner_t<PT_MAGMA>> && is_same_v<U,inner_t<R_MODULE>> ); }
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a , const int& N_sqrt ) : m_L( move( L ) ) , m_X( move( X ) ) , m_N( a.size() ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( move( a ) ) , m_b( m_N_d , m_L.Point() ) { static_assert( is_same_v<R,inner_t<PT_MAGMA>> && is_same_v<U,inner_t<R_MODULE>> ); }

template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> template <typename...Args> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::Initialise( Args&&... args ) { *this = DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>( move( m_L ) , move( m_X ) , forward<decay_t<Args>>( args )... ); }
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::Set( const int& i , const U& u ) { U& m_ai = m_a[i]; if( m_ai != u ){ Update( i / m_N_sqrt ); m_ai = u; } }

template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::IntervalAct( const int& i_start , const int& i_final , const R& r )
{

  if( r != m_L.Point() ){
    
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , m_N );
    const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
    const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
    const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1 * m_N_sqrt );

    if( d_0 > 0 ){

      Update( d_0 - 1 );

    }
  
    for( int i = i_min ; i < i_0 ; i++ ){

      U& m_ai = m_a[i];
      m_ai = m_X.Action( r , m_ai );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      R& m_bd = m_b[d];
      m_bd = m_L.Product( r , m_bd );

    }

    if( d_1 < m_N_d ){

      Update( d_1 );

    }
  
    for( int i = i_1 ; i < i_ulim ; i++ ){

      U& m_ai = m_a[i];
      m_ai = m_X.Action( r , m_ai );

    }

  }

  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline U DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); return m_X.Action( m_b[i / m_N_sqrt] , m_a[i] ); }
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline U DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename R , typename PT_MAGMA , typename U , typename R_MODULE> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_MODULE>::Update( const int& d )
{

  R& m_bd = m_b[d];
  const R& point = m_L.Point();

  if( m_bd != point ){

    const int j_min = d * m_N_sqrt;
    const int j_ulim = min( j_min + m_N_sqrt , m_N );

    for( int j = j_min ; j < j_ulim ; j++ ){

      U& m_aj = m_a[j];
      m_aj = m_X.Action( m_bd , m_aj );

    }

    m_bd = point;

  }
  
  return;

}
