// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a_Body.hpp

#pragma once
#include "a.hpp"

inline SqrtDecompositionCoordinate::SqrtDecompositionCoordinate( const int& N ) : SqrtDecompositionCoordinate( N , Sqrt( N ) ) {};
inline SqrtDecompositionCoordinate::SqrtDecompositionCoordinate( const int& N , const int& N_sqrt ) : m_N( N ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) {}

inline int SqrtDecompositionCoordinate::Sqrt( const int& N ) noexcept
{

  if( N <= 1 ){

    return 1;
    
  }
  
  int l = 0 , r = N;

  while( l + 1 < r ){

    int m = ( l + r ) >> 1;
    ( m <= ( N - 1 ) / m ? l : r ) = m;

  }

  return r;

}
