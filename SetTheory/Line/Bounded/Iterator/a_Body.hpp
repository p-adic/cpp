// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT>::IteratorOfBoundedLineSubset( BLS& S , INT i ) : m_p( &S ) , m_i( move( i ) ) {}

template <typename BLS , typename INT> inline bool IteratorOfBoundedLineSubset<BLS,INT>::operator==( const IteratorOfBoundedLineSubset<BLS,INT>& itr ) const noexcept { return m_p == itr.m_p && m_i == itr.m_i; }
template <typename BLS , typename INT> inline bool IteratorOfBoundedLineSubset<BLS,INT>::operator!=( const IteratorOfBoundedLineSubset<BLS,INT>& itr ) const noexcept { return !( *this == itr ); }

template <typename BLS , typename INT> inline INT IteratorOfBoundedLineSubset<BLS,INT>::operator*() const { return m_i; }

template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT>& IteratorOfBoundedLineSubset<BLS,INT>::operator++() { assert( m_i <= m_p->ubound() ); return *this = m_p->MinimumGt( m_i ); }
template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT> IteratorOfBoundedLineSubset<BLS,INT>::operator++( int ) { auto itr = *this; ++( *this ); return itr; }
template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT>& IteratorOfBoundedLineSubset<BLS,INT>::operator--() { assert( m_p->begin().m_i <= m_i ); return *this = m_p->MaximumLt( m_i ); }
template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT> IteratorOfBoundedLineSubset<BLS,INT>::operator--( int ) { auto itr = *this; --( *this ); return itr; }

template <typename BLS , typename INT> inline void IteratorOfBoundedLineSubset<BLS,INT>::Next() { assert( m_i < m_p->ubound() ); const INT r = m_p->RightEndPointOf( m_i ); *this = m_i <= r ? m_p->MinimumGt( r ) : m_p->end(); }
template <typename BLS , typename INT> inline void IteratorOfBoundedLineSubset<BLS,INT>::Prev() { assert( m_p->lbound() < m_i ); const INT l = m_p->LeftEndPointOf( m_i ); *this = l <= m_i ? m_p->MaximumLt( l ) : m_p->end(); }

template <typename BLS , typename INT> inline pair<INT,INT> IteratorOfBoundedLineSubset<BLS,INT>::ConnectedComponent() const { return m_p->ConnectedComponentOf( m_i ); }

template <typename BLS , typename INT> inline IteratorOfBoundedLineSubset<BLS,INT>& IteratorOfBoundedLineSubset<BLS,INT>::erase_from( BLS& S ) { assert( &S == m_p ); auto itr_copy = ( *this )++; S.erase( itr_copy ); return *this; }

