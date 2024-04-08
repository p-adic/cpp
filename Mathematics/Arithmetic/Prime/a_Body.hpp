// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constexpr/a_Body.hpp"

template <typename INT>
const INT& GetPrime( const INT& i ) noexcept
{

  static vector<INT> P{ 2 , 3 , 5 , 7 , 11 };

  INT L = P.size();

  while( i >= L ){

    INT p = P.back() + 2;

    bool prime = false;

    while( ! prime ){

      prime = true;
    
      for( INT j = 0 ; j < L && prime ; j++ ){

	INT& Pj = P[j];
	prime = ( p % Pj != 0 );

	if( Pj * Pj >= p ){

	  j = L;
	
	}

      }

      if( ! prime ){

	p += 2;

      }

    }

    P.push_back( p );
    L++;

  }

  return P[i];

}

template <typename INT , INT N>
const INT& GetPrimeBounded( const INT& i )
{

  static INT P[N] = { 2 , 3 , 5 , 7 , 11 };

  INT L = 5;

  while( i >= L ){

    INT p = P[L - 1] + 2;

    bool prime = false;

    while( ! prime ){

      prime = true;
    
      for( INT j = 0 ; j < L && prime ; j++ ){

	INT& Pj = P[j];
	prime = ( p % Pj != 0 );

	if( Pj * Pj >= p ){

	  j = L;
	
	}

      }

      if( ! prime ){

	p += 2;

      }

    }

    P[L++] = p;

  }

  return P[i];

}
