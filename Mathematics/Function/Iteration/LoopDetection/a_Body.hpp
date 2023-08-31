// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename U , U f(const T&) , int length_max> template <SFINAE_FOR_LOOP_DETECTION_BODY()> inline LoopDetectionBody<T,U,f,length_max>::LoopDetectionBody( const T& init ) : m_init( init ) , m_memory() , m_memory_inv() , m_value() , m_length() , m_loop_start( -1 ) , m_loop_length( -1 ) {}
template <int f(const int&) , int length_max> inline LoopDetection<f,length_max>::LoopDetection( const int& init ) : LoopDetectionBody<int,int,f,length_max>( init ) , m_value_inv() { for( int i = 0 ; i < length_max ; i++ ){ m_value_inv[i] = -1; } }
template <typename T , typename U , U f(const T&) , int length_max> inline MemorisationLoopDetection<T,U,f,length_max>::MemorisationLoopDetection( const T& init ) : LoopDetectionBody<T,U,f,length_max>( init ) {}
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline EnumerationLoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::EnumerationLoopDetection( const T& init ) : LoopDetectionBody<T,U,f,length_max>( init ) , m_value_inv() { for( int i = 0 ; i < length_max ; i++ ){ m_value_inv[i] = -1; } }

template <typename T , typename U , U f(const T&) , int length_max> template <typename INT>
T LoopDetectionBody<T,U,f,length_max>::IteratedComposition( const INT& n )
{

  if( m_length == 0 ){

    SetInit();

  }

  if( n < m_length ){

    return e( m_value[n] );
    
  }

  if( m_loop_start != -1 ){

    return e( m_value[ m_loop_start + ( n - m_loop_start ) % m_loop_length ] );

  }
  
  SetValue( e_inv( f( e( m_value[m_length - 1] ) ) ) );
  return IteratedComposition( n );

}

template <typename T , typename U , U f(const T&) , int length_max> inline const int& LoopDetectionBody<T,U,f,length_max>::GetLength() noexcept { if( m_loop_length == -1 ){ SearchLoop(); } return m_length; }
template <typename T , typename U , U f(const T&) , int length_max> inline const int& LoopDetectionBody<T,U,f,length_max>::GetLoopStart() noexcept { if( m_loop_start == -1 ){ SearchLoop(); } return m_loop_start; }
template <typename T , typename U , U f(const T&) , int length_max> inline const int& LoopDetectionBody<T,U,f,length_max>::GetLoopLength() noexcept { if( m_loop_length == -1 ){ SearchLoop(); } return m_loop_length; }

template <typename T , typename U , U f(const T&) , int length_max> inline void LoopDetectionBody<T,U,f,length_max>::SetInit() { assert( m_length == 0 ); SetValue( e_inv( m_init ) ); }

template <typename T , typename U , U f(const T&) , int length_max>
void LoopDetectionBody<T,U,f,length_max>::SearchLoop()
{

  assert( m_loop_length == -1 );
  int n = 0;
  
  while( m_loop_length == -1 ){

    IteratedComposition( n++ );
    
  }

  return;

}

template <typename T , typename U , U f(const T&) , int length_max>
T LoopDetectionBody<T,U,f,length_max>::e( const int& i )
{
  
  assert( i < m_length );
  return m_memory_inv[i];

}

template <int f(const int&) , int length_max> inline int LoopDetection<f,length_max>::e( const int& i ) { return i; }
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline T EnumerationLoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::e( const int& i ) { return enum_T( i ); }

template <typename T , typename U , U f(const T&) , int length_max>
int LoopDetectionBody<T,U,f,length_max>::e_inv( const T& t )
{

  if( m_memory.count( t ) == 0 ){

    assert( m_length < length_max );
    m_value[m_length] = m_length;
    m_memory_inv.push_back( t );
    return m_memory[t] = m_length++;

  }

  m_loop_length = m_length - ( m_loop_start = m_memory[t] );
  return m_loop_start;
  
}

template <int f(const int&) , int length_max> inline int LoopDetection<f,length_max>::e_inv( const int& t ) { return t; }
template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)> inline int EnumerationLoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::e_inv( const T& t ) { return enum_T_inv( t ); }

template <typename T , typename U , U f(const T&) , int length_max>
void LoopDetectionBody<T,U,f,length_max>::SetValue( const int& i ) {}

template <int f(const int&) , int length_max>
void LoopDetection<f,length_max>::SetValue( const int& i )
{

  using base = LoopDetectionBody<int,int,f,length_max>;
  int& m_value_inv_i = m_value_inv[i];

  if( m_value_inv_i != -1 ){

    base::m_loop_length = base::m_length - ( base::m_loop_start = m_value_inv_i );

  } else {
  
    base::m_value[base::m_length] = i;
    m_value_inv_i = base::m_length++;

  }

  return;

}

template <typename T , typename U , U f(const T&) , int length_max , T enum_T(const int&) , int enum_T_inv(const T&)>
void EnumerationLoopDetection<T,U,f,length_max,enum_T,enum_T_inv>::SetValue( const int& i )
{

  using base = LoopDetectionBody<T,U,f,length_max>;
  int& m_value_inv_i = m_value_inv[i];

  if( m_value_inv_i != -1 ){

    base::m_loop_length = base::m_length - ( base::m_loop_start = m_value_inv_i );

  } else {
  
    base::m_value[base::m_length] = i;
    m_value_inv_i = base::m_length++;

  }

  return;

}
