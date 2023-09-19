// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a_Body.hpp

#pragma once
#include "a.hpp"

// BinarySearchに使う。
#include "../../../../../Arithmetic/Power/Constexpr/Inverse/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline const T& AbstractBIT<T,m_T,e_T,i_T,N>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractBIT<T,m_T,e_T,i_T,N>::AbstractBIT() : m_fenwick() { const T& e = g_e; for( int i = 0 ; i <= N ; i++ ){ m_fenwick[i] = e; } }
template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractBIT<T,m_T,e_T,i_T,N>::AbstractBIT( const T ( &a )[N] ) : m_fenwick()
{

  for( int j = 1 ; j <= N ; j++ ){

    T& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i != i_lim ){

      fenwick_j = m_T( fenwick_j , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline T AbstractBIT<T,m_T,e_T,i_T,N>::Get( const int& i ) const { return IntervalSum( i , i ); }
template <TEMPLATE_ARGUMENTS_FOR_BIT> inline void AbstractBIT<T,m_T,e_T,i_T,N>::Set( const int& i , const T& n ) { Add( i , m_T( i_T( IntervalSum( i , i ) ) , n ) ); }
template <TEMPLATE_ARGUMENTS_FOR_BIT> inline void AbstractBIT<T,m_T,e_T,i_T,N>::Set( const T ( &a )[N] ) { AbstractBIT<T,m_T,e_T,i_T,N> a_copy{ a }; swap( m_fenwick , a_copy.m_fenwick ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractBIT<T,m_T,e_T,i_T,N>& AbstractBIT<T,m_T,e_T,i_T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <TEMPLATE_ARGUMENTS_FOR_BIT>
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

template <TEMPLATE_ARGUMENTS_FOR_BIT> 
T AbstractBIT<T,m_T,e_T,i_T,N>::InitialSegmentSum( const int& i_final ) const
{

  T sum = g_e;
  int j = ( i_final < N ? i_final : N - 1 ) + 1;

  while( j > 0 ){

    sum = m_T( sum , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline T AbstractBIT<T,m_T,e_T,i_T,N>::IntervalSum( const int& i_start , const int& i_final ) const { return m_T( i_T( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }


template <TEMPLATE_ARGUMENTS_FOR_BIT>
int AbstractBIT<T,m_T,e_T,i_T,N>::BinarySearch( const T& n ) const
{

  int j = 0;
  int power = PowerInverse_constexpr<N>().m_val;
  T sum = g_e;
  T sum_next = g_e;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < N ){
      
      sum_next = m_T( sum_next , m_fenwick[j_next] );

      if( sum_next < n ){
	
	sum = sum_next;
	j = j_next;

      } else {

	sum_next = sum;
	
      }
      
    }
    
    power >>= 1;

  }

  // InitialSegmentSum( i )がn未満となるiが存在するならばjはその最大値に1を足したものとなり、
  // InitialSegmentSum( i )がn未満となるiが存在しないならばj=0となり、
  // いずれの場合もInitialSegmentSum( i )がt以上となるiが存在するならば
  // jはそのような最小のiと等しい。
  return j;

}

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline int AbstractBIT<T,m_T,e_T,i_T,N>::BinarySearch( const int& i_start , const T& n ) const { return max( i_start , m_T( BinarySearch( InitialSegmentSum( i_start ) , n ) ) ); }
