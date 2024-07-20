// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/a_Body.hpp

#pragma once
#include "Constexpr/a_Body.hpp"
#include "../Prime/Constexpr/a_Body.hpp"

#include "../Prime/a_Body.hpp"
#include "../Prime/Factorisation/a_Body.hpp"

template <typename INT> INT CountDivisorBody( vector<int>& E ) noexcept
{
  
  const int length = E.size();
  INT answer = 1;

  for( int i = 0 ; i < length ; i++ ){

    answer *= ++E[i];

  }

  return answer;

}

template <typename INT>
INT CountDivisor( INT n ) noexcept
{

  auto [P,E] = PrimeFactorisation( move( n ) );
  return CountDivisorBody<INT>( E );

}

template <typename INT , typename PE>
INT CountDivisor( const PE& pe , INT n ) noexcept
{

  auto [P,E] = PrimeFactorisation( pe , move( n ) );
  return CountDivisorBody<INT>( E );

}

template <typename INT> vector<INT> EnumerateDivisorBody( const vector<INT>& P , vector<int>& E )
{

  const int length = P.size();
  vector answer( CountDivisorBody<INT>( E ) , 1 );
  int size = 1;

  for( int i = 0 ; i < length ; i++ ){

    auto& P_i = P[i];
    auto& E_i = E[i];
    INT q = 1;
    int j_shift = 0;

    // E_i‚ªCountDivisorBody‚Å‘‚¦‚Ä‚¢‚é‚±‚Æ‚É’ˆÓB
    for( int e = 1 ; e < E_i ; e++ ){

      q *= P_i;
      j_shift += size;

      for( int j = 0 ; j < size ; j++ ){

	answer[j + j_shift] = answer[j] * q;

      }


    }

    size *= E_i;

  }

  return answer;

}

template <typename INT>
vector<INT> EnumerateDivisor( INT n ) noexcept
{

  auto [P,E] = PrimeFactorisation( move( n ) );
  return EnumerateDivisorBody( P , E );
    
}

template <typename INT1 , INT1 val_limit , int length_max , typename INT2>
vector<INT2> EnumerateDivisor( const PrimeEnumeration<INT1,val_limit,length_max>& pe , INT2 n )
{

  auto [P,E] = PrimeFactorisation( pe , move( n ) );
  return EnumerateDivisorBody( P , E );
  
}

template <typename INT1 , INT1 val_limit , typename INT2>
vector<INT2> EnumerateDivisor( const LeastDivisor<INT1,val_limit>& ld , INT2 n )
{

  vector<INT2> P{};
  vector<int> E{};

  while( n > 1 ){

    auto& p = ld[n];
    int e = 1;

    while( ( n /= p ) % p == 0 ){

      e++;

    }

    P.push_back( p );
    E.push_back( e );

  }

  return EnumerateDivisorBody( P , E );

}

template <typename INT>
vector<vector<INT>> TotalEnumerateDivisor( const INT& size ) noexcept
{

  vector<vector<INT>> answer( size );

  for( INT d = 1 ; d < size ; d++ ){

    for( INT n = 0 ; n < size ; n += d ){

      answer[n].push_back( d );

    }

  }

  return answer;

}
