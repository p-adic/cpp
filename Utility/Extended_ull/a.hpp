// c:/Users/user/Documents/Programming/Utility/Extended_ull/a.hpp

#pragma once
#include "a.hpp"

template <typename UINT , int digit>
class Extended_ull
{

private:
  UINT m_n[2];

public:
  inline constexpr Extended_ull( const UINT& n0 = 0 ,  const UINT& n1 = 0 ) noexcept;
  inline constexpr Extended_ull( const UINT ( &n )[2] ) noexcept;
  inline constexpr Extended_ull( UINT ( &&n )[2] ) noexcept;
  inline constexpr Extended_ull( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull( Extended_ull<UINT,digit>&& n ) noexcept;

  inline constexpr Extended_ull<UINT,digit>& operator=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator=( Extended_ull<UINT,digit>&& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator+=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator-=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator*=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator/=( const Extended_ull<UINT,digit>& n );
  inline constexpr Extended_ull<UINT,digit>& operator%=( const Extended_ull<UINT,digit>& n );
  inline constexpr Extended_ull<UINT,digit>& operator&=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator|=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator^=( const Extended_ull<UINT,digit>& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator<<=( const int& n ) noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator>>=( const int& n ) noexcept;

  inline constexpr Extended_ull<UINT,digit>& operator++() noexcept;
  inline constexpr Extended_ull<UINT,digit>& operator--() noexcept;
  inline constexpr Extended_ull<UINT,digit> operator++( int ) noexcept;
  inline constexpr Extended_ull<UINT,digit> operator--( int ) noexcept;

  inline constexpr Extended_ull<UINT,digit> operator+( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator-() const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator-( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator*( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator/( const Extended_ull<UINT,digit>& n ) const;
  inline constexpr Extended_ull<UINT,digit> operator%( const Extended_ull<UINT,digit>& n ) const;
  inline constexpr Extended_ull<UINT,digit> operator~() const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator&( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator|( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator^( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator<<( const int& n ) const noexcept;
  inline constexpr Extended_ull<UINT,digit> operator>>( const int& n ) const noexcept;

  inline constexpr bool operator==( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator!=( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator<=( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator>=( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator<( const Extended_ull<UINT,digit>& n ) const noexcept;
  inline constexpr bool operator>( const Extended_ull<UINT,digit>& n ) const noexcept;

  inline constexpr const UINT& GetLowerDigit() const noexcept;
  inline constexpr const UINT& GetUpperDigit() const noexcept;

  inline constexpr Extended_ull<UINT,digit> Quotient( const Extended_ull<UINT,digit>& n );
  inline constexpr UINT Sqrt() const noexcept;

  static inline constexpr Extended_ull<UINT,digit> Sum( const UINT& n0 , const UINT& n1 ) noexcept;
  static inline constexpr Extended_ull<UINT,digit> Prod( const UINT& n0 , const UINT& n1 ) noexcept;

};

template <typename UINT , int digit> inline string to_string( Extended_ull<UINT,digit> n );
template <typename UINT , int digit , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Extended_ull<UINT,digit>& n );

