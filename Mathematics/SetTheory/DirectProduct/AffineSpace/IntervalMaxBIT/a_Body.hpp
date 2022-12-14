// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/IntervalMaxBIT/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int N> inline IntervalMaxBIT<T,N>::IntervalMaxBIT( const T& n , const bool& for_max ) : m_init( n ) , m_fenwick_0() , m_fenwick_1() , m_for_max( for_max ) { for( int i = 0 ; i <= N ; i++ ){ m_fenwick_0[i] = m_fenwick_1[i] = m_init; } }

template <typename T , int N>
void IntervalMaxBIT<T,N>::SetMax( const int& i , const T& n )
{

  int j = i + 1;

  while( j <= N ){

    T& ti = m_fenwick_0[j];

    if( ( ti < n ) == m_for_max ){

      ti = n;

    }
      
    j += ( j & -j );

  }

  j = i + 1;
  
  while( j >= 0 ){

    T& ti = m_fenwick_1[j];

    if( ( ti < n ) == m_for_max ){

      ti = n;

    }
      
    j -= ( j & -j );

  }

  return;
  
}

template <typename T , int N>
T IntervalMaxBIT<T,N>::IntervalMax( const int& i_start , const int& i_final )
{

  T answer = m_init;
  int j = i_start + 1;
  const int& j_max = i_final < N ? i_final : N;

  while( j <= j_max ){

    const T& ti = m_fenwick_0[j];

    if( ( answer < ti ) == m_for_max ){

      answer = ti;

    }

    j += ( j & - j );

  }

  j = i_final + 1;
  
  while( j > i_start ){

    const T& ti = m_fenwick_1[j];

    if( ( answer < ti ) == m_for_max ){

      answer = ti;

    }

    j -= ( j & - j );

  }
 
  return answer;
  
}


