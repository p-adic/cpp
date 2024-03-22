// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Cumulative/GridStampCoveringExpectation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
T GridBigStampCoveringExpectation( const uint& H ,  const uint& W , const uint& X ,  const uint& Y , const uint& N )
{

  const T S = T( H - X + 1 ) * ( W - Y + 1 );
  const T& one = Polynomial<T>::c_one();
  const T two = one + one;
  T answer{};
  Polynomial<T> power = Power( Polynomial<T>{ { one , - one / S } } , N );

  for( uint i = 1 ; i <= N ; i++ ){

    auto cs = CumulativeSum<T,(1<<16)-1>( Polynomial<T>( i , two ) );
    auto factor = [&]( const uint& h , const uint& k ){
      return cs( T( h < 2 * k ? h - k : k - 1 ) ) + ( h < 2 * k ? T( h - k + 1 ).Power( i ) *= T( 2 * k - h ) : T( k ).Power( i ) *= T( h - 2 * k + 2 ) );
    };
    answer -= factor( H , X ) * factor( W , Y ) * power[i];

  }

  return answer;
  
}

template <typename T>
T GridSmallStampCoveringEpxpectation( const int& H ,  const int& W ,  const int& X ,  const int& Y , const ull& N )
{
  
  const int H_minus = H - X;
  const int W_minus = W - Y;
  const T S_inv = 1 / ( T( H_minus + 1 ) * ( W_minus + 1 ) );
  T answer = T( H ) * W;

  for( int i = 0 ; i < H ; i++ ){

    T u{};

    for( int j = 0 ; j < W ; j++ ){

      T t = ( 1 - ( max( min( i , H_minus ) - max( i - X , -1 ) , 0 ) * max( min( j , W_minus ) - max( j - Y , -1 ) , 0 ) ) * S_inv ).Power( N );

      if( Y <= j && j < W_minus ){

	u += t * ( W - 2 * Y );
	j = W_minus - 1;

      } else {

	u += t;

      }
      
    }

    if( X <= i && i < H_minus ){

      answer -= u * ( H - 2 * X );
      i = H_minus - 1;

    } else {

      answer -= u;

    }

  }

  return answer;

}

template <typename T> inline T GridStampCoveringEpxpectation( const int& H ,  const int& W ,  const int& X ,  const int& Y , const ull& N ) { assert( 1 <= X && X <= H && 1 <= Y && Y <= W ); return ull( N ) * N <= ull( X ) * Y ? GridBigStampCoveringEpxpectation<T>( uint( H ) , uint( W ) , uint( X ) , uint( Y ) , uint( N ) ) : GridSmallStampCoveringEpxpectation<T>( H , W , X , Y , N ); }
