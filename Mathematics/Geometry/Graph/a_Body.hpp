// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename R1 , typename R2 , typename E> inline VirtualGraph<T,R1,R2,E>::VirtualGraph( const int& size , E edge ) : PointedSet<int>( size ) , m_edge( move( edge ) ) { static_assert( is_constructible_v<T,R1> && is_constructible_v<int,R2> && is_invocable_v<E,T> ); }
template <typename E> inline Graph<E>::Graph( const int& size , E edge ) : VirtualGraph<int,const int&,const int&,E>( size , move( edge ) ) {}
template <typename T , typename Enum_T , typename Enum_T_inv , typename E> inline EnumerationGraph<T,Enum_T,Enum_T_inv,E>::EnumerationGraph( const int& size , Enum_T enum_T , Enum_T_inv enum_T_inv , E edge ) : VirtualGraph<T,ret_t<Enum_T,int>,ret_t<Enum_T_inv,T>,E>( size , move( edge ) ) , m_enum_T( move( enum_T ) ) , m_enum_T_inv( move( enum_T_inv ) ) {}
template <typename T , typename E> inline MemorisationGraph<T,E>::MemorisationGraph( const int& size , E edge ) : VirtualGraph<T,T,const int&,E>( size , move( edge ) ) , m_length() , m_memory() , m_memory_inv() {}

template <typename T , typename R1 , typename R2 , typename E> inline ret_t<E,T> VirtualGraph<T,R1,R2,E>::Edge( const T& t ) { return m_edge( t ); }

template <typename E> inline const int& Graph<E>::Enumeration( const int& i ) { return i; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename E> inline ret_t<Enum_T,int> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration( const int& i ) { return m_enum_T( i ); }
template <typename T , typename E> inline T MemorisationGraph<T,E>::Enumeration( const int& i ) { assert( 0 <= i && i < m_length ); return m_memory[i]; }

template <typename E> inline const int& Graph<E>::Enumeration_inv( const int& i ) { return i; }
template <typename T , typename Enum_T , typename Enum_T_inv , typename E> inline ret_t<Enum_T_inv,T> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::Enumeration_inv( const T& t ) { return m_enum_T_inv( t ); }
template <typename T , typename E> inline const int& MemorisationGraph<T,E>::Enumeration_inv( const T& t )
{

  if( m_memory_inv.count( t ) == 0 ){

    assert( m_length < this->size() );
    m_memory.push_back( t );
    return m_memory_inv[t] = m_length++;

  }
  
  return m_memory_inv[t];

}

template <typename T , typename R1 , typename R2 , typename E> void VirtualGraph<T,R1,R2,E>::Reset() {}
template <typename T , typename E> inline void MemorisationGraph<T,E>::Reset() { m_length = 0; m_memory.clear(); m_memory_inv.clear(); }

template <typename E> template <typename F> inline Graph<F> Graph<E>::GetGraph( F edge ) const { return Graph<F>( this->size() , move( edge ) ); }
template <typename T , typename Enum_T , typename Enum_T_inv , typename E> template <typename F> inline EnumerationGraph<T,Enum_T,Enum_T_inv,F> EnumerationGraph<T,Enum_T,Enum_T_inv,E>::GetGraph( F edge ) const { return EnumerationGraph( this->size() , m_enum_T , m_enum_T_inv , move( edge ) ); }
template <typename T , typename E> template <typename F> inline MemorisationGraph<T,F> MemorisationGraph<T,E>::GetGraph( F edge ) const { return MemorisationGraph( this->size() , move( edge ) ); }
