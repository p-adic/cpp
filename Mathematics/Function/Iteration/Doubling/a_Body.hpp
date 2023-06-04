// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/Doubling/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T, typename U , U f(const T&) , int size_max , int digit> template <SFINAE_FOR_DOUBLING_BODY()> inline DoublingBody<T,U,f,size_max,digit>::DoublingBody( const int& size ) : m_size( size ) , m_doubling() , m_length() , m_memory() {}
template <int f(const int&) , int size_max , int digit> inline Doubling<f,size_max,digit>::Doubling( const int& size ) : DoublingBody<int,int,f,size_max,digit>( size ) {}
template <typename T, typename U , U f(const T&) , int size_max , int digit> inline MemorisationDoubling<T,U,f,size_max,digit>::MemorisationDoubling( const int& size ) : DoublingBody<T,U,f,size_max,digit>( size ) {}
template <typename T, typename U , U f(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&) , int digit> inline EnumerationDoubling<T,U,f,size_max,enum_T,enum_T_inv,digit>::EnumerationDoubling( const int& size ) : DoublingBody<T,U,f,size_max,digit>( size ) {}

template <typename T, typename U , U f(const T&) , int size_max , int digit> template <typename INT>
T DoublingBody<T,U,f,size_max,digit>::IteratedComposition( T t , INT n )
{
  
  int d_lim = 0;
  int i = e_inv( t );

  while( d_lim < digit ? m_doubling[d_lim][i] != -1 : false ){

    d_lim++;

  }

  while( ( n >> d_lim ) != 0 ){

    assert( d_lim < digit );
    int ( &doubling_d )[size_max] = m_doubling[d_lim];
    int j = i;

    if( d_lim == 0 ){

      while( doubling_d[j] != -1 ){

	j = doubling_d[j] = e_inv( t = f( t ) );

      }

    } else {

      int ( &doubling_d_minus )[size_max] = m_doubling[d_lim - 1];

      while( doubling_d[j] != -1 ){

	j = doubling_d[j] = doubling_d_minus[doubling_d_minus[j]];

      }

    }

    d_lim++;

  }

  int d = 0;
    
  while( n != 0 ){

    ( n & 1 ) == 1 ? i = m_doubling[d][i] : i;
    n >>= 1;
    d++;
      
  }

  return e( i );

}

template <typename T, typename U , U f(const T&) , int size_max , int digit>
T DoublingBody<T,U,f,size_max,digit>::e( const int& i )
{
  
  assert( i < m_length );
  return m_memory_inv[i];

}

template <int f(const int&) , int size_max , int digit> inline int Doubling<f,size_max,digit>::e( const int& i ) { return i; }
template <typename T, typename U , U f(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&) , int digit> inline T EnumerationDoubling<T,U,f,size_max,enum_T,enum_T_inv,digit>::e( const int& i ) { return enum_T( i ); }

template <typename T, typename U , U f(const T&) , int size_max , int digit>
int DoublingBody<T,U,f,size_max,digit>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < m_size );
    m_memory_inv[m_length] = t;
    return m_memory[t] = m_length++;

  }
  
  return m_memory[t];

}

template <int f(const int&) , int size_max , int digit> inline int Doubling<f,size_max,digit>::e_inv( const int& t ) { return t; }
template <typename T, typename U , U f(const T&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&) , int digit> inline int EnumerationDoubling<T,U,f,size_max,enum_T,enum_T_inv,digit>::e_inv( const T& t ) { return enum_T_inv( t ); }
