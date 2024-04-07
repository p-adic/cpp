// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Divisor/a_Body.hpp

#pragma once
#include "../a_Body.hpp"
#include "../Constexpr/a_Body.hpp"


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

template <typename INT>
vector<INT> GetLeastDivisor( const INT& size ) noexcept
{

  vector<INT> answer( size , 1 );

  for( int d = 1 ; d < size ; d++ ){

    if( answer[d] == 1 ){

      for( int n = d ; n < size ; n += d ){

	INT& answer_n = answer[n];
	answer_n == 1 ? answer_n = d : answer_n;

      }

    }

  }

  return answer;

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

template <typename INT , typename PE>
vector<INT> EnumerateDivisor( const PE& pe , INT n ) noexcept
{

  vector<INT> P{} , exponent{};
  SetPrimeFactorisation( pe , move( n ) , P , exponent );
  return EnumerateDivisorBody( P , exponent );
  
}

template <typename INT1 , typename INT2>
vector<INT2> EnumerateDivisor( const vector<INT1>& least_divisor , INT2 n )
{

  vector<INT> P{} , exponent{};

  while( n > 1 ){

    auto& p = least_divisor[n];
    P.push_back( p );
    INT e = 1;

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

template <typename INT , typename PE>
int MoeviusFunction( const PE& pe , INT n ) noexcept
{

  const int& length = pe.length();
  int answer = 1;
  int i = 0;

  while( i < length && n > 1 ){

    const int& p = pe[i++];

    if( n % p == 0 ){

      if( ( n /= p ) % p == 0 ){

	return 0;

      }

      answer *= -1;

    }

  }

  return n == 1 ? answer : answer *= -1;

}
