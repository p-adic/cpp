// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Power/a_Body.hpp"

template <typename INT , typename RET>
vector<RET> DivisorSum( const INT& n , const INT& m , const int& exponent )
{

  assert( exponent >= 0 );
  vector<RET> answer( n + 1 );
  const INT d_max = min( n , m );

  for( INT d = 1 ; d <= d_max ; d++ ){

    const RET power = Power( d , exponent );
    
    for( int i = d ; i <= n ; i += d ){

      answer[i] += power;

    }

  }

  return answer;

}
