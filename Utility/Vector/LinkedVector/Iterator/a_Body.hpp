// c:/Users/user/Documents/Programming/Utility/Vector/Linked/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Entry/a_Body.hpp"

// IteratorOfLinkedVector
template <typename T> inline IteratorOfLinkedVector<T>::IteratorOfLinkedVector( LinkedVector<T>* const& p , const uint& i ) noexcept : m_p( p ) , m_i( i ) {}
template <typename T> inline IteratorOfLinkedVector<T>::IteratorOfLinkedVector( const IteratorOfLinkedVector<T>& itr ) noexcept : m_p( itr.m_p ) , m_i( itr.m_i ) {}

template <typename T> inline T& IteratorOfLinkedVector<T>::operator*() const { return ( *m_p )[m_i]; }
template <typename T> inline T* IteratorOfLinkedVector<T>::operator->() const { return &( ( *m_p )[m_i] ); }

template <typename T> inline IteratorOfLinkedVector<T>& IteratorOfLinkedVector<T>::operator=( const IteratorOfLinkedVector<T>& itr ) noexcept { m_p = itr.m_p; m_i = itr.m_i; return *this; }

template <typename T> inline void IteratorOfLinkedVector<T>::operator++( int ) { m_i = m_p->m_entry[m_i].m_next_entry; }
template <typename T> inline void IteratorOfLinkedVector<T>::operator--( int ) { m_i = m_p->m_entry[m_i].m_prev_entry; }

template <typename T> inline const LinkedVector<T>& IteratorOfLinkedVector<T>::GetLinkedVector() const noexcept { return *m_p; }
template <typename T> inline LinkedVector<T>& IteratorOfLinkedVector<T>::RefLinkedVector() noexcept { return *m_p; }
template <typename T> inline const uint& IteratorOfLinkedVector<T>::GetIndex() const noexcept { return m_i; }
template <typename T> inline const uint& IteratorOfLinkedVector<T>::RefIndex() noexcept { return m_i; }



// ConstIteratorOfLinkedVector
template <typename T> inline ConstIteratorOfLinkedVector<T>::ConstIteratorOfLinkedVector( const LinkedVector<T>* const& p , const uint& i ) noexcept : m_p( p ) , m_i( i ) {}
template <typename T> inline ConstIteratorOfLinkedVector<T>::ConstIteratorOfLinkedVector( const ConstIteratorOfLinkedVector<T>& itr ) noexcept : m_p( itr.m_p ) , m_i( itr.m_i ) {}
template <typename T> inline ConstIteratorOfLinkedVector<T>::ConstIteratorOfLinkedVector( const IteratorOfLinkedVector<T>& itr ) noexcept : m_p( itr.m_p ) , m_i( itr.m_i ) {}

template <typename T> inline const T& ConstIteratorOfLinkedVector<T>::operator*() const { return ( *m_p )[m_i]; }
template <typename T> inline const T* ConstIteratorOfLinkedVector<T>::operator->() const { return &( ( *m_p )[m_i] ); }

template <typename T>
ConstIteratorOfLinkedVector<T>& ConstIteratorOfLinkedVector<T>::operator=( const ConstIteratorOfLinkedVector<T>& itr ) noexcept { m_p = itr.m_p; m_i = itr.m_i; return *this; }

template <typename T>
ConstIteratorOfLinkedVector<T>& ConstIteratorOfLinkedVector<T>::operator=( const IteratorOfLinkedVector<T>& itr ) noexcept { m_p = itr.m_p; m_i = itr.m_i; return *this; }

template <typename T> inline void ConstIteratorOfLinkedVector<T>::operator++( int ) { m_i = m_p->m_entry[m_i].m_next_entry; }
template <typename T> inline void ConstIteratorOfLinkedVector<T>::operator--( int ) { m_i = m_p->m_entry[m_i].m_prev_entry; }

template <typename T> inline const LinkedVector<T>& ConstIteratorOfLinkedVector<T>::GetLinkedVector() const noexcept { return *m_p; }
template <typename T> inline const uint& ConstIteratorOfLinkedVector<T>::GetIndex() const noexcept { return m_i; }
template <typename T> inline const uint& ConstIteratorOfLinkedVector<T>::RefIndex() noexcept { return m_i; }

template <typename T> inline bool ConstIteratorOfLinkedVector<T>::Equal( const IteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p && itr0.m_i == itr1.m_i; }
template <typename T> inline bool ConstIteratorOfLinkedVector<T>::Equal( const ConstIteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p && itr0.m_i == itr1.m_i; }
template <typename T> inline bool ConstIteratorOfLinkedVector<T>::Equal( const IteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p && itr0.m_i == itr1.m_i; }
template <typename T> inline bool ConstIteratorOfLinkedVector<T>::Equal( const ConstIteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p && itr0.m_i == itr1.m_i; }

template <typename T> inline bool operator==( const IteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return ConstIteratorOfLinkedVector<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return ConstIteratorOfLinkedVector<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfLinkedVector<T>& itr0 , const IteratorOfLinkedVector<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const IteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return ConstIteratorOfLinkedVector<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return ConstIteratorOfLinkedVector<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfLinkedVector<T>& itr0 , const ConstIteratorOfLinkedVector<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

