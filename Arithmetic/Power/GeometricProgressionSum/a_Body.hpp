// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/GeometricProgressionSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename UINT> inline T GeometricProgressionSum( T rate , UINT exponent_max , const T& init ) { T rate_minus = rate - 1; return rate_minus == 0 ? init * ++exponent_max : ( Power( move( rate ) , move( ++exponent_max ) ) - 1 ) / move( rate_minus ) * init; }

template <typename T , typename UINT>
T GeometricProgressionLinearCombinationSum( vector<T> rate , vector<UINT> exponent_max , const vector<T>& init )
{

  const int size = init.size();
  assert( int( rate.size() ) == size && int( exponent_max.size() ) == size );
  T answer{};

  for( int i = 0 ; i < size ; i++ ){

    answer += GeometricProgressionSum( move( rate[i] ) , move( exponent_max[i] ) , init[i] );

  }

  return answer;

}
