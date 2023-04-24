// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Lazy/NonCommutative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> const T& NonCommutativeLazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr NonCommutativeLazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::NonCommutativeLazySqrtDecomposition( const U ( &a )[N] ) : m_a() , m_b() { if( m_b[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } } for( int i = 0 ; i < N ; i++ ){ m_a[i] = a[i]; } }
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr NonCommutativeLazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::NonCommutativeLazySqrtDecomposition( U ( &&a )[N] ) : m_a() , m_b() { swap( m_a , a ); if( m_b[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } } }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U NonCommutativeLazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Get( const int& i ) const { return i < N_m ? o_U( m_b[i/N_sqrt] , m_a[i] ) : m_a[i]; }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void NonCommutativeLazySqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::IntervalAct( const int& i_start , const int& i_final , const T& n )
{

  if( n != g_e ){
  
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , N );
    const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
    const int d_1 = max( d_0 , i_ulim / N_sqrt );
    const int d_0_N_sqrt = d_0 * N_sqrt ;
    const int i_0 = min( d_0_N_sqrt , i_ulim ) ;
    const int d_1_N_sqrt = d_1 * N_sqrt ;
    const int i_1 = max( i_0 , d_1_N_sqrt );

    if( d_0 > 0 ){

      T& m_bd = m_b[d_0-1];

      if( m_bd != g_e ){
    
	for( int i = d_0_N_sqrt - N_sqrt ; i < d_0_N_sqrt ; i++ ){

	  U& m_ai = m_a[i];
	  m_ai = o_U( m_bd , m_ai );

	}

	m_bd = g_e;

      }
    
    }
  
    for( int i = i_min ; i < i_0 ; i++ ){

      U& m_ai = m_a[i];
      m_ai = o_U( n , m_ai );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      T& m_bd = m_b[d];
      m_bd = m_T( n , m_bd );

    }

    if( d_1 < N_d ){

      T& m_bd = m_b[d_1];
    
      if( m_bd != g_e ){
      
	for( int i = d_1_N_sqrt + N_sqrt - 1 ; i >= d_1_N_sqrt ; i-- ){

	  U& m_ai = m_a[i];
	  m_ai = o_U( m_bd , m_ai );

	}

	m_bd = g_e;

      }
    
    }
    
    for( int i = i_1 ; i < i_ulim ; i++ ){

      U& m_ai = m_a[i];
      m_ai = o_U( n , m_ai );

    }

  }

  return;
  
}
