// c:/Users/user/Documents/Programming/Utility/Extended_ull/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify: https://yukicoder.me/submissions/913505

template <typename UINT , int digit>
class Extended_ull
{

private:
  UINT m_n[2];

public:
  inline constexpr Extended_ull() noexcept;
  template <SFINAE_FOR_EXTENDED_ULL( = nullptr )> inline constexpr Extended_ull( T n0 ) noexcept;
  template <SFINAE_FOR_EXTENDED_ULL( = nullptr )> inline constexpr Extended_ull( T n0 , T n1 ) noexcept;
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
  static inline constexpr void swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept;

  using base = UINT;

};

#include a_alias.hpp

template <typename UINT , int digit> inline constexpr void swap( Extended_ull<UINT,digit>& n0 , Extended_ull<UINT,digit>& n1 ) noexcept;

// ULL = ullÇÃéûÅAéÛÇØéÊÇËè„å¿ÇÕ2^64 - 1 = 18446744073709551615 Å‡ 1.8Å~10^19
// ULL = ulllÇÃéûÅAéÛÇØéÊÇËè„å¿ÇÕ18446744073709551615999999999999999999 Å‡ 1.8Å~10^37
// ULL = ullllÇÃéûÅAéÛÇØéÊÇËè„å¿ÇÕñÒ1.8Å~10^73
// ULL = ulllllÇÃéûÅAéÛÇØéÊÇËè„å¿ÇÕñÒ1.8Å~10^145
template <typename ULL , int digit> inline ULL stoeull( string s );
template <typename UINT , int digit , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Extended_ull<UINT,digit>& n );

template <typename UINT , int digit> inline string to_string( Extended_ull<UINT,digit> n );
template <typename UINT , int digit , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Extended_ull<UINT,digit>& n );

