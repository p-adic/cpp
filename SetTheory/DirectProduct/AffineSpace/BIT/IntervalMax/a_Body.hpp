// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Algebra/Monoid/Semilattice/a_Body.hpp"

template <typename U , typename COMM_IDEM_MONOID> inline IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IdempotentMonoidBIT( COMM_IDEM_MONOID M , const int& size ) : m_M( move( M ) ) , m_size( size ) , m_a( size , m_M.One() ) , m_fenwick_0( m_size + 1 , m_M.One() ) , m_fenwick_1( m_size + 1 , m_M.One() ) , m_power( 1 ) { Construct(); }

template <typename U , typename COMM_IDEM_MONOID> inline IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IdempotentMonoidBIT( COMM_IDEM_MONOID M , vector<U> a ) : m_M( move( M ) ) , m_size( a.size() ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 ) , m_fenwick_1( m_size + 1 ) , m_power( 1 )
{

  Construct();
  
  for( int i = 0 ; i < m_size ; i++ ){

    int j = i + 1;
    U& fenwick_0i = m_fenwick_0[j];
    fenwick_0i = m_a[i];
    const int j_llim = j - ( j & -j );
    j--;

    while( j > j_llim ){

      fenwick_0i = m_M.Product( m_fenwick_0[j] , fenwick_0i );
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

      fenwick_1i = m_M.Product( move( fenwick_1i ) , m_fenwick_1[j] );
      j += ( j & -j );

    }

  }

}

template <typename U> template <typename...Args> inline IntervalMaxBIT<U>::IntervalMaxBIT( const U& zero_U , Args&&... args ) : IdempotentMonoidBIT<U,MaxSemilattice<U>>( MaxSemilattice<U>( zero_U ) , forward<Args>( args )... ) {}
template <typename U> template <typename...Args> inline IntervalMinBIT<U>::IntervalMinBIT( const U& infty_U , Args&&... args ) : IdempotentMonoidBIT<U,MinSemilattice<U>>( MinSemilattice<U>( infty_U ) , forward<Args>( args )... ) {}

template <typename U , typename COMM_IDEM_MONOID> inline void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Construct()
{

  static_assert( is_same_v<U,inner_t<COMM_IDEM_MONOID>> );
  
  while( m_power < m_size ){

    m_power <<= 1;

  }

}

template <typename U , typename COMM_IDEM_MONOID> template <typename...Args> inline void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Initialise( Args&&... args ) { IdempotentMonoidBIT<U,COMM_IDEM_MONOID> temp{ m_M , forward<Args>( args )... };  m_size = temp.m_size; m_a = move( temp.m_a ); m_fenwick_0 = move( temp.m_fenwick_0 ); m_fenwick_1 = move( temp.m_fenwick_1 ); m_power = temp.m_power; }

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Set( const int& i , const U& u )
{

  U& ai = m_a[i];

  if( u == m_M.Product( ai , u ) ){

    Multiply( i , u );

  } else {
  
    ai = u;
    int j = i + 1;
    int j_minus = j - ( j & -j );
    U temp_left = m_M.Product( IntervalProduct( j_minus , i - 1 ) , ai );
    U temp_right = m_M.One();
  
    while( j <= m_size ){

      m_fenwick_0[j] = m_M.Product( temp_left , temp_right );
      int j_next = j + ( j & -j );
      int j_minus_next = j_next - ( j_next & -j_next );

      if( j_minus_next != j_minus - 1 ){
	// 合計O(log_2 size)
	temp_left = m_M.Product( IntervalProduct( j_minus_next , j_minus - 1 ) , temp_left );
	j_minus = j_minus_next;

      }

      // 合計O((log_2 size)^2)
      temp_right = m_M.Product( move( temp_right ) , IntervalProduct( j , j_next - 1 ) );
      j = j_next;

    }

    j = i + 1;
    int j_plus = j + ( j & -j ) - 1;
    temp_left = m_M.One();
    temp_right = m_M.Product( ai , IntervalProduct( j , j_plus - 1 ) );

    while( j > 0 ){

      m_fenwick_1[j] = m_M.Product( temp_left , temp_right );
      int j_next = j - ( j & -j );
      int j_plus_next = j_next + ( j_next & -j_next ) - 1;
      // 合計O((log_2 size)^2)
      temp_left = m_M.Product( IntervalProduct( j_next - 1 , j - 2 ) , temp_left );
      j = j_next;

      if( j_plus != j_plus_next - 1 ){
	// 合計O(log_2 size)
	temp_right = m_M.Product( move( temp_right ) , IntervalProduct( j_plus , j_plus_next - 1 ) );
	j_plus = j_plus_next;

      }

    }

  }

  return;

}

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Multiply( const int& i , const U& u ) 
{

  U& ai = m_a[i];
  ai = m_M.Product( move( ai ) , u );
  int j = i + 1;

  while( j <= m_size ){

    U& tj = m_fenwick_0[j];
    tj = m_M.Product( move( tj ) , u );
    j += ( j & -j );

  }

  j = i + 1;

  while( j > 0 ){

    U& tj = m_fenwick_1[j];
    tj = m_M.Product( move( tj ) , u );
    j -= ( j & -j );

  }

  return;

}

