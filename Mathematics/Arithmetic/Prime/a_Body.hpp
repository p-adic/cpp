// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a_Body.hpp

#pragma once
#include "a.hpp"

template <uint N>
static const uint& GetPrimeBounded_Body( const uint& i );
{
  
  static uint P[N] = { 2 , 3 , 5 , 7 , 11 };
  static uint L = 5;

  if( i < L ){

    return P[i];

  }

  uint p = P[L - 1] + 2;

  bool prime = false;

  while( ! prime ){

    prime = true;
    
    for( uint j = 0 ; j < L && prime ; j++ ){

      uint& Pj = P[j];
      prime = ( p % Pj != 0 );

      if( Pj * Pj >= p ){

	j = L;
	
      }

    }

    if( ! prime ){

      p += 2;

    }

  }

  P[ L ] = p;
  L++;
  return GetPrimeBounded_Body<N>( i );
  
}

template <uint N>
void SetPrimeFactorisationBounded( const uint& n , uint ( &P )[N] , uint ( &exponent )[N] )
{

  uint n_copy = n;
  uint p = 2;
  uint L = 0;

  if( n_copy % p == 0 ){

    P[L] = p;
    uint& exponent_back = exponent[L];
    exponent_back = 1;
    n_copy /= p;
    L++;
    
    while( n_copy % p == 0 ){

      exponent_back++;
      n_copy /= p;
      
    }

  }

  p++;

  while( n_copy != 1 ){

    if( n_copy % p == 0 ){

      P[L] = p;
      uint& exponent_back = exponent[L];
      exponent_back = 1;
      n_copy /= p;
      L++;
    
      while( n_copy % p == 0 ){

	exponent_back++;
	n_copy /= p;
      
      }

    }

    p += 2;

    if( p * p > n_copy ){

      p = n_copy;

    }
    
  }

  return;

}

template <typename INT>
INT GCD( const INT& a , const INT& b )
{
  INT a_c = a >= 0 ? a : -a;
  INT b_c = b >= 0 ? b : -b;
  while( a_c > 0 && b_c > 0 ){
    if( a_c < b_c ){
      b_c -= a_c * ( a_c / b_c );
    } else {
      a_c -= b_c * ( a_c / b_c );
    }
  }
  return a_c > 0 ? a_c : b_c;
}
