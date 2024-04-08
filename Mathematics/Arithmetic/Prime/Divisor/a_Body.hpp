// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "Constexpr/a_Body.hpp"
#include "../Constexpr/a_Body.hpp"

#include "../a_Body.hpp"

template <typename INT> INT CountDivisorBody( vector<INT>& exponent ) noexcept
{
  
  const int length = exponent.size();
  INT answer = 1;

  for( int i = 0 ; i < length ; i++ ){

    answer *= ++exponent[i];

  }

  return answer;

}

template <typename INT> INT CountDivisor( const INT& n ) noexcept
{

  vector<INT> P{} , exponent{};
  SetPrimeFactorisation( n , P , exponent );
  return CountDivisorBody( exponent );

}

template <typename INT , typename PE> INT CountDivisor( const PE& pe , INT n ) noexcept
{

  vector<INT> P{} , exponent{};
  SetPrimeFactorisation( pe , n , P , exponent );
  return CountDivisorBody( exponent );

}

template <typename INT> vector<INT> EnumerateDivisorBody( const vector<INT>& P , vector<INT>& exponent )
{

  const int length = P.size();
  vector<INT> answer( CountDivisorBody( exponent ) , 1 );
  int size = 1;

  for( int i = 0 ; i < length ; i++ ){

    const INT& P_i = P[i];
    const int& exponent_i = exponent[i];
    INT power = 1;
    int j_shift = 0;

    // exponent_i‚ªCountDivisorBody‚Å‘‚¦‚Ä‚¢‚é‚±‚Æ‚É’ˆÓB
    for( int e = 1 ; e < exponent_i ; e++ ){

      power *= P_i;
      j_shift += size;

      for( int j = 0 ; j < size ; j++ ){

	answer[j + j_shift] = answer[j] * power;

      }


    }

    size *= exponent_i;

  }

  return answer;

}

template <typename INT>
vector<INT> EnumerateDivisor( INT n ) noexcept
{

  vector<INT> P{} , exponent{};
  SetPrimeFactorisation( move( n ) , P , exponent );
  return EnumerateDivisorBody( P , exponent );
    
}

template <typename INT1 , INT1 val_limit , typename INT2>
vector<INT2> EnumerateDivisor( const PrimeEnumeration<INT1,val_limit>& pe , INT2 n )
{

  vector<INT2> P{} , exponent{};
  SetPrimeFactorisation( pe , move( n ) , P , exponent );
  return EnumerateDivisorBody( P , exponent );
  
}

template <typename INT1 , INT1 val_limit , typename INT2>
vector<INT2> EnumerateDivisor( const LeastDivisor<INT1,val_limit>& ld , INT2 n )
{

  vector<INT2> P{} , exponent{};

  while( n > 1 ){

    auto& p = ld[n];
    P.push_back( p );
    INT2 e = 1;

    while( ( n /= p ) % p == 0 ){

      e++;

    }

    exponent.push_back( e );

  }

  return EnumerateDivisorBody( P , exponent );

}

template <typename INT>
vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept
{

  vector<vector<INT>> answer( size );

  for( int d = 1 ; d < size ; d++ ){

    for( int n = 0 ; n < size ; n += d ){

      answer[n].push_back( d );

    }

  }

  return answer;

}
