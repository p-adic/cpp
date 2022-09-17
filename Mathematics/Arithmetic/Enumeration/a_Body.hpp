// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Dimension/a_Body.hpp"
#include "../../../Utility/List/a_Body.hpp"

inline void BijSum12( const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 ) { BijSum12( infty() , infty() , n , n_1 , n_2 ); }

inline INT_TYPE_FOR_DIM BijSum21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 ) { return BijSum21( infty() , infty() , n_1 , n_2 ); }

inline void BijProd12( const INT_TYPE_FOR_DIM& n , INT_TYPE_FOR_DIM& n_1 , INT_TYPE_FOR_DIM& n_2 ) { BijProd12( infty() , infty() , n , n_1 , n_2 ); }

inline INT_TYPE_FOR_DIM BijProd21( const INT_TYPE_FOR_DIM& n_1 , const INT_TYPE_FOR_DIM& n_2 ) { return BijProd21( infty() , infty() , n_1 , n_2 ); }


template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n )
{

  const INT r_0 = a_0 % q;
  const INT r_1 = a_1 % q;
  const INT value_lim = ( r_0 + r_1 * n ) / q;
  INT answer = ( a_0 / q ) * ( n % 2 == 0 ? ( n / 2 ) * ( n - 1 ) : n * ( ( n - 1 ) / 2 ) ) + ( a_1 / q );
  
  if( value_lim != 0 ){

    const INT r_1_a_approx = value_lim * q - r_0;
    const INT e = r_1_a_approx % r_1;
    // r_1 == 0Ç∆âºíËÇ∑ÇÈÇ∆value_lim == r_0 / qÇ∑Ç»ÇÌÇøvalue_lim == 0Ç∆Ç»ÇËñµèÇÇ∑ÇÈÅB
    answer += ( n - ( ( r_1_a_approx + ( r_1 - 1 ) ) / r_1 ) ) * value_lim + FloorSum( e == 0 ? 0 : r_1 - e , q , r_1 , value_lim );
    
  }
  
  return answer;
  
}
