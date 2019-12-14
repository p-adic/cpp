// VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Error/IllegalCall/a.hpp"

#include "Iterator/a_Body.hpp"
#include "Wrap/a_Body.hpp"
#include "../../Error/IllegalImput/a_Body.hpp"

template <typename T> inline VLArray<T>::VLArray() : m_e() , m_p_e( &m_e ) , m_size( 0 ) {}
template <typename T> template <typename Arg> inline VLArray<T>::VLArray( const WrapForVLArray<Arg>& t ) : m_e( t.Get() ) , m_p_e( &m_e ) , m_size( 0 ) {}
template <typename T> template <typename Arg1 , typename... Arg2> inline VLArray<T>::VLArray( const Arg1& t0 , const Arg2&... t1 ) : VLArray() { push_back( t0 , t1... ); }
template <typename T> inline VLArray<T>::VLArray( const VLArray<T>& a ) : m_e( a.m_e.m_t , &m_e , &m_e ) , m_p_e( &m_e ) , m_size( 0 ) { *this = a; }
template <typename T> inline VLArray<T>::~VLArray() { clear(); }

template <typename T>
VLArray<T>& VLArray<T>::operator=( const VLArray<T>& a )
{

  if( this != &a ){
    
    clear();

    const EntryOfVLArray<T>* p = a.m_p_e;
    const uint& N = a.m_size;
    
    for( uint n = 0 ; n < N ; n++ ){

      p = ( *p ).m_next;
      push_back( ( *p ).m_t );

    }
  
  }

  return *this;

}

template <typename T> inline const uint& VLArray<T>::size() const noexcept { return m_size; }
template <typename T> inline void VLArray<T>::clear(){ while( m_size > 0 ) pop_back(); }
template <typename T> inline bool VLArray<T>::empty() const noexcept { return m_size == 0; }
template <typename T> inline T& VLArray<T>::front() { return ( *( m_e.m_next ) ).m_t; }
template <typename T> inline const T& VLArray<T>::front() const { return ( *( m_e.m_next ) ).m_t; }
template <typename T> inline T& VLArray<T>::back() { return ( *( m_e.m_prev ) ).m_t; }
template <typename T> inline const T& VLArray<T>::back() const { return ( *( m_e.m_prev ) ).m_t; }

template <typename T> inline void VLArray<T>::push_back() const noexcept {}

template <typename T> template <typename Arg1 , typename... Arg2>
void VLArray<T>::push_back( const Arg1& t0 , const Arg2&... t1 )
{
  
  EntryOfVLArray<T>* p_e_prev = m_e.m_prev;
  auto p = new EntryOfVLArray<T>( t0 , p_e_prev , m_p_e );
    
  m_e.m_prev = p;
  ( *p_e_prev ).m_next = p;
  
  m_size++;
  push_back( t1... );
  return;

}

template <typename T> template <typename Arg>
void VLArray<T>::push_front( const Arg& t )
{

  EntryOfVLArray<T>* p_b = m_e.m_next;
  auto p = new EntryOfVLArray<T>( t , m_p_e , p_b );
    
  ( *p_b ).m_prev = p;
  m_e.m_next = p;
  
  m_size++;
  return;

}

template <typename T>
void VLArray<T>::pop_back()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }
  
  EntryOfVLArray<T>* p_e_prev = m_e.m_prev;
  EntryOfVLArray<T>* p_e_prev_prev = ( *p_e_prev ).m_prev;

  m_e.m_prev = p_e_prev_prev;
  ( *p_e_prev_prev ).m_next = m_p_e;
  
  delete p_e_prev;
  m_size--;
  return;
  
}

template <typename T>
void VLArray<T>::pop_front()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }

  EntryOfVLArray<T>* p_b = m_e.m_next;
  EntryOfVLArray<T>* p_b_next = ( *p_b ).m_next;

  ( *p_b_next ).m_prev = m_p_e;
  m_e.m_next = p_b_next;
  
  delete p_b;  
  m_size--;
  return;
  
}

template <typename T> inline typename VLArray<T>::iterator VLArray<T>::begin() noexcept { return IteratorOfVLArray<T>( m_e.m_next ); }
template <typename T> inline typename VLArray<T>::const_iterator VLArray<T>::begin() const noexcept { return ConstIteratorOfVLArray<T>( m_e.m_next ); }
template <typename T> inline typename VLArray<T>::iterator VLArray<T>::end() noexcept { return IteratorOfVLArray<T>( m_p_e ); }
template <typename T> inline typename VLArray<T>::const_iterator VLArray<T>::end() const noexcept { return ConstIteratorOfVLArray<T>( m_p_e ); }

