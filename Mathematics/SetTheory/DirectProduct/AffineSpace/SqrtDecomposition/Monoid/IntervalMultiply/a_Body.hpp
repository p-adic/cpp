// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalMultiply/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename N_MODULE> template <typename...Args> inline IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args ) : MonoidSqrtDecomposition<U,N_MODULE>( move( M ) , forward<Args>( args )... ) , m_lazy_multiplication( this->m_N_d , this->m_M.One() ) {}

template <typename U , typename N_MODULE> template <typename...Args> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::Initialise( Args&&... args ) { *this = IntervalMultiplySqrtDecomposition<U,N_MODULE>( move( this->m_M ) , forward<Args>( args )... ); }

template <typename U , typename N_MODULE> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::Set( const int& i , const U& u )
{
  
  const int d = i / this->m_N_sqrt;
  const int j_min = this->m_N_sqrt * d;
  const int j_ulim = j_min + this->m_N_sqrt;
  const U& one = this->m_M.One();
  U& m_lazy_multiplication_d = m_lazy_multiplication[d];

  if( m_lazy_multiplication_d != one ){

    for( int j = j_min ; j < j_ulim ; j++ ){

      U& m_aj = this->m_a[j];
      m_aj = this->m_M.Product( m_lazy_multiplication_d , m_aj );

    }

    m_lazy_multiplication_d = one;

  }

  this->m_a[i] = u;
  U& m_bd = this->m_b[d] = one;

  for( int j = j_min ; j < j_ulim ; j++ ){

    m_bd = this->m_M.Product( m_bd , this->m_a[j] );

  }

  return;

}

template <typename U , typename N_MODULE> inline void IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalMultiply( const int& i_start , const int& i_final , const U& u )
{

  if( u != this->m_M.One() ){
    
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , this->m_N );
    const int d_0 = ( i_min + this->m_N_sqrt - 1 ) / this->m_N_sqrt;
    const int d_1 = max( d_0 , i_ulim / this->m_N_sqrt );
    const int i_0 = min( d_0 * this->m_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1 * this->m_N_sqrt );
    
    for( int i = i_min ; i < i_0 ; i++ ){

      this->Multiply( i , u );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      U& m_lazy_multiplication_d = m_lazy_multiplication[d];
      m_lazy_multiplication_d = this->m_M.Product( m_lazy_multiplication_d , u );

    }

    for( int i = i_1 ; i < i_ulim ; i++ ){

      this->Multiply( i , u );

    }

  }
  
  return;
  
}

template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < this->m_N ); return this->m_M.Product( MonoidSqrtDecomposition<U,N_MODULE>::operator[]( i ) , m_lazy_multiplication[i / this->m_N_sqrt] ); }
template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename N_MODULE> inline U IntervalMultiplySqrtDecomposition<U,N_MODULE>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , this->m_N );
  const int d_0 = ( i_min + this->m_N_sqrt - 1 ) / this->m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / this->m_N_sqrt );
  const int i_0 = min( d_0 * this->m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * this->m_N_sqrt );
  U answer = this->m_M.One();

  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = this->m_M.Product( answer , m_lazy_multiplication[d] );

  }

  answer = this->m_M.Power( answer , d_1 - d_0 );

  if( d_0 > 0 ){

    answer = this->m_M.Product( answer , this->m_M.Power( m_lazy_multiplication[d_0 - 1] , i_0 - i_min ) );

  }

  if( d_1 < this->m_N_d ){
  
    answer = this->m_M.Product( answer , this->m_M.Power( m_lazy_multiplication[d_1] , i_ulim - i_1 ) );

  }

  answer = this->m_M.Product( answer , MonoidSqrtDecomposition<U,N_MODULE>::IntervalProduct( i_start , i_final ) );
  return answer;
  
}
