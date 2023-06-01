// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/a.hpp

#pragma once

template <typename INT , INT val_limit , int length_max = val_limit>
class PrimeEnumeration
{

public:
  INT m_val[length_max];
  int m_length;
  inline constexpr PrimeEnumeration();

};
