// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/LatticePoint/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n )
{

  if( n == 0 ){

    return 0;
    
  } else if( n == 1 ){

    return a_0 / q;

  }
  
  const INT r_0 = a_0 % q;
  const INT r_1 = a_1 % q;
  const INT value_lim = ( r_0 + r_1 * n ) / q;
  INT answer = ( a_0 / q ) * n + ( a_1 / q ) * ( n % 2 == 0 ? ( n / 2 ) * ( n - 1 ) : n * ( ( n - 1 ) / 2 ) );
  
  if( value_lim != 0 ){

    const INT r_1_n_approx = value_lim * q - r_0;
    const INT e = r_1_n_approx % r_1;
    // r_1 == 0Ç∆âºíËÇ∑ÇÈÇ∆value_lim == r_0 / qÇ∑Ç»ÇÌÇøvalue_lim == 0Ç∆Ç»ÇËñµèÇÇ∑ÇÈÅB
    answer += ( n - ( ( r_1_n_approx + ( r_1 - 1 ) ) / r_1 ) ) * value_lim + FloorSum( e == 0 ? 0 : r_1 - e , q , r_1 , value_lim );
    
  }
  
  return answer;
  
}

