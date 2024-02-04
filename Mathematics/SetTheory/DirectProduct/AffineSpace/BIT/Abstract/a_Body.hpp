// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Abstract/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>::AbstractBIT( ABELIAN_GROUP M , const vector<U>& a ) : m_size( a.size() ) , m_M( move( M ) ) ,m_fenwick( m_size + 1 ) , m_power( 1 )
{

  static_assert( is_same_v<U,inner_t<ABELIAN_GROUP>> );
  
  for( int j = 1 ; j <= m_size ; j++ ){

    U& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i > i_lim ){

      fenwick_j = m_M.Sum( fenwick_j , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

  while( m_power < m_size ){

    m_power <<= 1;

  }
  
}

template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractBIT<U,ABELIAN_GROUP>::Set( const vector<U>& a ) { *this = AbstractBIT<U,ABELIAN_GROUP>( move( m_M ) , a ); }

template <typename U , typename ABELIAN_GROUP> inline AbstractBIT<U,ABELIAN_GROUP>& AbstractBIT<U,ABELIAN_GROUP>::operator+=( const vector<U>& a ) { AbstractBIT<U,ABELIAN_GROUP> a_copy{ m_M , a }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ m_fenwick[j] = m_M.Sum( m_fenwick[j] , a.m_fenwick[j] ); } return *this; }

template <typename U , typename ABELIAN_GROUP>
void AbstractBIT<U,ABELIAN_GROUP>::Add( const int& i , const U& u )
{
  
  int j = i + 1;

  while( j <= m_size ){

    U& m_fenwick_j = m_fenwick[j];
    m_fenwick_j = m_M.Sum( m_fenwick_j , u );
    j += ( j & -j );

  }

  return;
  
}

template <typename U , typename ABELIAN_GROUP> inline const int& AbstractBIT<U,ABELIAN_GROUP>::size() const noexcept { return m_size; }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::operator[]( const int& i ) const { assert( i < m_size ); return IntervalSum( i , i ); }
template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractBIT<U,ABELIAN_GROUP>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename U , typename ABELIAN_GROUP> 
U AbstractBIT<U,ABELIAN_GROUP>::InitialSegmentSum( const int& i_final )
{

  U sum = m_M.Zero();
  int j = min( i_final + 1 , m_size );

  while( j > 0 ){

    sum = m_M.Sum( sum , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename U , typename ABELIAN_GROUP> inline U AbstractBIT<U,ABELIAN_GROUP>::IntervalSum( const int& i_start , const int& i_final ) { return m_M.Sum( m_M.Inverse( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }


template <typename U , typename ABELIAN_GROUP>
int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const U& u )
{

  int j = 0;
  int power = m_power;
  U sum = m_M.Zero();
  U sum_next = sum;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next = m_M.Sum( sum_next , m_fenwick[j_next] );

      if( sum_next < u ){
	
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

template <typename U , typename ABELIAN_GROUP> inline int AbstractBIT<U,ABELIAN_GROUP>::BinarySearch( const int& i_start , const U& u ) { return max( i_start , m_M.Sum( BinarySearch( InitialSegmentSum( i_start ) , u ) ) ); }
