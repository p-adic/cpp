// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Enumeration/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Prime/Enumeration/SFINAE/a_Body.hpp"

#include "../Count/a_Body.hpp"

template <typename INT> vector<INT> EnumerateDivisorBody( const vector<INT>& P , vector<int>& E )
{

  const int length = P.size();
  vector answer( CountDivisorBody<INT>( E ) , INT( 1 ) );
  int size = 1;

  for( int i = 0 ; i < length ; i++ ){

    auto& P_i = P[i];
    auto& E_i = E[i];
    INT q = 1;
    int j_shift = 0;

    // E_iがCountDivisorBodyで増えていることに注意。
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

template <typename PE , typename INT>
auto EnumerateDivisor( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,vector<INT>>
{

  auto [P,E] = PrimeFactorisation( pe , move( n ) );
  return EnumerateDivisorBody( P , E );
  
}

template <typename LD , typename INT>
auto EnumerateDivisor( const LD& ld , INT n ) -> enable_if_t<!IsPE<LD>,vector<INT>>
{

  vector<INT> P{};
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

template <typename INT , typename FUNC , typename U>
vector<U> TotalEnumerateDivisor( const INT& size , FUNC f , const U& init ) noexcept
{

  static_assert( is_invocable_r_v<U,FUNC,U,const INT&> );
  vector<U> answer( size , init );

  for( INT d = 1 ; d < size ; d++ ){

    for( INT n = 0 ; n < size ; n += d ){

      answer[n] = f( move( answer[n] ) , d );

    }

  }

  return answer;


}

// 不使用だがどうせincludeする。
#include "../../Prime/Enumeration/a_Body.hpp"
#include "../../Prime/Enumeration/Heap/a_Body.hpp"
#include "../Least/a_Body.hpp"
#include "../Least/Heap/a_Body.hpp"

