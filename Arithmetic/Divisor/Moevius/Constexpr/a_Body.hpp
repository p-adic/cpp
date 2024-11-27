// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Moevius/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename INT , INT val_limit> inline constexpr MoeviusFunction<INT,val_limit>::MoeviusFunction( const LeastDivisor<INT,val_limit>& ld ) noexcept : m_val{ 0 , 1 }
{

  for( int i = 2 ; i < val_limit ; i++ ){

    auto& p = ld[i];
    const int j = i / p;
    m_val[i] = j % p == 0 ? 0 : -m_val[j];
    
  }

}

template <typename INT , INT val_limit> inline const INT& MoeviusFunction<INT,val_limit>::operator()( const int& n ) const { assert( 0 <= n && n < val_limit ); return m_val[n]; }
