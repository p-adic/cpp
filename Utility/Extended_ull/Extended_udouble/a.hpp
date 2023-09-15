// c:/Users/user/Documents/Programming/Utility/Extended_ull/Extended_udouble/a.hpp

#pragma once
#include "../a.hpp"

template <typename UINT , int digit>
class Extended_udouble
{

private:
  UINT m_n;
  // 2„∞ÇÃéwêî
  int m_exponent;

public:
  inline constexpr Extended_udouble( const UINT& n = 0 , const int& exponent = 0 ) noexcept;
  inline constexpr Extended_udouble( const Extended_udouble<UINT,digit>& n ) noexcept;
  inline constexpr Extended_udouble( Extended_udouble<UINT,digit>&& n ) noexcept;
  inline constexpr Extended_udouble( Extended_ull<UINT,digit> n , const int exponent = 0 ) noexcept;

  inline constexpr Extended_udouble<UINT,digit>& operator=( const Extended_udouble<UINT,digit>& n ) noexcept;
  inline constexpr Extended_udouble<UINT,digit>& operator=( Extended_udouble<UINT,digit>&& n ) noexcept;
  inline constexpr Extended_udouble<UINT,digit>& operator+=( const Extended_udouble<UINT,digit>& n ) noexcept;
  inline constexpr Extended_udouble<UINT,digit>& operator*=( const Extended_udouble<UINT,digit>& n ) noexcept;
  inline constexpr Extended_udouble<UINT,digit>& operator/=( const Extended_udouble<UINT,digit>& n );
  inline constexpr Extended_udouble<UINT,digit>& operator<<=( const int& n ) noexcept;
  inline constexpr Extended_udouble<UINT,digit>& operator>>=( const int& n ) noexcept;

  inline constexpr Extended_udouble<UINT,digit> operator+( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_udouble<UINT,digit> operator*( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_udouble<UINT,digit> operator/( const Extended_udouble<UINT,digit>& n ) const;
  inline constexpr Extended_udouble<UINT,digit> operator<<( const int& n ) const noexcept;
  inline constexpr Extended_udouble<UINT,digit> operator>>( const int& n ) const noexcept;

  // ãﬂéóìIìôçÜ
  inline constexpr bool operator==( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator!=( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator<=( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator>=( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator<( const Extended_udouble<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator>( const Extended_udouble<UINT,digit>& n ) const noexcept;

  inline constexpr const UINT& GetDigit() const noexcept;
  inline constexpr const int& GetExponent() const noexcept;

  inline constexpr Extended_udouble<UINT,digit> Sqrt() const noexcept;

};

template <typename UINT , int digit> inline string to_string( Extended_udouble<UINT,digit> n );
template <typename UINT , int digit , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Extended_udouble<UINT,digit>& n );

