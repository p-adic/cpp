// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <typename R , typename PT_MAGMA , typename U , typename R_SET> template <typename...Args> inline DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::DualSqrtDecomposition( PT_MAGMA L , R_SET X , vector<U> a , const Args&... args ) : SqrtDecompositionCoordinate( a.size() , args... ) , m_L( move( L ) ) , m_X( move( X ) ) , m_a( move( a ) ) , m_b( m_N_d , m_L.Point() ) { static_assert( is_same_v<R,inner_t<PT_MAGMA>> && is_same_v<U,inner_t<R_SET>> ); }

template <typename R , typename PT_MAGMA , typename U , typename R_SET> template <typename...Args> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::Initialise( Args&&... args ) { DualSqrtDecomposition<R,PT_MAGMA,U,R_SET> temp{ m_L , m_X , forward<decay_t<Args>>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); }
template <typename R , typename PT_MAGMA , typename U , typename R_SET> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::Set( const int& i , const U& u ) { U& m_ai = m_a[i]; if( m_ai != u ){ Update( i / m_N_sqrt ); m_ai = u; } }

template <typename R , typename PT_MAGMA , typename U , typename R_SET> template <typename Arg> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::IntervalAct( const int& i_start , const int& i_final , const Arg& r )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  const R r_copy = m_L.Action( r , m_L.Point() );

  if( d_0 > 0 ){

    Update( d_0 - 1 );

  }
  
  for( int i = i_min ; i < i_0 ; i++ ){

    U& m_ai = m_a[i];
    m_ai = m_X.Action( r_copy , move( m_ai ) );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    R& m_bd = m_b[d];
    m_bd = m_L.Action( r , move( m_bd ) );

  }

  if( d_1 < m_N_d ){

    Update( d_1 );

  }
  
  for( int i = i_1 ; i < i_ulim ; i++ ){

    U& m_ai = m_a[i];
    m_ai = m_X.Action( r_copy , move( m_ai ) );

  }

  return;
  
}

template <typename R , typename PT_MAGMA , typename U , typename R_SET> inline U DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); return m_X.Action( m_b[i / m_N_sqrt] , m_a[i] ); }
template <typename R , typename PT_MAGMA , typename U , typename R_SET> inline U DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::Get( const int& i ) { return operator[]( i ); }

template <typename R , typename PT_MAGMA , typename U , typename R_SET> inline void DualSqrtDecomposition<R,PT_MAGMA,U,R_SET>::Update( const int& d )
{

  R& m_bd = m_b[d];
  const R& point = m_L.Point();

  if( m_bd != point ){

    const int j_min = d * m_N_sqrt;
    const int j_ulim = min( j_min + m_N_sqrt , m_N );

    for( int j = j_min ; j < j_ulim ; j++ ){

      U& m_aj = m_a[j];
      m_aj = m_X.Action( m_bd , move( m_aj ) );

    }

    m_bd = point;

  }
  
  return;

}

#include "../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"
