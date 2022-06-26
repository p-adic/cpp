// Mod/a.hpp

#pragma once

template <typename INT , INT M>
class Mod
{

protected:
  INT m_n;
  INT m_inv;
  
  static INT Residue( const INT& n ) noexcept;

public:
  Mod() noexcept;
  Mod( const INT& n ) noexcept;
  Mod( const Mod<INT,M>& n ) noexcept;
  inline Mod<INT,M>& operator=( const INT& n ) noexcept;
  Mod<INT,M>& operator=( const Mod<INT,M>& n ) noexcept;
  Mod<INT,M>& operator+=( const INT& n ) noexcept;
  inline Mod<INT,M>& operator+=( const Mod<INT,M>& n ) noexcept;
  inline Mod<INT,M>& operator-=( const INT& n ) noexcept;
  inline Mod<INT,M>& operator-=( const Mod<INT,M>& n ) noexcept;
  Mod<INT,M>& operator*=( const INT& n ) noexcept;
  Mod<INT,M>& operator*=( const Mod<INT,M>& n ) noexcept;

  // INTでの割り算ではないことに注意
  virtual Mod<INT,M>& operator/=( const INT& n );
  virtual Mod<INT,M>& operator/=( const Mod<INT,M>& n );
  
  Mod<INT,M>& operator%=( const INT& n );
  inline Mod<INT,M>& operator%=( const Mod<INT,M>& n );

  // 前置++/--を使うつもりがないので後置++/--と同じものとして定義する
  inline Mod<INT,M>& operator++() noexcept;
  inline Mod<INT,M>& operator++( int ) noexcept;
  inline Mod<INT,M>& operator--() noexcept;
  inline Mod<INT,M>& operator--( int ) noexcept;
  
  inline const INT& Represent() const noexcept;
  void Invert() noexcept;
  bool CheckInvertible() noexcept;
  bool IsSmallerThan( const INT& n ) const noexcept;
  bool IsBiggerThan( const INT& n ) const noexcept;

};

template <typename INT , INT M> inline bool operator==( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator==( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator==( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator==( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> inline bool operator!=( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator!=( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator!=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator!=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> inline bool operator<( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator<( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator<( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> inline bool operator<=( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator<=( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator<=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator<=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> inline bool operator>( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> inline bool operator>=( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>=( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline bool operator>=( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;

template <typename INT , INT M> Mod<INT,M> operator+( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator+( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator+( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> inline Mod<INT,M> operator-( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator-( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator-( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator*( const Mod<INT,M>& n0 , const INT& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator*( const INT& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator*( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 ) noexcept;
template <typename INT , INT M> Mod<INT,M> operator/( const Mod<INT,M>& n0 , const INT& n1 );
template <typename INT , INT M> Mod<INT,M> operator/( const INT& n0 , const Mod<INT,M>& n1 );
template <typename INT , INT M> Mod<INT,M> operator/( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 );
template <typename INT , INT M> Mod<INT,M> operator%( const Mod<INT,M>& n0 , const INT& n1 );
template <typename INT , INT M> inline Mod<INT,M> operator%( const INT& n0 , const Mod<INT,M>& n1 );
template <typename INT , INT M> inline Mod<INT,M> operator%( const Mod<INT,M>& n0 , const Mod<INT,M>& n1 );
template <typename INT , INT M> Mod<INT,M> Inverse( const Mod<INT,M>& n );
template <typename INT , INT M> Mod<INT,M> Power( const Mod<INT,M>& n , const INT& p , const bool& is_binary_method = false );

#include "a_Alias.hpp"
