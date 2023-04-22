// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Lazy/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr LazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::LazySqrtDecomposition( const U ( &a )[N] ) : m_a() , m_b() { if( m_b[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } } for( int i = 0 ; i < N ; i++ ){ m_a[i] = a[i]; } }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr T LazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Get( const int& i ) const { return i < N_m ? o_U( m_b[i/N_sqrt] , m_a[i] ) : m_a[i]; }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Act( const int& i , const T& n ) { T& m_ai = m_a[i]; m_ai = o_U( n , m_ai ); }
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::IntervalAct( const int& i_start , const int& i_final , const T& n )
{
  
  const int i_min = max( i_start , 0 );
  const int i_max = min( i_final , N - 1 );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , ( i_max + 1 ) / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt - 1 , i_max ) ;
  const int i_1 = max( i_min , d_1 * N_sqrt );
  
  for( int i = i_min ; i < i_0 ; i++ ){

    T& m_ai = m_a[i];
    m_ai = o_U( n , m_ai );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    T& m_bd = m_b[d];
    m_bd = m_T( n , m_bd );

  }

  for( int i = i_1 ; i <= i_max ; i++ ){

    T& m_ai = m_a[i];
    m_ai = o_U( n , m_ai );

  }

  return;
  
}
