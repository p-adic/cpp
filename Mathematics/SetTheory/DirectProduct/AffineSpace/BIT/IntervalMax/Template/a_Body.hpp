// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename M_T> inline IdempotentMonoidBIT<T,M_T>::IdempotentMonoidBIT( M_T m_T , T e_T , const int& size ) : m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_size( size ) , m_a( m_size , m_e_T ) , m_fenwick_0( m_size + 1 , m_e_T ) , m_fenwick_1( m_size + 1 , m_e_T ) , m_power( 1 ) { static_assert( is_invocable_r_v<T,M_T,T,T> ); while( m_power < m_size ){ m_power <<= 1; } }

template <typename T , typename M_T> inline IdempotentMonoidBIT<T,M_T>::IdempotentMonoidBIT( M_T m_T , T e_T , vector<T> a ) :  m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_size( a.size() ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 ) , m_fenwick_1( m_size + 1 ) , m_power( 1 )
{

  static_assert( is_invocable_r_v<T,M_T,T,T> );
  
  for( int i = 0 ; i < m_size ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_m_T( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = m_size - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , m_size + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

  while( m_power < m_size ){

    m_power <<= 1;

  }

}

template <typename T , typename M_T> inline IdempotentMonoidBIT<T,M_T>& IdempotentMonoidBIT<T,M_T>::operator=( IdempotentMonoidBIT<T,M_T>&& a ) { m_m_T = move( a.m_m_T ); m_e_T = move( a.m_e_T ); m_size = move( a.m_size ); m_a = move( a.m_a ); m_fenwick_0 = move( a.m_fenwick_0 ); m_fenwick_1 = move( a.m_fenwick_1 ); m_power = a.m_power; return *this; }

template <typename T , typename M_T> inline const T& IdempotentMonoidBIT<T,M_T>::operator[]( const int& i ) const { assert( i < m_size ); return m_a[i]; } 
template <typename T , typename M_T> inline const T& IdempotentMonoidBIT<T,M_T>::Get( const int& i ) const { return operator[]( i ); } 
template <typename T , typename M_T> inline const T& IdempotentMonoidBIT<T,M_T>::LSBSegmentSum( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; }

template <typename T , typename M_T>
T IdempotentMonoidBIT<T,M_T>::IntervalSum( const int& i_start , const int& i_final ) const
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  if( j_min > j_max ){

    return m_e_T;
  }
    
  T answer1 = m_e_T;
  int j = j_min;
  int j_next = j + ( j & -j );

  while( j_next <= j_max ){

    answer1 = m_m_T( answer1 , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  answer1 = m_m_T( answer1 , m_a[j-1] ); 
  T answer0 = m_e_T;
  j = j_max;
  j_next = j - ( j & -j );

  while( j_next >= j_min ){

    answer0 = m_m_T( m_fenwick_0[j] , answer0 );
    j = j_next;
    j_next -= ( j & -j );

  }

  return m_m_T( answer1 , answer0 );

}

template <typename T , typename M_T>
void IdempotentMonoidBIT<T,M_T>::Set( const int& i , const T& n )
{

  T& ai = m_a[i];

  if( n == m_m_T( ai , n ) ){

    Add( i , n );

  } else {
  
    int j = i + 1;

    while( j <= m_size ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_m_T( m_m_T( IntervalSum( j - lsb , i - 1 ) , n ) , IntervalSum( i + 1 , j - 1 ) ); 
      j += lsb;

    }

    j = i + 1;

    while( j > 0 ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_m_T( m_m_T( IntervalSum( j - 1 , i - 1 ) , n ) , IntervalSum( i + 1 , j + lsb - 2 ) ); 
      j -= lsb;

    }

    ai = n;

  }

  return;

}

template <typename T , typename M_T> inline void IdempotentMonoidBIT<T,M_T>::Set( vector<T>&& a ) { *this = IdempotentMonoidBIT<T,M_T>( move( m_m_T ) , move( m_e_T ) , move( a ) ); }
template <typename T , typename M_T> inline void IdempotentMonoidBIT<T,M_T>::Initialise( const int& size ) { *this = IdempotentMonoidBIT<T,M_T>( move( m_m_T ) , move( m_e_T ) , m_size ); }

template <typename T , typename M_T> inline IdempotentMonoidBIT<T,M_T>& IdempotentMonoidBIT<T,M_T>::operator+=( vector<T>&& a ) { IdempotentMonoidBIT<T,M_T> a_copy{ m_m_T , m_e_T , move( a ) }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ T& t0j = m_fenwick_0[j]; t0j = m_m_T( t0j , a_copy.m_fenwick_0[j] ); T& t1j = m_fenwick_1[j]; t1j = m_m_T( t1j , a_copy.m_fenwick_1[j] ); } }

template <typename T , typename M_T>
void IdempotentMonoidBIT<T,M_T>::Add( const int& i , const T& n ) 
{

  T& ai = m_a[i];
  ai = m_m_T( ai , n );
  int j = i + 1;

  while( j <= m_size ){

    T& tj = m_fenwick_0[j];
    tj = m_m_T( tj , n );
    j += ( j & -j );

  }

  j = i + 1;

  while( j > 0 ){

    T& tj = m_fenwick_1[j];
    tj = m_m_T( tj , n );
    j -= ( j & -j );

  }

  return;

}

template <typename T , typename M_T>
void IdempotentMonoidBIT<T,M_T>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) 
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  for( int i = j_min - 1 ; i < j_max ; i++ ){

    T& ai = m_a[i];
    ai = m_m_T( ai , n );

  }

  const int j_llim = j_min - ( j_min & -j_min );
  const int j_ulim = min( j_max + ( j_max & j_max ) , m_size + 1 );

  if( j_min <= j_max ){

    int j = j_min;

    while( j < j_ulim ){

      if( j - ( j & -j ) < j_max ){

	T& tj = m_fenwick_0[j];
	tj = m_m_T( tj , n );
  
      }

      j++;

    }

    j = j_max;

    while( j  > j_llim ){

      if( j + ( j & -j ) > j_min ){

	T& tj = m_fenwick_0[j];
	tj = m_m_T( tj , n );

      }

      j--;

    }

  }

  return;

}

template <typename T , typename M_T> inline int IdempotentMonoidBIT<T,M_T>::BinarySearch( const T& t ) const
{

  int j = 0;
  int power = m_power;
  T sum = m_e_T;
  T sum_next = m_e_T;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next = m_m_T( sum_next , m_fenwick_0[j_next] );

      if( sum_next != m_m_T( sum_next , t ) ){
	
	sum = sum_next;
	j = j_next;

      } else {

	sum_next = sum;
	
      }
      
    }
    
    power >>= 1;

  }

  // m_a[0],...,m_a[i]がt未満となるiが存在するならばjはその最大値に1を足したものとなり、
  // そのようなiが存在しないならばj=0となり、
  // いずれの場合もjはm_a[0],...,m_a[i]がt以上となる最小のiと等しい。
  return j;

}
