// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Optimisation/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Sqrt/a_Body.hpp"
#include "../../../../../../Utility/Random/a_Body.hpp"

template <typename...Args> inline SqrtDecompositionOptimisation::SqrtDecompositionOptimisation( const int& N , const Args&... args ) : SqrtDecompositionCoordinate( N , args... ) , m_rand( m_N_d ) { assert( m_N > 0 ); for( int d = 0 ; d < m_N_d ; d++ ){ m_rand[d] = GetRand( - m_N_sqrt / 10 , m_N_sqrt / 10 ); } m_rand[0] = max( m_rand[0] , 0 ); if( m_N_d > 0 ){ m_rand[m_N_d-1] = min( m_rand[m_N_d-1] , m_N - 1 - ( m_N_m - m_N_sqrt ) ); } }
  
template <typename...Args> inline void SqrtDecompositionOptimisation::Initialise( const Args&... args ) { SqrtDecompositionOptimisation temp{ args... }; SqrtDecompositionCoordinate::operator=( temp ); m_rand = move( temp.m_rand ); }

template <typename FUNC>
int SqrtDecompositionOptimisation::Minimise( FUNC& func )
{

  static_assert( is_invocable_v<FUNC,const int&> );
  using U = ret_t<FUNC,const int&>;
  int d0 = 0;
  U u = func( m_rand[d0] );
  int i = m_N_sqrt;

  for( int d = 1 ; d < m_N_d ; i += m_N_sqrt , ++d ){

    U temp = func( i + m_rand[d] );
    temp < u ? ( u = move( temp ) , d0 = d ) : d0;

  }

  i = d0 > 0 ? m_N_sqrt * ( d0 - 1 ) : 0;
  int i_ulim = min( i + m_N_sqrt * 2 , m_N ); 
  int answer = i;
  u = func( i );

  while( ++i < i_ulim ){

    U temp = func( i );
    temp < u ? ( u = move( temp ) , answer = i ) : answer;

  }

  return answer;
  
}
