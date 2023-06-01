// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "../a_Body.hpp"
#include "../Constexpr/a_Body.hpp"

template <typename INT> list<int> EnumerateDivisor( const INT& n ) noexcept
{

  vector<INT> prime{};
  vector<INT> exponent{};
  SetPrimeFactorisation( i , prime , exponent );
  const int length = prime.size();
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  for( int i = 0 ; i < length ; length++ ){

    const INT& pi = prime[i];
    const int& ei = exponent[i];
    list<int> temp{};
    INT power = 1;
    
    for( int e = 1 ; e <= ei ; e++ ){

      power *= pi;

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

template <typename INT , INT val_limit , int length_max> list<int> EnumerateDivisor( const PrimeEnumeration<INT,val_limit,length_max>& prime , INT n ) noexcept
{

  list<pair<INT,int> > factor{};

  for( int i = 0 ; i < prime.m_length ; i++ ){

    const INT& pi = prime.m_val[i];
    int ei = 0;

    while( n % pi == 0 ){

      n /= pi;
      ei++;

    }

    if( ei > 0 ){

      factor.push_back( pair<INT,int>( pi , ei ) );

    }
    
    if( n == 1 ){

      break;

    }

  }

  if( n > 1 ){

    factor.push_back( pair<INT,int>( n , 1 ) );

  }
  
  list<INT> divisor{};
  divisor.push_back( 1 );
  auto begin = divisor.begin() , end = divisor.end();
  
  while( ! factor.empty() ){

    pair<INT,int>& factor_curr = factor.front();
    INT& pi = factor_curr.first;
    int& ei = factor_curr.second;
    list<int> temp{};
    INT power = 1;
    
    for( int e = 1 ; e <= ei ; e++ ){

      power *= pi;

      for( auto itr = begin ; itr != end ; itr++ ){

	temp.push_back( *itr * power );

      }
      
    }
    
    while( ! temp.empty() ){

      divisor.push_back( temp.front() );
      temp.pop_front();

    }

    factor.pop_front();
    
  }

  return divisor;

}
