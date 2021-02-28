// SmartPointer/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline SmartPointer<T>::SmartPointer() : m_p( new T() ) , m_n( new uint( 1 ) ) , m_b( new bool( false ) ){}

template <typename T> template <typename... Args> inline SmartPointer<T>::SmartPointer( const Args&... args ) : m_p( new T( args... ) ) , m_n( new uint( 1 ) ) , m_b( new bool( true ) ){}

template <typename T> inline SmartPointer<T>::SmartPointer( const SmartPointer<T>& p ) noexcept : m_p( p.m_p ) , m_n( p.m_n ) , m_b( p.m_b ){ *m_n += 1; }

template <typename T> inline SmartPointer<T>::SmartPointer( SmartPointer<T>&& p ) noexcept : m_p( p.m_p ) , m_n( p.m_n ) , m_b( p.m_b ){ *m_n += 1; }

template <typename T>
SmartPointer<T>::~SmartPointer()
{

  if( *m_n == 1 ){

    delete m_p;
    delete m_n;
    delete m_b;

  } else {

    *m_n -= 1;
    
  }

}

template <typename T> inline static void AvoidWunused( const SmartPointer<T>& ) noexcept {}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=( const SmartPointer<T>& p ) noexcept
{

  if( m_p != p.m_p ){
    
    SmartPointer<T> copy_this = *this;
    AvoidWunused( copy_this );
    
    *m_n -= 1;
    m_p = p.m_p;
    m_n = p.m_n;
    m_b = p.m_b;

  }

  return *this;

}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=( T* const& p ) noexcept
{

  if( m_p != p ){
    
    SmartPointer<T> copy_this = *this;
    AvoidWunused( copy_this );
    
    *m_n -= 1;
    m_p = p;
    m_n = 1;
    m_b = ( p == nullptr );

  }

  return *this;

}

// operator=の非const参照での以外の呼び出しではNULLチェックを行うかACCESSを経由すること。
template <typename T>
T& SmartPointer<T>::operator*() const
{

  *m_b = true;
  return *m_p;

}

template <typename T> inline T* SmartPointer<T>::operator->() const noexcept { return m_p; }

// nullptrを使うとポインタのアドレスそのものも代わってしまうため、アドレスを変えずに有効性を判定するためにbool型の変数を記憶。
template <typename T> inline void SmartPointer<T>::Forget() const noexcept { *m_b = false; }

// m_pは決してnullptrにならない。
template <typename T> inline const bool& SmartPointer<T>::IsAccessible() const noexcept { return *m_b; }

template <typename T> inline bool operator==( const SmartPointer<T>& p , const nullptr_t& np ) noexcept { return !( p != nullptr ); }

template <typename T> inline const bool& operator!=( const SmartPointer<T>& p , const nullptr_t& np ) noexcept { return p.IsAccessible(); }

template <typename T> inline T& Access( const SmartPointer<T>& p ){ return *p; }

template <typename T> inline SmartPointer<T> to_SmartPointer( const T& t ){ return SmartPointer<T>( t ); }

template <typename T>
list<SmartPointer<T> > to_SmartPointer_Listed( const list<T>& a )
{

  list<SmartPointer<T> > p;
  
  for( typename list<T>::const_iterator itr = a.begin() , end = a.end() ; itr != end ; itr++ ){

    p.pushback( SmartPointer<T>( *itr ) );

  }

  return p;

}