template <typename U> void IntervalMaxBIT<U>::SetMax( const int& i , const U& u ) { this->Multiply( i , u ); }
template <typename U> void IntervalMinBIT<U>::SetMin( const int& i , const U& u ) { this->Multiply( i , u ); }

template <typename U , typename COMM_IDEM_MONOID>
void IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IntervalMultiply( const int& i_start , const int& i_final , const U& u ) 
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  for( int i = j_min - 1 ; i < j_max ; i++ ){

    U& ai = m_a[i];
    ai = m_M.Product( move( ai ) , u );

  }

  const int j_llim = j_min - ( j_min & -j_min );
  const int j_ulim = min( j_max + ( j_max & j_max ) , m_size + 1 );

  if( j_min <= j_max ){

    int j = j_min;

    while( j < j_ulim ){

      if( j - ( j & -j ) < j_max ){

	U& tj = m_fenwick_0[j];
	tj = m_M.Product( move( tj ) , u );
  
      }

      j++;

    }

    j = j_max;

    while( j  > j_llim ){

      if( j + ( j & -j ) > j_min ){

	U& tj = m_fenwick_0[j];
	tj = m_M.Product( move( tj ) , u );

      }

      j--;

    }

  }

  return;

}

template <typename U> void IntervalMaxBIT<U>::IntervalSetMax( const int& i_start , const int& i_final , const U& u ) { this->IntervalMultiply( i_start , i_final , u ); }
template <typename U> void IntervalMinBIT<U>::IntervalSetMin( const int& i_start , const int& i_final , const U& u ) { this->IntervalMultiply( i_start , i_final , u ); }

template <typename U , typename COMM_IDEM_MONOID> inline const int& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::size() const noexcept { return m_size; } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Get( const int& i ) const { return operator[]( i ); } 
template <typename U , typename COMM_IDEM_MONOID> inline const U& IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::LSBSegmentProduct( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; }
template <typename U> const U& IntervalMaxBIT<U>::LSBSegmentMax( const int& j , const bool& left ) const { return this->LSBSegmentProduct( j , left ); }
template <typename U> const U& IntervalMinBIT<U>::LSBSegmentMin( const int& j , const bool& left ) const { return this->LSBSegmentProduct( j , left ); }

template <typename U , typename COMM_IDEM_MONOID>
U IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  if( j_min > j_max ){

    return m_M.One();
  }
    
  U answer1 = m_M.One();
  int j = j_min;
  int j_next = j + ( j & -j );

  while( j_next <= j_max ){

    answer1 = m_M.Product( move( answer1 ) , m_fenwick_1[j] );
    j = j_next;
    j_next += ( j & -j );

  }

  answer1 = m_M.Product( move( answer1 ) , m_a[j-1] ); 
  U answer0 = m_M.One();
  j = j_max;
  j_next = j - ( j & -j );

  while( j_next >= j_min ){

    // 可換性を使った。
    answer0 = m_M.Product( move( answer0 ) , m_fenwick_0[j] );
    j = j_next;
    j_next -= ( j & -j );

  }

  return m_M.Product( move( answer1 ) , answer0 );

}

template <typename U> U IntervalMaxBIT<U>::IntervalMax( const int& i_start , const int& i_final ) { return this->IntervalProduct( i_start , i_final ); }
template <typename U> U IntervalMinBIT<U>::IntervalMin( const int& i_start , const int& i_final ) { return this->IntervalProduct( i_start , i_final ); }

template <typename U , typename COMM_IDEM_MONOID> template <typename F , SFINAE_FOR_BIT_BS> inline int IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Search( const F& f )
{

  int j = 0;
  int power = m_power;
  U product = m_M.One();
  U product_next = product;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next <= m_size ){
      
      product_next = m_M.Product( product_next , m_fenwick_0[j_next] );

      if( f( product_next , j_next - 1 ) ){
	
	product_next = product;
	
      } else {

	product = product_next;
	j = j_next;

      }
      
    }
    
    power >>= 1;

  }

  // f( IntervalProduct( 0 , i ) , i )がfalseとなるiが存在するならば
  // jはその最大値に1を足したものとなり、そのようなiが存在しないならばj=0となる。
  // いずれの場合もjはf( IntervalProduct( 0 , i ) , i )がtrueとなる最小のiと等しい。
  return j;

}

template <typename U , typename COMM_IDEM_MONOID> inline int IdempotentMonoidBIT<U,COMM_IDEM_MONOID>::Search( const U& u ) { return Search( [&]( const U& prod , const int& ){ return prod == m_M.Product( prod , u ); } ); }
