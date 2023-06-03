// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T, T f(const T&) , int length_max> inline LoopDetection<T,f,length_max>::LoopDetection( const T& init ) : m_length() , m_value() , m_loop_start( -1 ) , m_memory() {}
template <typename T, T f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline LoopDetection<T,f,length_max,enum_T,enum_T_inv>::LoopDetection() : LoopDetection() , m_value_inv() { for( int i = 0 ; i < length_max ; i++ ){ m_value_inv[i] = -1; } }

template <typename T, T f(const T&) , int length_max> inline void LoopDetection<T,f,length_max>::SetInit( const T& init ) { assert( m_length == 0 ); m_value[0] = e_inv( t ); }

template <typename T, T f(const T&) , int length_max>
T LoopDetection<T,f,length_max>::IteratedComposition( const int& n )
{

  if( n < m_length ){

    return m_value[n];
    
  }

  if( m_loop_start != -1 ){

    return m_value[ m_loop_start + ( n - m_loop_start ) % ( m_length - m_loop_start ) ];

  }
  
  SetValue( e_inv( f( e( m_value[m_length - 1] ) ) ) );
  return IteratedComposition( n );

}


template <typename T, T f(const T&) , int length_max>
T LoopDetection<T,f,length_max>::e( const int& i )
{
  
  assert( i < m_length );
  return m_value[i];

}

template <typename T, T f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
T LoopDetection<T,f,length_max,enum_T,enum_T_inv>::e( const int& i )
{
  
  return enum_T( i );

}

template <typename T, T f(const T&) , int length_max>
int LoopDetection<T,f,length_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < length_max );
    return m_memory[t] = m_length++;

  }

  return m_loop_start = m_memory[t]

}

template <typename T, T f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
int LoopDetection<T,f,length_max,enum_T,enum_T_inv>::e_inv( const T& t )
{

  return enum_T_inv( t );

}

template <typename T, T f(const T&) , int length_max> void LoopDetection<T,f,length_max>::SetValue( const int& i )
{

  int& m_value_inv_i = m_value_inv[i];

  if( m_value_inv_i != -1 ){

    m_loop_start = m_value_inv_i;

  } else {
  
    m_value[m_length] = i;
    m_value_inv_i = m_length++;

  }

  return;

}
