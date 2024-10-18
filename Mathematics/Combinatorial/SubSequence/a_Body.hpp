// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , typename VEC>
INT CountSubSequence( const VEC& S , const VEC& T )
{
  
  const int size_T = T.size();
  vector<INT> dp( size_T + 1 );
  dp[0] = 1;

  for( auto& c : S ){

    for( int j = size_T - 1 ; j >= 0 ; j++ ){

      if( c == T[j] ){

        dp[j+1] += dp[j];

      }

    }

  }

  return dp[size_T];

}
