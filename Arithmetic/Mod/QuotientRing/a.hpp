// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a.hpp

#pragma once
#include "a_Macro.hpp"

// Z[i]やFp[T]などZ以外の環の商を扱うための型。
// Zの商はModやDynamicModを用いる。

// インスタンスごとに異なる法を定めたい場合は
// MultiBase/a.hpp
// のクラスを用いる。
template <typename U , int NUM>
class QuotientRings
{

protected:
  U m_n;
  bool m_reduced;

public:
  inline QuotientRings() noexcept;
  inline QuotientRings( const QuotientRings<U,NUM>& n ) noexcept;
  inline QuotientRings( QuotientRings<U,NUM>&& n ) noexcept;
  inline QuotientRings( U n ) noexcept;

  inline QuotientRings<U,NUM>& operator=( QuotientRings<U,NUM> n ) noexcept;
  inline QuotientRings<U,NUM>& operator+=( const QuotientRings<U,NUM>& n ) noexcept;
  inline QuotientRings<U,NUM>& operator-=( const QuotientRings<U,NUM>& n ) noexcept;
  inline QuotientRings<U,NUM>& operator*=( const QuotientRings<U,NUM>& n ) noexcept;
  inline QuotientRings<U,NUM>& operator/=( QuotientRings<U,NUM> n );
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline QuotientRings<U,NUM>& operator<<=( INT n );
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline QuotientRings<U,NUM>& operator>>=( INT n );

  inline QuotientRings<U,NUM>& operator++() noexcept;
  inline QuotientRings<U,NUM> operator++( int ) noexcept;
  inline QuotientRings<U,NUM>& operator--() noexcept;
  inline QuotientRings<U,NUM> operator--( int ) noexcept;

  inline bool operator==( const QuotientRings<U,NUM>& n ) const noexcept;
  inline bool operator!=( const QuotientRings<U,NUM>& n ) const noexcept;

  DECLARATION_OF_ARITHMETIC_FOR_QUOTIENT( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_QUOTIENT( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_QUOTIENT( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_QUOTIENT( / , );
  // Mが素数であるかexponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline QuotientRings<U,NUM> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍を返す。
  template <typename INT> inline QuotientRings<U,NUM> operator<<( INT n ) const;
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍を返す。
  template <typename INT> inline QuotientRings<U,NUM> operator>>( INT n ) const;

  inline QuotientRings<U,NUM> operator-() const noexcept;
  // -1倍する。
  inline QuotientRings<U,NUM>& SignInvert() noexcept;
  // -1乗する。
  inline QuotientRings<U,NUM>& Invert();
  // exponent乗する。
  template <typename INT> inline QuotientRings<U,NUM>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( QuotientRings<U,NUM>& n ) noexcept;

  inline const bool& Reduced() const noexcept;
  inline void Reduce() noexcept;
  inline const U& Represent() noexcept;
  inline U Represent() const noexcept;
  // QuotientRings<U,NUM>(n).m_n == nの場合のみサポート。定数倍高速化のためにassertなし。
  static inline QuotientRings<U,NUM> Derepresent( U n ) noexcept;
  
  static inline const QuotientRings<U,NUM>& zero() noexcept;
  static inline const QuotientRings<U,NUM>& one() noexcept;

  static inline const U& GetModulo() noexcept;
  static inline void SetModulo( const U& M , const int& order_minus_1 , const bool& embedded = false ) noexcept;

private:
  template <typename INT> inline QuotientRings<U,NUM>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline QuotientRings<U,NUM>& NonNegativePower( INT exponent ) noexcept;

  using Constants = ConstantsForQuotientRings<U,NUM>;

};

#include "a_Alias.hpp"

template <typename U , int NUM> inline QuotientRings<U,NUM> Inverse( const QuotientRings<U,NUM>& n );
template <typename U , int NUM , typename INT> inline QuotientRings<U,NUM> Power( QuotientRings<U,NUM> n , INT exponent );

template <typename U , int NUM> inline void swap( QuotientRings<U,NUM>& n0 , QuotientRings<U,NUM>& n1 ) noexcept;

template <typename U , int NUM> inline string to_string( QuotientRings<U,NUM>& n ) noexcept;

template <typename U , int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , QuotientRings<U,NUM>& n );
template <typename U , int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const QuotientRings<U,NUM>& n );

#include "../Hash/a.hpp"
template <typename U , int NUM> DECLARATION_OF_HASH( QuotientRings<U,NUM> );

