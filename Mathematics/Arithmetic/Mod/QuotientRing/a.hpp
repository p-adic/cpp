// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a.hpp

#pragma once

template <typename INT>
class QuotientRing
{

protected:
  INT m_n;
  const INT* m_p_M;

public:
  inline QuotientRing() noexcept;
  inline QuotientRing( const INT& n , const INT* const& p_M = nullptr ) noexcept;
  inline QuotientRing( const QuotientRing<INT>& n ) noexcept;

  inline QuotientRing<INT>& operator+=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator+=( const INT& n ) noexcept;
  // operator<が定義されていても負の数は正に直さず剰余を取ることに注意。
  inline QuotientRing<INT>& operator-=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator-=( const INT& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const INT& n ) noexcept;
  // *m_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  inline QuotientRing<INT>& operator/=( const QuotientRing<INT>& n );
  inline QuotientRing<INT>& operator/=( const INT& n );

  // m_nの正負やm_p_Mの一致込みの等号。
  inline bool operator==( const QuotientRing<INT>& n ) const noexcept;
  inline bool operator!=( const QuotientRing<INT>& n ) const noexcept;

  template <typename T> inline QuotientRing<INT> operator+( const T& n1 ) const noexcept;
  inline QuotientRing<INT> operator-() const noexcept;
  template <typename T> inline QuotientRing<INT> operator-( const T& n1 ) const noexcept;
  template <typename T> inline QuotientRing<INT> operator*( const T& n1 ) const noexcept;
  // *m_p_Mが素数でかつn1の逆元が存在する場合のみサポート。
  template <typename T> inline QuotientRing<INT> operator/( const T& n1 ) const;

  inline const INT& Represent() const noexcept;
  inline const INT& GetModulo() const noexcept;
  inline void SetModulo( const INT* const& p_M = nullptr ) noexcept;

  template <typename T> static QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
  // *m_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  static QuotientRing<INT> Inverse( const QuotientRing<INT>& n );
  
};

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
// *(n.m_p_M)が素数でかつnの逆元が存在する場合のみサポート。
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n );
