// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline BIT<T>::BIT( const int& size ) : m_size( size ) , m_fenwick( m_size + 1 ) , m_power( 1 ) { static_assert( ! is_same<T,int>::value ); while( m_power < m_size ){ m_power <<= 1; } }

template <typename T>
BIT<T>::BIT( const vector<T>& a ) : BIT( a.size() )
{

  for( int j = 1 ; j <= m_size ; j++ ){

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

template <typename T> inline BIT<T>& BIT<T>::operato=( BIT<T>&& a ) { m_size = a.m_size; m_fenwick = move( a.m_fenwick ); m_power = a.m_power; return *this; }

template <typename T> inline T BIT<T>::Get( const int& i ) const { return IntervalSum( i , i ); }
template <typename T> inline void BIT<T>::Set( const int& i , const T& n ) { Add( i , n - IntervalSum( i , i ) ); }
template <typename T> inline void BIT<T>::Set( const vector<T>& a ) { *this = BIT<T>{ a }; }
template <typename T> inline void BIT<T>::Initialise( const int& size ) { *this = BIT<T>( size ); }

template <typename T> inline BIT<T>& BIT<T>::operator+=( const vector<T>& a ) { BIT<T> a_copy{ a }; assert( m_size == a.m_size ); for( int i = 1 ; i <= m_size ; i++ ){ m_fenwick[i] += a.m_fenwick[i]; } return *this; }

template <typename T>
void BIT<T>::Add( const int& i , const T& n )
{
  
  int j = i + 1;

  while( j <= m_size ){

    m_fenwick[j] += n;
    j += ( j & -j );

  }

  return;
  
}

xtemplate <typename T> inline const T& BIT<T>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename T> 
T BIT<T>::InitialSegmentSum( const int& i_final ) const
{

  T sum = 0;
  int j = ( i_final < m_size ? i_final : m_size - 1 ) + 1;

  while( j > 0 ){

    sum += m_fenwick[j];
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename T> inline T BIT<T>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }


template <typename T>
int BIT<T>::BinarySearch( const T& n ) const
{

  int power = m_power;
  int j = 0;
  T sum{};
  T sum_next{};
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next += m_fenwick[j_next];

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

template <typename T> inline int BIT<T>::BinarySearch( const int& i_start , const T& n ) const { return max( i_start , BinarySearch( InitialSegmentSum( i_start ) + n ) ); }
