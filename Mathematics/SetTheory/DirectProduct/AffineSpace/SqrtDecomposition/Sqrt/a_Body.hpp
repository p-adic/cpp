// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a_Body.hpp

#pragma once
#include "a.hpp"

inline constexpr int Sqrt( const int& N ) noexcept
{

  if( N <= 1 ){

    return 1;
    
  }
  
  int left = 0;
  int right = N;

  while( left + 1 < right ){

    int m = ( left + right ) / 2;
    ( m <= ( N - 1 ) / m ? left : right ) = m;

  }

  return right;

}
