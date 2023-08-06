// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/GCD/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT GCD( const INT& b_0 , const INT& b_1 )
{

  INT b[2] = { b_0 , b_1 };
  int i_0 = ( b_0 >= b_1 ? 0 : 1 );
  int i_1 = 1 - i_0;

  while( b[i_1] != 0 ){

    b[i_0] %= b[i_1];
    swap( i_0 , i_1 );

  }

  return b[i_0];

}

template <typename INT> inline INT LCM( const INT& b_0 , const INT& b_1 ) { return ( b_0 == 0 && b_1 == 0 ) ? 0 : ( b_0 / GCD( b_0 , b_1 ) ) * b_1; }
