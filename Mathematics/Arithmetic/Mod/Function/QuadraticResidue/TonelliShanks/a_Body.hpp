// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/TonelliShanks/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Power/a_Body.hpp"

template <typename INT1 , typename INT2>
ll TonelliShanks( INT1 a , const INT2& p , const bool& reduced )
{

  if( !reduced ){

    ( a %= p ) < 0 ? a += p : a;

  }

  const int qrs = QuadraticResidueSymbol( a , p , true );

  if( qrs != 1 ){

    return qrs;

  }

  ll factor = a;

  while( QuadraticResidueSymbol( ++factor < p ? factor : factor = 2 , p , true ) != -1 ){}

  INT2 l = p - 1;
  int v2 = 0;

  while( ( l & 1 ) == 0 ){

    l >>= 1;
    v2++;

  }

  ll answer = PowerMod( a , ( l + 1 ) >> 1 , p , true );
  ll temp = PowerMod( a , l , p , true );
  factor = PowerMod( move( factor ) , move( l ) , p , true );

  while( temp > 1 ){

    ll power = temp;
    int v2_next = 0;

    while( power != 1 ){

      ( power *= power ) %= p;
      v2_next++;

    }

    assert( v2_next < v2 );
    ( answer *= factor = PowerMod( move( factor ) , INT2( 1 ) << ( v2 - 1 - v2_next ) , p , true ) ) %= p;
    ( temp *= ( factor *= factor ) %= p ) %= p;
    v2 = v2_next;

  }

  assert( temp == 1 && ( answer * answer ) % p == a );
  return answer;

}
