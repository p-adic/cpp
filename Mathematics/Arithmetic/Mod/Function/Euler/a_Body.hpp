// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Prime/Constexpr/a_Body.hpp"

#include "../CRT/a_Body.hpp"
#include "../../../Prime/a_Body.hpp"


template <typename INT> inline INT EulerFunction( const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; return EulerFunction( n , P , exponent ); }
template <typename INT , INT val_limit , int length_max> inline INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; return EulerFunction( prime , n , P , exponent ); }

template <typename INT>
INT EulerFunction( const INT& n , vector<INT>& P , vector<INT>& exponent )
{

  SetPrimeFactorisation( n , P , exponent );
  EULER_FUNCTION;

}

template <typename INT , INT val_limit , int length_max>
INT EulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent )
{

  SetPrimeFactorisation( prime , n , P , exponent );
  EULER_FUNCTION;

}

template <typename INT , INT val_limit , int length_max , int size , typename INT2>
void MemoriseEulerFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT2 ( &memory )[size] )
{

  static INT quotient[size];
  
  for( int n = 1 ; n < size ; n++ ){

    memory[n] = quotient[n] = n;

  }

  for( int i = 0 ; i < prime.m_length ; i++ ){
    
    const INT& p_i = prime[i];
    int n = 0;

    while( ( n += p_i ) < size ){

      INT2& memory_n = memory[n];
      INT& quotient_n = quotient[n];
      memory_n -= memory_n / p_i;

      while( ( quotient_n /= p_i ) % p_i == 0 ){}

    }

  }
  
  for( int n = val_limit ; n < size ; n++ ){

    const INT& quotient_n = quotient[n];

    if( quotient_n != 1 ){

      INT2& memory_n = memory[n];
      memory_n -= memory_n / quotient_n;
      
    }

  }

  return;

}

template <typename INT> inline INT CarmichaelFunction( const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; vector<INT> P_power{}; return CarmichaelFunction( n , P , exponent , P_power ); }
template <typename INT , INT val_limit , int length_max> inline INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n ) { vector<INT> P{}; vector<INT> exponent{}; vector<INT> P_power{}; return CarmichaelFunction( prime , n , P , exponent , P_power ); }

template <typename INT>
INT CarmichaelFunction( const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power )
{

  vector<INT> P{};
  vector<INT> exponent{};
  vector<INT> P_power{};
  SetPrimeFactorisation( n , P , exponent , P_power );
  CARMICHAEL_FUNCTION;

}

template <typename INT , INT val_limit , int length_max>
INT CarmichaelFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const INT& n , vector<INT>& P , vector<INT>& exponent , vector<INT>& P_power )
{

  vector<INT> P{};
  vector<INT> exponent{};
  vector<INT> P_power{};
  SetPrimeFactorisation( prime , n , P , exponent , P_power );
  CARMICHAEL_FUNCTION;

}
