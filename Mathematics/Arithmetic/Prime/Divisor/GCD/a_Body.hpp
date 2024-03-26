// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/GCD/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT GCD( const INT& b_0 , const INT& b_1 )
{

  INT a_0 = abs( b_0 );
  INT a_1 = abs( b_1 );

  while( a_1 != 0 ){

    swap( a_0 %= a_1 , a_1 );

  }

  return a_0;

}

DEFINITION_OF_UNSIGNED_GCD( uint );
DEFINITION_OF_UNSIGNED_GCD( ull );

template <typename INT> inline INT LCM( const INT& b_0 , const INT& b_1 ) { return ( b_0 == 0 && b_1 == 0 ) ? 0 : ( b_0 / GCD( b_0 , b_1 ) ) * b_1; }
