// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename U , U f(const T&) , int length_max> template <SFINAE_FOR_LOOP_DETECTION_BODY()> inline LoopDetectionBody<T,U,f,length_max>::LoopDetectionBody( const T& init ) : m_length() , m_value() , m_loop_start( -1 ) , m_memory() {}
template <typename T , typename U , U f(const T&) , int length_max> inline LoopDetection<T,U,f,length_max>::LoopDetection() : LoopDetectionBody<T,U,f,length_max>() {}
template <int f(const int&) , int length_max> inline LoopDetection<f,length_max>::LoopDetection() : LoopDetectionBody<int,f,length_max>() , m_value_inv() { for( int i = 0 ; i < length_max ; i++ ){ m_value_inv[i] = -1; } }
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline LoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::LoopDetection() : LoopDetectionBody<T,U,f,length_max>() , m_value_inv() { for( int i = 0 ; i < length_max ; i++ ){ m_value_inv[i] = -1; } }

template <typename T , typename U , U f(const T&) , int length_max> inline void LoopDetectionBody<T,U,f,length_max>::SetInit( const T& init ) { assert( m_length == 0 ); m_value[0] = e_inv( t ); }

template <typename T , typename U , U f(const T&) , int length_max> template <typename INT>
T LoopDetectionBody<T,U,f,length_max>::IteratedComposition( const INT& n )
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


template <typename T , typename U , U f(const T&) , int length_max>
T LoopDetectionBody<T,U,f,length_max>::e( const int& i )
{
  
  assert( i < m_length );
  return m_value[i];

}

template <int f(const T&) , int length_max> inline int LoopDetection<int,f,length_max>::e( const int& i ) { return i; }
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline T LoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::e( const int& i ) { return enum_T( i ); }

template <typename T , typename U , U f(const T&) , int length_max>
int LoopDetectionBody<T,U,f,length_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < length_max );
    return m_memory[t] = m_length++;

  }

  return m_loop_start = m_memory[t]

}

template <int f(const T&) , int length_max> inline int LoopDetection<int,f,length_max>::e( const int& t ) { return t; }
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline int LoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::e_inv( const T& t ) { return enum_T_inv( t ); }

template <int f(const int&) , int length_max>
void LoopDetectionBody<f,length_max>::SetValue( const int& i ) {}

template <int f(const int&) , int length_max>
void LoopDetection<f,length_max>::SetValue( const int& i )
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

template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
void LoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::SetValue( const int& i )
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
