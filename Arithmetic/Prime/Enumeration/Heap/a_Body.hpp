// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Heap/a_Body.hpp

#pragma once
#include "a.hpp"

inline HeapPrimeEnumeration::HeapPrimeEnumeration( const int& val_limit ) : m_val_limit( val_limit ) , m_is_composite( m_val_limit ) , m_val() , m_length( 0 )
{

  for( int i = 2 ; i < m_val_limit ; i++ ){

    if( ! m_is_composite[i] ){

      if( i <= ( m_val_limit - 1 ) / i ){

	for( int j = i * i ; j < val_limit ; j += i ){

	  m_is_composite[j] = true;

	}

      }

      m_val.push_back( i );

    }

  }

  m_length = m_val.size();

}

inline const int& HeapPrimeEnumeration::operator[]( const int& i ) const { assert( 0 <= i && i < m_length ); return m_val[i]; }
inline const int& HeapPrimeEnumeration::Get( const int& i ) const { return operator[]( i );}

inline bool HeapPrimeEnumeration::IsComposite( const int& n ) const { assert( 0 <= n && n < m_val_limit ); return m_is_composite[n]; }
inline const int& HeapPrimeEnumeration::length() const noexcept { return m_length; }


