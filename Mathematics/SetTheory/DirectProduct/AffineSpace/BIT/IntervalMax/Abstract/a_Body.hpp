// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/Abstract/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U , typename COMM_IDEM_MONOID> inline IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IdempotentMonoidBIT( COMM_IDEM_MONOID M , vector<U> a ) :  m_size( a.size() ) , m_M( move( M ) ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 ) , m_fenwick_1( m_size + 1 ) , m_power( 1 )
{

  static_assert( is_same_v<U,inner_t<COMM_IDEM_MONOID>> );
  
  for( int i = 0 ; i < m_size ; i++ ){

    int j = i + 1;
    U& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_M.Sum( m_fenwick_0[j] , fenwick_0i );
      j -= ( j & -j );

    }

  }

  for( int i = m_size - 1 ; i >= 0 ; i-- ){

    int j = i + 1;
    U& fenwick_1i = m_fenwick_1[j];
    fenwick_1i = m_a[i];
    const int j_ulim = min( j + ( j & -j ) , m_size + 1 );
    j++;

    while( j < j_ulim ){

      fenwick_1i = m_M.Sum( fenwick_1i , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

  while( m_power < m_size ){

    m_power <<= 1;

  }

}

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Set( const int& i , const U& u )
{

  U& ai = m_a[i];

  if( u == m_M.Sum( ai , u ) ){

    Add( i , u );

  } else {
  
    ai = u;
    int j = i + 1;
    int j_minus = j - ( j & -j );
    U temp_left = m_M.Sum( IntervalSum( j_minus , i - 1 ) , ai );
    U temp_right = m_M.Zero();
  
    while( j <= m_size ){

      m_fenwick_0[j] = m_M.Sum( temp_left , temp_right );
      int j_next = j + ( j & -j );
      int j_minus_next = j_next - ( j_next & -j_next );

      if( j_minus_next != j_minus - 1 ){
	// 合計O(log_2 size)
	temp_left = m_M.Sum( IntervalSum( j_minus_next , j_minus - 1 ) , temp_left );
	j_minus = j_minus_next;

      }

      // 合計O((log_2 size)^2)
      temp_right = m_M.Sum( temp_right , IntervalSum( j , j_next - 1 ) );
      j = j_next;

    }

    j = i + 1;
    int j_plus = j + ( j & -j ) - 1;
    temp_left = m_M.Zero();
    temp_right = m_M.Sum( ai , IntervalSum( j , j_plus - 1 ) );

    while( j > 0 ){

      m_fenwick_1[j] = m_M.Sum( temp_left , temp_right );
      int j_next = j - ( j & -j );
      int j_plus_next = j_next + ( j_next & -j_next ) - 1;
      // 合計O((log_2 size)^2)
      temp_left = m_M.Sum( IntervalSum( j_next - 1 , j - 2 ) , temp_left );
      j = j_next;

      if( j_plus != j_plus_next - 1 ){
	// 合計O(log_2 size)
	temp_right = m_M.Sum( temp_right , IntervalSum( j_plus , j_plus_next - 1 ) );
	j_plus = j_plus_next;

      }

    }

  }

  return;

}

template <typename U , typename COMM_IDEM_MONOID> inline void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Set( vector<U>&& a ) { *this = IdempotentMonoidBIT<U,COMM_IDEM_MONOID>( move( m_M ) , move( a ) ); }

template <typename U , typename COMM_IDEM_MONOID> inline IdempotentMonoidBIT<U,COMM_IDEM_MONOID>& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::operator+=( vector<U>&& a ) { IdempotentMonoidBIT<U,COMM_IDEM_MONOID> a_copy{ m_M , move( a ) }; assert( m_size == a_copy.m_size ); for( int j = 1 ; j <= m_size ; j++ ){ U& t0j = m_fenwick_0[j]; t0j = m_M.Sum( t0j , a_copy.m_fenwick_0[j] ); U& t1j = m_fenwick_1[j]; t1j = m_M.Sum( t1j , a_copy.m_fenwick_1[j] ); } }

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Add( const int& i , const U& u ) 
{

  U& ai = m_a[i];
  ai = m_M.Sum( ai , u );
  int j = i + 1;

  while( j <= m_size ){

    U& tj = m_fenwick_0[j];
    tj = m_M.Sum( tj , u );
    j += ( j & -j );

  }

  j = i + 1;

  while( j > 0 ){

    U& tj = m_fenwick_1[j];
    tj = m_M.Sum( tj , u );
    j -= ( j & -j );

  }

  return;

}

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IntervalAdd( const int& i_start , const int& i_final , const U& u ) 
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  for( int i = j_min - 1 ; i < j_max ; i++ ){

    U& ai = m_a[i];
    ai = m_M.Sum( ai , u );

  }

  const int j_llim = j_min - ( j_min & -j_min );
  const int j_ulim = min( j_max + ( j_max & j_max ) , m_size + 1 );

  if( j_min <= j_max ){

    int j = j_min;

    while( j < j_ulim ){

      if( j - ( j & -j ) < j_max ){

	U& tj = m_fenwick_0[j];
	tj = m_M.Sum( tj , u );
  
      }

      j++;

    }

    j = j_max;

    while( j  > j_llim ){

      if( j + ( j & -j ) > j_min ){

	U& tj = m_fenwick_0[j];
	tj = m_M.Sum( tj , u );

      }

      j--;

    }

  }

  return;

}

template <typename U , typename COMM_IDEM_MONOID> inline const int& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::size() const noexcept { return m_size; } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Get( const int& i ) const { return operator[]( i ); } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::LSBSegmentSum( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; }

template <typename U , typename COMM_IDEM_MONOID>
U IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IntervalSum( const int& i_start , const int& i_final )
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  if( j_min > j_max ){

    return m_M.Zero();
  }
    
  U answer1 = m_M.Zero();
  int j = j_min;
  int j_next = j + ( j & -j );

  while( j_next <= j_max ){

    answer1 = m_M.Sum( answer1 , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  answer1 = m_M.Sum( answer1 , m_a[j-1] ); 
  U answer0 = m_M.Zero();
  j = j_max;
  j_next = j - ( j & -j );

  while( j_next >= j_min ){

    answer0 = m_M.Sum( m_fenwick_0[j] , answer0 );
    j = j_next;
    j_next -= ( j & -j );

  }

  return m_M.Sum( answer1 , answer0 );

}

template <typename U , typename COMM_IDEM_MONOID> inline int IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::BinarySearch( const U& u )
{

  int j = 0;
  int power = m_power;
  U sum = m_M.Zero();
  U sum_next = sum;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next < m_size ){
      
      sum_next = m_M.Sum( sum_next , m_fenwick_0[j_next] );

      if( sum_next != m_M.Sum( sum_next , u ) ){
	
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
  // いずれの場合もjはm_a[0],...,m_a[i]がu以上となる最小のiと等しい。
  return j;

}
