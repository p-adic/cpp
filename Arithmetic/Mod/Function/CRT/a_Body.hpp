// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Prime/Divisor/GCD/a_Body.hpp"
#include "../Residue/a_Body.hpp"

template <typename INT>
INT PartitionOfUnity( const INT& b_0 , const INT& b_1 , INT& u_0 ,  INT& u_1 )
{

  INT a[2][2] = { { 1 , 0 } , { 0 , 1 } };
  INT b[2] = { b_0 , b_1 };

  for( int i = 0 ; i < 2 ; i++ ){

    if( b[i] < 0 ){

      a[i][i] = -1;
      b[i] *= -1;

    }

  }
  
  int i_0 = ( b_0 >= b_1 ? 0 : 1 );
  int i_1 = 1 - i_0;

  while( b[i_1] != 0 ){

    INT& b_i_0 = b[i_0];
    const INT& b_i_1 = b[i_1];
    INT ( &a_i_0 )[2] = a[i_0];
    const INT ( &a_i_1 )[2] = a[i_1];
    const INT q = b_i_0 / b_i_1;
    a_i_0[i_0] -= q * a_i_1[i_0];
    a_i_0[i_1] -= q * a_i_1[i_1];
    b_i_0 -= q * b_i_1;
    swap( i_0 , i_1 );

  }

  INT ( &a_i_0 )[2] = a[i_0];
  u_0 = move( a_i_0[0] );
  u_1 = move( a_i_0[1] );
  return move( b[i_0] );

}

template <typename INT>
INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 )
{

  INT u_0 , u_1;
  const INT gcd = PartitionOfUnity( b_0 , b_1 , u_0 , u_1 );
  const INT c = c_0 % gcd;

  if( c_1 % gcd != c ){

    return -1;

  }
  
  const INT lcm = ( b_0 / gcd ) * b_1;
  u_0 *= ( c_1 - c ) / gcd;
  Residue( u_0 , lcm );
  u_1 *= ( c_0 - c ) / gcd;
  u_1 = ( u_1 >= 0 ? u_1 % lcm : lcm - ( - u_1 - 1 ) % lcm - 1 );
  return ( c + u_0 * b_0 + u_1 * b_1 ) % lcm;

}
