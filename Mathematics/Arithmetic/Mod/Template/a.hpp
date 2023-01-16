// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "a_Alias.hpp"

#include "Operator/a.hpp"

// Mod<M>のテンプレート化。Montgomery<M>の圧縮時のファイル容量を小さくできる。
// 一方で実行時間は1.2倍程度に膨れ上がるためファイル容量と実行時間のトレードオフである。
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> >
class Mod
{
  
protected:
  INT_TYPE_FOR_MOD m_n;

public:
  inline constexpr Mod() noexcept;
  inline constexpr Mod( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod( Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod( Mod<M,OPR>&& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( const T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T& n ) noexcept;
  template <SFINAE_FOR_MOD( = nullptr )> inline constexpr Mod( T&& n ) noexcept;

  inline constexpr Mod<M,OPR>& operator=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator=( Mod<M,OPR>&& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator+=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator-=( const Mod<M,OPR>& n ) noexcept;
  inline constexpr Mod<M,OPR>& operator*=( const Mod<M,OPR>& n ) noexcept;
  inline Mod<M,OPR>& operator/=( const Mod<M,OPR>& n );
  inline constexpr Mod<M,OPR>& operator<<=( int n ) noexcept;
  // Mが奇数である場合のみサポート。
  inline constexpr Mod<M,OPR>& operator>>=( int n ) noexcept;

  inline constexpr Mod<M,OPR>& operator++() noexcept;
  inline constexpr Mod<M,OPR> operator++( int ) noexcept;
  inline constexpr Mod<M,OPR>& operator--() noexcept;
  inline constexpr Mod<M,OPR> operator--( int ) noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( == );
  DECLARATION_OF_COMPARISON_FOR_MOD( != );

  DECLARATION_OF_ARITHMETIC_FOR_MOD( + );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( - );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( * );
  DECLARATION_OF_ARITHMETIC_FOR_MOD( / );
  inline constexpr Mod<M,OPR> operator<<( int n ) const noexcept;
  inline constexpr Mod<M,OPR> operator>>( int n ) const noexcept;

  inline constexpr Mod<M,OPR> operator-() const noexcept;
  inline constexpr Mod<M,OPR>& SignInvert() noexcept;
  inline constexpr Mod<M,OPR>& Double() noexcept;
  // Mが奇数である場合のみサポート。
  inline constexpr Mod<M,OPR>& Halve() noexcept;
  // Mが素数である場合のみサポート。
  inline Mod<M,OPR>& Invert();
  template <typename T> inline constexpr Mod<M,OPR>& PositivePower( T&& exponent ) noexcept;
  template <typename T> inline constexpr Mod<M,OPR>& NonNegativePower( T&& exponent ) noexcept;
  // Mが素数であるかexponent>=0である場合にのみサポート。
  template <typename T> inline Mod<M,OPR>& Power( T&& exponent );

  inline constexpr void swap( Mod<M,OPR>& n ) noexcept;

  inline constexpr conditional_t<is_same<OPR,OperatorsForMod<M> >::value,const INT_TYPE_FOR_MOD&,INT_TYPE_FOR_MOD> Represent() const noexcept;
  inline constexpr const INT_TYPE_FOR_MOD& Deconstruct() const noexcept;
  
  // 0 <= n < Mの場合のみサポート。
  static inline constexpr Mod<M,OPR> Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept;
  // 0 <= n < Mの場合のみサポート。
  static inline constexpr Mod<M,OPR> Construct( INT_TYPE_FOR_MOD n ) noexcept;
  
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline Mod<M,OPR> Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_lengthである場合のみサポート。
  static inline Mod<M,OPR> Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // Mが素数かつn < g_memory_lengthである場合のみサポート。
  static inline Mod<M,OPR> FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M,OPR>& zero() noexcept;
  static inline const Mod<M,OPR>& one() noexcept;
  
private:
  template <typename T> inline constexpr Mod<M,OPR>& Ref( T&& n ) noexcept;

};

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Twice( Mod<M,OPR> n ) noexcept;
// Mが奇数である場合のみサポート。
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Half( Mod<M,OPR> n ) noexcept;

// Mが素数でありnが0でない場合にのみサポート。
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline Mod<M,OPR> Inverse( Mod<M,OPR> n );
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr Mod<M,OPR> Inverse_constexpr( Mod<M,OPR> n );

// Mが素数であるかexponent>=0である場合にのみサポート。
template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> , typename T> inline constexpr Mod<M,OPR> Power( Mod<M,OPR> n , const T& exponent );

// ../Power/a_Body.hppにて定義。
template <typename T> inline constexpr T Square( const T& t );
template <> inline constexpr Mod<2> Square<Mod<2> >( const Mod<2>& n );

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline constexpr void swap( Mod<M,OPR>& n0 , Mod<M,OPR>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> > inline string to_string( const Mod<M,OPR>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , typename OPR = OperatorsForMod<M> , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M,OPR>& n );
