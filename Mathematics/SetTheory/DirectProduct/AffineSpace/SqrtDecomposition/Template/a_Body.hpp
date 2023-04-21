// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Template/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::AbstractSqrtDecomposition() : m_a() , m_b() { if( m_a[0] != g_e ){ for( int d = 0 ; d < N_d ; d++ ){ m_b[d] = g_e; } for( int i = 0 ; i < N ; i++ ){ m_a[i] = g_e; } } }
template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::AbstractSqrtDecomposition( const T ( &a )[N] ) : m_a() , m_b() { int i = 0; for( int d = 0 ; d < N_d ; d++ ){ T& m_bd = m_b[d] = g_e; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd = m_T( m_bd , m_a[i] = a[i] ); i++; } } while( i < N ){ m_a[i] = a[i]; i++; } }

template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr const T& AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::operator[]( const int& i ) const { return m_a[i]; }
template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr const T& AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::Get( const int& i ) const { return m_a[i]; }

template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr T AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::IntervalSum( const int& i_start , const int& i_final )
{
  
  int j_0 = ( i_start + N_sqrt - 1 ) / N_sqrt;
  int j_1 = max( j_0 , ( i_final + 1 ) / N_sqrt );
  int i_0 = min( j_0 * N_sqrt - 1 , i_final ) ;
  int i_1 = max( i_start , j_1 * N_sqrt );
  T answer{ g_e };
  
  for( int i = i_start ; i < i_0 ; i++ ){

    answer = m_T( answer , m_a[i] );

  }
  
  for( int j = j_0 ; j < j_1 ; j++ ){

    answer = m_T( answer , m_b[j] );

  }

  for( int i = i_1 ; i <= i_final ; i++ ){

    answer = m_T( answer , m_a[i] );

  }

  return answer;
  
}

template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr void AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::Set( const int& i , const T& n ) { T& m_ai = m_a[i]; if( i < N_m ){ T& m_bd = m_b[i / N_d]; m_bd = m_T( m_bd , m_T( i_T( m_ai ) , n ) ) } m_ai = n; }
template <TEMPLATE_ARGUMENTS_FOR_ABSTRACT_SQRT_DECOMPOSITION> inline constexpr void AbstractSqrtDecomposition<T,m_T,e_T,i_T,N,N_sqrt>::Add( const int& i , const T& n ) { T& m_ai = m_a[i]; if( i < N_m ){ T& m_bd = m_b[i / N_d]; m_bd = m_T( m_bd , n ); }  m_ai = m_T( m_ai , n ); }