template <typename T> template <typename Arg>
void VLArray<T>::insert( const typename VLArray<T>::iterator& itr , const Arg& t )
{

  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr , t );
    
  }
  
  EntryOfVLArray<T>* p0 = itr.m_p;
  EntryOfVLArray<T>* p1 = ( *p0 ).m_next;
  auto p = new EntryOfVLArray<T>( t , p0 , p1 );
  
  ( *p1 ).m_prev = p;
  ( *p0 ).m_next = p;
  
  m_size++;
  return;

}
template <typename T>
typename VLArray<T>::iterator VLArray<T>::erase( typename VLArray<T>::iterator& itr )
{
  
  if( ! CheckContain( itr ) ){

    ERR_IMPUT( itr );
    
  }

  EntryOfVLArray<T>* p = itr.m_p;
  EntryOfVLArray<T>* p0 = ( *p ).m_prev;
  EntryOfVLArray<T>* p1 = ( *p ).m_next;
  
  ( *p0 ).m_next = p1;
  ( *p1 ).m_prev = p0;
  itr++;
  
  delete p;
  m_size--;
  return itr;

}

template <typename T>
T& VLArray<T>::operator[]( const uint& i )
{

  if( i >= m_size ){

    ERR_IMPUT( i );

  }

  if( i < m_size / 2 ){

    EntryOfVLArray<T>* p = m_e.m_next;

    for( uint n = 0 ; n < i ; n++ ){

      p = ( *p ).m_next;

    }

    return ( *p ).m_t;

  }

  EntryOfVLArray<T>* p = m_e.m_prev;

  for( uint n = m_size - 1 ; n > i ; n-- ){

    p = ( *p ).m_prev;

  }

  return ( *p ).m_t;

}

template <typename T>
const T& VLArray<T>::operator[]( const uint& i ) const
{

  if( i >= m_size ){

    ERR_IMPUT( i );

  }

  if( i < m_size / 2 ){

    EntryOfVLArray<T>* p = m_e.m_next;

    for( uint n = 0 ; n < i ; n++ ){

      p = ( *p ).m_next;

    }

    return ( *p ).m_t;

  }

  EntryOfVLArray<T>* p = m_e.m_prev;

  for( uint n = m_size - 1 ; n > i ; n-- ){

    p = ( *p ).m_prev;

  }

  return ( *p ).m_t;

}

template <typename T>
bool VLArray<T>::CheckContain( const iterator& itr ) const noexcept
{

  for( auto itr_b = begin() , itr_e = end() ; itr_b != itr_e ; itr_b++ ){

    if( itr == itr_b ){

      return true;

    }
    
  }

  return false;

}

template <typename T>
bool VLArray<T>::CheckContain( const const_iterator& itr ) const noexcept
{

  for( auto itr_b = begin() , itr_e = end() ; itr_b != itr_e ; itr_b++ ){

    if( itr == itr_b ){

      return true;

    }
    
  }

  return false;

}

template <typename T>
string VLArray<T>::Display() const
{

  string s = "(";
  EntryOfVLArray<T>* p = m_p_e;
  
  for( uint n = 0 ; n < m_size ; n++ ){

    p = ( *p ).m_next;
    
    if( n > 0 ){

      s += ",";

    }
    
    s += to_string( ( *p ).m_t );

  }

  s += ")";

  return s;

}

template <typename T> VLArray<T> to_VLArray( const uint& N , const T& t )
{

  auto a = VLArray<T>();

  for( uint n = 0 ; n < N ; n++ ){

    a.push_back( t );

  }

  return a;
  
}

template <typename T> inline VLMatrix<1,T> to_VLMatrix( const uint& N , const T& t ){ return to_VLArray( N , t ); }

template <typename T> inline VLMatrix<2,T> to_VLMatrix( const uint& N0 , const uint& N1 , const T& t ){ return to_VLArray( N1 , to_VLArray( N0 , t ) ); }

template <typename T> inline VLMatrix<3,T> to_VLMatrix( const uint& N0 , const uint& N1 , const uint& N2 , const T& t){ return to_VLArray( N2 , to_VLMatrix( N0 , N1 , t ) ); }
