// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Template/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

// BinarySearchに使う。
#include "../../../../../../Arithmetic/Power/Constexpr/a_Body.hpp"

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline const T& MonoidBIT<T,m_T,e_T,N>::g_e = e_T();

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline MonoidBIT<T,m_T,e_T,N>::MonoidBIT() : m_a() , m_fenwick_0() , m_fenwick_1() { if( m_a[0] != g_e ){ for( int i = 0 ; i < N ; i++ ){ m_a[i] = g_e; } for( int j = 1 ; j <= N ; j++ ){ m_fenwick_0[j] = m_fenwick_1[j] = g_e; } } }

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline MonoidBIT<T,m_T,e_T,N>::MonoidBIT( const T ( &a )[N] ) : m_a() , m_fenwick_0() , m_fenwick_1() 
{

  for( int i = 0 ; i < N ; i++ ){

    m_a[i] = a[i];

  }

  for( int i = 0 ; i < N ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_T( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = N - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , N + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline MonoidBIT<T,m_T,e_T,N>::MonoidBIT( T ( &&a )[N] ) : m_a() , m_fenwick_0() , m_fenwick_1() 
{

  swap( m_a , a );

  for( int i = 0 ; i < N ; i++ ){

    int j = i + 1;
    T& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_T( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = N - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    T& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , N + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_T( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline const T& MonoidBIT<T,m_T,e_T,N>::operator[]( const int& i ) const { return m_a[i]; } 
template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline const T& MonoidBIT<T,m_T,e_T,N>::Get( const int& i ) const { return m_a[i]; } 

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT>
T MonoidBIT<T,m_T,e_T,N>::IntervalProduct( const int& i_start , const int& i_final ) const 
{

  const int j_min = i_start < 0 ? 1 : i_start + 1;
  const int j_max = i_final < N ? i_final + 1 : N;

  if( j_min > j_max ){

    return g_e;
  }
    
  T answer1 = g_e;
  int j = j_min;
  int j_next = j + ( j & -j );

  while( j_next <= j_max ){

    answer1 = m_T( answer1 , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  answer1 = m_T( answer1 , m_a[j-1] ); 
  T answer0 = g_e;
  j = j_max;
  j_next = j - ( j & -j );

  while( j_next >= j_min ){

    answer0 = m_T( m_fenwick_0[j] , answer0 );
    j = j_next;
    j_next -= ( j & -j );

  }

  return m_T( answer1 , answer0 );

}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT>
void MonoidBIT<T,m_T,e_T,N>::Set( const int& i , const T& n )
{

  T& ai = m_a[i];

  if( n == m_T( ai , n ) ){

    Add( i , n );

  } else {
  
    int j = i + 1;

    while( j <= N ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalProduct( j - lsb + 1 , i - 1 ) , n ) , IntervalProduct( i + 1 , j ) ); 
      j += lsb;

    }

    j = i + 1;

    while( j > 0 ){

      const int lsb = ( j & -j );
      m_fenwick_0[j] = m_T( m_T( IntervalProduct( j , i - 1 ) , n ) , IntervalProduct( i + 1 , j + lsb - 1 ) ); 
      j -= lsb;

    }

    ai = n;

  }

  return;

}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT>
void MonoidBIT<T,m_T,e_T,N>::Set( T ( &&a )[N] )
{

  MonoidBIT<T,m_T,e_T,N> a_copy{ move( a ) };
  swap( m_a , a_copy.m_a );
  swap( m_fenwick_0 , a_copy.m_fenwick_0 );
  swap( m_fenwick_1 , a_copy.m_fenwick_1 );
  return;

}

template <TEMPLATE_ARGUMENTS_FOR_MONOID_BIT> inline int MonoidBIT<T,m_T,e_T,i_T,N>::BinarySearch( const T& t ) const
{

  int j = 0;
  int power = PowerInverse_constexpr<N>.m_val;
  T sum = g_e;
  T sum_next = g_e;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < N ){
      
      sum_next = m_T( sum_next , m_fenwick[j_next] );

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
