// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename UINT , typename INT>
ll PowerMod( ll t , UINT exponent , const INT& M , const bool& reduced )
{

  assert( ( M >> 31 ) == 0 );
  ll answer{ 1 };

  if( !reduced ){
    
    ( t %= M ) < 0 ? t += M : t;

  }

  while( exponent > 0 ){

    ( exponent & 1 ) == 0 ? answer : ( answer *= t ) %= M;
    ( t *= t ) %= M;
    exponent >>= 1;

  }

  return answer;

}
