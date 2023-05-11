// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Sqrt/a_Body.hpp"

template <typename T , int N , int N_sqrt> inline constexpr SqrtDecomposition<T,N,N_sqrt>::SqrtDecomposition() : m_a() , m_b() {}

template <typename T , int N , int N_sqrt> inline constexpr const T& SqrtDecomposition<T,N,N_sqrt>::operator[]( const int& i ) const { return m_a[i]; }
template <typename T , int N , int N_sqrt> inline constexpr const T& SqrtDecomposition<T,N,N_sqrt>::Get( const int& i ) const { return m_a[i]; }

template <typename T , int N , int N_sqrt> inline constexpr T SqrtDecomposition<T,N,N_sqrt>::IntervalSum( const int& i_start , const int& i_final )
{
  
  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , N );
  const int d_0 = ( i_min + N_sqrt - 1 ) / N_sqrt;
  const int d_1 = max( d_0 , i_ulim / N_sqrt );
  const int i_0 = min( d_0 * N_sqrt , i_ulim ) ;
  const int i_1 = max( i_0 , d_1 * N_sqrt );
  T answer{ 0 };
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer += m_a[i];

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer += m_b[d];

  }

  for( int i = i_1 ; i < i_ulim ; i++ ){

    answer += m_a[i];

  }

  return answer;
  
}

template <typename T , int N , int N_sqrt> inline constexpr void SqrtDecomposition<T,N,N_sqrt>::Set( const int& i , const T& n ) { T& m_ai = m_a[i]; ( m_b[i / N_sqrt] -= m_ai ) += n; m_ai = n; }
template <typename T , int N , int N_sqrt> inline constexpr void SqrtDecomposition<T,N,N_sqrt>::Add( const int& i , const T& n ) { T& m_ai = m_a[i]; m_b[i / N_sqrt] += n;  m_ai += n; }
