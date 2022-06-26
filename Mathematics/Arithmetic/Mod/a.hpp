// Mod/a.hpp

#pragma once

template <int M>
class Mod
{

protected:
  int m_n;
  int m_inv;
  
  static int Residue( const int& n ) noexcept;

public:
  Mod() noexcept;
  Mod( const int& n ) noexcept;
  Mod( const Mod<M>& n ) noexcept;
  Mod<M>& operator=( const int& n ) noexcept;
  Mod<M>& operator=( const Mod<M>& n ) noexcept;
  Mod<M>& operator+=( const int& n ) noexcept;
  Mod<M>& operator+=( const Mod<M>& n ) noexcept;
  Mod<M>& operator-=( const int& n ) noexcept;
  Mod<M>& operator-=( const Mod<M>& n ) noexcept;
  Mod<M>& operator*=( const int& n ) noexcept;
  Mod<M>& operator*=( const Mod<M>& n ) noexcept;

  // intでの割り算ではないことに注意
  virtual Mod<M>& operator/=( const int& n );
  virtual Mod<M>& operator/=( const Mod<M>& n );
  
  Mod<M>& operator%=( const int& n );
  Mod<M>& operator%=( const Mod<M>& n );

  // 前置++/--を使うつもりがないので後置++/--と同じものとして定義する
  inline const Mod<M>& operator++() noexcept;
  inline const Mod<M>& operator++( const int& ) noexcept;
  inline const Mod<M>& operator--() noexcept;
  inline const Mod<M>& operator--( const int& ) noexcept;
  
  inline const int& Represent() const noexcept;
  void Invert() noexcept;
  bool CheckInvertible() noexcept;
  bool IsSmallerThan( const int& n ) const noexcept;
  bool IsBiggerThan( const int& n ) const noexcept;

};

template <int M> inline bool operator==( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator==( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator==( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> inline bool operator!=( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator!=( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator!=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> inline bool operator<( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator<( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator<( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> inline bool operator<=( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator<=( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator<=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> inline bool operator>( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator>( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator>( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> inline bool operator>=( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> inline bool operator>=( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> inline bool operator>=( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;

template <int M> Mod<M> operator+( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> Mod<M> operator+( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator+( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator-( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> Mod<M> operator-( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator-( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator*( const Mod<M>& n0 , const int& n1 ) noexcept;
template <int M> Mod<M> operator*( const int& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator*( const Mod<M>& n0 , const Mod<M>& n1 ) noexcept;
template <int M> Mod<M> operator/( const Mod<M>& n0 , const int& n1 );
template <int M> Mod<M> operator/( const int& n0 , const Mod<M>& n1 );
template <int M> Mod<M> operator/( const Mod<M>& n0 , const Mod<M>& n1 );
template <int M> Mod<M> operator%( const Mod<M>& n0 , const int& n1 );
template <int M> Mod<M> operator%( const int& n0 , const Mod<M>& n1 );
template <int M> Mod<M> operator%( const Mod<M>& n0 , const Mod<M>& n1 );
template <int M> Mod<M> Inverse( const Mod<M>& n );
template <int M> Mod<M> Power( const Mod<M>& n , const int& p , const bool& is_binary_method = false );
