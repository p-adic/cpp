// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../CRT/a_Body.hpp"
#include "../../Prime/a_Body.hpp"


template <typename INT>
INT EulerFunction( const INT& n )
{

  vector<uint> P{};
  vector<uint> exponent{};
  SetPrimeFactorisation( n , P , exponent );
  INT answer = n;
  uint size = P.size();

  for( uint i = 0 ; i < size ; i++ ){

    uint& P_i = P[i];
    answer = ( answer / P_i ) * ( P_i - 1 );
    
  }

  return answer;

}

template <typename INT>
INT CarmichaelFunction( const INT& n )
{

  vector<uint> P{};
  vector<uint> exponent{};
  vector<uint> P_power{};
  SetPrimeFactorisation( n , P , exponent , P_power );
  INT answer = 1;
  uint size = P.size();

  for( uint i = 0 ; i < size ; i++ ){

    uint& P_i = P[i];
    uint& P_power_i = P_power[i];
    answer = LCM( answer , ( P_power_i / P_i ) * ( P_i - 1 ) );
    
  }

  return answer;

}
