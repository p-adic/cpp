// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <TEMPLETE_ARGUMENTS_FOR_BIT> inline const T& AbstractBIT<T,m_T,e_T,i_T,N>::g_e = e_T();

template <TEMPLETE_ARGUMENTS_FOR_BIT> inline AbstractBIT<T,m_T,e_T,i_T,N>::AbstractBIT() : m_fenwick() { const T& e = g_e; for( int i = 0 ; i <= N ; i++ ){ m_fenwick[i] = e; } }
template <TEMPLETE_ARGUMENTS_FOR_BIT>
AbstractBIT<T,m_T,e_T,i_T,N>::AbstractBIT( const T ( & a )[N] ) : m_fenwick()
{

  for( int j = 1 ; j <= N ; j++ ){

    int& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i != i_lim ){

      fenwick_j = m_T( fenwick_j , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

}

template <TEMPLETE_ARGUMENTS_FOR_BIT> inline void AbstractBIT<T,m_T,e_T,i_T,N>::Set( const int& i , const T& n ) { Add( i , m_T( i_T( IntervalSum( i , i ) ) , n ) ); }

template <TEMPLETE_ARGUMENTS_FOR_BIT> inline AbstractBIT<T,m_T,e_T,i_T,N>& AbstractBIT<T,m_T,e_T,i_T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <TEMPLETE_ARGUMENTS_FOR_BIT>
void AbstractBIT<T,m_T,e_T,i_T,N>::Add( const int& i , const T& n )
{
  
  int j = i + 1;

  while( j <= N ){

    T& m_fenwick_j = m_fenwick[j];
    m_fenwick_j = m_T( m_fenwick_j , n );
    j += ( j & -j );

  }

  return;
  
}

template <TEMPLETE_ARGUMENTS_FOR_BIT> 
T AbstractBIT<T,m_T,e_T,i_T,N>::InitialSegmentSum( const int& i_final )
{

  T sum = g_e;
  int j = ( i_final < N ? i_final : N - 1 ) + 1;

  while( j > 0 ){

    sum = m_T( sum , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <TEMPLETE_ARGUMENTS_FOR_BIT> inline T AbstractBIT<T,m_T,e_T,i_T,N>::IntervalSum( const int& i_start , const int& i_final ) { return m_T( i_T( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }

