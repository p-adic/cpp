// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull() noexcept : m_n() {}
template <typename UINT , int digit> template <SFINAE_FOR_EXTENDED_ULL()> inline constexpr Extended_ull<UINT,digit>::Extended_ull( T n0 ) noexcept : m_n{ UINT( n0 ) , UINT( 0 ) } {}
template <typename UINT , int digit> template <SFINAE_FOR_EXTENDED_ULL()> inline constexpr Extended_ull<UINT,digit>::Extended_ull( T n0 , T n1 ) noexcept : m_n{ UINT( n0 ) , UINT( n1 ) } {}
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( const UINT ( &n )[2] ) noexcept : m_n{ n[0] , n[1] } {}
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( UINT ( &&n )[2] ) noexcept : m_n{ move( n[0] ) , move( n[1] ) } {}
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( const Extended_ull<UINT,digit>& n ) noexcept : m_n{ n.m_n[0] , n.m_n[1] } {}
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>::Extended_ull( Extended_ull<UINT,digit>&& n ) noexcept : m_n{ move( n.m_n[0] ) , move( n.m_n[1] ) } {}

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator=( const Extended_ull<UINT,digit>& n ) noexcept { m_n[0] = n.m_n[0]; m_n[1] = n.m_n[1]; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator=( Extended_ull<UINT,digit>&& n ) noexcept { m_n[0] = move( n.m_n[0] ); m_n[1] = move( n.m_n[1] ); return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator+=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator+( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator-=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator-( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator*=( const Extended_ull<UINT,digit>& n ) noexcept { return operator=( operator*( n ) ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator/=( const Extended_ull<UINT,digit>& n ) { return *this = Quotient( n ); }

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator%=( const Extended_ull<UINT,digit>& n )
{

  assert( n != 0 );
  constexpr const Extended_ull<UINT,digit> full_power = Extended_ull<UINT,digit>( 1 ) << ConstantsForExtended_ull<UINT,digit>::g_full_digit_minus;
  Extended_ull<UINT,digit> power = full_power;
  
  for( int d = ConstantsForExtended_ull<UINT,digit>::g_full_digit_minus ; d >= 0 ; d-- ){

    if( ( *this >> d ) >= n ){

      *this -= ( n << d );

    }

    power >>= 1;

  }
  
  return *this;

}

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator&=( const Extended_ull<UINT,digit>& n ) noexcept { m_n[0] &= n.m_n[0]; m_n[1] &= n.m_n[1]; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator|=( const Extended_ull<UINT,digit>& n ) noexcept { m_n[0] |= n.m_n[0]; m_n[1] |= n.m_n[1]; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator^=( const Extended_ull<UINT,digit>& n ) noexcept { m_n[0] ^= n.m_n[0]; m_n[1] ^= n.m_n[1]; return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator<<=( const int& n ) noexcept
{ n == 0 ? m_n[1] : n < digit ? ( ( m_n[1] <<= n ) |= ( m_n[0] >> ( digit - n ) ) , m_n[0] <<= n ) : n < ConstantsForExtended_ull<UINT,digit>::g_full_digit ? ( m_n[1] = ( m_n[0] << ( n - digit ) ) , m_n[0] = 0 ) : ( m_n[1] = m_n[0] = 0 ); return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator>>=( const int& n ) noexcept { n == 0 ? m_n[0] : n < digit ? ( ( m_n[0] >>= n ) |= ( m_n[1] << ( digit - n ) ) , m_n[1] >>= n ) : n < ConstantsForExtended_ull<UINT,digit>::g_full_digit ? ( m_n[0] = ( m_n[1] >> ( n - digit ) ) , m_n[1] = 0 ) : ( m_n[0] = m_n[1] = 0 ); return *this; }


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator++() noexcept { if( ++m_n[0] == 0 ){ ++m_n[1]; } return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit>& Extended_ull<UINT,digit>::operator--() noexcept { if( m_n[0]-- == 0 ){ m_n[1]--; } return *this; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator++( int ) noexcept { const Extended_ull<UINT,digit> answer = *this; if( ++m_n[0] == 0 ){ ++m_n[1]; } return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator--( int ) noexcept { const Extended_ull<UINT,digit> answer = *this; if( m_n[0]-- == 0 ){ m_n[1]--; } return answer; }


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator+( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = Sum( m_n[0] , n.m_n[0] ); answer.m_n[1] += m_n[1] + n.m_n[1]; return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator-() const noexcept { return ++( operator~() ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator-( const Extended_ull<UINT,digit>& n ) const noexcept { return operator+( -n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator*( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = Prod( m_n[0] , n.m_n[0] ); answer.m_n[1] += m_n[1] * n.m_n[0] + m_n[0] * n.m_n[1]; return answer; }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator/( const Extended_ull<UINT,digit>& n ) const { return move( Extended_ull<UINT,digit>( *this ) /= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator%( const Extended_ull<UINT,digit>& n ) const { return move( Extended_ull<UINT,digit>( *this ) %= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator~() const noexcept { return Extended_ull<UINT,digit>( ~m_n[0] , ~m_n[1] ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator&( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer &= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator|( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer |= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator^( const Extended_ull<UINT,digit>& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer ^= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator<<( const int& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer <<= n ); }
template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::operator>>( const int& n ) const noexcept { Extended_ull<UINT,digit> answer = *this; return move( answer >>= n ); }


template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator==( const Extended_ull<UINT,digit>& n ) const noexcept { return m_n[0] == n.m_n[0] && m_n[1] == n.m_n[1]; }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator!=( const Extended_ull<UINT,digit>& n ) const noexcept { return !( *this == n ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator<=( const Extended_ull<UINT,digit>& n ) const noexcept { return !( n < *this ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator>=( const Extended_ull<UINT,digit>& n ) const noexcept { return !( *this < n ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator<( const Extended_ull<UINT,digit>& n ) const noexcept { return m_n[1] < n.m_n[1] || ( m_n[1] == n.m_n[1] && m_n[0] < n.m_n[0] ); }
template <typename UINT , int digit> inline constexpr bool Extended_ull<UINT,digit>::operator>( const Extended_ull<UINT,digit>& n ) const noexcept { return n < *this; }

template <typename UINT , int digit> inline constexpr const UINT& Extended_ull<UINT,digit>::GetLowerDigit() const noexcept { return m_n[0]; }
template <typename UINT , int digit> inline constexpr const UINT& Extended_ull<UINT,digit>::GetUpperDigit() const noexcept { return m_n[1]; }

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Quotient( const Extended_ull<UINT,digit>& n )
{

  assert( n != 0 );
  constexpr const Extended_ull<UINT,digit> full_power = Extended_ull<UINT,digit>( 1 ) << ConstantsForExtended_ull<UINT,digit>::g_full_digit_minus;
  Extended_ull<UINT,digit> answer{};
  Extended_ull<UINT,digit> power = full_power;
  
  for( int d = ConstantsForExtended_ull<UINT,digit>::g_full_digit_minus ; d >= 0 ; d-- ){

    if( ( *this >> d ) >= n ){

      *this -= ( n << d );
      answer |= power;

    }

    power >>= 1;

  }
  
  return answer;

}

template <typename UINT , int digit> inline constexpr UINT Extended_ull<UINT,digit>::Sqrt() const noexcept {

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


template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Sum( const UINT& n0 , const UINT& n1 ) noexcept
{

  UINT temp[2] = {
    ( n0 & ConstantsForExtended_ull<UINT,digit>::g_low_bit ) + ( n1 & ConstantsForExtended_ull<UINT,digit>::g_low_bit ) ,
    ( n0 >> ConstantsForExtended_ull<UINT,digit>::g_digit_half ) + ( n1 >> ConstantsForExtended_ull<UINT,digit>::g_digit_half )
  };
  temp[1] += ( temp[0] >> ConstantsForExtended_ull<UINT,digit>::g_digit_half );
  ( temp[0] &= ConstantsForExtended_ull<UINT,digit>::g_low_bit ) |= ( temp[1] << ConstantsForExtended_ull<UINT,digit>::g_digit_half );
  temp[1] >>= ConstantsForExtended_ull<UINT,digit>::g_digit_half;
  return Extended_ull<UINT,digit>( move( temp ) );

}

template <typename UINT , int digit> inline constexpr Extended_ull<UINT,digit> Extended_ull<UINT,digit>::Prod( const UINT& n0 , const UINT& n1 ) noexcept
{

  const UINT n0_copy[2] = { n0 & ConstantsForExtended_ull<UINT,digit>::g_low_bit , n0 >> ConstantsForExtended_ull<UINT,digit>::g_digit_half };
  const UINT n1_copy[2] = { n1 & ConstantsForExtended_ull<UINT,digit>::g_low_bit , n1 >> ConstantsForExtended_ull<UINT,digit>::g_digit_half };
  UINT temp0[2] = {
    n0_copy[0] * n1_copy[0] ,
    n0_copy[1] * n1_copy[1]
  };
  UINT temp1[2] = {
    n0_copy[0] * n1_copy[1] ,
    n0_copy[1] * n1_copy[0] ,
  };
  temp0[1] += ( temp1[0] >> ConstantsForExtended_ull<UINT,digit>::g_digit_half ) + ( temp1[1] >> ConstantsForExtended_ull<UINT,digit>::g_digit_half );
  ( temp1[1] &= ConstantsForExtended_ull<UINT,digit>::g_low_bit ) += ( temp1[0] &= ConstantsForExtended_ull<UINT,digit>::g_low_bit ) + ( temp0[0] >> ConstantsForExtended_ull<UINT,digit>::g_digit_half );
  temp0[1] += temp1[1] >> ConstantsForExtended_ull<UINT,digit>::g_digit_half;
  ( temp0[0] &= ConstantsForExtended_ull<UINT,digit>::g_low_bit ) |= ( temp1[1] << ConstantsForExtended_ull<UINT,digit>::g_digit_half );
  return Extended_ull<UINT,digit>( move( temp0 ) );

}

template <typename UINT , int digit> inline constexpr void Extended_ull<UINT,digit>::swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept { swap( n0.m_n , n1.m_n ); }

template <typename UINT , int digit> inline constexpr void swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept { Extended_ull<UINT,digit>::swap( n0 , n1 ); }


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
    
    return size_half0 > 0 ? ULL::Prod( stoeull<UINT>( s.substr( 0 , size_half1 ) ) , ten_power[size_half0] ) + stoeull<UINT>( s.substr( size_half1 ) ) : ULL( stoeull<UINT>( move( s ) ) );

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
  static const Extended_ull<UINT,digit> zero{ 0 };
  static const Extended_ull<UINT,digit> ten{ 10 };

  while( n != zero ){

    Extended_ull<UINT,digit> n_div = n / ten;
    Extended_ull<UINT,digit> n_res = n - ( n_div * ten );
    temp.push_front( to_string( n_res.GetLowerDigit() )[0] );
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

