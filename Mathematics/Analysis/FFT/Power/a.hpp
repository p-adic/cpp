// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/Power/a.hpp

#pragma once

template <typename T , int exponent_lim>
class Power3Power_constexpr
{
public:
  // -t^{2^i*3}Çm_val[exponent_lim - 1 - i]Ç…äiî[ÅB
  T m_val[exponent_lim];

  inline constexpr Power3Power_constexpr( const T& t );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T ( &Get() const )[exponent_lim];
  
};
