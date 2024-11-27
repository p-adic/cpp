// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/PowerPower/a.hpp

#pragma once

template <typename T , int exponent_lim>
class PowerPower_constexpr
{
private:
// t^{2^i}Çm_val[i]Ç…äiî[ÅB
  T m_val[exponent_lim];

public:
  inline constexpr PowerPower_constexpr( const T& t );

  inline constexpr const T& operator[]( const int& i ) const;
  inline constexpr const T ( &Get() const )[exponent_lim];
  
};
