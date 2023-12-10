// c:/Users/user/Documents/Programming/Mathematics/Polynomial/ParallelTranslation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T>
void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false )
{

  f.RemoveRedundantZero();
  const uint& size = f.size();
  
  if( size > 0 ){

    TruncatedPolynomial<T> exp_t_transpose{ size * 2 };
    T power_t = Polynomial<T>::const_one();
  
    for( uint d = 0 ; d < size ; d++ ){

      exp_t_transpose[size - 1 - d] = power_t * T::FactorialInverse( d );
      power_t *= t;

    }

    if( exponential ){

      exp_t_transpose *= f;

      for( uint d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1];

      }

    } else {

      for( uint d = 0 ; d < size ; d++ ){

	f[d] *= T::Factorial( d );

      }

      exp_t_transpose *= f;

      for( uint d = 0 ; d < size ; d++ ){

	f[d] = exp_t_transpose[d + size - 1] * T::FactorialInverse( d );

      }

    }

  }

}
