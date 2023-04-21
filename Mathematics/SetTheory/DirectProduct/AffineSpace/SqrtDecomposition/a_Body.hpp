// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Sqrt/a_Body.hpp"

template <typename T , int N , int N_sqrt> inline constexpr SqrtDecomposition<T,N,N_sqrt>::SqrtDecomposition() : m_a() , m_b() {}
template <typename T , int N , int N_sqrt> inline constexpr SqrtDecomposition<T,N,N_sqrt>::SqrtDecomposition( const T ( &a )[N] ) : m_a() , m_b() { int i = 0; for( int d = 0 ; d < N_d ; d++ ){ T& m_bd = m_b[d]; for( int j = 0 ; j < N_sqrt ; j++ ){ m_bd += m_a[i] = a[i]; i++; } } while( i < N ){ m_a[i] = a[i]; i++; } }

template <typename T , int N , int N_sqrt> inline constexpr const T& SqrtDecomposition<T,N,N_sqrt>::operator[]( const int& i ) const { return m_a[i]; }
template <typename T , int N , int N_sqrt> inline constexpr const T& SqrtDecomposition<T,N,N_sqrt>::Get( const int& i ) const { return m_a[i]; }

template <typename T , int N , int N_sqrt> inline constexpr T SqrtDecomposition<T,N,N_sqrt>::IntervalSum( const int& i_start , const int& i_final )
{
  
  const int i_min = max( i_start , 0 );
  const int i_max = min( i_final , N - 1 );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , ( i_max + 1 ) / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt - 1 , i_max ) ;
  const int i_1 = max( i_min , d_1 * N_sqrt );
  T answer{ 0 };
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer += m_a[i];

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer += m_b[d];

  }

  for( int i = i_1 ; i <= i_max ; i++ ){

    answer += m_a[i];

  }

  return answer;
  
}

template <typename T , int N , int N_sqrt> inline constexpr void SqrtDecomposition<T,N,N_sqrt>::Set( const int& i , const T& n ) { T& m_ai = m_a[i]; if( i < N_m ){ ( m_b[i / N_d] -= m_ai ) += n; } m_ai = n; }
template <typename T , int N , int N_sqrt> inline constexpr void SqrtDecomposition<T,N,N_sqrt>::Add( const int& i , const T& n ) { T& m_ai = m_a[i]; if( i < N_m ){ m_b[i / N_d] += n; }  m_ai += n; }
