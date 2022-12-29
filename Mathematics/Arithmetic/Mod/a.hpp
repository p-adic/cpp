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
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound = 1000000;
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;

public:
  inline Mod() noexcept;
  inline Mod( const Mod<M>& n ) noexcept;
  inline Mod( Mod<M>&& n ) noexcept;
  inline Mod( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator=( Mod<M>&& n ) noexcept;
  inline Mod<M>& operator=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator+=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator-=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator*=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator*=( const INT_TYPE_FOR_MOD& n ) noexcept;

  // INT_TYPE_FOR_MODでの割り算ではないことに注意
  inline Mod<M>& operator/=( const Mod<M>& n );
  inline Mod<M>& operator/=( const INT_TYPE_FOR_MOD& n );
  
  inline Mod<M>& operator%=( const Mod<M>& n );
  inline Mod<M>& operator%=( const INT_TYPE_FOR_MOD& n );

  inline Mod<M> operator-() const noexcept;

  // 前置++/--を使うつもりがないので後置++/--と同じものとして定義する
  inline Mod<M>& operator++() noexcept;
  inline Mod<M>& operator++( int ) noexcept;
  inline Mod<M>& operator--() noexcept;
  inline Mod<M>& operator--( int ) noexcept;
  
  inline const INT_TYPE_FOR_MOD& Represent() const noexcept;
  // Mが素数である場合のみサポート
  inline Mod<M>& Invert() noexcept;

  DECLARATION_OF_COMPARISON_FOR_MOD( IsEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsNotEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsSmallerThan );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsSmallerThanOrEqualTo );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsBiggerThan );
  DECLARATION_OF_COMPARISON_FOR_MOD( IsBiggerThanOrEqualTo );

  inline void swap( Mod<M>& n ) noexcept;

  // Mが素数かつn < g_memory_lengthである場合のみサポート
  static inline const Mod<M>& Inverse( const INT_TYPE_FOR_MOD& n ) noexcept;
  // n < g_memory_lengthである場合のみサポート
  static inline const Mod<M>& Factorial( const INT_TYPE_FOR_MOD& n ) noexcept;
  // Mが素数かつn < g_memory_lengthである場合のみサポート
  static inline const Mod<M>& FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept;

  static inline const Mod<M>& zero() noexcept;
  static inline const Mod<M>& one() noexcept;

private:
  static inline Mod<M> error() noexcept;
  
};

DECLARATION_OF_OPERATOR_FOR_MOD( bool , == );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , != );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , < );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , <= );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , > );
DECLARATION_OF_OPERATOR_FOR_MOD( bool , >= );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , + );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , - );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , * );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , / );
DECLARATION_OF_OPERATOR_FOR_MOD( Mod<M> , % );

// Mが素数である場合にのみサポート
template <INT_TYPE_FOR_MOD M> Mod<M> inline Inverse( const Mod<M>& n );

// Mが素数であるかp>=0である場合にのみサポート
template <INT_TYPE_FOR_MOD M> Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p );
template <> inline Mod<2> Power( const Mod<2>& n , const INT_TYPE_FOR_MOD& p );
// M乗が1になるよう定義されていることに注意
template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p );
template <> inline Mod<2> Power( const Mod<2>& n , const Mod<2>& p );

// ../Power/a_Body.hppにて定義
template <typename T> inline T Square( const T& t );
template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t );

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );
