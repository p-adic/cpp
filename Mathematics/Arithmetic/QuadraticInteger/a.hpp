// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticInteger/a.hpp

#pragma once
#include "a_Alias.hpp"

class QuadraticInteger
{

private:
  IntTypeForQuadraticInteger m_a;
  IntTypeForQuadraticInteger m_b;
  const IntTypeForQuadraticInteger* m_p_D;

public:
  inline QuadraticInteger( const IntTypeForQuadraticInteger& a = 0 , const IntTypeForQuadraticInteger& b = 0 , const IntTypeForQuadraticInteger* const & p_D = nullptr ) noexcept;
  inline QuadraticInteger( const QuadraticInteger& n ) noexcept;

  inline const IntTypeForQuadraticInteger& GetA() const noexcept;
  inline const IntTypeForQuadraticInteger& GetB() const noexcept;
  inline const IntTypeForQuadraticInteger& GetD() const noexcept;

  inline QuadraticInteger& operator+=( const QuadraticInteger& n ) noexcept;
  inline QuadraticInteger& operator-=( const QuadraticInteger& n ) noexcept;

  // 3数の乗法が入るのでオーバーフローに注意
  // 10^6より大きいmodで計算する時はIntTypeForQuadraticInteger自体をMod<M>としてエイリアスする
  inline QuadraticInteger& operator*=( const QuadraticInteger& n ) noexcept;
  inline QuadraticInteger& operator%=( const IntTypeForQuadraticInteger& a ) noexcept;

  // m_p_Dの一致込みの等号
  static inline bool Equal( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;
  
};

inline bool operator==( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;
inline bool operator!=( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;

inline QuadraticInteger operator+( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;
inline QuadraticInteger operator-( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;
inline QuadraticInteger operator*( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept;
inline QuadraticInteger operator%( const QuadraticInteger& n , const IntTypeForQuadraticInteger& a ) noexcept;
