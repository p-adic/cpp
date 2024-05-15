// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/Commutative/IntervalMultiply/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Sqrt/a_Body.hpp"

template <typename U , typename N_MODULE> template <typename...Args> inline IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalMultiplySqrtDecomposition( N_MODULE M , const int& N , const Args&... args ) : SqrtDecompositionCoordinate( N , args... ) , m_M( move( M ) ) , m_a( m_N_m , m_M.Zero() ) , m_b( m_N_d , m_M.Zero() ) , m_lazy_multiplication( m_N_d , m_M.One() ) { static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<N_MODULE>> ); }
template <typename U , typename N_MODULE> template <typename...Args> inline IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalMultiplySqrtDecomposition( N_MODULE M , vector<U> a , const Args&... args ) : SqrtDecompositionCoordinate( a.size() , args... ) , m_M( move( M ) ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() ) , m_lazy_multiplication( m_N_d , m_M.One() )
{

  static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<N_MODULE>> );
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

template <typename U , typename N_MODULE> template <typename...Args> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::Initialise( Args&&... args ) { IntervalMultiplySqrtDecomposition<U,N_MODULE> temp{ m_M , forward<Args>( args )... }; SqrtDecompositionCoordinate::operator=( temp ); m_a = move( temp.m_a ); m_b = move( temp.m_b ); m_lazy_multiplication = vector( m_N_d , m_M.One() ); }

template <typename U , typename N_MODULE> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::Set( const int& i , const U& u )
{
  
  const int d = i / m_N_sqrt;
  const int j_min = m_N_sqrt * d;
  const int j_ulim = j_min + m_N_sqrt;
  const U& one = m_M.One();
  U& m_lazy_multiplication_d = m_lazy_multiplication[d];

  if( m_lazy_multiplication_d != one ){

    for( int j = j_min ; j < j_ulim ; j++ ){

      U& m_aj = m_a[j];
      m_aj = m_M.Product( move( m_aj ) , m_lazy_multiplication_d );

    }

    m_lazy_multiplication_d = one;

  }

  m_a[i] = u;
  U& m_bd = m_b[d] = one;

  for( int j = j_min ; j < j_ulim ; j++ ){

    m_bd = m_M.Product( move( m_bd ) , m_a[j] );

  }

  return;

}

template <typename U , typename N_MODULE> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::Multiply( const int& i , const U& u ) { U& m_ai = m_a[i]; U& m_bd = m_b[i / m_N_sqrt]; m_bd = m_M.Product( move( m_bd ) , u ); m_ai = m_M.Product( move( m_ai ) , u ); }

template <typename U , typename N_MODULE> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalMultiply( const int& i_start , const int& i_final , const U& u )
{

  if( u != m_M.One() ){
    
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , m_N );
    const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
    const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
    const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1 * m_N_sqrt );
    
    for( int i = i_min ; i < i_0 ; i++ ){

      Multiply( i , u );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      U& m_lazy_multiplication_d = m_lazy_multiplication[d];
      m_lazy_multiplication_d = m_M.Product( move( m_lazy_multiplication_d ) , u );

    }

    for( int i = i_1 ; i < i_ulim ; i++ ){

      Multiply( i , u );

    }

  }
  
  return;
  
}

template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < m_N ); return m_M.Product( m_a[i] , m_lazy_multiplication[i / m_N_sqrt] ); }
template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  U answer = m_M.One();

  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Product( move( answer ) , m_lazy_multiplication[d] );

  }

  answer = m_M.Power( answer , d_1 - d_0 );

  if( d_0 > 0 ){

    answer = m_M.Product( move( answer ) , m_M.Power( m_lazy_multiplication[d_0 - 1] , i_0 - i_min ) );

  }

  if( d_1 < m_N_d ){
  
    answer = m_M.Product( move( answer ) , m_M.Power( m_lazy_multiplication[d_1] , i_ulim - i_1 ) );

  }

  answer = m_M.Product( move( answer ) , IntervalProduct_Body( i_start , i_final ) );
  return answer;
  
}

template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalProduct_Body( const int& i_start , const int& i_final )
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

#include "../../../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"
