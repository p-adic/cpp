// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Prime/Factorisation/a_Body.hpp"

template <typename PF , typename INT>
tuple<INT,vector<INT>,vector<int>> EulerFunction_Body( PF pf , const INT& n )
{

  auto [P,E] = pf( n );
  INT answer = n;

  for( auto& p : P ){

    answer -= answer / p;

  }

  return { answer , move( P ) , move( E ) };

}

template <typename INT> inline tuple<INT,vector<INT>,vector<int>> EulerFunction( const INT& n ) { return EulerFunction_Body( PrimeFactorisation , n ); }
template <typename PE , typename INT> inline tuple<INT,vector<int>,vector<int>> EulerFunction( const PE& pe , const INT& n ) { return EulerFunction_Body( [&]( const int& i ){ return PrimeFactorisation( PE , i ); } , n ); }

template <typename PE , typename INT>
vector<INT> TotalEulerFunction( const PE , const INT& n_max )
{

  vector<INT> answer( n_max + 1 );
  
  for( INT n = 1 ; n <= n_max ; n++ ){

    answer[n] = n;

  }

  auto quotient = answer;
  const int& length = pe.length();

  for( int i = 0 ; i < length ; i++ ){
    
    auto& p_i = pe[i];
    INT n = 0;

    while( ( n += p_i ) <= n_max ){

      INT& answer_n = answer[n];
      INT& quotient_n = quotient[n];
      answer_n -= answer_n / p_i;

      while( ( quotient_n /= p_i ) % p_i == 0 ){}

    }

  }
  
  for( INT n = length == 0 ? 2 : pe[length - 1] ; n <= n_max ; n++ ){

    const INT& quotient_n = quotient[n];

    if( quotient_n != 1 ){

      INT& answer_n = answer[n];
      answer_n -= answer_n / quotient_n;
      
    }

  }

  return answer;

}

