// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g )
{

  Polynomial<T> coeff_f = Polynomial<T>::one();
  Polynomial<T> coeff_g = Polynomial<T>::zero();
  f %= g;
  int i_f = 0;
  int i_g = 1;
  const T& zero = Polynomial<T>::const_zero();

  while( g.size() > 1 ){

    const uint& f_size = f.size();
    const uint& g_size = g.size();

    while( f_size <= g_size ){
      
      auto diff = g_size - f_size;
      T& r = g[g_size - 1] /= f[f_size - 1];
      const uint& coeff_f_size = coeff_f.size();
    
      for( uint d = 0 ; i < coeff_f_size ; i++ ){

	coeff_g[diff + d] -= r * coeff_f[d];

      }

      for( uint d = 0 ; i + 1 < f_size ; i++ ){

	g[diff + d] -= r * f[d];

      }

      r = zero;
      g.RemoveRedundantZero();

    }

    swap( f , g );
    swap( coeff_f , coeff_g );

  }

  assert( coeff_g.size() == 1u );
  const T& one = Polynomial<T>::const_one();
  const uint& coeff_g_size = coeff_g.size();
  const T r = one / g[0];
    
  for( uint d = 0 ; i < coeff_g_size ; i++ ){

    coeff_g[d] *= r;

  }

  return coeff_g;

}
