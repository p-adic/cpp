// c:/Users/user/Documents/Programming/Utility/Extended_ull/Extended_udouble/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../a_Body.hpp"

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>::Extended_udouble( const UINT& n , const int& exponent ) noexcept : m_n( n ) , m_exponent( exponent ) {}

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>::Extended_udouble( const Extended_udouble<UINT,digit>& n ) noexcept : m_n( n.m_n ) , m_exponent( n.m_exponent ) {}
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>::Extended_udouble( Extended_udouble<UINT,digit>&& n ) noexcept : m_n( move( n.m_n ) ) , m_exponent( n.m_exponent ) {}
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>::Extended_udouble( Extended_ull<UINT,digit> n , const int exponent ) noexcept : m_n() , m_exponent()
{

  const UINT& n1 = n.GetUpperDigit();

  int l = 0;
  int r = digit;

  while( l + 1 < r ){

    int m = ( l + r ) / 2;
    ( ( n1 >> m ) == 0 ? r : l ) = m;

  }

  m_n = ( n >>= r ).GetLowerDigit();
  m_exponent = exponent + r;

}

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator=( const Extended_udouble<UINT,digit>& n ) noexcept { m_n = n.m_n; m_exponent = n.m_exponent; return *this; }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator=( Extended_udouble<UINT,digit>&& n ) noexcept { m_n = move( n.m_n ); m_exponent = n.m_exponent; return *this; }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator+=( const Extended_udouble<UINT,digit>& n ) noexcept { return operator=( *this + n ); }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator*=( const Extended_udouble<UINT,digit>& n ) noexcept { return operator=( *this * n ); }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator/=( const Extended_udouble<UINT,digit>& n ) { return operator=( *this / n ); }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator<<=( const int& n ) noexcept { m_exponent += n; return *this; }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit>& Extended_udouble<UINT,digit>::operator>>=( const int& n ) noexcept { m_exponent -= n; return *this; }

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::operator+( const Extended_udouble<UINT,digit>& n ) const noexcept
{

  if( m_exponent < n.m_exponent ){

    return n + *this;

  }

  if( m_exponent >= n.m_exponent + digit ){

    return *this;

  }

  Extended_ull<UINT,digit> sum{ this->m_n };
  ( sum <<= ( m_exponent - n.m_exponent ) ) += Extended_ull<UINT,digit>( n.m_n );
  return Extended_udouble<UINT,digit>( sum , n.m_exponent );

}

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::operator*( const Extended_udouble<UINT,digit>& n ) const noexcept { return Extended_udouble<UINT,digit>( Extended_ull<UINT,digit>::Prod( m_n , n.m_n ) , m_exponent + n.m_exponent ); }

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::operator/( const Extended_udouble<UINT,digit>& n ) const
{

  Extended_ull<UINT,digit> div{ this->m_n };
  ( div <<= digit ) /= Extended_ull<UINT,digit>( n.m_n );
  return Extended_udouble<UINT,digit>( div , -digit );

}

template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::operator<<( const int& n ) const noexcept { return Extended_udouble<UINT,digit>( m_n , m_exponent + n ); }
template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::operator>>( const int& n ) const noexcept { return Extended_udouble<UINT,digit>( m_n , m_exponent - n ); }

template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator==( const Extended_udouble<UINT,digit>& n ) const noexcept { return m_exponent + digit <= n.m_exponent ? false : m_exponent >= n.m_exponent + digit ? false : m_exponent < n.m_exponent ? Extended_ull<UINT,digit>( *this ) == ( Extended_ull<UINT,digit>( n ) << ( n.m_exponent - m_exponent ) ) : ( Extended_ull<UINT,digit>( *this ) << ( m_exponent - n.m_exponent ) ) == Extended_ull<UINT,digit>( n ); }
template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator!=( const Extended_udouble<UINT,digit>& n ) const noexcept { return !( *this == n ); }
template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator<=( const Extended_udouble<UINT,digit>& n ) const noexcept { return !( n < *this ); }
template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator>=( const Extended_udouble<UINT,digit>& n ) const noexcept { return !( *this < n ); }
template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator<( const Extended_udouble<UINT,digit>& n ) const noexcept { return m_exponent + digit <= n.m_exponent ? true : m_exponent >= n.m_exponent + digit ? false : m_exponent < n.m_exponent ? Extended_ull<UINT,digit>( *this ) < ( Extended_ull<UINT,digit>( n ) << ( n.m_exponent - m_exponent ) ) : ( Extended_ull<UINT,digit>( *this ) << ( m_exponent - n.m_exponent ) ) < Extended_ull<UINT,digit>( n ); }
template <typename UINT , int digit> inline constexpr bool Extended_udouble<UINT,digit>::operator>( const Extended_udouble<UINT,digit>& n ) const noexcept { return n < *this; }


template <typename UINT , int digit> inline constexpr const UINT& Extended_udouble<UINT,digit>::GetDigit() const noexcept { return m_n; }
template <typename UINT , int digit> inline constexpr const int& Extended_udouble<UINT,digit>::GetExponent() const noexcept { return m_exponent; }


template <typename UINT , int digit> inline constexpr Extended_udouble<UINT,digit> Extended_udouble<UINT,digit>::Sqrt() const noexcept
{

  Extended_ull<UINT,digit> this_copy{ this->m_n };
  int exponent = m_exponent - digit;
  return exponent % 2 == 0 ? Extended_udouble<UINT,digit>( ( this_copy <<= digit ).Sqrt() , exponent >>= 1 ) : Extended_udouble<UINT,digit>( ( this_copy <<= ( digit - 1 ) ).Sqrt() , ( ++exponent ) >>= 1 );

}

template <typename UINT , int digit> inline string to_string( Extended_udouble<UINT,digit> n )
{

  static const Extended_udouble<UINT,digit> ten_power{ ConstantsForExtended_udouble<UINT,digit>::g_ten_power };

  if( n.GetDigit() == 0 ){

    return "0";

  }
  
  const int& exponent = n.GetExponent();

  int ten_digit = 0;
  
  while( exponent < 0 ){

    n *= ten_power;
    ten_digit++;

  }

  Extended_ull<UINT,digit> n_copy{ n.GetDigit() };
  n_copy <<= exponent;

  string answer = to_string( n_copy );

  if( ten_digit > 0 ){ 

    ten_digit *= ConstantsForExtended_udouble<UINT,digit>::g_ten_exponent;
    int size = answer.size();

    if( size <= ten_digit ){
      
      string leading = "";

      for( int d = size ; d < ten_digit ; d++ ){

	leading += "0";
    
      }

      answer = "0." + leading + answer;

    } else {

      size -= ten_digit;
      answer = answer.substr( 0 , size ) + "." + answer.substr( size );
      
    }

  }

  return answer;

}

template <typename UINT , int digit , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Extended_udouble<UINT,digit>& n ) { return os << to_string( n ); }

