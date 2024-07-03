// c:/Users/user/Documents/Programming/Utility/VLArray/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Error/IllegalCall/a.hpp"

#include "Iterator/a_Body.hpp"
#include "../WrappedType/a_Body.hpp"
#include "../../Error/IllegalInput/a_Body.hpp"

template <typename T> inline VLArray<T>::VLArray() : m_e() , m_p_e( &m_e ) , m_size( 0 ) , m_p_last( nullptr ) , m_p_p_last( &m_p_last ) , m_i_last( 0 ) , m_p_i_last( &m_i_last ) {}
template <typename T> template <typename Arg1 , typename... Arg2> inline VLArray<T>::VLArray( const Arg1& t0 , const Arg2&... t1 ) : VLArray() { push_back( t0 , t1... ); }
template <typename T> inline VLArray<T>::VLArray( const VLArray<T>& a ) : m_e( a.m_e.m_t ) , m_p_e( &m_e ) , m_size( 0 ) , m_p_last( nullptr ) , m_p_p_last( &m_p_last ) , m_i_last( 0 ) , m_p_i_last( &m_i_last ) { Concatenate( a ); }
template <typename T> template <typename Arg> inline VLArray<T>::VLArray( const WrappedType<Arg>& t ) : m_e( t.Get() ) , m_p_e( &m_e ) , m_size( 0 ) , m_p_last( nullptr ) , m_p_p_last( &m_p_last ) , m_i_last( 0 ) , m_p_i_last( &m_i_last ) {}

template <typename T> VLArray<T>::~VLArray() { clear(); }

template <typename T>
VLArray<T>& VLArray<T>::operator=( const VLArray<T>& a )
{

  if( this != &a ){
    
    clear();
    Concatenate( a );
  
  }

  return *this;

}

template <typename T> inline const uint& VLArray<T>::size() const noexcept { return m_size; }
template <typename T> inline void VLArray<T>::clear(){ while( m_size > 0 ) pop_back(); }
template <typename T> inline bool VLArray<T>::empty() const noexcept { return m_size == 0; }

template <typename T>
T& VLArray<T>::front()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }
  
  return m_e.m_next->m_t;

}

template <typename T>
const T& VLArray<T>::front() const
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }

  return m_e.m_next->m_t;

}

template <typename T>
T& VLArray<T>::back()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }

  return m_e.m_prev->m_t;

}

template <typename T>
const T& VLArray<T>::back() const
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }

  return m_e.m_prev->m_t;

}

template <typename T> template <typename Arg>
void VLArray<T>::push_back( const Arg& t )
{
  
  EntryOfVLArray<T>* p_e_prev = m_e.m_prev;
  auto p = new EntryOfVLArray<T>( t , p_e_prev , m_p_e );
    
  m_e.m_prev = p;
  p_e_prev->m_next = p;
  
  m_size++;
  return;

}


template <typename T> template <typename... Args>
void VLArray<T>::push_back( const Args&... args )
{

  VLArray<T> copy{};

  // 関数の処理は後ろからなのでbackではなくfrontを使う。
  ExpandParameterPack( copy.push_front_int( args )... );
  Concatenate_back( copy );
  return;
  
}

template <typename T> template <typename Arg> inline int VLArray<T>::push_back_int( const Arg& t ) { push_back( t ); return 0; }

template <typename T> template <typename Arg>
void VLArray<T>::push_front( const Arg& t )
{

  EntryOfVLArray<T>* p_b = m_e.m_next;
  auto p = new EntryOfVLArray<T>( t , m_p_e , p_b );
    
  p_b->m_prev = p;
  m_e.m_next = p;
  
  m_size++;
  return;

}

template <typename T> template <typename... Args>
void VLArray<T>::push_front( const Args&... args )
{

  VLArray<T> copy{};

  // 関数の処理は後ろからなのでfrontではなくbackを使う。
  ExpandParameterPack( copy.push_back_int( args )... );
  Concatenate_front( copy );
  return;

}

template <typename T> template <typename Arg> inline int VLArray<T>::push_front_int( const Arg& t ) { push_front( t ); return 0; }

template <typename T>
void VLArray<T>::pop_back()
{

  if( m_size == 0 ){

    ERR_CALL;
    
  }
  
  EntryOfVLArray<T>* p_e_prev = m_e.m_prev;
  EntryOfVLArray<T>* p_e_prev_prev = p_e_prev->m_prev;

  m_e.m_prev = p_e_prev_prev;
  p_e_prev_prev->m_next = m_p_e;

  if( m_p_last == p_e_prev ){

    m_p_last = nullptr;

  }
  
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

  p_b_next->m_prev = m_p_e;
  m_e.m_next = p_b_next;
  
  if( m_p_last == p_b ){

    m_p_last = nullptr;

  }
  
  delete p_b;  
  m_size--;
  return;
  
}

template <typename T> template <typename... Args> inline void VLArray<T>::Concatenate( const Args&... args ) { Concatenate_back( args... ); }

