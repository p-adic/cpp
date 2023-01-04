// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

// ここをtempate <typename INT , INT M>などにしてしまうとoperator+などを呼び出す際に型推論に失敗する。整数型を変えたい時はINT_TYPE_FOR_MODの型エイリアスを変更する。
template <INT_TYPE_FOR_MOD M>
class Mod
{

protected:
  INT_TYPE_FOR_MOD m_n;

public:
  inline constexpr Mod() noexcept;
  inline constexpr Mod( const Mod<M>& n ) noexcept;
  inline constexpr Mod( Mod<M>& n ) noexcept;
  inline constexpr Mod( Mod<M>&& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T&& n ) noexcept;

  inline constexpr Mod<M>& operator=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline constexpr Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator/=( const Mod<M>& n );

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

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + , Add );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - , Substract );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * , Multiply );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / , Devide );

  inline constexpr Mod<M> operator-() const noexcept;
  inline constexpr Mod<M>& SignInvert() noexcept;
  // Mが素数である場合のみサポート。
  inline Mod<M>& Invert();
  template <typename T> inline constexpr Mod<M>& PositivePower( T&& exponent ) noexcept;
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename T> inline constexpr Mod<M>& Power( T&& exponent );
  template <typename T> inline constexpr Mod<M> NonNegativePower_constexpr( const Mod<M>& repetitive_square , T&& exponent ) noexcept;
  
  inline constexpr const INT_TYPE_FOR_MOD& Represent() const noexcept;
  inline constexpr void swap( Mod<M>& n ) noexcept;

  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;
  // 0 <= n < Mの場合のみサポート。
  static inline constexpr Mod<M> Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept;

private:
  static inline constexpr INT_TYPE_FOR_MOD MontgomeryForm( const INT_TYPE_FOR_MOD& n ) noexcept;
  static inline constexpr ull& MontgomeryReduction( ull& n ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD MontgomeryMultiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
  static inline constexpr INT_TYPE_FOR_MOD& Normalise( INT_TYPE_FOR_MOD& n ) noexcept;
  template <typename T> inline constexpr Mod<M>& Ref( T&& n ) noexcept;

};

// Mが素数でありnが0でない場合にのみサポート。
template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n );
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Inverse_constexpr( const Mod<M>& n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power( const Mod<M>& n , const T& exponent );
template <typename T> inline constexpr Mod<2> Power( const Mod<2>& n , const T& p );
template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power_constexpr( const Mod<M>& n , const T& exponent );

// ../Power/a_Body.hppにて定義。
template <typename T> inline constexpr T Square( const T& t );
template <> inline constexpr Mod<2> Square<Mod<2> >( const Mod<2>& t );

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );
