// c:/Users/user/Documents/Programming/Utility/VLArray/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Entry/a_Body.hpp"

// IteratorOfVLArray
template <typename T> inline IteratorOfVLArray<T>::IteratorOfVLArray( EntryOfVLArray<T>* const& p ) noexcept : m_p( p ) {}
template <typename T> inline IteratorOfVLArray<T>::IteratorOfVLArray( const IteratorOfVLArray<T>& itr ) noexcept : m_p( itr.m_p ) {}

template <typename T> inline T& IteratorOfVLArray<T>::operator*() const { return ( *m_p ).m_t; }
template <typename T> inline T* IteratorOfVLArray<T>::operator->() const { return &( *( *this ) ); }

template <typename T>
IteratorOfVLArray<T>& IteratorOfVLArray<T>::operator=( const IteratorOfVLArray<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;
  
}

template <typename T> inline void IteratorOfVLArray<T>::operator++( int ){ m_p = ( *m_p ).m_next; }
template <typename T> inline void IteratorOfVLArray<T>::operator--( int ){ m_p = ( *m_p ).m_prev; }

// ConstIteratorOfVLArray
template <typename T> inline ConstIteratorOfVLArray<T>::ConstIteratorOfVLArray( EntryOfVLArray<T>* const& p ) noexcept : m_p( p ) {}
template <typename T> inline ConstIteratorOfVLArray<T>::ConstIteratorOfVLArray( const ConstIteratorOfVLArray<T>& itr ) noexcept : m_p( itr.m_p ) {}
template <typename T> inline ConstIteratorOfVLArray<T>::ConstIteratorOfVLArray( const IteratorOfVLArray<T>& itr ) noexcept : m_p( itr.m_p ) {}

template <typename T> inline const T& ConstIteratorOfVLArray<T>::operator*() const { return ( *m_p ).m_t; };
template <typename T> inline const T* ConstIteratorOfVLArray<T>::operator->() const { return &( *( *this ) ); }

template <typename T>
ConstIteratorOfVLArray<T>& ConstIteratorOfVLArray<T>::operator=( const ConstIteratorOfVLArray<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;

}

template <typename T>
ConstIteratorOfVLArray<T>& ConstIteratorOfVLArray<T>::operator=( const IteratorOfVLArray<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;

}

template <typename T> inline void ConstIteratorOfVLArray<T>::operator++( int ) { m_p = ( *m_p ).m_next; }
template <typename T> inline void ConstIteratorOfVLArray<T>::operator--( int ) { m_p = ( *m_p ).m_prev; }

template <typename T> inline bool ConstIteratorOfVLArray<T>::Equal( const IteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLArray<T>::Equal( const ConstIteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLArray<T>::Equal( const IteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLArray<T>::Equal( const ConstIteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }

template <typename T> inline bool operator==( const IteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return ConstIteratorOfVLArray<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return ConstIteratorOfVLArray<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfVLArray<T>& itr0 , const IteratorOfVLArray<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const IteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return ConstIteratorOfVLArray<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return ConstIteratorOfVLArray<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfVLArray<T>& itr0 , const ConstIteratorOfVLArray<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

