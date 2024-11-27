// c:/Users/user/Documents/Programming/Mathematics/Polynomial/BostanMori/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T , typename INT>
void MultiCoefficientEvaluation_Body( Polynomial<T> f , Polynomial<T> g , unordered_map<INT,T>& coeff )
{

  assert( !coeff.empty() );
  const uint g_size = g.size();
  assert( f.size() <= g_size );
  Polynomial<T> g_sym{};

  for( uint d = 0 ; d < g_size ; d++ ){

    ( d & 1 ) == 0 ? g_sym[d] += g[d] : g_sym[d] -= g[d];

  }

  f *= g_sym;
  g *= g_sym;
  g_sym.resize( 0 );

  for( uint d = 0 ; d < g_size ; d++ ){

    g[d] = move( g[d << 1] );

  }

  g.resize( g_size );
  unordered_map<INT,T> coeff_even{};
  unordered_map<INT,T> coeff_odd{};

  for( auto itr = coeff.begin() , end = coeff.end() ; itr != end ; itr++ ){

    ( ( itr->first & 1 ) == 0 ? coeff_even : coeff_odd )[itr->first >> 1];

  }

  if( !coeff_even.empty() ){

    auto itr = coeff_even.begin();

    if( coeff_even.size() == 1 ? itr->first == 0 : false ){

      itr->second = move( f[0] /= g[0] );

    } else {
	
      Polynomial<T> f_even{};
      const uint f_even_size = ( f.size() + 1 ) >> 1;

      for( uint d = 0 ; d < f_even_size ; d++ ){

	f_even[d] = move( f[d << 1] );

      }

      if( !coeff_odd.empty() ){

	MultiCoefficientEvaluation_Body( move( f_even ) , g , coeff_even );

      } else {

	MultiCoefficientEvaluation_Body( move( f_even ) , move( g ) , coeff_even );

      }

    }

    for( auto end = coeff_even.end() ; itr != end ; itr++ ){

      coeff[itr->first << 1] = move( itr->second );

    }

    coeff_even.clear();
      
  }

  if( !coeff_odd.empty() ){

    auto itr = coeff_odd.begin();

    if( coeff_odd.size() == 1 ? itr->first == 0 : false ){

      itr->second = move( f[1] /= g[0] );

    } else {

      const uint f_odd_size = f.size() >> 1;

      for( uint d = 0 ; d < f_odd_size ; d++ ){

	f[d] = move( f[( d << 1 ) | 1] );

      }

      f.resize( f_odd_size );
      MultiCoefficientEvaluation_Body( move( f ) , move( g ) , coeff_odd );

    }

    for( auto end = coeff_odd.end() ; itr != end ; itr++ ){

      coeff[( itr->first << 1 ) | 1] = move( itr->second );

    }

    coeff_odd.clear();

  }

  return;
  
}

template <typename T , typename INT>
void MultiCoefficientEvaluation( Polynomial<T> f , Polynomial<T> g , unordered_mapx<INT,T>& coeff )
{

  if( coeff.empty() ){

    return;

  }
  
  const Polynomial<T> f_div = f / g;
  f -= f_div * g;
  f.RemoveRedundantZero();
  MultiCoefficientEvaluation_Body( move( f ) , move( g ) , coeff );
  const uint& f_div_size = f_div.size();

  if( f_div_size > 0 ){

    for( auto itr = coeff.begin() , end = coeff.end() ; itr != end ; itr++ ){

      if( itr->first < f_div_size ){
	
	itr->second += f_div[itr->first];

      }

    }

  }

  return;

}
