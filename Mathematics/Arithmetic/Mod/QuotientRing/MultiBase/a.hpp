// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/MultiBase/a.hpp

#pragma once

// verify:
https://yukicoder.me/submissions/939377

// インスタンスごとに異なる法を定めたい場合に用いる。
// ポインタを持たせる分メモリ使用量が膨れ上がることに注意。
template <typename INT>
class MultiBaseQuotientRing
{

protected:
  INT m_n;
  const INT* m_p_M;
  static const INT* g_p_M;

public:
  inline MultiBaseQuotientRing() noexcept;
  inline MultiBaseQuotientRing( const INT& n , const INT* const& p_M = g_p_M ) noexcept;
  inline MultiBaseQuotientRing( const MultiBaseQuotientRing<INT>& n ) noexcept;

  inline MultiBaseQuotientRing<INT>& operator+=( const MultiBaseQuotientRing<INT>& n ) noexcept;
  template <typename T> inline MultiBaseQuotientRing<INT>& operator+=( const T& n ) noexcept;
  // operator<が定義されていても負の数は正に直さず剰余を取ることに注意。
  inline MultiBaseQuotientRing<INT>& operator-=( const MultiBaseQuotientRing<INT>& n ) noexcept;
  template <typename T> inline MultiBaseQuotientRing<INT>& operator-=( const T& n ) noexcept;
  inline MultiBaseQuotientRing<INT>& operator*=( const MultiBaseQuotientRing<INT>& n ) noexcept;
  template <typename T> inline MultiBaseQuotientRing<INT>& operator*=( const T& n ) noexcept;
  // *m_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  inline MultiBaseQuotientRing<INT>& operator/=( const MultiBaseQuotientRing<INT>& n );
  template <typename T> inline MultiBaseQuotientRing<INT>& operator/=( const T& n );

  // m_nの正負やm_p_Mの一致込みの等号。
  inline bool operator==( const MultiBaseQuotientRing<INT>& n ) const noexcept;
  // m_nの正負込みの等号。
  template <typename T> inline bool operator==( const T& n ) const noexcept;
  template <typename T> inline bool operator!=( const T& n ) const noexcept;

  template <typename T> inline MultiBaseQuotientRing<INT> operator+( const T& n1 ) const noexcept;
  inline MultiBaseQuotientRing<INT> operator-() const noexcept;
  template <typename T> inline MultiBaseQuotientRing<INT> operator-( const T& n1 ) const noexcept;
  template <typename T> inline MultiBaseQuotientRing<INT> operator*( const T& n1 ) const noexcept;
  // *m_p_Mが素数でかつn1の逆元が存在する場合のみサポート。
  template <typename T> inline MultiBaseQuotientRing<INT> operator/( const T& n1 ) const;
  template <typename T> MultiBaseQuotientRing<INT> operator^( T exponent );

  inline const INT& Represent() const noexcept;
  inline const INT& GetModulo() const noexcept;
  inline void SetModulo( const INT* const& p_M = nullptr ) noexcept;
  static inline const INT& GetStaticModulo() noexcept;
  static inline void SetStaticModulo( const INT* const& p_M ) noexcept;

  // *m_p_Mが素数でかつnの逆元が存在する場合のみサポート。
  static MultiBaseQuotientRing<INT> Inverse( const MultiBaseQuotientRing<INT>& n );
  
};

template <typename INT , typename T> inline MultiBaseQuotientRing<INT> Power( const MultiBaseQuotientRing<INT>& n , T exponent );
// *(n.m_p_M)が素数でかつnの逆元が存在する場合のみサポート。
template <typename INT> inline MultiBaseQuotientRing<INT> Inverse( const MultiBaseQuotientRing<INT>& n );

template <typename INT , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , MultiBaseQuotientRing<INT>& n );
template <typename INT , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MultiBaseQuotientRing<INT>& n );
