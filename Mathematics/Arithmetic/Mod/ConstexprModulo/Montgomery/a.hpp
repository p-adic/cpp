// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

// 非常によくバグるので、更新したら必ずverifyすること！
// verify:
// https://yukicoder.me/submissions/959351
// （Derepresent,+=,-=,*,Combination,one）
// https://yukicoder.me/submissions/959510
// （Derepresent,+=,-=,*=,SignInvert,+,*,^,++,--,Combination,zero,one）

// Mが奇数の場合にのみサポート
template <INT_TYPE_FOR_MONTGOMERY M>
class Montgomery
{

private:
  INT_TYPE_FOR_MONTGOMERY m_n;

public:
  inline constexpr Montgomery() noexcept;
  inline constexpr Montgomery( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery( Montgomery<M>&& n ) noexcept;
  template <typename T> inline constexpr Montgomery( T n ) noexcept;

  inline constexpr Montgomery<M>& operator=( Montgomery<M> n ) noexcept;
  inline constexpr Montgomery<M>& operator+=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator-=( const Montgomery<M>& n ) noexcept;
  inline constexpr Montgomery<M>& operator*=( const Montgomery<M>& n ) noexcept;
  inline Montgomery<M>& operator/=( Montgomery<M> n );
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline constexpr Montgomery<M>& operator<<=( INT n );
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline constexpr Montgomery<M>& operator>>=( INT n );

  inline constexpr Montgomery<M>& operator++() noexcept;
  inline constexpr Montgomery<M> operator++( int ) noexcept;
  inline constexpr Montgomery<M>& operator--() noexcept;
  inline constexpr Montgomery<M> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( == );
  DECLARATION_OF_COMPARISON_FOR_MONTGOMERY( != );
  
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_MONTGOMERY( / , );
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename INT> inline constexpr Montgomery<M> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline constexpr Montgomery<M> operator<<( INT n ) const;
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline constexpr Montgomery<M> operator>>( INT n ) const;

  inline constexpr Montgomery<M> operator-() const noexcept;
  inline constexpr Montgomery<M>& SignInvert() noexcept;
  // Mが素数である場合のみサポート。
  inline constexpr Montgomery<M>& Invert();
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename INT> inline constexpr Montgomery<M>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline constexpr void swap( Montgomery<M>& n ) noexcept;

  inline constexpr INT_TYPE_FOR_MONTGOMERY Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline constexpr Montgomery<M> Derepresent( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& Inverse( const INT_TYPE_FOR_MONTGOMERY& n );
  // n < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& Factorial( const INT_TYPE_FOR_MONTGOMERY& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Montgomery<M>& FactorialInverse( const INT_TYPE_FOR_MONTGOMERY& n );
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline Montgomery<M> Combination( const INT_TYPE_FOR_MONTGOMERY& n , const INT_TYPE_FOR_MONTGOMERY& i );

  static inline const Montgomery<M>& zero() noexcept;
  static inline const Montgomery<M>& one() noexcept;
  static inline const Montgomery<M>& two() noexcept;

private:
  static inline constexpr INT_TYPE_FOR_MONTGOMERY Form( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept;
  static inline constexpr ull& Reduction( ull& n ) noexcept;
  static inline constexpr ull& ReducedMultiplication( ull& n , const INT_TYPE_FOR_MONTGOMERY& m ) noexcept;
  static inline constexpr uint BaseSquareTruncation( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

  template <typename INT> inline constexpr Montgomery<M>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline constexpr Montgomery<M>& NonNegativePower( INT exponent ) noexcept;

  template <typename T> inline constexpr Montgomery<M>& Ref( T&& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MONTGOMERY& Normalise( INT_TYPE_FOR_MONTGOMERY& n ) noexcept;

};

// Mが素数でありnが0でない場合にのみサポート。
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <INT_TYPE_FOR_MONTGOMERY M , typename INT> inline constexpr Montgomery<M> Power( const Montgomery<M>& n , INT exponent );

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M> inline string to_string( const Montgomery<M>& n ) noexcept;

template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Montgomery<M>& n );
template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n );
