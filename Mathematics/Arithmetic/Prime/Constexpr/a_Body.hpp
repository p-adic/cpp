// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , INT val_limit , int length_max>
inline constexpr PrimeEnumeration<INT,val_limit,length_max>::PrimeEnumeration() : m_val() , m_length( 0 )
{

  bool is_comp[val_limit] = {};

  for( INT i = 2 ; i < val_limit ; i++ ){

    if( is_comp[i] == false ){

      INT j = i;

      while( ( j += i ) < val_limit ){

	is_comp[j] = true;

      }

      m_val[m_length++] = i;

    }

  }

}
