// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/939377

// インスタンスごとに異なる法を定めたい場合は
// MultiBase/a.hpp
// のクラスを用いる。
template <typename INT>
class QuotientRing
{

protected:
  INT m_n;
  static const INT* g_p_M;

public:
  inline QuotientRing() noexcept;
  inline QuotientRing( const INT& n ) noexcept;
  inline QuotientRing( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing( QuotientRing<INT>&& n ) noexcept;

  inline QuotientRing<INT>& operator=( QuotientRing<INT> n ) noexcept;
  inline QuotientRing<INT>& operator+=( const QuotientRing<INT>& n ) noexcept;
  // operator<が定義されていても負の数は正に直さず剰余を取ることに注意。
  inline QuotientRing<INT>& operator-=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const QuotientRing<INT>& n ) noexcept;
  // *g_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  inline QuotientRing<INT>& operator/=( QuotientRing<INT> n );

  // m_nの正負込みの等号。
  inline bool operator==( const QuotientRing<INT>& n ) const noexcept;
  // m_nの正負込みの等号。
  inline bool operator!=( const QuotientRing<INT>& n ) const noexcept;

  inline QuotientRing<INT> operator+( QuotientRing<INT> n1 ) const noexcept;
  inline QuotientRing<INT> operator-() const noexcept;
  inline QuotientRing<INT> operator-( QuotientRing<INT> n1 ) const noexcept;
  inline QuotientRing<INT> operator*( QuotientRing<INT> n1 ) const noexcept;
  // *g_p_Mが素数でかつn1の逆元が存在する場合のみサポート。
  inline QuotientRing<INT> operator/( const QuotientRing<INT>& n1 ) const;
  template <typename T> QuotientRing<INT> operator^( T exponent );

  inline const INT& Represent() const noexcept;
  static inline const INT& GetModulo() noexcept;
  static inline void SetModulo( const INT* const& p_M ) noexcept;

  // *g_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  static QuotientRing<INT> Inverse( const QuotientRing<INT>& n );
  
};

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent );
// *g_p_Mが素数でかつnの逆元が存在する場合のみサポート。
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n );

template <typename INT , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , QuotientRing<INT>& n );
template <typename INT , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const QuotientRing<INT>& n );
