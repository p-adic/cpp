// c:/Users/user/Documents/Programming/Utility/LinkedVector/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Entry/a_Body.hpp"

template <typename T> inline LinkedVector<T>::LinkedVector() : m_entry( 1 ) , m_front_linked_entry( 0 ) , m_back_linked_entry( 0 ) , m_size_of_vector( 0 ) , m_size_of_link( 0 ) {}
template <typename T>
LinkedVector<T>::LinkedVector( const uint& max_size ) : m_entry() , m_front_linked_entry( 0 ) , m_back_linked_entry( 0 ) , m_size_of_vector( 0 ) , m_size_of_link( 0 )
{

  m_entry.shrink_to_fit();
  const uint capacity = m_entry.capacity();
  m_entry.reserve( max_size );

  // àÍíUÉÅÉÇÉäÇÃçƒämï€Çê∂Ç∂Ç≥ÇπÇÈÅB
  for( uint i = 0 ; i <= capacity ; i++ ){

    m_entry.push_back( EntryOfLinkedVector<T>() );

  }

  for( uint i = 0 ; i < capacity ; i++ ){

    m_entry.pop_back();

  }
  
}

template <typename T> inline const T& LinkedVector<T>::operator[]( const uint& i ) const { return m_entry[i].m_t; }
template <typename T> inline T& LinkedVector<T>::operator[]( const uint& i ) { return m_entry[i].m_t; }

template <typename T>
uint LinkedVector<T>::GetLinkedEntry( const uint& i ) const
{

  uint linked_entry = m_front_linked_entry;

  for( uint j = 0 ; j < i ; j++ ){

    linked_entry = m_entry[linked_entry].m_next_entry;

  }

  return linked_entry;
  
}

template <typename T> inline const uint& LinkedVector<T>::GetFrontLinkedEntryIndex() const noexcept { return m_front_linked_entry; }
template <typename T> inline const uint& LinkedVector<T>::GetBackLinkedEntryIndex() const noexcept { return m_back_linked_entry; }
template <typename T> inline const uint& LinkedVector<T>::GetSizeOfVector() const noexcept { return m_size_of_vector; }
template <typename T> inline const uint& LinkedVector<T>::GetSizeOfLink() const noexcept { return m_size_of_link; }

template <typename T> inline bool LinkedVector<T>::EmptyVector() const noexcept { return m_size_of_vector == 0; }
template <typename T> inline bool LinkedVector<T>::EmptyLink() const noexcept { return m_size_of_link == 0; }

template <typename T> inline void LinkedVector<T>::push_back() {}

template <typename T> template <typename U>
void LinkedVector<T>::push_back( const U& u )
{

  EntryOfLinkedVector<T>& e = push_back_Body_0();
  e.m_t = u;
  push_back_Body_1( e );
  return;
  
}

template <typename T> template <typename U , typename... ARGS> inline void LinkedVector<T>::push_back( const U& u , const ARGS&... args ) { push_back( u ); push_back( args... ); }

template <typename T> inline EntryOfLinkedVector<T>& LinkedVector<T>::push_back_Body_0() { m_entry.push_back( EntryOfLinkedVector<T>( m_size_of_vector , m_front_linked_entry ) ); return m_entry[m_size_of_vector]; }
template <typename T> inline void LinkedVector<T>::push_back_Body_1( EntryOfLinkedVector<T>& e ) { e.m_next_entry = m_size_of_vector + 1; m_entry[m_front_linked_entry].m_prev_entry = m_size_of_vector + 1; m_back_linked_entry = m_size_of_vector; m_size_of_vector++; m_size_of_link++; }

template <typename T> inline void LinkedVector<T>::SetPreviousLink( const uint& i , const uint& j ) { m_entry[i].m_prev_entry = j; }
template <typename T> inline void LinkedVector<T>::SetNexttLink( const uint& i , const uint& j ) { m_entry[i].m_next_entry = j; }
template <typename T> inline const uint& LinkedVector<T>::GetPreviousLinkIndex( const uint& i ) const { return m_entry[i].m_prev_entry; }
template <typename T> inline const uint& LinkedVector<T>::GetNexttLinkIndex( const uint& i ) const { return m_entry[i].m_next_entry; }

template <typename T>
const uint& LinkedVector<T>::DeLink( const uint& i )
{

  const EntryOfLinkedVector<T>& e = m_entry[i];
  m_entry[e.m_prev_entry].m_next_entry = e.m_next_entry;
  m_entry[e.m_next_entry].m_prev_entry = e.m_prev_entry;

  if( m_front_linked_entry == i ){

    m_front_linked_entry = e.m_next_entry;

  }

  if( m_back_linked_entry == i ){

    m_back_linked_entry = e.m_prev_entry;

  }

  m_size_of_link--;
  return e.m_next_entry;

}

template <typename T>
void LinkedVector<T>::ReLink( const uint& i )
{

  EntryOfLinkedVector<T>& current_entry = m_entry[i];

  if( m_size_of_link == 0 ){

    EntryOfLinkedVector<T>& end_entry = m_entry[m_size_of_vector];
    end_entry.m_prev_entry = end_entry.m_next_entry = i;
    current_entry.m_prev_entry = current_entry.m_next_entry = m_size_of_vector;
    m_front_linked_entry = m_back_linked_entry = i;

  } else {

    uint prev;

    if( m_front_linked_entry > i ){

      m_front_linked_entry = i;
      prev = m_size_of_vector;

    } else {

      prev = m_front_linked_entry;

    }

    if( m_back_linked_entry < i ){

      m_back_linked_entry = i;
      
    }
    
    prev = m_entry[prev].m_next_entry;
  
    while( prev < i ){

      prev = m_entry[prev].m_next_entry;

    }

    const uint next = prev;
    EntryOfLinkedVector<T>& next_entry = m_entry[next];
    prev = next_entry.m_prev_entry;
    EntryOfLinkedVector<T>& prev_entry = m_entry[prev];
    prev_entry.m_next_entry = i;
    current_entry.m_prev_entry = prev;
    current_entry.m_next_entry = next;
    next_entry.m_prev_entry = i;

  }
  
  m_size_of_link++;
  return;
    
}

template <typename T> inline typename LinkedVector<T>::iterator LinkedVector<T>::GetIterator( const uint& i ) noexcept { return typename LinkedVector<T>::iterator( this , i ); }
template <typename T> inline typename LinkedVector<T>::const_iterator LinkedVector<T>::GetIterator( const uint& i ) const noexcept { return typename LinkedVector<T>::const_iterator( this , i ); }
template <typename T> inline typename LinkedVector<T>::iterator LinkedVector<T>::begin() noexcept { return typename LinkedVector<T>::iterator( this , m_front_linked_entry ); }
template <typename T> inline typename LinkedVector<T>::const_iterator LinkedVector<T>::begin() const noexcept { return typename LinkedVector<T>::const_iterator( this , m_front_linked_entry ); }
template <typename T> inline typename LinkedVector<T>::iterator LinkedVector<T>::end() noexcept { return typename LinkedVector<T>::iterator( this , m_size_of_vector ); }
template <typename T> inline typename LinkedVector<T>::const_iterator LinkedVector<T>::end() const noexcept { return typename LinkedVector<T>::const_iterator( this , m_size_of_vector ); }
template <typename T> typename LinkedVector<T>::iterator LinkedVector<T>::erase( typename LinkedVector<T>::iterator& itr ) { return typename LinkedVector<T>::iterator( this , DeLink( itr.m_i ) ); }
