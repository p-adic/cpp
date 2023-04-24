// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Monoid/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> const T& IntervalAddSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalAddSqrtDecomposition() : m_a() , m_b() { if( m_a[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } for( int i = 0 ; i < N ; i++ ){ m_a[i] = g_e; } } }
template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalAddSqrtDecomposition( const T ( &a )[N] ) : m_a() , m_b() { int i = 0; for( int d = 0 ; d < N_d ; d++ ){ T& m_bd = m_b[d] = g_e; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd = m_T( m_bd , m_a[i] = a[i] ); i++; } } while( i < N ){ m_a[i] = a[i]; i++; } }
template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalAddSqrtDecomposition( T ( &&a )[N] ) : m_a() , m_b() { swap( m_a , a ); int i = 0; for( int d = 0 ; d < N_d ; d++ ){ T& m_bd = m_b[d] = g_e; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd = m_T( m_bd , m_a[i++] ); } } }

template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr T IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalSum( const int& i_start , const int& i_final ) const
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , N );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , i_ulim / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt , i_ulim ) ;
  const int i_1 = max( i_0 , d_1 * N_sqrt );
  int i = i_min;

  while( i < i_0 ){

    answer = m_T( answer , m_a[i++] );

  }

  if( d_0 > 0 ){

    T power{ m_b[d_0 - 1] };
    int exponent = i_0 - i_min;

    while( exponent > 0 ){

      ( exponent & 1 ) == 1 ? answer = m_T( answer , power ) : answer;
      power = m_T( power , power );
      exponent >>= 1;

    }

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    for( int j = 0 ; j < N_sqrt ; j++ ){

      answer = m_T( answer , m_a[i++] );

    }

    T power{ m_b[d] };
    int exponent = N_sqrt;

    while( exponent > 0 ){

      ( exponent & 1 ) == 1 ? answer = m_T( answer , power ) : answer;
      power = m_T( power , power );
      exponent >>= 1;

    }

  }

  while( i < i_ulim ){

    answer = m_T( answer , m_a[i++] );

  }
  
  return answer;

}

template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr void IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::Add( const int& i , const T& n ) { T& m_ai = m_a[i]; m_ai = m_T( m_ai , n ); }
template <TEMPLATE_ARGUMENTS_FOR_INTERVAL_ADD_SQRT_DECOMPOSITION> inline constexpr void IntervalAddSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalAdd( const int& i_start , const int& i_final , const T& n )
{

  if( n != g_e ){
    
    const int i_min = max( i_start , 0 );
    const int i_max = min( i_final , N - 1 );
    const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
    const int d_1 = max( d_0 , ( i_max + 1 ) / N_sqrt );
    const int i_0 = min( d_0 * N_sqrt - 1 , i_max ) ;
    const int i_1 = max( i_min , d_1 * N_sqrt );
  
    for( int i = i_min ; i < i_0 ; i++ ){

      T& m_ai = m_a[i];
      m_ai = m_T( m_ai , n );

    }
  
    for( int d = d_0 ; d < d_1 ; d++ ){

      T& m_bd = m_b[d];
      m_bd = m_T( m_bd , n );

    }

    for( int i = i_1 ; i <= i_max ; i++ ){

      T& m_ai = m_a[i];
      m_ai = m_T( m_ai , n );

    }

  }
  
  return;
  
}
