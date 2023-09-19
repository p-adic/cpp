// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/a.hpp

#pragma once

template <typename T , uint exponent_lim>
class Power_constexpr
{
public:
  T m_val[exponent_lim];
  inline constexpr Power_constexpr( const T& t , const T& init = T( 1 ) );
  
};
