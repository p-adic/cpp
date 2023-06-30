// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "../a_Body.hpp"
#include "../Constexpr/a_Body.hpp"

template <typename INT> INT CountDivisor( const INT& n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( n , P , exponent );
  COUNT_DIVISOR;

}

template <typename INT , INT val_limit , int length_max> INT CountDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( prime , n , P , exponent );
  COUNT_DIVISOR;

}

template <typename INT>
list<INT> EnumerateDivisor( const INT& n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( n , P , exponent );
  ENUMERATE_DIVISOR;
    
}

template <typename INT , INT val_limit , int length_max>
list<INT> EnumerateDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( prime , n , P , exponent );
  ENUMERATE_DIVISOR;
  
}

template <int size_max>
void MemoriseEnumerateDivisor( list<int> ( &memory )[size_max] ) noexcept
{

  for( int d = 1 ; d < size_max ; d++ ){

    int n = 0;

    while( ( n += d ) < size_max ){

      memory[n].push_back( d );

    }

  }

  return;

}

template <typename INT> int MoeviusFunction( const INT& n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( n , P , exponent );
  const int length = P.size();

  for( int i = 0 ; i < length ; i++ ){

    if( exponent[i] > 1 ){

      return 0;

    }

  }

  return length % 2 == 0 ? 1 : -1;

}

template <typename INT , INT val_limit , int length_max>
int MoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept
{

  int answer = 1;
  int i = 0;

  while( i < prime.m_length && n > 1 ){

    const int& p = prime.m_val[i++];

    if( n % p == 0 ){

      if( ( n /= p ) % p == 0 ){

	return 0;

      }

      answer *= -1;

    }

  }

  return n == 1 ? answer : answer *= -1;

}
