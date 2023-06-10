// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "../a_Body.hpp"
#include "../Constexpr/a_Body.hpp"

template <typename INT>
list<int> EnumerateDivisor( const INT& n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( n , P , exponent );
  const int length = P.size();
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  for( int i = 0 ; i < length ; i++ ){

    const INT& P_i = P[i];
    const int& exponent_i = exponent[i];
    list<int> temp{};
    INT power = 1;
    
    for( int e = 1 ; e <= exponent_i ; e++ ){

      power *= P_i;

      for( auto itr = begin ; itr != end ; itr++ ){

	temp.push_back( *itr * power );

      }
      
    }
    
    while( ! temp.empty() ){

      divisor.push_back( temp.front() );
      temp.pop_front();

    }
    
  }

  return divisor;
  
}

template <typename INT , INT val_limit , int length_max>
list<int> EnumerateDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( prime , n , P , exponent );
  const int length = P.size();
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  for( int i = 0 ; i < length ; i++ ){

    const INT& P_i = P[i];
    const int& exponent_i = exponent[i];
    list<int> temp{};
    INT power = 1;
    
    for( int e = 1 ; e <= exponent_i ; e++ ){

      power *= P_i;

      for( auto itr = begin ; itr != end ; itr++ ){

	temp.push_back( *itr * power );

      }
      
    }
    
    while( ! temp.empty() ){

      divisor.push_back( temp.front() );
      temp.pop_front();

    }
    
  }

  return divisor;

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

    const int& p = prime.m_val[i];

    if( n % p == 0 ){

      n /= p;

      if( n % p == 0 ){

	return 0;

      }

      answer *= -1;

    }

    i++;

  }

  return n == 1 ? answer : answer *= -1;

}
