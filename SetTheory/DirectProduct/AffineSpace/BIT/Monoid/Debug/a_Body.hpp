// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Monoid/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../../../Error/Debug/a_Body.hpp"

template <typename U , typename MONOID> inline MonoidBIT<U,MONOID>::MonoidBIT( MONOID M , const int& size , const bool& output_mode ) : MonoidBIT( M , vector<U>( size , M.One() ) , output_mode ) {}
template <typename U , typename MONOID> inline MonoidBIT<U,MONOID>::MonoidBIT( MONOID M , vector<U> a , const bool& output_mode ) : Debug( output_mode ) , m_M( move( M ) ) , m_size( a.size() ) , m_a( move( a ) ) , m_fenwick_0( m_size + 1 , m_M.One() ) , m_fenwick_1( m_fenwick_0 ) , m_power( 1 )
{

  static_assert( is_same_v<U,inner_t<MONOID>> );
  
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

  while( m_power < m_size ){

    m_power <<= 1;

  }

  static bool init = true;

  if( init ){

    if( m_output_mode ){
      
      DERR( "MonoidBITをデバッグモードで実行します。" );
      DERR( "通常のMonoidBITと比べると各種操作にO(N)かかることに" );
      DERR( "ご注意ください。" );
      DERR( "" );

    }

    init = false;

  }

  if( m_output_mode ){
      
    DERR( "MonoidBITの初期値：" );
    DERR( *this );
    DERR( "" );

  }
  
}

template <typename U , typename MONOID> template <typename...Args> inline void MonoidBIT<U,MONOID>::Initialise( Args&&... args ) { MonoidBIT<U,MONOID> temp{ move( m_M ) , forward<decay_t<Args>>( args )... }; m_size = temp.m_size; m_a = move( temp.m_a ); m_fenwick_0 = move( temp.m_fenwick_0 ); m_fenwick_1 = move( temp.m_fenwick_1 ); m_power = temp.m_power; }

template <typename U , typename MONOID>
void MonoidBIT<U,MONOID>::Set( const int& i , const U& u )
{

  if( m_output_mode ){
      
    DERR( "MonoidBITの第" , i , "成分に" , u , "を代入します。" );

  }

  U& ai = m_a[i] = u;
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
    
  if( m_output_mode ){
      
    DERR( "MonoidBITの更新後の成分：" );
    DERR( *this );
    DERR( "" );

  }

  return;

}

template <typename U , typename MONOID> inline const int& MonoidBIT<U,MONOID>::size() const noexcept { return m_size; }
template <typename U , typename MONOID> inline const U& MonoidBIT<U,MONOID>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return m_a[i]; }
template <typename U , typename MONOID> inline const U& MonoidBIT<U,MONOID>::Get( const int& i ) const { return operator[]( i ); }
template <typename U , typename MONOID> inline const U& MonoidBIT<U,MONOID>::LSBSegmentProduct( const int& j , const bool& left ) const { assert( 0 < j && j <= m_size ); return ( left ? m_fenwick_0 : m_fenwick_1 )[j]; }

template <typename U , typename MONOID>
U MonoidBIT<U,MONOID>::IntervalProduct( const int& i_start , const int& i_final )
{

  const int j_min = max( i_start + 1 , 1 );
  const int j_max = min( i_final + 1 , m_size );

  if( j_min > j_max ){

    if( m_output_mode ){
      
      DERR( "MonoidBITの区間[" , i_start , "," , i_final , "] は空であり、その総和は" , m_M.One() , "です。" );

    }

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

    answer0 = m_M.Product( m_fenwick_0[j] , answer0 );
    j = j_next;
    j_next -= ( j & -j );

  }

  answer1 = m_M.Product( move( answer1 ) , answer0 );

  if( m_output_mode ){
      
    DERR( "MonoidBITの区間[" , i_start , "," , i_final , "] における総和：" , answer1 );

  }

  return answer1;

}

template <typename U , typename MONOID> template <typename F , SFINAE_FOR_BIT_BS> inline int MonoidBIT<U,MONOID>::Search( const F& f )
{

  int j = 0;
  int power = m_power;
  U sum = m_M.One();
  U sum_next = sum;
  
  while( power > 0 ){

    int j_next = j | power;

    if( j_next <= m_size ){
      
      sum_next = m_M.Product( move( sum_next ) , m_fenwick_0[j_next] );

      if( f( sum_next , j_next - 1 ) ){

	sum_next = sum;
	
      } else {

	sum = sum_next;
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

template <typename U , typename MONOID> inline int MonoidBIT<U,MONOID>::Search( const U& u ) { return Search( [&]( const U& prod , const int& ){ return !( prod < u ); } ); }

template <class Traits , typename U , typename MONOID> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MonoidBIT<U,MONOID>& bit )
{

  auto&& size = bit.size();

  if( exec_mode == solve_mode ){

    os << "[";

  }

  for( int i = 0 ; i < size ; i++ ){

    ( i == 0 ? os : os << "," ) << bit[i];

  }

  if( exec_mode == solve_mode ){

    os << "]";

  }

  return os;

}
