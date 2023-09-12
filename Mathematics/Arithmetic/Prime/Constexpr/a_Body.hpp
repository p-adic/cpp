// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT , INT val_limit , int length_max> inline constexpr PrimeEnumeration<INT,val_limit,length_max>::PrimeEnumeration() : m_is_composite() , m_val() , m_length( 0 )
{

  for( INT i = 2 ; i < val_limit ; i++ ){

    if( ! m_is_composite[i] ){

      INT j = i;

      while( ( j += i ) < val_limit ){

	m_is_composite[j] = true;

      }

      m_val[m_length++] = i;

      if( m_length >= length_max ){

	break;
	
      }

    }

  }

}

template <typename INT , INT val_limit , int length_max> inline constexpr const INT& PrimeEnumeration<INT,val_limit,length_max>::Get( const int& n ) const { assert( n < m_length ); return m_val[n]; }
template <typename INT , INT val_limit , int length_max> inline constexpr const bool& PrimeEnumeration<INT,val_limit,length_max>::IsComposite( const int& i ) const { assert( i < val_limit ); return m_is_composite[i]; }
template <typename INT , INT val_limit , int length_max> inline constexpr const int& PrimeEnumeration<INT,val_limit,length_max>::length() const noexcept { return m_length; }


