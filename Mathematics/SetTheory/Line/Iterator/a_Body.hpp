// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline IteratorOfLineSubset<INT>::IteratorOfLineSubset( const map<INT,INT>& l , typename map<INT,INT>::iterator itr , INT i ) : m_p( &l ) , m_itr( move( itr ) ) , m_i( move( i ) ) {}

template <typename INT> inline bool IteratorOfLineSubset<INT>::operator==( const IteratorOfLineSubset<INT>& itr ) const noexcept { return m_p == itr.m_p && m_itr == itr.m_itr && m_i == itr.m_i; }
template <typename INT> inline bool IteratorOfLineSubset<INT>::operator!=( const IteratorOfLineSubset<INT>& itr ) const noexcept { return !( *this == itr ); }

template <typename INT> inline INT IteratorOfLineSubset<INT>::operator*() const { return m_i; }
  
template <typename INT> inline IteratorOfLineSubset<INT>& IteratorOfLineSubset<INT>::operator++() { auto end = m_p->end(); assert( m_itr != end ); if( m_i < m_itr->first ){ m_i++; } else { m_i = ++m_itr == end ? 0 : m_itr->second; } return *this; }
template <typename INT> inline IteratorOfLineSubset<INT> IteratorOfLineSubset<INT>::operator++( int ) { auto itr = *this; ++( *this ); return itr; }
template <typename INT> inline IteratorOfLineSubset<INT>& IteratorOfLineSubset<INT>::operator--() { auto begin = m_p->begin(); assert( m_itr != begin ); m_itr->second < m_i ? --m_i : m_i = ( --m_itr )->first; return *this; }
template <typename INT> inline IteratorOfLineSubset<INT> IteratorOfLineSubset<INT>::operator--( int ) { auto itr = *this; --( *this ); return itr; }

template <typename INT> inline void IteratorOfLineSubset<INT>::Next() { auto end = m_p->end(); assert( m_itr != end ); m_i = ++m_itr == end ? 0 : m_itr->second; }
template <typename INT> inline void IteratorOfLineSubset<INT>::Prev() { auto begin = m_p->begin(); if( m_itr == begin ){ m_itr = m_p->end(); m_i = 0; } else { m_i = ( --m_itr )->first; } }

template <typename INT> inline pair<INT,INT> IteratorOfLineSubset<INT>::ConnectedComponent() const { auto end = m_p->end(); assert( m_itr != end ); return { m_itr->second , m_itr->first }; }

template <typename INT> inline IteratorOfLineSubset<INT>& IteratorOfLineSubset<INT>::erase_from( map<INT,INT>& l ) { assert( &l == m_p ); auto itr_copy = ( *this )++; l.erase( itr_copy ); return *this; }

