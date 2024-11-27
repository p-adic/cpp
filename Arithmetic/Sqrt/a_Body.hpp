// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename INT>
INT RoundDownSqrt( const INT& n )
{

  assert( n >= 0 );
  
  if( n <= 1 ){

    return n;
    
  }
  
  INT l = 1 , r = n;

  while( l < r - 1 ){

    const INT m = ( l + r ) >> 1;
    // m * m <= n‚©”Û‚©‚ð”»’èB
    ( m <= n / m ? l : r ) = m;

  }

  return l;

}

template <typename INT>
INT RoundUpSqrt( const INT& n )
{
  
  assert( n >= 0 );

  if( n <= 2 ){

    return n;
    
  }

  const INT n_minus = n - 1;
  INT l = 1 , r = n;

  while( l + 1 < r ){

    const INT m = ( l + r ) >> 1;
    // m * m < n‚©”Û‚©‚ð”»’èB
    ( m <= n_minus / m ? l : r ) = m;

  }

  return r;

}
