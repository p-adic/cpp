// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Sqrt/a_Body.hpp"

template <typename U , typename ABELIAN_GROUP> inline AbstractSqrtDecomposition<U,ABELIAN_GROUP>::AbstractSqrtDecomposition( ABELIAN_GROUP M , const int& N ) : AbstractSqrtDecomposition( move( M ) , N , Sqrt( N ) ) {}
template <typename U , typename ABELIAN_GROUP> inline AbstractSqrtDecomposition<U,ABELIAN_GROUP>::AbstractSqrtDecomposition( ABELIAN_GROUP M , const int& N , const int& N_sqrt ) : m_M( move( M ) ) , m_N( N ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( m_N_m , m_M.Zero() ) , m_b( m_N_d , m_M.Zero() ) { static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<ABELIAN_GROUP>> ); }
template <typename U , typename ABELIAN_GROUP> inline AbstractSqrtDecomposition<U,ABELIAN_GROUP>::AbstractSqrtDecomposition( ABELIAN_GROUP M , vector<U> a ) : m_M( move( M ) ) , m_N( a.size() ) , m_N_sqrt( Sqrt( m_N ) ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() ) { Initialise(); }
template <typename U , typename ABELIAN_GROUP> inline AbstractSqrtDecomposition<U,ABELIAN_GROUP>::AbstractSqrtDecomposition( ABELIAN_GROUP M , vector<U> a , const int& N_sqrt ) : m_M( move( M ) ) , m_N( a.size() ) , m_N_sqrt( N_sqrt ) , m_N_d( ( m_N + m_N_sqrt - 1 ) / m_N_sqrt ) , m_N_m( m_N_d * m_N_sqrt ) , m_a( move( a ) ) , m_b( m_N_d , m_M.Zero() ) { Initialise(); }

template <typename U , typename ABELIAN_GROUP> inline void AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Initialise()
{

  static_assert( ! is_same_v<U,int> && is_same_v<U,inner_t<ABELIAN_GROUP>> );
  m_a.resize( m_N_m );
  int i_min = 0;
  int i_ulim = m_N_sqrt;

  for( int d = 0 ; d < m_N_d ; d++ ){

    U& m_bd = m_b[d];
  
    for( int i = i_min ; i < i_ulim ; i++ ){

      m_bd = m_M.Sum( m_bd , m_a[i] );

    }
    
    i_min = i_ulim;
    i_ulim += m_N_sqrt;

  }

}

template <typename U> template <typename...Args> inline SqrtDecomposition<U>::SqrtDecomposition( Args&&... args ) : AbstractSqrtDecomposition<U,AdditiveGroup<U>>( AdditiveGroup<U>() , forward<Args>( args )... ) {}

template <typename U , typename ABELIAN_GROUP> template <typename...Args> inline void AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Reset( Args&&...args ) { *this = AbstractSqrtDecomposition<U,ABELIAN_GROUP>( move( m_M ) , forward<Args>( args )... ); }
template <typename U , typename ABELIAN_GROUP> inline void AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Set( const int& i , const U& u ) { U& m_ai = m_a[i]; U& m_bd = m_b[i / m_N_sqrt]; m_bd = m_M.Sum( m_bd , m_M.Sum( m_M.Inverse( m_ai ) , u ) ); m_ai = u; }
template <typename U , typename ABELIAN_GROUP> inline void AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Add( const int& i , const U& u ) { U& m_ai = m_a[i]; U& m_bd = m_b[i / m_N_sqrt]; m_bd = m_M.Sum( m_bd , u ); m_ai = m_M.Sum( m_ai , u ); }

template <typename U , typename ABELIAN_GROUP> inline const U& AbstractSqrtDecomposition<U,ABELIAN_GROUP>::operator[]( const int& i ) const { assert( 0 <= i && i < m_N ); return m_a[i]; }
template <typename U , typename ABELIAN_GROUP> inline const U& AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Get( const int& i ) const { return operator[]( i ); }

template <typename U , typename ABELIAN_GROUP> inline U AbstractSqrtDecomposition<U,ABELIAN_GROUP>::IntervalSum( const int& i_start , const int& i_final )
{

  const int i_min = max( i_start , 0 );
  const int i_ulim = min( i_final + 1 , m_N );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int d_1 = max( d_0 , i_ulim / m_N_sqrt );
  const int i_0 = min( d_0 * m_N_sqrt , i_ulim );
  const int i_1 = max( i_0 , d_1 * m_N_sqrt );
  U answer = m_M.Zero();
  
  for( int i = i_min ; i < i_0 ; i++ ){

    answer = m_M.Sum( answer , m_a[i] );

  }
  
  for( int d = d_0 ; d < d_1 ; d++ ){

    answer = m_M.Sum( answer , m_b[d] );

  }

  for( int i = i_1 ; i < i_ulim ; i++ ){

    answer = m_M.Sum( answer , m_a[i] );

  }

  return answer;
  
}

template <typename U , typename ABELIAN_GROUP> inline int AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Search( const int& i_start , const U& u ) { return Search( i_start , u , m_M.Zero() ); }

template <typename U , typename ABELIAN_GROUP> int AbstractSqrtDecomposition<U,ABELIAN_GROUP>::Search_Body( const int& i_start , const U& u , U sum_temp )
{

  const int i_min = max( i_start , 0 );
  const int d_0 = ( i_min + m_N_sqrt - 1 ) / m_N_sqrt;
  const int i_0 = min( d_0 * m_N_sqrt , m_N );
  
  for( int i = i_min ; i < i_0 ; i++ ){

    sum_temp = m_M.Sum( sum_temp , m_a[i] );

    if( !( sum_temp < u ) ){

      return i;

    }

  }
  
  for( int d = d_0 ; d < m_N_d ; d++ ){

    U sum_next = m_M.Sum( sum_temp , m_b[d] );

    if( sum_next < u ){

      sum_temp = move( sum_next );

    } else {

      return Search_Body( d * m_N_sqrt , u , sum_temp );

    }
    
  }

  return -1;

}
