// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Euler/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Prime/Constexpr/a_Body.hpp"

#include "../CRT/a_Body.hpp"
#include "../../Prime/a_Body.hpp"


template <typename INT> inline INT EulerFunction( const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; return EulerFunction( n , P , exponent ); }

template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent )
{

  SetPrimeFactorisation( n , P , exponent );
  INT answer = n;
  const INT size = P.size();

  for( INT i = 0 ; i < size ; i++ ){

    const INT& P_i = P[i];
    answer -= answer / P_i;
    
  }

  return answer;

}

template <typename INT , INT val_limit , int length_max>
INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent )
{

  SetPrimeFactorisation( prime , n , P , exponent );
  INT answer = n;
  const INT size = P.size();

  for( INT i = 0 ; i < size ; i++ ){

    const INT& P_i = P[i];
    answer -= answer / P_i;
    
  }

  return answer;

}

template <typename INT> inline INT CarmichaelFunction( const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; vector<INT> P_power{}; return CarmichaelFunction( n , P , exponent , P_power ); }
  
template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power )
{

  vector<INT> P{};
  vector<INT> exponent{};
  vector<INT> P_power{};
  SetPrimeFactorisation( n , P , exponent , P_power );
  INT answer = 1;
  INT size = P.size();

  for( INT i = 0 ; i < size ; i++ ){

    const INT& P_i = P[i];
    const INT& P_power_i = P_power[i];
    answer = LCM( answer , ( P_power_i - P_power_i / P_i ) );
    
  }

  return answer;

}

template <typename INT , INT val_limit , int length_max>
INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power )
{

  vector<INT> P{};
  vector<INT> exponent{};
  vector<INT> P_power{};
  SetPrimeFactorisation( prime , n , P , exponent , P_power );
  INT answer = 1;
  INT size = P.size();

  for( INT i = 0 ; i < size ; i++ ){

    const INT& P_i = P[i];
    const INT& P_power_i = P_power[i];
    answer = LCM( answer , ( P_power_i - P_power_i / P_i ) );
    
  }

  return answer;

}
