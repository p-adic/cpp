// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Enumeration/Counting/Heap/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Heap/a_Body.hpp"

inline HeapPrimeCounting::HeapPrimeCounting( const HeapPrimeEnumeration& pe ) : m_p_max( pe.length() > 0 ? pe[pe.length() - 1] : 1 ) , m_val( m_p_max + 1 )
{

  if( length > 0 ){

    int temp = 0;

    for( int i = 2 ; i <= p_max ; i++ ){

      m_val[i] = pe.IsComposite( i ) ? temp : ++temp;

    }

  }

}

inline const int& HeapPrimeCounting::operator[]( const int& i ) const { assert( 0 <= i ); return m_val[min( i , m_p_max )] ; }
inline const int& HeapPrimeCounting::Pi( const int& i ) const { return operator[]( i ); }
inline const int& HeapPrimeCounting::Get( const int& i ) const { return operator[]( i ); }

