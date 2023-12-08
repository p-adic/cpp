// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g )
{

  const T& zero = Polynomial<T>::const_zero();
  Polynomial<T> coeff_f{ 0 , Polynomial<T>::const_one() };
  Polynomial<T> coeff_g{ Polynomial<T>::zero() };
  f %= g;

  while( f.size() > 1 ){

    const uint& f_size = f.size();
    const uint& g_size = g.size();

    while( f_size <= g_size ){
      
      auto diff = g_size - f_size;
      T& r = g[g_size - 1] /= f[f_size - 1];
      const uint& coeff_f_size = coeff_f.size();
    
      for( uint d = 0 ; d < coeff_f_size ; d++ ){

	coeff_g[diff + d] -= r * coeff_f[d];

      }

      for( uint d = 0 ; d + 1 < f_size ; d++ ){

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
  const uint& coeff_f_size = coeff_f.size();
  const T r = one / f[0];
    
  for( uint d = 0 ; d < coeff_f_size ; d++ ){

    coeff_f[d] *= r;

  }

  return coeff_f;

}
