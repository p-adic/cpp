// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/a.hpp

#pragma once

template <typename INT>
class QuadraticExtension
{

private:
  INT m_a;
  INT m_b;
  const INT* m_p_D;
  static const INT g_zero = 0;
  
public:
  inline QuadraticExtension( const INT& a = 0 ) noexcept;
  inline QuadraticExtension( const INT& a , const INT& b , const INT* const & p_D ) noexcept;
  inline QuadraticExtension( const QuadraticExtension<INT>& n ) noexcept;

  inline const INT& GetA() const noexcept;
  inline const INT& GetB() const noexcept;
  inline const INT& GetD() const noexcept;

  inline QuadraticExtension<INT>& operator+=( const QuadraticExtension<INT>& n ) noexcept;
  template <typename T> inline QuadraticExtension<INT>& operator+=( const T& a ) noexcept;
  inline QuadraticExtension<INT>& operator-=( const QuadraticExtension<INT>& n ) noexcept;
  template <typename T> inline QuadraticExtension<INT>& operator-=( const T& a ) noexcept;

  // 3数の乗法が入るのでオーバーフローに注意
  // 10^6より大きいmodで計算する時はINTにMod<M>などを代入するか乗法の定義を修正する
  inline QuadraticExtension<INT>& operator*=( const QuadraticExtension<INT>& n ) noexcept;
  template <typename T> inline QuadraticExtension<INT>& operator*=( const T& a ) noexcept;
  template <typename T> inline QuadraticExtension<INT>& operator/=( const T& a ) noexcept;
  template <typename T> inline QuadraticExtension<INT>& operator%=( const T& a ) noexcept;

  // m_p_Dの一致込みの等号
  static inline bool Equal( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
  
};

template <typename INT> inline bool operator==( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> inline bool operator!=( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;

template <typename INT> inline QuadraticExtension<INT> operator+( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator+( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> inline QuadraticExtension<INT> operator-( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator-( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> inline QuadraticExtension<INT> operator*( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator*( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept;
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator/( const QuadraticExtension<INT>& n , const T& a ) noexcept;
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator%( const QuadraticExtension<INT>& n , const T& a ) noexcept;

// Dは一時変数でない変数
template <typename INT> inline QuadraticExtension<INT> Sqrt( const INT& D ) noexcept;

