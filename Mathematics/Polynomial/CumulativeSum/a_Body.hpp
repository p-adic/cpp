// c:/Users/user/Documents/Programming/Mathematics/Polynomial/CumulativeSum/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Combinatorial/BernulliNumber/a_Body.hpp"

template <typename T , uint deg_max>
Polynomial<T> CumulativeSum( Polynomial<T> f , const bool& exponential )
{

  const uint f_size = f.size();

  if( f_size == 0 ){

    return f;

  }
  
  const uint deg = f_size - 1;
  assert( deg <= deg_max );
  const T f0 = f[0];
  const uint deg_half = ( deg + 1 ) / 2;

  if( !exponential ){

    for( uint d = 1 ; d <= deg ; d++ ){

      f[d] *= T::Factorial( d );

    }

  }

  for( uint d = 0 ; d < deg_half ; d++ ){

    swap( f[d] , f[deg - d] );

  }

  f.resize( deg );
  TruncatedPolynomial<T> f_transpose{ f_size , move( f ) };
  static const BernulliNumberCalculator<T,deg_max+1> B{ false };
  static Polynomial<T> g{};
  static uint g_size = 0;
  
  while( deg >= g_size ){

    g[g_size] = B[g_size] * T::FactorialInverse( g_size );
    g_size++;

  }
  
  f_transpose *= g;
  f_transpose.SetTruncation( f_size + 1 );
  const uint f_size_half = ( f_size + 1 ) / 2;
  
  for( uint d = 0 ; d < f_size_half ; d++ ){

    swap( f_transpose[d] , f_transpose[f_size - d] );

  }

  if( !exponential ){

    for( uint d = 1 ; d <= f_size ; d++ ){

      f_transpose[d] *= T::FactorialInverse( d );

    }

  }

  f_transpose[1] += f_transpose[0] = f0;
  return f_transpose;

}
