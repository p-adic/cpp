// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T, typename F> inline Doubling_Body<T,F>::Doubling_Body( F f , const int& size , const int& digit ) : m_f( move( f ) ) , m_size( size ) , m_digit( digit ) , m_doubling( m_digit , vector<int>( m_size , -1 ) ) { static_assert( is_invocable_r_v<T,F,T> ); }
template <typename F> inline Doubling<F>::Doubling( F f , const int& size , const int& digit ) : Doubling_Body<int,F>( move( f ) , size , digit ) {}
template <typename T, typename F> inline MemorisationDoubling<T,F>::MemorisationDoubling( F f , const int& size , const int& digit ) : Doubling_Body<T,F>( move( f ) , size , digit ) , m_length() , m_memory() , m_memory_inv() {}
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline EnumerationDoubling<T,Enum_T,Enum_T_inv,F>::EnumerationDoubling( Enum_T enum_T , Enum_T_inv enum_T_inv , F f , const int& size , const int& digit) : Doubling_Body<T,F>( move( f ) , size , digit ) , m_enum_T( move( enum_T ) ) , m_enum_T_inv( move( enum_T_inv ) ) { static_assert( is_invocable_r_v<T,Enum_T,int> && is_invocable_r_v<int,Enum_T_inv,T> ); }

template <typename T, typename F> template <typename INT>
T Doubling_Body<T,F>::IteratedComposition( T t , INT n )
{
  
  int i = e_inv( t );
  int d = 0;

  while( n != 0 ){

    assert( d < m_digit );
    auto& doubling_d = m_doubling[d];
    const int& doubling_d_i = doubling_d[i];

    if( doubling_d_i == -1 ){
      
      int j = i;

      if( d == 0 ){

	while( doubling_d[j] == -1 ){

	  j = doubling_d[j] = e_inv( t = m_f( t ) );

	}

      } else {

	auto& doubling_d_minus = m_doubling[d - 1];

	while( doubling_d[j] == -1 ){

	  j = doubling_d[j] = doubling_d_minus[doubling_d_minus[j]];

	}

      }

    }

    ( n & 1 ) == 1 ? i = doubling_d_i : i;
    n >>= 1;
    d++;

  }

  return e( i );

}

template <typename F> inline int Doubling<F>::e( const int& i ) { return i; }
template <typename T, typename F> inline T MemorisationDoubling<T,F>::e( const int& i ) { assert( i < m_length ); return m_memory_inv[i]; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline T EnumerationDoubling<T,Enum_T,Enum_T_inv,F>::e( const int& i ) { using base = Doubling_Body<T,F>; assert( i < base::m_size ); return m_enum_T( i ); }

template <typename F> inline int Doubling<F>::e_inv( const int& t ) { return t; }
template <typename T, typename F> inline int MemorisationDoubling<T,F>::e_inv( const T& t ) { if( m_memory.count( t ) == 0 ){ using base = Doubling_Body<T,F>; assert( m_length < base::m_size ); m_memory_inv.push_back( t ); return m_memory[t] = m_length++; } return m_memory[t]; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline int EnumerationDoubling<T,Enum_T,Enum_T_inv,F>::e_inv( const T& t ) { return m_enum_T_inv( t ); }
