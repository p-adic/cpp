// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/Euler/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Prime/Constexpr/a_Body.hpp"

template <typename PF , typename INT>
INT EulerFunction_Body( PF pf , const INT& n )
{

  auto [P,E] = pf( n );
  INT answer = n;

  for( auto& p : P ){

    answer -= answer / p;

  }

  return { answer , move( P ) , move( E ) };

}

template <typename INT> inline INT EulerFunction( const INT& n ) { return EulerFunction_Body( PrimeFactorisation , n ); }
template <typename INT1 , INT1 val_limit , int length_max , typename INT2> inline tuple<INT2,vector<INT1>,vector<int>> EulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n ) { return EulerFunction_Body( [&]( const int& i ){ return PrimeFactorisation( pe , i ); } , n ); }

template <typename INT1 , INT1 val_limit , int length_max , int size , typename INT2>
vector<INT2> TotalEulerFunction( const PrimeEnumeration<INT1,val_limit,length_max>& pe , const INT2& n_max )
{

  vector<INT2> answer( n_max + 1 );
  
  for( INT2 n = 1 ; n <= n_max ; n++ ){

    answer[n] = n;

  }

  auto quotient = answer;
  const int& length = pe.length();

  for( int i = 0 ; i < length ; i++ ){
    
    const INT2& p_i = pe[i];
    INT2 n = 0;

    while( ( n += p_i ) <= n_max ){

      INT2& answer_n = answer[n];
      INT2& quotient_n = quotient[n];
      answer_n -= answer_n / p_i;

      while( ( quotient_n /= p_i ) % p_i == 0 ){}

    }

  }
  
  for( INT2 n = val_limit ; n <= n_max ; n++ ){

    const INT2& quotient_n = quotient[n];

    if( quotient_n != 1 ){

      INT2& answer_n = answer[n];
      answer_n -= answer_n / quotient_n;
      
    }

  }

  return answer;

}

