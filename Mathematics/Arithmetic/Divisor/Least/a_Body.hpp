// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Least/a_Body.hpp

#pragma once
#include "a.hpp"

template <int val_limit> inline constexpr LeastDivisor<val_limit>::LeastDivisor() noexcept : m_val{}
{

  for( int d = 2 ; d < val_limit ; d++ ){

    if( m_val[d] == 0 ){

      for( int n = d ; n < val_limit ; n += d ){

	m_val[n] == 0 ? m_val[n] = d : d;

      }

    }

  }

}

template <int val_limit> inline const int& LeastDivisor<val_limit>::operator[]( const int& i ) const { assert( 0 <= i && i < val_limit ); return m_val[i]; }
template <int val_limit> inline constexpr const int& LeastDivisor<val_limit>::Get( const int& i ) const { return m_val[i]; }
