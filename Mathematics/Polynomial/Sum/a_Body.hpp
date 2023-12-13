// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Sum/a_Body.hpp

#pragma once
// Sum/RationalSum/ProdÇ…égÇ§ÅB
#include "../../Arithmetic/a_Macro.hpp"
#include "a.hpp"

#include "../a_Body.hpp"

// CumulativeSumÇ…égÇ§
#include "../../Combinatorial/BernulliNumber/a_Body.hpp"



template <typename T , template <typename...> typename V>
Polynomial<T>& Sum( V<Polynomial<T>>& f )
{
  
  DEFIINTION_OF_PROD( Sum , Polynomial<T>::zero() , t += *itr );

}

template <typename T , template <typename...> typename V>
pair<Polynomial<T>,Polynomial<T>>& RationalSum( V<pair<Polynomial<T>,Polynomial<T>>>& f )
{
  
  DEFIINTION_OF_PROD( RationalSum , { Polynomial<T>::zero() , Polynomial<T>::one() } , t = { t.first * itr->second + t.second * itr->first , t.second * itr->second } );

}

template <typename T , template <typename...> typename V>
Polynomial<T>& Prod( V<Polynomial<T>>& f )
{

  DEFIINTION_OF_PROD( Prod , Polynomial<T>::one() , t += *itr );

}

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
