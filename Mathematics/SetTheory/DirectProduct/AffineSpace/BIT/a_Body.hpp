// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../SegmentTree/Power/a_Body.hpp"

template <typename T , int N> inline BIT<T,N>::BIT() : m_fenwick() {}
template <typename T , int N>
BIT<T,N>::BIT( const T ( & a )[N] ) : m_fenwick()
{

  for( int j = 1 ; j <= N ; j++ ){

    T& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i != i_lim ){

      fenwick_j += m_fenwick[i];
      i -= ( i & -i );

    }

  }

}

template <typename T , int N> inline void BIT<T,N>::Set( const int& i , const T& n ) { Add( i , n - IntervalSum( i , i ) ); }

template <typename T , int N> inline BIT<T,N>& BIT<T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <typename T , int N>
void BIT<T,N>::Add( const int& i , const T& n )
{
  
  int j = i + 1;

  while( j <= N ){

    m_fenwick[j] += n;
    j += ( j & -j );

  }

  return;
  
}

template <typename T , int N> 
T BIT<T,N>::InitialSegmentSum( const int& i_final ) const
{

  T sum = 0;
  int j = ( i_final < N ? i_final : N - 1 ) + 1;

  while( j > 0 ){

    sum += m_fenwick[j];
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename T , int N> inline T BIT<T,N>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }

template <typename T> inline int BIT<T>::BinarySearch( const T& t ) const
{

  int j = 0;
  int power = PowerCalculation<N>.m_val;
  T sum{};
  T sum_next{};
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < N ){
      
      sum_next += m_fenwick[j_next];

      if( sum_next < t ){
	
	sum = sum_next;
	j = j_next;

      } else {

	sum_next = sum;
	
      }
      
    }
    
    power >>= 1;

  }

  // InitialSegmentSum( i )がt未満となるiが存在するならばjはその最大値に1を足したものとなり、
  // InitialSegmentSum( i )がt未満となるiが存在しないならばj=0となり、
  // いずれの場合もjはInitialSegmentSum( i )がt以上となる最小のiと等しい。
  return j;

}
