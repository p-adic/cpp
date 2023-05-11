// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/LazyEvaluation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"


template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> const T& LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::g_e_T = e_T();
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> const T& LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::g_e_U = e_U();

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::LazySqrtDecomposition() : m_a() , m_c() { if( m_a[0] != g_e_U ){ for( int i = 0 ; i < N_m ; i++ ){ m_a[i] = g_e_U; } for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e_U; } } if( m_c[0] != g_e_T ){ for( int d = 0 ; d < N_d ; d++ ){ m_c[d] = g_e_T; } } }
template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::LazySqrtDecomposition( const U ( &a )[N] )
: m_a() , m_c()
{

  int i = 0;

  while( i < N ){
    
      m_a[i] = a[i];
      i++;
  }

  while( i < N_m ){

    m_a[i] = g_e_U;
    i++;

  }

  i = 0;
  
  for( int d = 0 ; d < N_d ; d++ ){

    U& m_bd = m_b[d] = g_e_U;

    for( int j = 0 ; j < N_sqrt ; j++ ){

      m_bd = m_U( m_bd , m_a[i] );
      i++;

    }

  }

  if( m_c[0] != g_e_T ){

    for( int d = 0 ; d < N_d ; d++ ){

      m_c[d] = g_e_T;

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Get( const int& i ) const { return o_U( m_c[i/N_sqrt] , m_a[i] ); }

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U IntervalProd( const int& i_start , const int& i_final ) const
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , N );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , i_ulim / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt , i_ulim ) ;
  const int i_1 = max( i_0 , d_1 * N_sqrt );
  
  U answer = g_e_U;

  if( i_min < i_0 ){

    // この時d_0 > 0になる。
    answer = o_U( m_c[d_0-1] , IntervalProd_Body( i_min , i_0 ) );
    
  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_U( answer , o_U( m_c[d] , m_b[d] ) )

  }

  if( i_1 < i_ulim ){

    // この時d_1 < N_dになる。
    answer = m_U( answer , o_U( m_c[d_1] , IntervalProd_Body( i_1 , i_ulim ) ) };

  }

  return answer;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Set( const int& i , const U& u )
{

  U& m_ai = m_a[i];

  if( m_ai != u ){
    
    const int d = i / N_sqrt;
    T& m_cd = m_c[d];

    if( m_cd != g_e ){

      const i_min = d * N_sqrt;
      IntervalAct_Body( i_min , i_min + N_sqrt , m_cd );
      m_cd = g_e;

    }

    m_ai = u;
    Set_Body( d );

  }
  
  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalAct( const int& i_start , const int& i_final , const T& t )
{

  if( t != g_e ){
  
    const int i_min = max( i_start , 0 );
    const int i_ulim = min( i_final + 1 , N );
    const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
    const int d_1 = max( d_0 , i_ulim / N_sqrt );
    const int d_0_N_sqrt = d_0 * N_sqrt;
    const int d_1_N_sqrt = d_1 * N_sqrt;
    const int i_0 = min( d_0_N_sqrt , i_ulim );
    const int i_1 = max( i_0 , d_1_N_sqrt );

    if( i_min < i_0 ){

      const int d_0_N_sqrt_minus = d_0_N_sqrt - N_sqrt;
      // この時d_0 > 0になる。
      T& m_cd = m_c[d_0-1];
      IntervalAct_Body( d_0_N_sqrt_minus , d_0_N_sqrt , m_cd );
      m_cd = g_T_e;
      IntervalAct_Body( i_min , i_0 , t );
      Set_Body( d_0 );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      T& m_cd = m_c[d];
      m_cd = m_T( t , m_cd );

    }

    if( i_1 < i_ulim ){
      
      // この時d_1 < N_dになる。
      T& m_cd = m_c[d_1];
      IntervalAct_Body( d_1_N_sqrt , d_1_N_sqrt + N_sqrt , m_cd );
      m_cd = g_T_e;
      IntervalAct_Body( i_1, i_ulim , t );
      Set_Body( d_1 );

    }

  }
  
  return;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr U LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalProd_Body( const int& i_min , const int& i_ulim ) const
{

  U answer = g_e_U;
  
  for( int i = i_min ; i < i_ulim ; i++ ){

    answer = m_U( answer , m_a[i] );

  }

  return answer;
  
}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::Set_Body( const int& d )
{

  U& m_bd = m_b[d] = g_e_U;
  const int i_min = d * N_sqrt;
  const int i_ulim = i_min + N_sqrt;

  for( int i = i_min ; i < i_ulim ; i++ ){

    m_bd = m_U( m_bd , m_a[i] );

  }

  return;

}

template <TEMPLATE_ARGUMENTS_FOR_LAZY_SQRT_DECOMPOSITION> inline constexpr void LazySqrtDecomposition<T,m_T,e_T,U,m_U,e_U,o_U,N,N_sqrt>::IntervalAct_Body( const int& i_min , const int& i_ulim , const T& t )
{

  for( int i = i_min ; i < i_ulim ; i++ ){

    U& m_ai = m_a[i];
    m_ai = o_U( t , m_ai );

  }

  return;
  
}
