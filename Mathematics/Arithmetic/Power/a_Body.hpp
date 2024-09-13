// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline T Square( const T& t ) { return t * t; }

template <typename T , typename UINT>
T Power( T t , UINT exponent )
{

  T answer = ( exponent & 1 ) == 1 ? t : 1;
  exponent >>= 1;

  while( exponent > 0 ){

    // オーバーフロー対策で先に（必要な時だけ）2乗する。
    // 部分特殊化ではなくオーバーロードで処理できるようにするためにSquare<T>としない。
    t = Square( t );
    ( exponent & 1 ) == 1 ? answer *= t : answer;
    exponent >>= 1;
    
  }

  return answer;

}

template <typename T , typename UINT>
T Power( T t , UINT exponent , T init )
{

  ( exponent & 1 ) == 1 ? init *= t : init;
  exponent >>= 1;

  while( exponent > 0 ){

    // オーバーフロー対策で先に（必要な時だけ）2乗する。
    // 部分特殊化ではなくオーバーロードで処理できるようにするためにSquare<T>としない。
    t = Square( t );
    ( exponent & 1 ) == 1 ? init *= t : init;
    exponent >>= 1;
    
  }

  return move( init );

}

