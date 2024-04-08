// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Constexpr/Counting/a_Body.hpp

#pragma once
#include "a.hpp"


template <typename INT , INT val_limit , int length_max> inline constexpr PrimeCounting<INT,val_limit,length_max>::PrimeCounting( const PrimeEnumeration<INT,val_limit,length_max>& pe ) : m_val{ 0 , 0 } { int temp = 0; for( int i = 2 ; i < val_limit ; i++ ){ m_val[i] = pe.IsComposite( i ) ? temp : ++temp; } }

template <typename INT , INT val_limit , int length_max> inline constexpr const int& PrimeCounting<INT,val_limit,length_max>::operator[i]( const int& i ) const { assert( i < val_limit ); return m_val[i]; }
template <typename INT , INT val_limit , int length_max> inline constexpr const int& PrimeCounting<INT,val_limit,length_max>::Pi( const int& i ) const { return operator[]( i ); }
template <typename INT , INT val_limit , int length_max> inline constexpr const int& PrimeCounting<INT,val_limit,length_max>::Get( const int& i ) const { return operator[]( i ); }

