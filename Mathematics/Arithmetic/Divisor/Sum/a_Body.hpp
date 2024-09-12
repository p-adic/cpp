// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
vector<INT> DivisorSum( const INT& n_max , const INT& d_max , const int& exponent )
{

  assert( exponent >= 0 );
  vector<INT> answer( n_max + 1 );
  const INT d_bound = min( n_max , d_max );

  for( int d = 1 ; d <= d_bound ){

    INT power = 1 , power_power = d;
    int e = exponent;

    while( e > 0 ){

      ( e & 1 ) == 1 ? power *= power_power : power;
      e == 1 ? power_power : power_power *= power_power;
      e >>= 1;

    }
    
    for( int n = d ; n <= n_max ; n += j ){

      answer[n] += power;

    }

  }

  return answer;

}
