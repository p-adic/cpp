// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "../a_Body.hpp"
#include "../Constexpr/a_Body.hpp"

template <typename INT>
list<int> EnumerateDivisor( const INT& n ) noexcept
{

  vector<INT> P{};
  vector<INT> exponent{};
  SetPrimeFactorisation( i , P , exponent );
  const int length = P.size();
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  for( int i = 0 ; i < length ; length++ ){

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
  SetPrimeFactorisation( prime , i , P , exponent );
  const int length = P.size();
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  for( int i = 0 ; i < length ; length++ ){

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
