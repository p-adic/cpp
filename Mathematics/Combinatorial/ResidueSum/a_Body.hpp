// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ResidueSum/a_Body.hpp

#pragma once
#include "a.hpp"

// ResidueSumに使用。
#include "../../Arithmetic/Sqrt/a_Body.hpp"
// TotalResidueSumに使用。
#include "../../Arithmetic/Divisor/Sum/a_Body.hpp"

template <typename INT , typename RET>
RET ResidueSum( const INT& n , const INT& m )
{

  INT r = RoundDownSqrt( n );
  RET answer{};

  for( INT i = 1 ; i <= r ; i++ ){

    INT j_llim = min( n / ( i + 1 ) , m ) , j_max = min( n / i , m );
    RET d = j_max - j_llim;
    // 分配律でまとめるとオーバーフローしうることに注意
    answer += n * d - ( j_max + j_llim + 1 ) * d / 2 * i;
 
  }

  if( n < m ){

    answer += ( m - n ) * RET( n );

  }

  r = min( n / ( r + 1 ) , m );

  for( INT j = 1 ; j <= r ; j++ ){

    answer += n % j;

  }

  return answer;
  
}


template <typename INT , typename RET>
vector<RET> TotalResidueSum( const INT& n , const INT& m )
{

  vector<RET> answer( n + 1 ) , sigma = DivisorSum<INT,RET>( n , m );
  RET temp{};

  for( int i = 1 ; i <= n ; i++ ){

    answer[i] = temp += m - sigma[i];

  }
  
  return answer;
  
}
