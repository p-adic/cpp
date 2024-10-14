// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Least/Heap/a_Body.hpp

#pragma once
#include "a.hpp"

inline HeapLeastDivisor::HeapLeastDivisor( const int& val_limit ) noexcept : m_val_limit( val_limit ) , m_val( m_val_limit )
{

  for( int d = 2 ; d < m_val_limit ; d++ ){

    if( m_val[d] == 0 ){

      for( int n = d ; n < m_val_limit ; n += d ){

	m_val[n] == 0 ? m_val[n] = d : d;

      }

    }

  }

}

inline const int& HeapLeastDivisor::operator[]( const int& i ) const { assert( 0 <= i && i < m_val_limit ); return m_val[i]; }
inline const int& HeapLeastDivisor::Get( const int& i ) const { return m_val[i]; }
inline const int& HeapLeastDivisor::length() const noexcept { return m_val_limit; }
