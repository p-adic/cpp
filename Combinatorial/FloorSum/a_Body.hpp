// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/FloorSum/a_Body.hpp

#pragma once
#include "a.hpp"

// FloorReimanZetaに使用
#include "../../Arithmetic/Sqrt/a_Body.hpp"
#include "../../Arithmetic/Power/a_Body.hpp"

template <typename INT>
INT FloorSum( const INT& y , const INT& d , const INT& q , const INT& n )
{

  if( n == 0 ){

    return 0;
    
  } else if( n == 1 ){

    return y / q;

  }

  // q=1の時value_lim=0となり再帰が終了する。
  const INT r_0 = y % q;
  const INT r_1 = d % q;
  const INT value_lim = ( r_0 + r_1 * n ) / q;
  INT answer = ( y / q ) * n + ( d / q ) * ( n >> 1 ) * ( n - ( ( n & 1 ) ^ 1 ) );
  
  if( value_lim != 0 ){

    const INT r_1_n_approx = value_lim * q - r_0;
    const INT e = r_1_n_approx % r_1;
    // r_1 == 0と仮定するとvalue_lim == r_0 / qすなわちvalue_lim == 0となり矛盾する。
    // (d,q)->(q,r_1)はユークリッドの互除法なのでO(log_2 min(d,q))回の再帰となる。
    answer += ( n - ( ( r_1_n_approx + ( r_1 - 1 ) ) / r_1 ) ) * value_lim + FloorSum<INT>( e == 0 ? 0 : r_1 - e , q , r_1 , value_lim );
    
  }
  
  return answer;
  
}

template <typename INT>
INT FloorRiemanZeta( const INT& n , const INT& exponent )
{

  INT i_max = RoundDownSqrt( n );
  INT answer = 0;

  for( INT i = 1 ; i <= i_max ; i++ ){

    answer += ( n / i - n / ( i + 1 ) ) * Power( i , exponent );

  }

  i_max = n / ( i_max + 1 );

  for( INT i = 1 ; i <= i_max ; i++ ){

    answer += Power( n / i , exponent );

  }

  return answer;

}

template <typename INT> inline INT HarmonicFloorSum( const INT& n ){ return n < 0 ? - FloorRiemanZeta<INT>( - n - 1 , 1 ) - n : FloorRiemanZeta<INT>( n , 1 ); }
