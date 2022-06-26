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
  Mod( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator=( const INT& n ) noexcept;
  Mod<M>& operator=( const Mod<M>& n ) noexcept;
  Mod<M>& operator+=( const INT& n ) noexcept;
  inline Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  inline Mod<M>& operator-=( const INT& n ) noexcept;
  inline Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  Mod<M>& operator*=( const INT& n ) noexcept;
  Mod<M>& operator*=( const Mod<M>& n ) noexcept;

  // INTでの割り算ではないことに注意
  virtual Mod<M>& operator/=( const INT& n );
  virtual Mod<M>& operator/=( const Mod<M>& n );
  
  Mod<M>& operator%=( const INT& n );
  inline Mod<M>& operator%=( const Mod<M>& n );

  // 前置++/--を使うつもりがないので後置++/--と同じものとして定義する
  inline Mod<M>& operator++() noexcept;
  inline Mod<M>& operator++( int ) noexcept;
  inline Mod<M>& operator--() noexcept;
  inline Mod<M>& operator--( int ) noexcept;
  
  inline const INT& Represent() const noexcept;
  void Invert() noexcept;
  bool CheckInvertible() noexcept;
  bool IsSmallerThan( const INT& n ) const noexcept;
  bool IsBiggerThan( const INT& n ) const noexcept;

};

template <INT M> inline bool operator==( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator==( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> inline bool operator!=( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator!=( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> inline bool operator<( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator<( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> inline bool operator<=( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator<=( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> inline bool operator>( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator>( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> inline bool operator>=( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> inline bool operator>=( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <INT M> Mod<M> operator+( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> Mod<M> operator+( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> inline Mod<M> operator-( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> Mod<M> operator-( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> Mod<M> operator*( const Mod<M>& n0 , const INT& n1 ) noexcept;
template <INT M> Mod<M> operator*( const INT& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <INT M> Mod<M> operator/( const Mod<M>& n0 , const INT& n1 );
template <INT M> Mod<M> operator/( const INT& n0 , const Mod<M>& n1 );
template <INT M> Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 );
template <INT M> Mod<M> operator%( const Mod<M>& n0 , const INT& n1 );
template <INT M> inline Mod<M> operator%( const INT& n0 , const Mod<M>& n1 );
template <INT M> inline Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 );
template <INT M> Mod<M> Inverse( const Mod<M>& n );
template <INT M> Mod<M> Power( const Mod<M>& n , const INT& p , const bool& is_binary_method = false );
