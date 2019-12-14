// c:/Users/user/Documents/Programming/Utility/VLTree/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Entry/a_Body.hpp"

// IteratorOfVLTree
template <typename T> inline IteratorOfVLTree<T>::IteratorOfVLTree() noexcept : m_p( nullptr ) {}
template <typename T> inline IteratorOfVLTree<T>::IteratorOfVLTree( EntryOfVLTree<T>* const& p ) noexcept : m_p( p ) {}
template <typename T> inline IteratorOfVLTree<T>::IteratorOfVLTree( const IteratorOfVLTree<T>& itr ) noexcept : m_p( itr.m_p ) {}
template <typename T> inline T& IteratorOfVLTree<T>::operator*() const { return ( *m_p ).m_t; }
template <typename T> inline T* IteratorOfVLTree<T>::operator->() const { return &( *( *this ) ); }

template <typename T>
IteratorOfVLTree<T>& IteratorOfVLTree<T>::operator=( const IteratorOfVLTree<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;
  
}

template <typename T>
void IteratorOfVLTree<T>::operator++( int )
{

  if( m_p == ( *m_p ).m_right_branch ){

    m_p = nullptr;
    
  } else {

    m_p = ( *m_p ).m_right_branch;

  }

  return;

}

template <typename T>
void IteratorOfVLTree<T>::operator--( int )
{

  if( m_p == ( *m_p ).m_left_branch ){

    m_p = nullptr;

  } else {
    
    m_p = ( *m_p ).m_left_branch;

  }

  return;

}

template <typename T>
void IteratorOfVLTree<T>::operator[]( const int& n )
{

  if( n > 0 ){
      
    m_p = ( *m_p ).m_leftmost_node;

    for( int i = 1 ; i < n ; i++ ){

      m_p = ( *m_p ).m_right_branch;

    }

  }

  if( n < 0 ){
      
    m_p = ( *m_p ).m_rightmost_node;

    for( int i = -1 ; n < i ; i-- ){

      m_p = ( *m_p ).m_left_branch;

    }

  }

  return;

}

template <typename T> inline bool IteratorOfVLTree<T>::IsLeaf() const noexcept { return m_p == ( *m_p ).m_leftmost_node; }
template <typename T> inline bool IteratorOfVLTree<T>::IsLeftMost() const noexcept { return m_p == ( *m_p ).m_left_branch; }
template <typename T> inline bool IteratorOfVLTree<T>::IsRightMost() const noexcept { return m_p == ( *m_p ).m_right_branch; }
template <typename T> inline bool IteratorOfVLTree<T>::IsValid() const noexcept { return m_p != nullptr; }

// ConstIteratorOfVLTree
template <typename T> inline ConstIteratorOfVLTree<T>::ConstIteratorOfVLTree() noexcept : m_p( nullptr ) {}
template <typename T> inline ConstIteratorOfVLTree<T>::ConstIteratorOfVLTree( EntryOfVLTree<T>* const& p ) noexcept : m_p( p ) {}
template <typename T> inline ConstIteratorOfVLTree<T>::ConstIteratorOfVLTree( const ConstIteratorOfVLTree<T>& itr ) noexcept : m_p( itr.m_p ) {}
template <typename T> inline ConstIteratorOfVLTree<T>::ConstIteratorOfVLTree( const IteratorOfVLTree<T>& itr ) noexcept : m_p( itr.m_p ) {}
template <typename T> inline const T& ConstIteratorOfVLTree<T>::operator*() const { return ( *m_p ).m_t; };
template <typename T> inline const T* ConstIteratorOfVLTree<T>::operator->() const { return &( *( *this ) ); }

template <typename T>
ConstIteratorOfVLTree<T>& ConstIteratorOfVLTree<T>::operator=( const ConstIteratorOfVLTree<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;

}

template <typename T>
ConstIteratorOfVLTree<T>& ConstIteratorOfVLTree<T>::operator=( const IteratorOfVLTree<T>& itr ) noexcept
{

  m_p = itr.m_p;
  return *this;

}

template <typename T>
void ConstIteratorOfVLTree<T>::operator++( int )
{

  if( m_p == ( *m_p ).m_right_branch ){

    m_p = nullptr;
    
  } else {

    m_p = ( *m_p ).m_right_branch;

  }

  return;

}

template <typename T>
void ConstIteratorOfVLTree<T>::operator--( int )
{

  if( m_p == ( *m_p ).m_left_branch ){

    m_p = nullptr;

  } else {
    
    m_p = ( *m_p ).m_left_branch;

  }

  return;

}

template <typename T>
void ConstIteratorOfVLTree<T>::operator[]( const int& n )
{

  if( n > 0 ){
      
    m_p = ( *m_p ).m_leftmost_node;

    for( int i = 1 ; i < n ; i++ ){

      m_p = ( *m_p ).m_right_branch;

    }

  }

  if( n < 0 ){
      
    m_p = ( *m_p ).m_rightmost_node;

    for( int i = -1 ; n < i ; i-- ){

      m_p = ( *m_p ).m_left_branch;

    }

  }

  return;

}

template <typename T> inline bool ConstIteratorOfVLTree<T>::IsLeaf() const noexcept { return m_p == ( *m_p ).m_leftmost_mode; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::IsLeftMost() const noexcept { return m_p == ( *m_p ).m_left_branch; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::IsRightMost() const noexcept { return m_p == ( *m_p ).m_right_branch; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::IsValid() const noexcept { return m_p != nullptr; }

template <typename T> inline bool ConstIteratorOfVLTree<T>::Equal( const IteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::Equal( const ConstIteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::Equal( const IteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }
template <typename T> inline bool ConstIteratorOfVLTree<T>::Equal( const ConstIteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return itr0.m_p == itr1.m_p; }

template <typename T> inline bool operator==( const IteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return ConstIteratorOfVLTree<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return ConstIteratorOfVLTree<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfVLTree<T>& itr0 , const IteratorOfVLTree<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const IteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return ConstIteratorOfVLTree<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const IteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return !( itr0 == itr1 );}

template <typename T> inline bool operator==( const ConstIteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return ConstIteratorOfVLTree<T>::Equal( itr0 , itr1 ); }
template <typename T> inline bool operator!=( const ConstIteratorOfVLTree<T>& itr0 , const ConstIteratorOfVLTree<T>& itr1 ) noexcept { return !( itr0 == itr1 );}
