// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::MonoidSqrtDecomposition() : m_a() , m_b() { if( m_a[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } for( int i = 0 ; i < N ; i++ ){ m_a[i] = g_e; } } }
template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::MonoidSqrtDecomposition( const T ( &a )[N] ) : m_a() , m_b() { int i = 0; for( int d = 0 ; d < N_d ; d++ ){ T& m_bd = m_b[d] = g_e; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd = m_T( m_bd , m_a[i] = a[i] ); i++; } } while( i < N ){ m_a[i] = a[i]; i++; } }

template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr const T& MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::operator[]( const int& i ) const { return m_a[i]; }
template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr const T& MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::Get( const int& i ) const { return m_a[i]; }

template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr T MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::IntervalSum( const int& i_start , const int& i_final )
{
  
  const int i_min = max( i_start , 0 );
  const int i_max = min( i_final , N - 1 );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , ( i_max + 1 ) / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt - 1 , i_max ) ;
  const int i_1 = max( i_min , d_1 * N_sqrt );
  T answer{ g_e };
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer = m_T( answer , m_a[i] );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_T( answer , m_b[d] );

  }

  for( int i = i_1 ; i <= i_max ; i++ ){

    answer = m_T( answer , m_a[i] );

  }

  return answer;
  
}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr void MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::Set( const int& i , const T& n ) { m_a[i] = n; if( i < N_m ){ const int d = i / N_d; T& m_bd = m_b[d] = g_e; int i_d = N_sqrt * d; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd = m_T( m_bd , m_a[i_d++] ); } } }
template <TEMPLATE_ARGUMENTS_FOR_MONOID_SQRT_DECOMPOSITION> inline constexpr void MonoidSqrtDecomposition<T,m_T,e_T,N,N_sqrt>::Add( const int& i , const T& n ) { T& m_ai = m_a[i]; if( i < N_m ){ T& m_bd = m_b[i / N_d]; m_bd = m_T( m_bd , n ); }  m_ai = m_T( m_ai , n ); }