template <typename T> template <typename Arg>
void VLArray<T>::Concatenate_back( const Arg& a )
{
  
  const EntryOfVLArray<T>* p = a.m_p_e;
  const uint& N = a.m_size;
    
  for( uint n = 0 ; n < N ; n++ ){

    p = p->m_next;
    push_back( p->m_t );

  }

  return;

}

template <typename T> template <typename... Args>
void VLArray<T>::Concatenate_back( const Args&... args )
{

  VLArray<T> copy{};

  // 関数の処理は後ろからなのでbackではなくfrontを使う。
  ExpandParameterPack( copy.Concatenate_front_int( args )... );
  Concatenate_back( copy );
  return;

}

template <typename T> template <typename Arg> inline int VLArray<T>::Concatenate_back_int( const Arg& a ) { Concatenate( a ); return 0; }

template <typename T> template <typename Arg>
void VLArray<T>::Concatenate_front( const Arg& a )
{
  
  const EntryOfVLArray<T>* p = a.m_p_e;
  const uint& N = a.m_size;
    
  for( uint n = 0 ; n < N ; n++ ){

    p = p->m_prev;
    push_front( p->m_t );

  }

  return;

}

template <typename T> template <typename... Args>
void VLArray<T>::Concatenate_front( const Args&... args )
{

  VLArray<T> copy{};

  // 関数の処理は後ろからなのでfrontではなくbackを使う。
  ExpandParameterPack( copy.Concatenate_back_int( args )... );
  Concatenate_front( copy );
  return;

}

template <typename T> template <typename Arg> inline int VLArray<T>::Concatenate_front_int( const Arg& a ) { Concatenate_front( a ); return 0; }


template <typename T> inline typename VLArray<T>::iterator VLArray<T>::begin() noexcept { return IteratorOfVLArray<T>( m_e.m_next ); }
template <typename T> inline typename VLArray<T>::const_iterator VLArray<T>::begin() const noexcept { return ConstIteratorOfVLArray<T>( m_e.m_next ); }
template <typename T> inline typename VLArray<T>::iterator VLArray<T>::end() noexcept { return IteratorOfVLArray<T>( m_p_e ); }
template <typename T> inline typename VLArray<T>::const_iterator VLArray<T>::end() const noexcept { return ConstIteratorOfVLArray<T>( m_p_e ); }

template <typename T> template <typename Arg> inline typename VLArray<T>::iterator VLArray<T>::insert( const typename VLArray<T>::iterator& itr , const Arg& t ) { return insert_front( itr , t ); }

template <typename T> template <typename Arg>
typename VLArray<T>::iterator VLArray<T>::insert_front( const typename VLArray<T>::iterator& itr , const Arg& t )
{

  if( ! CheckContain( itr ) ){

    auto& s = itr.Access();
    ERR_INPUT( s , t );
    
  }

  if( itr == begin() ){

    push_front( t );
    return begin();

  }

  EntryOfVLArray<T>* p1 = itr.m_p;
  EntryOfVLArray<T>* p0 = p1->m_prev;
  auto p = new EntryOfVLArray<T>( t , p0 , p1 );
  
  p0->m_next = p;
  p1->m_prev = p;
  
  m_size++;
  return typename VLArray<T>::iterator( p );

}

template <typename T> template <typename Arg>
typename VLArray<T>::iterator VLArray<T>::insert_back( const typename VLArray<T>::iterator& itr , const Arg& t )
{

  if( ! CheckContain( itr ) ){

    auto& s = itr.Access();
    ERR_INPUT( s , t );
    
  }
  
  EntryOfVLArray<T>* p0 = itr.m_p;
  EntryOfVLArray<T>* p1 = p0->m_next;
  auto p = new EntryOfVLArray<T>( t , p0 , p1 );
  
  p1->m_prev = p;
  p0->m_next = p;
  
  m_size++;
  return typename VLArray<T>::iterator( p );

}

template <typename T> inline typename VLArray<T>::iterator VLArray<T>::erase( typename VLArray<T>::iterator& itr ) { return erase_back( itr ); }

template <typename T>
typename VLArray<T>::iterator VLArray<T>::erase_back( typename VLArray<T>::iterator& itr )
{
  
  if( ! CheckContain( itr ) ){

    auto& t = itr.Access();
    ERR_INPUT( t );
    
  }

  EntryOfVLArray<T>* p = itr.m_p;
  EntryOfVLArray<T>* p0 = p->m_prev;
  EntryOfVLArray<T>* p1 = p->m_next;
  
  p0->m_next = p1;
  p1->m_prev = p0;
  itr++;
  
  if( m_p_last == p ){

    m_p_last = nullptr;

  }
  
  delete p;
  m_size--;
  return itr;

}

