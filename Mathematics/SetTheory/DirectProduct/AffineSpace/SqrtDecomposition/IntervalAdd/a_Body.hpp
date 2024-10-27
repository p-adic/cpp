// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename Z_MODULE> template <typename...Args> inline IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) : AbstractSqrtDecomposition<U,Z_MODULE>( move( M ) , forward<Args>( args )... ) , m_lazy_addition( this->m_N_d , this->m_M.Zero() ) {}
template <typename U> template <typename...Args> inline IntervalAddSqrtDecomposition<U>::IntervalAddSqrtDecomposition( Args&&... args ) : IntervalAddAbstractSqrtDecomposition<U,Module<int,U>>( Module<int,U>() , args... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::Initialise( Args&&... args ) { AbstractSqrtDecomposition<U,Z_MODULE>::Initialise( forward<Args>( args )... ); m_lazy_addition = vector( this->m_N_d , this->m_M.Zero() ); }

template <typename U , typename Z_MODULE> inline void IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::Set( const int& i , const U& u ) { const int d = i / this->m_N_sqrt; this->m_b[d] = this->m_M.Sum( move( this->m_b[d] ) , this->m_M.Sum( this->m_M.Inverse( this->m_a[i] ) , u ) ); this->m_a[i] = this->m_M.Sum( this->m_M.Inverse( m_lazy_addition[d] ) , u ); }

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
      m_lazy_addition_d = this->m_M.Sum( move( m_lazy_addition_d ) , u );

    }

    for( int i = i_1 ; i < i_ulim ; i++ ){

      this->Add( i , u );

    }

  }
  
  return;
  
}

template <typename U , typename Z_MODULE> inline U IntervalAddAbstractSqrtDecomposition<U,Z_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < this->m_N ); return this->m_M.Sum( this->m_a[i] , m_lazy_addition[i / this->m_N_sqrt] ); }
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

    answer = this->m_M.Sum( move( answer ) , m_lazy_addition[d] );

  }

  answer = this->m_M.ScalarProduct( answer , d_1 - d_0 );

  if( d_0 > 0 ){

    answer = this->m_M.Sum( move( answer ) , this->m_M.ScalarProduct( m_lazy_addition[d_0 - 1] , i_0 - i_min ) );

  }

  if( d_1 < this->m_N_d ){
  
    answer = this->m_M.Sum( move( answer ) , this->m_M.ScalarProduct( m_lazy_addition[d_1] , i_ulim - i_1 ) );

  }

  answer = this->m_M.Sum( move( answer ) , AbstractSqrtDecomposition<U,Z_MODULE>::IntervalSum( i_start , i_final ) );
  return answer;
  
}

template <typename U , typename Z_MODULE> template <typename F , SFINAE_FOR_SD_S> inline int IntrvalAddAbstractSqrtDecomposition<U,Z_MODULE>::Search( const int& i_start , const F& f , const bool& reversed ) { return reversed ? SearchReverse_Body( i_start , f , m_M.Zero() ) : Search_Body( i_start , f , m_M.Zero() ); }
template <typename U , typename Z_MODULE> inline int IntrvalAddAbstractSqrtDecomposition<U,Z_MODULE>::Search( const int& i_start , const U& u , const bool& reversed ) { return Search( i_start , [&]( const U& sum , const int& ){ return !( sum < u ); } , reversed ); }

template <typename U , typename Z_MODULE> template <typename F> int IntrvalAddAbstractSqrtDecomposition<U,Z_MODULE>::Search_Body( const int& i_start , const F& f , U sum_temp )
{

  const int i_min = max( i_start , 0 );
  // d_0 = ( i_min + this->m_N_sqrt - 1 ) / m_N_sqrt;とすると再帰が無限ループする。
  const int d_0 = i_min / thi->m_N_sqrt + 1;
  const int i_0 = min( d_0 * this->m_N_sqrt , this->m_N );
  const U& lazy_addition_d = m_lazy_addition[d_0];
  
  for( int i = i_min ; i < i_0 ; i++ ){

    sum_temp = this->m_M.Sum( move( sum_temp ) , this->m_M.Sum( this->m_a[i] , lazy_addition_d ) );

    if( f( sum_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_0 ; d < this->m_N_d ; d++ ){

    U sum_next = this->m_M.Sum( sum_temp , this->m_M.Sum( this->m_b[d] , m_M.ScalarProduct( m_lazy_addition[d] , this->m_N_sqrt ) ) );

    if( f( sum_next , min( ( d + 1 ) * this->m_N_sqrt , this->m_N ) - 1 ) ){

      return Search_Body( d * this->m_N_sqrt , f , move( sum_temp ) );

    }

    sum_temp = move( sum_next );
    
  }

  return -1;

}

template <typename U , typename Z_MODULE> template <typename F> int IntrvalAddAbstractSqrtDecomposition<U,Z_MODULE>::SearchReverse_Body( const int& i_final , const F& f , U sum_temp )
{

  const int i_max = min( i_final , this->m_N - 1 );
  const int d_1 = i_max / this->m_N_sqrt;
  const int i_1 = max( d_1 * this->m_N_sqrt , 0 );
  const U& lazy_addition_d = m_lazy_addition[d_1];
  
  for( int i = i_max ; i >= i_1 ; i-- ){

    // 可換性を用いた。
    sum_temp = this->m_M.Sum( move( sum_temp ) , this->m_M.Sum( this->m_a[i] , lazy_addition_d ) );

    if( f( sum_temp , i ) ){

      return i;

    }

  }
  
  for( int d = d_1 - 1 ; d >= 0 ; d-- ){

    // 可換性を用いた。
    U sum_next = this->m_M.Sum( sum_temp , this->m_M.ScalarProduct( this->m_b[d] , this->m_M.ScalarProduct( m_lazy_addition[d] , tihs->m_N_sqrt ) ) );

    if( f( sum_next , d * this->m_N_sqrt ) ){

      return Search_Body( ( d + 1 ) * this->m_N_sqrt - 1 , f , move( sum_temp ) );

    }

    sum_temp = move( sum_next );
    
  }

  return -1;

}
