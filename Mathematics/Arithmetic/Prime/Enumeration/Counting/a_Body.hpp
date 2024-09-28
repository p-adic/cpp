// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Counting/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <int val_limit , int length_max> inline constexpr PrimeCounting<val_limit,length_max>::PrimeCounting( const PrimeEnumeration<val_limit,length_max>& pe ) : m_val{ 0 , 0 }
{

  int temp = 0;

  for( int i = 2 ; i < val_limit ; i++ ){

    m_val[i] = pe.IsComposite( i ) ? temp : ++temp;

  }

}

template <int val_limit , int length_max> inline const int& PrimeCounting<val_limit,length_max>::operator[]( const int& i ) const { assert( 0 <= i && i < val_limit ); return m_val[i]; }
template <int val_limit , int length_max> inline constexpr const int& PrimeCounting<val_limit,length_max>::Pi( const int& i ) const { return m_val[i]; }
template <int val_limit , int length_max> inline constexpr const int& PrimeCounting<val_limit,length_max>::Get( const int& i ) const { return m_val[i]; }

