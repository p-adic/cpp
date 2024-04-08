// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/Moevius/Constexpr/a.hpp

#pragma once
#include "../../a.hpp"

template <typename INT , INT val_limit>
class MoeviusFunction
{

private:
  INT m_val[val_limit];

public:
  // O(val_limit)
  inline constexpr MoeviusFunction( const LeastDivisor<INT,val_limit>& ld ) noexcept;

  inline const INT& operator()( const int& n ) const;

};

