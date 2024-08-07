// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const int& size ) : m_M( move( M ) ) , m_bit_0( m_M , size ) , m_bit_1( m_M , size ) {}
template <typename U , typename Z_MODULE> AbstractIntervalAddBIT<U,Z_MODULE>::AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a ) : m_M( move( M ) ) , m_bit_0( m_M ) , m_bit_1( m_M )
{

  const int size = a.size();
  vector<U> diff( size , m_M.Zero() );
  diff[0] = a[0];
  
  for( int i = 1 ; i < size ; i++ ){

    diff[i] = m_M.Sum( m_M.Inverse( a[i-1] ) , a[i] );

  }

  m_bit_1.Initialise( diff );

  for( int i = 1 ; i < size ; i++ ){

    U& diff_i = diff[i];
    diff_i = m_M.ScalarProduct( 1 - i , move( diff_i ) );

  }

  m_bit_0.Initialise( diff );

}

template <typename U>  template <typename...Args> inline IntervalAddBIT<U>::IntervalAddBIT( const Args&... args ) : AbstractIntervalAddBIT<U,Module<int,U>>( Module<int,U>() , args... ) {}

template <typename U , typename Z_MODULE> template <typename...Args> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Initialise( const Args&... args ) { AbstractIntervalAddBIT<U,Z_MODULE> temp{ m_M , args... }; m_bit_0 = move( temp.m_bit_0 ); m_bit_1 = move( temp.m_bit_1 ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Set( const int& i , const U& u ) { Add( i , m_M.Sum( m_M.Inverse( IntervalSum( i , i ) ) , u ) ); }

template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::Add( const int& i , const U& u ) { assert( 0 <= i && i < size() ); IntervalAdd( i , i , u ); }
template <typename U , typename Z_MODULE> inline void AbstractIntervalAddBIT<U,Z_MODULE>::IntervalAdd( const int& i_start , const int& i_final , const U& u ) { const U u_inv = m_M.Inverse( u ); m_bit_0.Add( i_start , m_M.ScalarProduct( ( i_start - 1 ) , u_inv ) ); m_bit_0.Add( i_final + 1 , m_M.ScalarProduct( i_final , u ) ); m_bit_1.Add( i_start , u ); m_bit_1.Add( i_final + 1 , u_inv ); }


template <typename U , typename Z_MODULE> inline const int& AbstractIntervalAddBIT<U,Z_MODULE>::size() const noexcept { return m_bit_0.size(); }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::operator[]( const int& i ) { assert( 0 <= i && i < size() ); return IntervalSum( i , i ); }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::Get( const int& i ) { return operator[]( i ); }
template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::InitialSegmentSum( const int& i_final ) { return m_M.Sum( m_bit_0.InitialSegmentSum( i_final ) , m_M.ScalarProduct( i_final , m_bit_1.InitialSegmentSum( i_final ) ) ); }

template <typename U , typename Z_MODULE> inline U AbstractIntervalAddBIT<U,Z_MODULE>::IntervalSum( const int& i_start , const int& i_final ) { return m_M.Sum( m_M.Inverse( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }
