// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once

#include "a_Alias.hpp"

// ここをtempate <typename INT , INT M>などにしてしまうとoperator+などを呼び出す際に型推論に失敗する。整数型を変えたい時はINT_TYPE_FOR_MODの型エイリアスを変更する。
template <INT_TYPE_FOR_MOD M>
class Mod
{

protected:
  INT_TYPE_FOR_MOD m_n;
  INT_TYPE_FOR_MOD m_inv;

public:
  inline Mod() noexcept;
  inline Mod( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator=( const INT_TYPE_FOR_MOD& n ) noexcept;
  Mod<M>& operator=( const Mod<M>& n ) noexcept;
  Mod<M>& operator+=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator-=( const INT_TYPE_FOR_MOD& n ) noexcept;
  inline Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  Mod<M>& operator*=( const INT_TYPE_FOR_MOD& n ) noexcept;
  Mod<M>& operator*=( const Mod<M>& n ) noexcept;

  // INT_TYPE_FOR_MODでの割り算ではないことに注意
  virtual Mod<M>& operator/=( const INT_TYPE_FOR_MOD& n );
  virtual Mod<M>& operator/=( const Mod<M>& n );
  
  Mod<M>& operator%=( const INT_TYPE_FOR_MOD& n );
  inline Mod<M>& operator%=( const Mod<M>& n );

  inline Mod<M> operator-() const noexcept;

  // 前置++/--を使うつもりがないので後置++/--と同じものとして定義する
  inline Mod<M>& operator++() noexcept;
  inline Mod<M>& operator++( int ) noexcept;
  inline Mod<M>& operator--() noexcept;
  inline Mod<M>& operator--( int ) noexcept;
  
  inline const INT_TYPE_FOR_MOD& Represent() const noexcept;
  void Invert() noexcept;
  bool CheckInvertible() noexcept;
  bool IsSmallerThan( const INT_TYPE_FOR_MOD& n ) const noexcept;
  bool IsBiggerThan( const INT_TYPE_FOR_MOD& n ) const noexcept;

};

template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator==( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator<( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT_TYPE_FOR_MOD M> Mod<M> operator+( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator+( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline Mod<M> operator-( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator-( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator*( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator*( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT_TYPE_FOR_MOD M> Mod<M> operator/( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 );
template <INT_TYPE_FOR_MOD M> Mod<M> operator/( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 );
template <INT_TYPE_FOR_MOD M> Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 );
template <INT_TYPE_FOR_MOD M> Mod<M> operator%( const Mod<M>& n0 , const INT_TYPE_FOR_MOD& n1 );
template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const INT_TYPE_FOR_MOD& n0 , const Mod<M>& n1 );
template <INT_TYPE_FOR_MOD M> inline Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 );
template <INT_TYPE_FOR_MOD M> Mod<M> Inverse( const Mod<M>& n );

template <INT_TYPE_FOR_MOD M> Mod<M> Power( const Mod<M>& n , const INT_TYPE_FOR_MOD& p , const string& method = "normal" );

template <> inline Mod<2> Power( const Mod<2>& n , const INT_TYPE_FOR_MOD& p , const string& method );

// M乗が1になるよう定義されていることに注意
template <INT_TYPE_FOR_MOD M> inline Mod<M> Power( const Mod<M>& n , const Mod<M>& p , const string& method = "normal" );

template <> inline Mod<2> Power( const Mod<2>& n , const Mod<2>& p , const string& method );

// ../Power/a_Body.hppにて定義
template <typename T> inline T Square( const T& t );
template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t );

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept;

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n );
