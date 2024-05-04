// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Shifted/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Constant/a.hpp"

// verify:
// https://yukicoder.me/submissions/977606（+,*=,Factorial）


// 非負整数の同値関係x~yを
// - (x=y<K)または(x>=Kかつy>=Kかつx-K≡y-K(mod M))
// と定めた時の剰余類を扱う型。
template <int NUM>
class ShiftedMods
{

private:
  uint m_n;

public:
  inline ShiftedMods() noexcept;
  inline ShiftedMods( const ShiftedMods<NUM>& n ) noexcept;
  inline ShiftedMods( ShiftedMods<NUM>&& n ) noexcept;
  template <typename T> inline ShiftedMods( T n ) noexcept;

  inline ShiftedMods<NUM>& operator=( ShiftedMods<NUM> n ) noexcept;
  inline ShiftedMods<NUM>& operator+=( const ShiftedMods<NUM>& n ) noexcept;
  inline ShiftedMods<NUM>& operator*=( const ShiftedMods<NUM>& n ) noexcept;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍する。
  template <typename INT> inline ShiftedMods<NUM>& operator<<=( INT n );

  inline ShiftedMods<NUM>& operator++() noexcept;
  inline ShiftedMods<NUM> operator++( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( != );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( < );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( <= );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( > );
  DECLARATION_OF_COMPARISON_FOR_SHIFTED_MOD( >= );

  DECLARATION_OF_ARITHMETIC_FOR_SHIFTED_MOD( + , noexcept );
  DECLARATION_OF_ARITHMETIC_FOR_SHIFTED_MOD( * , noexcept );
  // exponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline ShiftedMods<NUM> operator^( INT exponent ) const;
  // n>=0である場合のみサポート。計算量O(log n)で2^n倍を返す。
  template <typename INT> inline ShiftedMods<NUM> operator<<( INT n ) const;

  // exponent>=0である場合にのみサポート。exponent乗する。
  template <typename INT> inline ShiftedMods<NUM>& Power( INT exponent );
  // グローバルスコープでswapを定義するためのもの。
  inline void swap( ShiftedMods<NUM>& n ) noexcept;

  inline const uint& Represent() const noexcept;
  // 0 <= n < Mの場合のみサポート。定数倍高速化のためにassertなし。
  static inline ShiftedMods<NUM> Derepresent( uint n ) noexcept;

  template <typename T> static inline T Residue( T n );
  
  // k!≡0(mod n)である場合のみサポート。
  static inline const ShiftedMods<NUM>& Factorial( const uint& n );

  static inline const ShiftedMods<NUM>& zero() noexcept;
  static inline const ShiftedMods<NUM>& one() noexcept;

  static inline const uint& GetShift() noexcept;
  static inline const uint& GetModulo() noexcept;
  static inline void SetModulo( const uint& K , const uint& M ) noexcept;
  
private:
  template <typename INT> inline ShiftedMods<NUM>& PositivePower( INT exponent ) noexcept;
  using Constants = ConstantsForShiftedMods<NUM>;

};

#include "a_Alias.hpp"

// exponent>=0である場合にのみサポート。
template <int NUM , typename T> inline ShiftedMods<NUM> Power( ShiftedMods<NUM> n , T exponent );

template <int NUM> inline void swap( ShiftedMods<NUM>& n0 , ShiftedMods<NUM>& n1 ) noexcept;

template <int NUM> inline string to_string( const ShiftedMods<NUM>& n ) noexcept;

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ShiftedMods<NUM>& n );
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ShiftedMods<NUM>& n );

#include "../../Hash/a.hpp"
template <int NUM> DECLARATION_OF_HASH( ShiftedMods<NUM> );
