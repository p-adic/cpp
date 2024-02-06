// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U> inline BIT<U>::BIT( const int& size ) : m_size( size ) , m_fenwick( m_size + 1 ) , m_power( 1 ) { static_assert( ! is_same<U,int>::value ); while( m_power < m_size ){ m_power <<= 1; } }

template <typename U>
BIT<U>::BIT( const vector<U>& a ) : BIT( a.size() )
{

  for( int j = 1 ; j <= m_size ; j++ ){

    U& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i > i_lim ){

      fenwick_j += m_fenwick[i];
      i -= ( i & -i );

    }

  }

}

template <typename U> inline void BIT<U>::Set( const int& i , const U& u ) { Add( i , u - IntervalSum( i , i ) ); }
template <typename U> inline void BIT<U>::Set( const vector<U>& a ) { *this = BIT<U>{ a }; }
template <typename U> inline void BIT<U>::Initialise( const int& size ) { *this = BIT<U>( size ); }

template <typename U> inline BIT<U>& BIT<U>::operator+=( const vector<U>& a ) { BIT<U> a_copy{ a }; assert( m_size == a.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ m_fenwick[j] += a.m_fenwick[j]; } return *this; }

template <typename U>
void BIT<U>::Add( const int& i , const U& u )
{
  
  assert( 0 <= i && i < m_size );
  int j = i + 1;

  while( j <= m_size ){

    m_fenwick[j] += u;
    j += ( j & -j );

  }

  return;
  
}

template <typename U> inline const int& BIT<U>::size() const noexcept { return m_size; }
template <typename U> inline U BIT<U>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return IntervalSum( i , i ); }
template <typename U> inline U BIT<U>::Get( const int& i ) const { return operator[]( i ); }
template <typename U> inline const U& BIT<U>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename U> 
U BIT<U>::InitialSegmentSum( const int& i_final ) const
{

  U sum = 0;
  int j = ( i_final < m_size ? i_final : m_size - 1 ) + 1;

  while( j > 0 ){

    sum += m_fenwick[j];
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename U> inline U BIT<U>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }


template <typename U>
int BIT<U>::BinarySearch( const U& u ) const
{

  int power = m_power;
  int j = 0;
  U sum{};
  U sum_next{};
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next += m_fenwick[j_next];

      if( sum_next < u ){
	
	sum = sum_next;
	j = j_next;

      } else {

	sum_next = sum;
	
      }
      
    }
    
    power >>= 1;

  }

  // InitialSegmentSum( i )がu未満となるiが存在するならばjはその最大値に1を足したものとなり、
  // InitialSegmentSum( i )がu未満となるiが存在しないならばj=0となり、
  // いずれの場合もInitialSegmentSum( i )がu以上となるiが存在するならば
  // jはそのような最小のiと等しい。
  return j;

}

template <typename U> inline int BIT<U>::BinarySearch( const int& i_start , const U& u ) const { return max( i_start , BinarySearch( InitialSegmentSum( i_start - 1 ) + u ) ); }
