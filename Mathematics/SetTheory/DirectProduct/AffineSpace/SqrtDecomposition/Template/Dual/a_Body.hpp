// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Dual/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"


template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> const T& DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::DualSqrtDecomposition( const U ( &a )[N] ) : m_a() , m_b() { if( m_b[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } } for( int i = 0 ; i < N ; i++ ){ m_a[i] = a[i]; } }

template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr U DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Get( const int& i ) const { return o_U( m_b[i/N_sqrt] , m_a[i] ); }

template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr void DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Set( const int& i , const U& u )
{

  U& m_ai = m_a[i];

  if( m_ai != u ){
    
    const int d = i / N_sqrt;
    T& m_bd = m_b[d];

    if( m_bd != g_e ){

      const int ini_min = d * N_sqrt;
      IntervalAct_Body( i_min , i_min + N_sqrt , m_bd );
      m_bd = g_e;

    }

    m_ai = u;

  }

  return;

}

template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr void DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::Act( const int& i , const T& t ) { T& m_ai = m_a[i]; m_ai = o_U( t , m_ai ); }
template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr void DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::IntervalAct( const int& i_start , const int& i_final , const T& t )
{

  if( t != g_e ){
  
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , N );
    const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
    const int d_1 = max( d_0 , i_ulim / N_sqrt );
    const int i_0 = min( d_0 * N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1 * N_sqrt );
    IntervalAct_Body( i_min , i_0 , t );
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      T& m_bd = m_b[d];
      m_bd = m_T( t , m_bd );

    }

    IntervalAct_Body( i_1, i_ulim , t );

  }
  
  return;
  
}

template <TEMPLATE_ARGUMENTS_FOR_DUAL_SQRT_DECOMPOSITION> inline constexpr void DualSqrtDecomposition<T,m_T,e_T,U,o_U,N,N_sqrt>::IntervalAct_Body( const int& i_min , const int& i_ulim , const T& t )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    U& m_ai = m_a[i];
    m_ai = o_U( t , m_ai );

  }

  return;
  
}
