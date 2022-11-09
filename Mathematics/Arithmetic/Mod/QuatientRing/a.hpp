// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a.hpp

#pragma once

template <typename INT>
class QuotientRing
{

protected:
  INT m_n;
  const INT* m_p_M;

public:
  inline QuotientRing() noexcept;
  inline QuotientRing( const INT& n , const INT* const & p_M = nullptr ) noexcept;
  inline QuotientRing( const QuotientRing<INT>& n ) noexcept;

  inline QuotientRing<INT>& operator+=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator+=( const INT& n ) noexcept;
  // operator<が定義されていても負の数は正に直さず剰余を取ることに注意。
  inline QuotientRing<INT>& operator-=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator-=( const INT& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const QuotientRing<INT>& n ) noexcept;
  inline QuotientRing<INT>& operator*=( const INT& n ) noexcept;

  inline const INT& Represent() const noexcept;
  inline const INT& GetModulo() const noexcept;

  // m_nの正負やm_p_Mの一致込みの等号。
  static inline bool Equal( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept;

  template <typename T> static QuotientRing<INT> Power( const QuotientRing<INT>& n , const T& exponent );
  
};

template <typename INT> inline bool operator==( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept;
template <typename INT> inline bool operator!=( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept;

template <typename INT , typename T> inline QuotientRing<INT> operator+( const QuotientRing<INT>& n0 , const T& n1 ) noexcept;
template <typename INT , typename T> inline QuotientRing<INT> operator-( const QuotientRing<INT>& n0 , const T& n1 ) noexcept;
template <typename INT , typename T> inline QuotientRing<INT> operator*( const QuotientRing<INT>& n0 , const T& n1 ) noexcept;

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , const T& exponent );
