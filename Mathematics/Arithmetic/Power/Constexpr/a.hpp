// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/a.hpp

#pragma once

template <typename T , uint exponent_lim>
class Power_constexpr
{
public:
  T m_val[exponent_lim];
  inline constexpr Power_constexpr( const T& t , const T& init = T( 1 ) );
  
};

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <int N>
class PowerInverse_constexpr
{
public:
  int m_val;
  inline constexpr PowerInverse_constexpr();
};
