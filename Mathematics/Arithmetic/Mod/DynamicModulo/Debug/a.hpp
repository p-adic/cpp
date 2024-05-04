// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../Constant/a.hpp"

template <int NUM>
class DynamicMods
{

private:
  // 符号
  bool m_non_negative;
  // 分子
  uint m_n;
  // 分母
  uint m_d;

public:
  inline DynamicMods() noexcept;
  inline DynamicMods( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods( DynamicMods<NUM>&& n ) noexcept;
  template <typename T> inline DynamicMods( T n ) noexcept;

  inline DynamicMods<NUM>& operator=( DynamicMods<NUM> n ) noexcept;
  inline DynamicMods<NUM>& operator+=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator-=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator*=( const DynamicMods<NUM>& n ) noexcept;
  inline DynamicMods<NUM>& operator/=( DynamicMods<NUM> n );
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline DynamicMods<NUM>& operator<<=( INT n );
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍する。
  template <typename INT> inline DynamicMods<NUM>& operator>>=( INT n );

  inline DynamicMods<NUM>& operator++() noexcept;
  inline DynamicMods<NUM> operator++( int ) noexcept;
  inline DynamicMods<NUM>& operator--() noexcept;
  inline DynamicMods<NUM> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_DYNAMIC_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( - , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( * , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( / , );
  // Mが素数であるかexponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline DynamicMods<NUM> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍を返す。
  template <typename INT> inline DynamicMods<NUM> operator<<( INT n ) const;
  // n>=0かつMが奇数である場合のみサポート。計算量O(n)で2^{-n}倍を返す。
  template <typename INT> inline DynamicMods<NUM> operator>>( INT n ) const;

  inline DynamicMods<NUM> operator-() const noexcept;
  // -1倍する。
  inline DynamicMods<NUM>& SignInvert() noexcept;
  // -1乗する。
  inline DynamicMods<NUM>& Invert();
  // exponent乗する。
  template <typename INT> inline DynamicMods<NUM>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( DynamicMods<NUM>& n ) noexcept;

  inline const bool& GetSign() const noexcept;
  inline const uint& GetNumerator() const noexcept;
  inline const uint& GetDenominator() const noexcept;
  // 非DEBUG時に型が違うのでauto&&などで受け取ることに注意。
  inline uint Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline DynamicMods<NUM> Derepresent( uint n ) noexcept;

  // 0 < n < MかつMが素数である場合のみサポート。
  static inline const DynamicMods<NUM>& Inverse( const uint& n );
  static inline const DynamicMods<NUM>& Factorial( const uint& n );
  // 0 < n < MかつMが素数である場合のみサポート。
  static inline const DynamicMods<NUM>& FactorialInverse( const uint& n );
  // 0 < n < MかつMが素数である場合のみサポート。
  static inline DynamicMods<NUM> Combination( const uint& n , const uint& i );

  static inline const DynamicMods<NUM>& zero() noexcept;
  static inline const DynamicMods<NUM>& one() noexcept;

  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& M , const int& order_minus_1 = -1 ) noexcept;
  
private:
  template <typename INT> inline DynamicMods<NUM>& PositivePower( INT exponent ) noexcept;
  template <typename INT> inline DynamicMods<NUM>& NonNegativePower( INT exponent ) noexcept;

  using Constants = ConstantsForDynamicMods<NUM>;
  
};

#include "../a_Alias.hpp"

// Mが素数でありnが0でない場合にのみサポート。
template <int NUM> inline DynamicMods<NUM> Inverse( const DynamicMods<NUM>& n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <int NUM , typename T> inline DynamicMods<NUM> Power( DynamicMods<NUM> n , T exponent );

template <int NUM> inline void swap( DynamicMods<NUM>& n0 , DynamicMods<NUM>& n1 ) noexcept;

template <int NUM> inline string to_string( const DynamicMods<NUM>& n ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DynamicMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DynamicMods<NUM>& n );

#include "../../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( DynamicMods<NUM> );
