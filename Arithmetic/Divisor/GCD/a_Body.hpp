// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/GCD/a_Body.hpp

#pragma once
#include "a.hpp"

inline int GCD() { return 0; }

template <typename INT1 , typename...INT2>
INT1 GCD( INT1 b_0 , INT2... args )
{

  b_0 < 0 ? b_0 = -b_0 : b_0;
  INT1 b_1 = GCD( move( args )... );
  
  while( b_1 != 0 ){

    swap( b_0 %= b_1 , b_1 );

  }

  return move( b_0 );

}

template <typename INT , template <typename...> typename V>
INT GCD( V<INT> a )
{

  INT answer = 0;
  
  for( auto& b : a ){

    answer = GCD( move( answer ) , b );

  }

  return answer;

}


inline int LCM() { return 0; }

template <typename INT1 , typename...INT2>
INT1 LCM( INT1 b_0 , INT2... args )
{

  b_0 < 0 ? -b_0 : b_0;
  INT1 b_1 = LCM( move( args )... );
  return b_1 == 0 ? b_0 : b_0 / GCD( b_0 , b_1 ) * b_1;

}

template <typename INT , template <typename...> typename V>
INT LCM( V<INT> a )
{

  INT answer = 1;
  
  for( auto& b : a ){

    answer = LCM( move( answer ) , b );

  }

  return answer;

}
