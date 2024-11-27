// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

#include "Constant/a.hpp"

// 非常によくバグるので、更新したら必ずverifyすること！
// verify:
// https://yukicoder.me/submissions/965330（+=,*,/,Power）
// https://yukicoder.me/submissions/965328（Derepresent,+=,-=,*,Combination,one）
// https://yukicoder.me/submissions/965332（Derepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one）

template <INT_TYPE_FOR_MOD M>
class Mod
{

private:
  INT_TYPE_FOR_MOD m_n;

public:
  inline constexpr Mod() noexcept;
  inline constexpr Mod( const Mod<M>& n ) noexcept;
  inline constexpr Mod( Mod<M>&& n ) noexcept;
  template <typename T , SFINAE_FOR_MOD = nullptr> inline constexpr Mod( T n ) noexcept;

  inline constexpr Mod<M>& operator=( Mod<M> n ) noexcept;
  inline constexpr Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator/=( Mod<M> n );
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline constexpr Mod<M>& operator<<=( INT n );
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline constexpr Mod<M>& operator>>=( INT n );

  inline constexpr Mod<M>& operator++() noexcept;
  inline constexpr Mod<M> operator++( int ) noexcept;
  inline constexpr Mod<M>& operator--() noexcept;
  inline constexpr Mod<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / , );
  // Mが素数であるかexponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline constexpr Mod<M> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍を返す。
  template <typename INT> inline constexpr Mod<M> operator<<( INT n ) const;
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍を返す。
  template <typename INT> inline constexpr Mod<M> operator>>( INT n ) const;

  inline constexpr Mod<M> operator-() const noexcept;
  // -1倍する。
  inline constexpr Mod<M>& SignInvert() noexcept;
  // Mが素数である場合のみサポート。-1乗する。
  inline Mod<M>& Invert();
  // Mが素数であるかexponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline constexpr Mod<M>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline constexpr void swap( Mod<M>& n ) noexcept;

  inline constexpr const INT_TYPE_FOR_MOD& Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline constexpr Mod<M> Derepresent( INT_TYPE_FOR_MOD n ) noexcept;
  
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n );
  // n < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline Mod<M> Combination( const INT_TYPE_FOR_MOD& n , const INT_TYPE_FOR_MOD& i );

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;

  static inline constexpr INT_TYPE_FOR_MOD GetModulo() noexcept;

private:
  template <typename INT> inline constexpr Mod<M>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline constexpr Mod<M>& NonNegativePower( INT exponent ) noexcept;

  using Constants = ConstantsForMod<M>;

};

// Mが素数でありnが0でない場合にのみサポート。
template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power( Mod<M> n , T exponent );

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n );
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );

#include "../Hash/a.hpp"
template <INT_TYPE_FOR_MOD M> DECLARATION_OF_HASH( Mod<M> );
