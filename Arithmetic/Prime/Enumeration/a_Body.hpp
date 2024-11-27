// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/a_Body.hpp

#pragma once
#include "a.hpp"

template <int val_limit , int length_max> inline constexpr PrimeEnumeration<val_limit,length_max>::PrimeEnumeration() : m_is_composite() , m_val() , m_length( 0 )
{

  for( int i = 2 ; i < val_limit ; i++ ){

    if( ! m_is_composite[i] ){

      if( i <= ( val_limit - 1 ) / i ){

	for( int j = i * i ; j < val_limit ; j += i ){

	  m_is_composite[j] = true;

	}

      }

      m_val[m_length++] = i;

      if( m_length >= length_max ){

	break;
	
      }

    }

  }

}

template <int val_limit , int length_max> inline const int& PrimeEnumeration<val_limit,length_max>::operator[]( const int& i ) const { assert( 0 <= i && i < m_length ); return m_val[i]; }
template <int val_limit , int length_max> inline constexpr const int& PrimeEnumeration<val_limit,length_max>::Get( const int& i ) const { return m_val[i];}

template <int val_limit , int length_max> inline constexpr const bool& PrimeEnumeration<val_limit,length_max>::IsComposite( const int& n ) const { return m_is_composite[n]; }
template <int val_limit , int length_max> inline constexpr const int& PrimeEnumeration<val_limit,length_max>::length() const noexcept { return m_length; }


