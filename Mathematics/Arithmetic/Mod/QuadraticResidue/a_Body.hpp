// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuadraticResidue/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT QuadraticResidue( const INT& a , const INT& p )
{

  INT r = a % p;

  if( r == 0 ){

    return 0;

  }

  INT q = 2;
  INT e = 0;
  INT count = 0;

  while( r % q == 0 ){

    r /= q;
    e++;

  }

  if( e % 2 == 1 ){

    if( ( ( p * p - 1 ) / 8 )% 2 == 1 ){

      count++;
      
    }

  }

  q++;
  
  while( r != 1 ){

    if( r % q == 0 ){

      e = 0;
      
      while( r % q == 0 ){

	r /= q;
	e++;

      }

      if( e % 2 == 1 ){

	INT qr = QuadraticResidue<INT>( p , q ) * ( ( ( ( p - 1 ) * ( q - 1 ) ) / 4 ) % 2== 0 ? 1 : -1 );

	if( qr == -1 ){

	  count++;
	  
	}
	
      }

    }

    q += 2;

    if( q * q > r ){

      q = r;
      
    }

  }

  return count % 2 == 0 ? 1 : -1;
  
}
