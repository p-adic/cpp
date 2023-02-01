// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/CRT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Residue/a_Body.hpp"

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

template <typename INT>
INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 )
{
  
  INT a[2][2];
  INT b[2] = { b_0 , b_1 };
  int i_0 = ( b_0 >= b_1 ? 0 : 1 );
  int i_1 = 1 - i_0;

  for( uint i = 0 ; i < 2 ; i++ ){

    INT ( & ai )[2] = a[i];

    for( uint j = 0 ; j < 2 ; j++ ){
      ai[j] = ( i == j ? 1 : 0 );
    }

  }
  
  INT q;

  while( b[i_1] != 0 ){

    INT& b_i_0 = b[i_0];
    INT& b_i_1 = b[i_1];
    INT ( &a_i_0 )[2] = a[i_0];
    INT ( &a_i_1 )[2] = a[i_1];
    q = b_i_0 / b_i_1;
    a_i_0[i_0] -= q * a_i_1[i_0];
    a_i_0[i_1] -= q * a_i_1[i_1];
    b_i_0 %= b_i_1;
    swap( i_0 , i_1 );

  }

  INT& gcd = b[i_0];
  INT c = c_0 % gcd;

  if( c_1 % gcd != c ){

    return -1;

  }
  
  INT lcm = ( b_0 / gcd ) * b_1;
  INT ( &a_i_0 )[2] = a[i_0];
  INT& a_i_00 = a_i_0[0];
  a_i_00 *= ( c_1 - c ) / gcd;
  Residue( a_i_00 , lcm );
  INT& a_i_01 = a_i_0[1];
  a_i_01 *= ( c_0 - c ) / gcd;
  a_i_01 = ( a_i_01 >= 0 ? a_i_01 % lcm : lcm - ( - a_i_01 - 1 ) % lcm - 1 );
  return ( c + a_i_00 * b_0 + a_i_01 * b_1 ) % lcm;

}
