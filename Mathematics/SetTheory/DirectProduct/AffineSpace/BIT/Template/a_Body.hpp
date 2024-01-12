// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename M_T , typename I_T> inline AbstractBIT<T,M_T,I_T>::AbstractBIT( M_T m_T , T e_T , I_T i_T , const int& size ) : m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_i_T( move( i_T ) ) , m_size( size ) , m_fenwick( m_size + 1 , m_e_T ) , m_power( 1 ) { static_assert( is_invocable_r_v<T,M_T,T,T> && is_invocable_r_v<T,I_T,T> ); while( m_power < m_size ){ m_power <<= 1; } }
template <typename T , typename M_T , typename I_T> inline AbstractBIT<T,M_T,I_T>::AbstractBIT( M_T m_T , T e_T , I_T i_T , const vector<T>& a ) : m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_i_T( move( i_T ) ) , m_size( a.size() ) , m_fenwick( m_size + 1 ) , m_power( 1 )
{

  static_assert( is_invocable_r_v<T,M_T,T,T> && is_invocable_r_v<T,I_T,T> );
  
  for( int j = 1 ; j <= m_size ; j++ ){

    T& fenwick_j = m_fenwick[j];
    int i = j - 1;
    fenwick_j = a[i];
    int i_lim = j - ( j & -j );

    while( i > i_lim ){

      fenwick_j = m_m_T( fenwick_j , m_fenwick[i] );
      i -= ( i & -i );

    }

  }

  while( m_power < m_size ){

    m_power <<= 1;

  }
  
}

template <typename T , typename M_T , typename I_T> inline AbstractBIT<T,M_T,I_T>& AbstractBIT<T,M_T,I_T>::operator=( AbstractBIT<T,M_T,I_T>&& a ) { m_m_T = move( a.m_m_T ); m_e_T = move( a.m_e_T ); m_i_T = move( a.m_i_T ); m_size = a.m_size; m_fenwick = move( a.m_fenwick ); m_power = a.m_power; return *this; }

template <typename T , typename M_T , typename I_T> inline void AbstractBIT<T,M_T,I_T>::Set( const int& i , const T& n ) { Add( i , m_m_T( m_i_T( IntervalSum( i , i ) ) , n ) ); }
template <typename T , typename M_T , typename I_T> inline void AbstractBIT<T,M_T,I_T>::Set( const vector<T>& a ) { *this = AbstractBIT<T,M_T,I_T>( move( m_m_T ) , move( m_e_T ) , move( m_i_T ) , a ); }
template <typename T , typename M_T , typename I_T> inline void AbstractBIT<T,M_T,I_T>::Initialise( const int& size ) { *this = AbstractBIT<T,M_T,I_T>( move( m_m_T ) , move( m_e_T ) , move( m_i_T ) , size ); }

template <typename T , typename M_T , typename I_T> inline AbstractBIT<T,M_T,I_T>& AbstractBIT<T,M_T,I_T>::operator+=( const vector<T>& a ) { AbstractBIT<T,M_T,I_T> a_copy{ m_m_T , m_e_T , m_i_T , a }; assert( m_size == a.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ m_fenwick[j] += a.m_fenwick[j]; } return *this; }

template <typename T , typename M_T , typename I_T>
void AbstractBIT<T,M_T,I_T>::Add( const int& i , const T& n )
{
  
  int j = i + 1;

  while( j <= m_size ){

    T& m_fenwick_j = m_fenwick[j];
    m_fenwick_j = m_m_T( m_fenwick_j , n );
    j += ( j & -j );

  }

  return;
  
}

template <typename T , typename M_T , typename I_T> inline T AbstractBIT<T,M_T,I_T>::operator[]( const int& i ) const { assert( i < m_size ); return IntervalSum( i , i ); }
template <typename T , typename M_T , typename I_T> inline T AbstractBIT<T,M_T,I_T>::Get( const int& i ) const { return operator[]( i ); }

template <typename T , typename M_T , typename I_T> inline const T& AbstractBIT<T,M_T,I_T>::LSBSegmentSum( const int& j ) const { assert( 0 < j && j <= m_size ); return m_fenwick[j]; }

template <typename T , typename M_T , typename I_T> 
T AbstractBIT<T,M_T,I_T>::InitialSegmentSum( const int& i_final ) const
{

  T sum = m_e_T;
  int j = min( i_final + 1 , m_size );

  while( j > 0 ){

    sum = m_m_T( sum , m_fenwick[j] );
    j -= j & -j;
    
  }

  return sum;
  
}

template <typename T , typename M_T , typename I_T> inline T AbstractBIT<T,M_T,I_T>::IntervalSum( const int& i_start , const int& i_final ) const { return m_m_T( m_i_T( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }


template <typename T , typename M_T , typename I_T>
int AbstractBIT<T,M_T,I_T>::BinarySearch( const T& n ) const
{

  int j = 0;
  int power = m_power;
  T sum = m_e_T;
  T sum_next = m_e_T;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next = m_m_T( sum_next , m_fenwick[j_next] );

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

template <typename T , typename M_T , typename I_T> inline int AbstractBIT<T,M_T,I_T>::BinarySearch( const int& i_start , const T& n ) const { return max( i_start , m_m_T( BinarySearch( InitialSegmentSum( i_start ) , n ) ) ); }
