// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "../a.hpp"

template <typename T>
class TruncatedPolynomial :
  public Polynomial<T>
{

private:
  // m_N == 0でも動くが、その場合はm_size == 1の時にm_size <= m_Nが成り立たなくなることに注意
  uint m_N;
  
public:
  inline TruncatedPolynomial( const uint& N = 0 );
  inline TruncatedPolynomial( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , const T& t );
  TruncatedPolynomial( const uint& N , const Polynomial<T>& f );
  inline TruncatedPolynomial( const uint& N , const uint& i , const T& t );

  // m_Nも代入されることに注意
  inline TruncatedPolynomial<T>& operator=( const TruncatedPolynomial<T>& f );
  inline TruncatedPolynomial<T>& operator=( const T& t );
  inline TruncatedPolynomial<T>& operator=( const Polynomial<T>& f );

  // m_Nは変化しないことに注意
  inline TruncatedPolynomial<T>& operator+=( const T& t );
  TruncatedPolynomial<T>& operator+=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator-=( const T& t );
  TruncatedPolynomial<T>& operator-=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator*=( const T& t );
  TruncatedPolynomial<T>& operator*=( const Polynomial<T>& f );
  inline TruncatedPolynomial<T>& operator/=( const T& t );
  inline TruncatedPolynomial<T>& operator/=( const TruncatedPolynomial<T>& t );
  inline TruncatedPolynomial<T>& operator%=( const T& t );

  inline TruncatedPolynomial<T> operator-() const;

  inline void SetTruncation( const uint& N ) noexcept;
  inline const uint& GetTruncation() const noexcept;

private:
  inline void Truncate();

};

template <typename T , typename P> inline TruncatedPolynomial<T> operator+( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f );
template <typename T , typename P> inline TruncatedPolynomial<T> operator-( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator*( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T , typename P> inline TruncatedPolynomial<T> operator/( const TruncatedPolynomial<T>& f0 , const P& f1 );
template <typename T> inline TruncatedPolynomial<T> operator%( const TruncatedPolynomial<T>& f0 , const T& t1 );

// m_Nが1下がることに注意
template <typename T>
TruncatedPolynomial<T> Differential( const TruncatedPolynomial<T>& f );
// m_Nがi下がることに注意
template <typename T> inline TruncatedPolynomial<T> Differential( const uint& i , const TruncatedPolynomial<T>& f );

// m_Nが1上がることに注意
// Tが標数0またはf.m_N + 1以上の体の場合のみサポート
template <typename T>
TruncatedPolynomial<T> Integral( const TruncatedPolynomial<T>& f );

// f[0]が可逆な場合のみサポート
template <typename T>
TruncatedPolynomial<T> Inverse( const TruncatedPolynomial<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 0の場合のみサポート
template <typename T>
TruncatedPolynomial<T> Exp( const TruncatedPolynomial<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 1の場合のみサポート
template <typename T> inline TruncatedPolynomial<T> Log( const TruncatedPolynomial<T>& f );

// Tが標数0またはf.m_N以上の体でかつf[0] == 1の場合のみサポート
template <typename T>
TruncatedPolynomial<T> Power( const TruncatedPolynomial<T>& f , const T& t );

