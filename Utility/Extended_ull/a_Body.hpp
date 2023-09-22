// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull() noexcept : m_n() , m_is_zero( true ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> template <SFINAE_FOR_EXTENDED_ULL()> inline constexpr Extended_ull<UINT,digit>::Extended_ull( T n0 ) noexcept : m_n{ UINT( n0 ) , UINT( 0 ) } , m_is_zero( n0 == 0 ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> template <SFINAE_FOR_EXTENDED_ULL()> inline constexpr Extended_ull<UINT,digit>::Extended_ull( T n0 , T n1 ) noexcept : m_n{ UINT( n0 ) , UINT( n1 ) } , m_is_zero( n0 == 0 && n1 == 0 ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( const UINT ( &n )[2] ) noexcept : m_n{ n[0] , n[1] } , m_is_zero( m_n[0] == 0 && m_n[1] == 0 ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( UINT ( &&n )[2] ) noexcept : m_n{ move( n[0] ) , move( n[1] ) } , m_is_zero( m_n[0] == 0 && m_n[1] == 0 ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( const Extended_ull<UINT,digit>& n ) noexcept : m_n{ n.m_n[0] , n.m_n[1] } , m_is_zero( n.m_is_zero ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( Extended_ull<UINT,digit>&& n ) noexcept : m_n{ move( n.m_n[0] ) , move( n.m_n[1] ) } , m_is_zero( n.m_is_zero ) { STATIC_ASSERT_FOR_EXTENDED_ULL; }

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator=( const Extended_ull<UINT,digit>& n ) noexcept { m_n[0] = n.m_n[0]; m_n[1] = n.m_n[1]; m_is_zero = n.m_is_zero; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator=( Extended_ull<UINT,digit>&& n ) noexcept { m_n[0] = move( n.m_n[0] ); m_n[1] = move( n.m_n[1] ); m_is_zero = n.m_is_zero; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator+=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator+( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator-=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator-( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator*=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator*( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator/=( const Extended_ull<UINT,digit>& n ) { return *this = Quotient( n ); }

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator%=( const Extended_ull<UINT,digit>& n )
{

  assert( !n.m_is_zero );
  Extended_ull<UINT,digit> answer{};
  int l = 0;
  int r = ( digit << 1 );

  while( l + 1 < r ){

    int m = ( l + r ) >> 1;
    ( ( *this >> m ) >= n ? l : r ) = m;

  }

  Extended_ull<UINT,digit> power_n = n << l;

  for( int d = l ; d >= 0 ; d-- ){

    if( *this >= power_n ){

      *this -= power_n;

    }

    power_n >>= 1;

  }

  m_is_zero = m_n[0] == 0 && m_n[1] == 0;
  return *this;

}

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator&=( const Extended_ull<UINT,digit>& n ) noexcept { if( !m_is_zero && n.m_is_zero ){ return operator=( n ); } m_n[0] &= n.m_n[0]; m_n[1] &= n.m_n[1]; m_is_zero = m_n[0] == 0 && m_n[1] == 0; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator|=( const Extended_ull<UINT,digit>& n ) noexcept { if( !n.m_is_zero ){ if( m_is_zero ){ return operator=( n ); }  m_n[0] |= n.m_n[0]; m_n[1] |= n.m_n[1]; m_is_zero = m_is_zero || n.m_is_zero; } return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator^=( const Extended_ull<UINT,digit>& n ) noexcept { if( !n.m_is_zero ){ if( !m_is_zero ){ return operator=( n ); } m_n[0] ^= n.m_n[0]; m_n[1] ^= n.m_n[1]; m_is_zero = m_n[0] == 0 && m_n[1] == 0; } return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator<<=( const int& n ) noexcept { m_is_zero || n == 0 ? m_is_zero : n < digit ? ( ( m_n[1] <<= n ) |= ( m_n[0] >> ( digit - n ) ) , m_n[0] <<= n , m_is_zero = m_n[0] == 0 && m_n[1] == 0 ) : n < ( digit << 1 ) ? ( m_n[1] = ( m_n[0] << ( n - digit ) ) , m_n[0] = 0 , m_is_zero = m_n[1] == 0 ) : ( m_n[1] = m_n[0] = 0 , m_is_zero = true ); return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator>>=( const int& n ) noexcept { m_is_zero || n == 0 ? m_is_zero : n < digit ? ( ( m_n[0] >>= n ) |= ( m_n[1] << ( digit - n ) ) , m_n[1] >>= n , m_is_zero = m_n[0] == 0 && m_n[1] == 0 ) : n < ( digit << 1 ) ? ( m_n[0] = ( m_n[1] >> ( n - digit ) ) , m_n[1] = 0 , m_is_zero = m_n[0] == 0 ) : ( m_n[0] = m_n[1] = 0 , m_is_zero = true ); return *this; }


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator++() noexcept { m_is_zero = ++m_n[0] == 0 ? ++m_n[1] == 0 : false; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator--() noexcept { if( m_n[0]-- == 0 ){ m_n[1]--; } m_is_zero = m_n[0] == 0 && m_n[1] == 0; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator++( int ) noexcept { const Extended_ull<UINT,digit> answer = *this; operator++(); return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator--( int ) noexcept { const Extended_ull<UINT,digit> answer = *this; operator--(); return answer; }


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator+( const Extended_ull<UINT,digit>& n ) const noexcept { if( m_is_zero ){ return n; } if( n.m_is_zero ){ return *this; } Extended_ull<UINT,digit> answer = Sum( m_n[0] , n.m_n[0] ); answer.m_n[1] += m_n[1] + n.m_n[1]; answer.m_is_zero = answer.m_n[0] == 0 && answer.m_n[1] == 0; return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator-() const noexcept { return m_is_zero ? *this : ++( operator~() ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator-( const Extended_ull<UINT,digit>& n ) const noexcept { return operator+( -n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator*( const Extended_ull<UINT,digit>& n ) const noexcept { if( m_is_zero ){ return *this; } if( n.m_is_zero ){ return n; } Extended_ull<UINT,digit> answer = Prod( m_n[0] , n.m_n[0] ); answer.m_n[1] += m_n[1] * n.m_n[0] + m_n[0] * n.m_n[1]; answer.m_is_zero = answer.m_n[0] == 0 && answer.m_n[1] == 0; return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator/( const Extended_ull<UINT,digit>& n ) const { return move( Extended_ull<UINT,digit>( *this ) /= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator%( const Extended_ull<UINT,digit>& n ) const { return move( Extended_ull<UINT,digit>( *this ) %= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator~() const noexcept { return Extended_ull<UINT,digit>( ~m_n[0] , ~m_n[1] ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator&( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer &= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator|( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer |= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator^( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer ^= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator<<( const int& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer <<= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator>>( const int& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer >>= n ); }


template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator==( const Extended_ull<UINT,digit>& n ) const noexcept { return ( m_is_zero && n.m_is_zero ) || ( m_n[0] == n.m_n[0] && m_n[1] == n.m_n[1] ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator==( const ull& n ) const noexcept { return n == 0 ? m_is_zero : ( m_n[0] == n && m_n[1] == 0 ); }
template <typename UINT , int digit> template <typename T> inline constexpr bool Extended_ull<UINT,digit>::operator!=( const T& n ) const noexcept { return !( *this == n ); }
template <typename UINT , int digit> template <typename T> inline constexpr bool Extended_ull<UINT,digit>::operator<=( const T& n ) const noexcept { return !( *this > n ); }
template <typename UINT , int digit> template <typename T> inline constexpr bool Extended_ull<UINT,digit>::operator>=( const T& n ) const noexcept { return !( *this < n ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator<( const Extended_ull<UINT,digit>& n ) const noexcept { return ( m_is_zero && !n.m_is_zero ) || m_n[1] < n.m_n[1] || ( m_n[1] == n.m_n[1] && m_n[0] < n.m_n[0] ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator<( const ull& n ) const noexcept { return n == 0 ? m_is_zero : ( m_n[1] == 0 && m_n[0] < n ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator>( const Extended_ull<UINT,digit>& n ) const noexcept { return n < *this; }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator>( const ull& n ) const noexcept { return n == 0 ? !m_is_zero : ( m_n[1] > 0 || m_n[0] > n ); }


template <typename UINT , int digit> inline constexpr const UINT& Extended_ull<UINT,digit>::GetLowerDigit() const noexcept { return m_n[0]; }
template <typename UINT , int digit> inline constexpr const UINT& Extended_ull<UINT,digit>::GetUpperDigit() const noexcept { return m_n[1]; }

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Quotient( const Extended_ull<UINT,digit>& n )
{

  assert( !n.m_is_zero );
  Extended_ull<UINT,digit> answer{};
  int l = 0;
  int r = ( digit << 1 );

  while( l + 1 < r ){

    int m = ( l + r ) >> 1;
    ( ( *this >> m ) >= n ? l : r ) = m;

  }

  Extended_ull<UINT,digit> power = Extended_ull<UINT,digit>( 1 ) << l;
  Extended_ull<UINT,digit> power_n = n << l;

  for( int d = l ; d >= 0 ; d-- ){

    if( *this >= power_n ){

      *this -= power_n;
      answer |= power;

    }

    power_n >>= 1;
    power >>= 1;

  }

  return answer;

}

template <typename UINT , int digit> inline constexpr UINT Extended_ull<UINT,digit>::Sqrt() const noexcept
{

  constexpr const UINT UINT_max = ~( UINT( 0 ) ); 
  constexpr const Extended_ull<UINT,digit> threshold{ 1 , UINT_max - 1 };
  
  if( threshold <= *this ){

    return UINT_max;

  }
  
  UINT l = 0;
  UINT r = UINT_max;

  while( l + 1 < r ){

    UINT m = ( ( l + r ) >> 1 );
    ( Extended_ull<UINT,digit>::Prod( m , m ) <= *this ? l : r ) = move( m );

  }
  
  return l;

}

template <typename UINT , int digit> inline constexpr ull Extended_ull<UINT,digit>::Cast() const noexcept
{

  if constexpr( is_same<UINT,ull>::value ){

      return m_n[0];
    
    } else {

    return m_n[0].Cast();

  }

}


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Sum( const UINT& n0 , const UINT& n1 ) noexcept
{
  
  if constexpr ( is_same<UINT,ull>::value ){

      constexpr const ull digit_half = digit >> 1;
      constexpr const ull low_bit = ( ull( 1 ) << digit_half ) - 1;
      ull temp[2] = {
	( n0 & low_bit ) + ( n1 & low_bit ) ,
	( n0 >> digit_half ) + ( n1 >> digit_half )
      };
      temp[1] += ( temp[0] >> digit_half );
      ( temp[0] &= low_bit ) |= ( temp[1] << digit_half );
      temp[1] >>= digit_half;
      return Extended_ull<UINT,digit>( move( temp ) );

    } else {

    UINT temp[2] = {
      UINT::Sum( n0.m_n[0] , n1.m_n[0] ) ,
      UINT::Sum( n0.m_n[1] , n1.m_n[1] )
    };
    temp[1] += temp[0].m_n[1];
    temp[0].m_n[1] = move( temp[1].m_n[0] );
    temp[1].m_n[0] = move( temp[1].m_n[1] );
    temp[1].m_n[1] = 0;
    temp[0].m_is_zero = temp[0].m_n[0] == 0 && temp[0].m_n[1] == 0;
    temp[1].m_is_zero = temp[1].m_n[0] == 0 && temp[1].m_n[1] == 0;
    return Extended_ull<UINT,digit>( move( temp ) );

  }

}

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Prod( const UINT& n0 , const UINT& n1 ) noexcept
{
  if constexpr ( is_same<UINT,ull>::value ){

      constexpr const ull digit_half = digit >> 1;
      constexpr const ull low_bit = ( ull( 1 ) << digit_half ) - 1;
      const ull n0_copy[2] = { n0 & low_bit , n0 >> digit_half };
      const ull n1_copy[2] = { n1 & low_bit , n1 >> digit_half };
      ull temp0[2] = { n0_copy[0] * n1_copy[0] , n0_copy[1] * n1_copy[1] };
      ull temp1[2] = { n0_copy[0] * n1_copy[1] , n0_copy[1] * n1_copy[0] };
      temp0[1] += ( temp1[0] >> digit_half ) + ( temp1[1] >> digit_half );
      ( temp1[1] &= low_bit ) += ( temp1[0] &= low_bit ) + ( temp0[0] >> digit_half );
      temp0[1] += temp1[1] >> digit_half;
      ( temp0[0] &= low_bit ) |= ( temp1[1] << digit_half );
      return Extended_ull<UINT,digit>( move( temp0 ) );

    } else {

    UINT temp0[2] = { UINT::Prod( n0.m_n[0] , n1.m_n[0] ) , UINT::Prod( n0.m_n[1] , n1.m_n[1] ) };
    UINT temp1[2] = { UINT::Prod( n0.m_n[0] , n1.m_n[1] ) , UINT::Prod( n0.m_n[1] , n1.m_n[0] ) };
    temp0[1] += UINT::Sum( temp1[0].m_n[1] , temp1[1].m_n[1] );
    temp1[1] = UINT::Sum( temp1[0].m_n[0] , temp1[1].m_n[0] );
    temp1[1] += temp0[0].m_n[1];
    temp0[1] += temp1[1].m_n[1];
    temp0[0].m_n[1] = move( temp1[1].m_n[0] );
    temp0[0].m_is_zero = temp0[0].m_n[0] == 0 && temp0[0].m_n[1] == 0;
    return Extended_ull<UINT,digit>( move( temp0 ) );
    
  }

}

template <typename UINT , int digit> inline constexpr void Extended_ull<UINT,digit>::swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept { swap( n0.m_n , n1.m_n ); swap( n0.m_is_zero , n1.m_is_zero ); }

template <typename UINT , int digit> inline constexpr void swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept { Extended_ull<UINT,digit>::swap( n0 , n1 ); }


template <typename ULL> inline ULL stoeull( string s , const vector<ULL>& ten_power , const int& length )
{

  if constexpr ( is_same<ULL,ull>::value ){

      return stoull( s );

    } else {

    using UINT = typename ULL::base;
    static vector<UINT> ten_power_sub = { 1 };
    static int length_sub = 1;
    const int size = s.size();
    const int size_half0 = size / 2;
    const int size_half1 = size - size_half0;

    while( size_half0 >= length_sub ){

      assert( length_sub < length );
      ten_power_sub.push_back( ten_power[length_sub].GetLowerDigit() );
      length_sub++;

    }
    
    return size_half0 > 0 ? ULL::Prod( stoeull<UINT>( s.substr( 0 , size_half1 ) , ten_power_sub , length_sub ) , ten_power_sub[size_half0] ) + stoeull<UINT>( s.substr( size_half1 ) , ten_power_sub , length_sub ) : ULL( stoeull<UINT>( move( s ) , ten_power_sub , length_sub ) );

  }

}

template <typename ULL> inline ULL stoeull( string s )
{

  if constexpr ( is_same<ULL,ull>::value ){

      return stoull( s );

    } else {

    using UINT = typename ULL::base;
    static vector<UINT> ten_power = { 1 };
    static int length = 1;
    const int size = s.size();
    const int size_half0 = size / 2;
    const int size_half1 = size - size_half0;

    while( size_half0 >= length ){

      ten_power.push_back( ten_power.back() * 10 );
      length++;

    }
    
    return size_half0 > 0 ? ULL::Prod( stoeull<UINT>( s.substr( 0 , size_half1 ) , ten_power , length ) , ten_power[size_half0] ) + stoeull<UINT>( s.substr( size_half1 ) , ten_power , length ) : ULL( stoeull<UINT>( move( s ) , ten_power , length ) );

  }

}


template <typename UINT , int digit , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Extended_ull<UINT,digit>& n )
{

  string temp;
  is >> temp;
  n = stoeull<Extended_ull<UINT,digit> >( move( temp ) );
  return is;

}

template <typename UINT , int digit> inline string to_string( Extended_ull<UINT,digit> n )
{

  list<char> temp{};
  static const Extended_ull<UINT,digit> ten{ 10 };

  while( n != 0 ){

    Extended_ull<UINT,digit> n_div = n.Quotient( ten );
    temp.push_front( to_string( n.Cast() )[0] );
    n = move( n_div );
  }

  if( temp.empty() ){

    temp.push_back( '0' );

  }

  string answer = "";

  for( auto itr = temp.begin() , end = temp.end() ; itr != end ; itr++ ){

    answer += *itr;

  }

  return answer;

}

template <typename UINT , int digit , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Extended_ull<UINT,digit>& n ) { return os << to_string( n ); }

