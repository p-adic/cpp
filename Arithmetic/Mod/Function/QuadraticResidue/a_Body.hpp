// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/QuadraticResidue/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Power/a_Body.hpp"

template <typename INT>
int QuadraticResidueSymbol( INT a , const ll& p , const bool& reduced )
{

  if( !reduced ){

    ( a %= p ) < 0 ? a += p : a;

  }

  if( a == 0 ){

    return 0;

  }

  // p*pがオーバーフローしない時はオイラーの判定法を用いる。
  if( ( p >> 31 ) == 0 ){

    int answer = PowerMod( move( a ) , p >> 1 , p , true );

    if( answer > 1 ){

      assert( answer == p - 1 );
      answer = -1;

    }

    return answer;

  }

  // aの素因数pfを探索する。
  // 前計算しても計算量は変わらない。
  bool even_exponent = true;
  bool qr = true;

  // pf=2のみ第2補充則を用いる。
  while( ( a & 1 ) == 0 ){

    a >>= 1;
    even_exponent = !even_exponent;

  }

  if( !even_exponent ){

    int k = ( p >> 1 ) & 3;

    if( 0 < k && k < 3 ){

      qr = !qr;
      
    }

  }

  ll pf = 3;
  
  while( a != 1 ){

    if( a % pf == 0 ){

      a /= pf;
      bool even_exponent = false;
      
      while( a % pf == 0 ){

	a /= pf;
	even_exponent = !even_exponent;

      }

      if( !even_exponent ){

        // pf>2では相互法則を用いる。
	int qrs = QuadraticResidueSymbol<ll>( p , pf ) * ( ( ( ( p >> 1 ) & 1 ) & ( ( pf >> 1 ) & 1 ) ) == 0 ? 1 : -1 );

	if( qrs == -1 ){

	  qr = !qr;
	  
	}
	
      }

    }

    pf += 2;

    if( pf > a / pf ){

      // 素因数分解と違って最後まで処理する必要あり。
      pf = a;
      
    }

  }

  return qr ? 1 : -1;
  
}
