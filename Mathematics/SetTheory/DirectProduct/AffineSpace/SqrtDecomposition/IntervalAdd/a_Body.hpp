// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename Z_MODULE> template <typename...Args> inline IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) : AbstractSqrtDecomposition<U,Z_MODULE>( move( M ) , forward<Args>( args )... ) , m_lazy_addition( this->m_N_d , this->m_M.Zero() ) {}
template <typename U> template <typename...Args> inline IntervalAddSqrtDecomposition<U>::IntervalAddSqrtDecomposition( Args&&... args ) : IntervalAddAbstractSqrtDecomposition<U,Module<int,U>>( Module<int,U>() , args... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::Initialise( Args&&... args ) { *this = IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>( move( this->m_M ) , forward<Args>( args )... ); }

template <typename U , typename Z_MODULE> inline void IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::Set( const int& i , const U& u ) { const int d = i / this->m_N_sqrt; this->m_b[d] = this->m_M.Sum( this->m_b[d] , this->m_M.Sum( u , this->m_M.Inverse( this->m_a[i] ) ) ); this->m_a[i] = this->m_M.Sum( u , this->m_M.Inverse( m_lazy_addition[d] ) ); }

template <typename U , typename Z_MODULE> inline void IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::IntervalAdd( const int& i_start , const int& i_final , const U& u )
{

  if( u != this->m_M.Zero() ){
    
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , this->m_N );
    const int d_0 = ( i_min + this->m_N_sqrt - 1 ) / this->m_N_sqrt;
    const int d_1 = max( d_0 , i_ulim / this->m_N_sqrt );
    const int i_0 = min( d_0 * this->m_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1 * this->m_N_sqrt );
    
    for( int i = i_min ; i < i_0 ; i++ ){

      this->Add( i , u );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      U& m_lazy_addition_d = m_lazy_addition[d];
      m_lazy_addition_d = this->m_M.Sum( m_lazy_addition_d , u );

    }

    for( int i = i_1 ; i < i_ulim ; i++ ){

      this->Add( i , u );

    }

  }
  
  return;
  
}

template <typename U , typename Z_MODULE> inline U IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < this->m_N ); return this->m_M.Sum( AbstractSqrtDecomposition<U,Z_MODULE>::operator[]( i ) , m_lazy_addition[i / this->m_N_sqrt] ); }
template <typename U , typename Z_MODULE> inline U IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::Get( const int& i ) { return operator[]( i ); }

template <typename U , typename Z_MODULE> inline U IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::IntervalSum( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , this->m_N );
  const int d_0 = ( i_min + this->m_N_sqrt - 1 ) / this->m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / this->m_N_sqrt );
  const int i_0 = min( d_0 * this->m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * this->m_N_sqrt );
  U answer = this->m_M.Zero();

  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = this->m_M.Sum( answer , m_lazy_addition[d] );

  }

  answer = this->m_M.ScalarProduct( answer , d_1 - d_0 );

  if( d_0 > 0 ){

    answer = this->m_M.Sum( answer , this->m_M.ScalarProduct( m_lazy_addition[d_0 - 1] , i_0 - i_min ) );

  }

  if( d_1 < this->m_N_d ){
  
    answer = this->m_M.Sum( answer , this->m_M.ScalarProduct( m_lazy_addition[d_1] , i_ulim - i_1 ) );

  }

  answer = this->m_M.Sum( answer , AbstractSqrtDecomposition<U,Z_MODULE>::IntervalSum( i_start , i_final ) );
  return answer;
  
}