template <typename T>
typename VLArray<T>::iterator VLArray<T>::erase_front( typename VLArray<T>::iterator& itr )
{
  
  if( ! CheckContain( itr ) ){

    auto& t = itr.Access();
    ERR_INPUT( t );
    
  }

  EntryOfVLArray<T>* p = itr.m_p;
  EntryOfVLArray<T>* p0 = p->m_prev;
  EntryOfVLArray<T>* p1 = p->m_next;
  
  p0->m_next = p1;
  p1->m_prev = p0;
  itr--;
  
  if( m_p_last == p ){

    m_p_last = nullptr;

  }
  
  delete p;
  m_size--;
  return itr;

}

template <typename T>
T& VLArray<T>::operator[]( const uint& i )
{

  if( i >= m_size ){

    ERR_INPUT( i );

  }

  EntryOfVLArray<T>*& p = *m_p_p_last;
  uint& i_last = *m_p_i_last;

  if( p == nullptr ){

    p = m_e.m_next;
    i_last = 0;

  }

  if( i < ( i_last >> 1 ) ){

    p = m_e.m_next;
    i_last = 0;

  } else if( ( ( m_size + i_last ) >> 1 ) < i ){

    p = m_e.m_prev;
    i_last = m_size - 1;

  }

  if( i < i_last ){

    for( uint n = i_last ; n > i ; n-- ){

      p = p->m_prev;

    }

  } else {

    for( uint n = i_last ; n < i ; n++ ){

      p = p->m_next;

    }

  }

  i_last = i;
  return p->m_t;

}

template <typename T>
const T& VLArray<T>::operator[]( const uint& i ) const
{

  if( i >= m_size ){

    ERR_INPUT( i );

  }

  EntryOfVLArray<T>*& p = *m_p_p_last;
  uint& i_last = *m_p_i_last;

  if( p == nullptr ){

    p = m_e.m_next;
    i_last = 0;

  }

  if( i < ( i_last >> 1 ) ){

    p = m_e.m_next;
    i_last = 0;

  } else if( ( ( m_size + i_last ) >> 1 ) < i ){

    p = m_e.m_prev;
    i_last = m_size - 1;

  }

  if( i < i_last ){

    for( uint n = i_last ; n > i ; n-- ){

      p = p->m_prev;

    }

  } else {

    for( uint n = i_last ; n < i ; n++ ){

      p = p->m_next;

    }

  }

  i_last = i;
  return p->m_t;

}

template <typename T>
VLArray<T> VLArray<T>::GetInitialSegment( const int& n ) const
{

  const int N = (int)m_size;
  int M;

  if( N <= n ){

    M = N;

  } else {
    
    if( 0 <= n ){

      M = n;
      
    } else {

      M = N + n;

    }

  }

  VLArray<T> b{};
  const_iterator itr = begin();

  for( int m = 1 ; m <= M ; m++ ){

    b.push_back( *itr );
    itr++;

  }

  return b;

}

template <typename T>
VLArray<T> VLArray<T>::GetFinalSegment( const int& n ) const
{

  const int N = (int)m_size;
  int M;

  if( N <= n ){

    M = N;

  } else {
    
    if( 0 <= n ){

      M = n;
      
    } else {

      M = N + n;

    }
  
  }

  VLArray<T> b{};
  const_iterator itr = end();

  for( int m = 1 ; m <= M ; m++ ){

    itr--;
    b.push_front( *itr );

  }

  return b;

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
string VLArray<T>::Display() const noexcept
{

  string s = "(";
  EntryOfVLArray<T>* p = m_p_e;
  
  for( uint n = 0 ; n < m_size ; n++ ){

    if( n > 0 ){

      s += ",";

    } else {

      if( p == nullptr ){

	s += "error: nullptr for m_p_e for non-empty VLArray";
	break;

      }

    }
    
    p = p->m_next;
    
    if( p == nullptr ){

      s += "error: nullptr for node";
      break;

    }

    s += to_string( p->m_t );

  }

  s += ")";

  return s;

}

template <typename T> template <typename... Args> inline void VLArray<T>::ExpandParameterPack( const Args&... ) noexcept {};

template <typename T>
bool operator==( const VLArray<T>& a1 , const VLArray<T>& a2 )
{

  auto itr1 = a1.begin();
  auto end1 = a1.end();
  auto itr2 = a2.begin();
  auto end2 = a2.end();

  while( itr1 != end1 && itr2 != end2 ){

    if( *itr1 != *itr2 ){

      return false;

    }

    itr1++;
    itr2++;

  }

  return ( itr1 == end1 ) && ( itr2 == end2 );

}

template <typename T> inline bool operator!=( const VLArray<T>& a1 , const VLArray<T>& a2 ) { return !( a1 == a2 ); }


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

template <typename T , typename... Arg>
VLArray<T> Frown( const Arg&... args )
{

  VLArray<T> a{};
  a.Concatenate( args... );
  return a;

}

template <typename T> T Sum( const VLArray<T>& a )
{
  
  T t{};
  for( auto itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    t += *itr;

  }

  return t;

}
