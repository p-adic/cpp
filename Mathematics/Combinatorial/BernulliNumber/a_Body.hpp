// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/BernulliNumber/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Polynomial/a_Body.hpp"

template <typename T , int length> inline BernulliNumberCalculator<T,length>::BernulliNumberCalculator() : m_val() 
{

  TruncatedPolynomial<T> f{ length };
  
  for( int i = 0 ; i < length ; i++ ){

    f[i] = T::FactorialInverse( i + 1 );
    
  }

  f = Inverse( f );

  for( int i = 0 ; i < length ; i++ ){

    m_val[i] = move( f[i] *= T::Factorial( i ) );

  }

}

template <typename T , int length> inline const T& BernulliNumberCalculator<T,length>::operator[]( const int& i ) const { assert( i < length ); return m_val[i]; }
