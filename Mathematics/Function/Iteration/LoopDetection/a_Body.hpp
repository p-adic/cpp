// c:/Users/user/Documents/Programming/Mathematics/Function/Iteration/LoopDetection/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Map/a_Body.hpp"

template <typename T , typename F> inline LoopDetection_Body<T,F>::LoopDetection_Body( const T& init , F f ) : m_init( init ) , m_f( move( f ) ) , m_length() , m_loop_start( -1 ) , m_loop_length( -1 ) { static_assert( is_invocable_r_v<T,F,T> ); }
template <typename T , typename F> inline ValueCalculatorForLoopDetection<T,F>::ValueCalculatorForLoopDetection( const T& init , F f ) : LoopDetection_Body<T,F>( init , move( f ) ) , m_value() , m_value_inv() {}
template <typename F> inline LoopDetection<F>::LoopDetection( const int& init , F f ) : ValueCalculatorForLoopDetection<int,F>( init , move( f ) ) {}
template <typename T , typename F> inline MemorisationLoopDetection<T,F>::MemorisationLoopDetection( const T& init , F f ) : LoopDetection_Body<T,F>( init , move( f ) ) , m_memory() , m_memory_inv() {}
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline EnumerationLoopDetection<T,Enum_T,Enum_T_inv,F>::EnumerationLoopDetection( const T& init , Enum_T enum_T , Enum_T_inv enum_T_inv , F f ) : ValueCalculatorForLoopDetection<T,F>( init , move( f ) ) , m_enum_T( enum_T ) , m_enum_T_inv( enum_T_inv ) { static_assert( is_invocable_r_v<T,Enum_T,int> && is_invocable_r_v<int,Enum_T_inv,T> ); }

template <typename T , typename F> template <typename INT>
T LoopDetection_Body<T,F>::IteratedComposition( const INT& n )
{

  if( m_length == 0 ){

    SetInit();

  }

  if( n < m_length ){

    return e( GetValue( n ) );
    
  }

  if( m_loop_start != -1 ){

    return e( GetValue( m_loop_start + ( n - m_loop_start ) % m_loop_length ) );

  }
  
  SetValue( e_inv( m_f( e( GetValue( m_length - 1 ) ) ) ) );
  return IteratedComposition( n );

}

template <typename T , typename F> inline const int& LoopDetection_Body<T,F>::GetLength() noexcept { if( m_loop_length == -1 ){ SearchLoop(); } return m_length; }
template <typename T , typename F> inline const int& LoopDetection_Body<T,F>::GetLoopStart() noexcept { if( m_loop_start == -1 ){ SearchLoop(); } return m_loop_start; }
template <typename T , typename F> inline const int& LoopDetection_Body<T,F>::GetLoopLength() noexcept { if( m_loop_length == -1 ){ SearchLoop(); } return m_loop_length; }

template <typename T , typename F> inline void LoopDetection_Body<T,F>::SetInit() { assert( m_length == 0 ); SetValue( e_inv( m_init ) ); }

template <typename T , typename F> inline void LoopDetection_Body<T,F>::SearchLoop() { assert( m_loop_length == -1 ); int n = 0; while( m_loop_length == -1 ){ IteratedComposition( n++ ); } }

template <typename F> inline int LoopDetection<F>::e( const int& i ) { return i; }
template <typename T , typename F> inline T MemorisationLoopDetection<T,F>::e( const int& i ) { using base = LoopDetection_Body<T,F>; assert( i < base::m_length ); return m_memory_inv[i]; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline T EnumerationLoopDetection<T,Enum_T,Enum_T_inv,F>::e( const int& i ) { return m_enum_T( i ); }

template <typename F> inline int LoopDetection<F>::e_inv( const int& t ) { return t; }
template <typename T , typename F> inline int MemorisationLoopDetection<T,F>::e_inv( const T& t ) { using base = LoopDetection_Body<T,F>; if( m_memory.count( t ) == 0 ){ m_memory_inv.push_back( t ); return m_memory[t] = base::m_length++; } base::m_loop_length = base::m_length - ( base::m_loop_start = m_memory[t] ); return base::m_loop_start; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename F> inline int EnumerationLoopDetection<T,Enum_T,Enum_T_inv,F>::e_inv( const T& t ) { return m_enum_T_inv( t ); }

template <typename T , typename F> inline void ValueCalculatorForLoopDetection<T,F>::SetValue( const int& i )
{

  using base = LoopDetection_Body<T,F>;
  int& m_value_inv_i = RefValue_inv( i );

  if( m_value_inv_i != -1 ){

    base::m_loop_length = base::m_length - ( base::m_loop_start = m_value_inv_i );

  } else {
  
    RefValue( base::m_length ) = i;
    m_value_inv_i = base::m_length++;

  }

  return;

}

template <typename T , typename F> inline void MemorisationLoopDetection<T,F>::SetValue( const int& i ) {}

template <typename T , typename F> inline int& ValueCalculatorForLoopDetection<T,F>::RefValue( const int& i ) { if( m_value.count( i ) == 0 ){ return m_value[i] = -1; } return m_value[i]; }
template <typename T , typename F> inline const int& ValueCalculatorForLoopDetection<T,F>::GetValue( const int& i ) { return RefValue( i ); }
template <typename T , typename F> inline const int& MemorisationLoopDetection<T,F>::GefValue( const int& i ) { return i; }

template <typename T , typename F> inline int& ValueCalculatorForLoopDetection<T,F>::RefValue_inv( const int& i ) { if( m_value_inv.count( i ) == 0 ){ return m_value_inv[i] = -1; } return m_value_inv[i]; }
