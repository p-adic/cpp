// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Iterator/a_Body.hpp

#pragma once
#include "a.hpp"

#ifdef DEBUG
  #include "../Debug/a_Body.hpp"
#else
  #include "../a_Body.hpp"
#endif

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>::IteratorOfBoundedLineSubset( const AbstractBoundedLineSubset<INT,DATA_STR>& S , INT i ) : m_p( &S ) , m_i( move( i ) ) {}
  
template <typename INT , template <typename...> typename DATA_STR> inline bool IteratorOfBoundedLineSubset<INT,DATA_STR>::operator==( const IteratorOfBoundedLineSubset<INT,DATA_STR>& itr ) const noexcept { return m_p == itr.m_p && m_i == itr.m_i; }
template <typename INT , template <typename...> typename DATA_STR> inline bool IteratorOfBoundedLineSubset<INT,DATA_STR>::operator!=( const IteratorOfBoundedLineSubset<INT,DATA_STR>& itr ) const noexcept { return !( *this == itr ); }

template <typename INT , template <typename...> typename DATA_STR> inline INT IteratorOfBoundedLineSubset<INT,DATA_STR>::operator*() const { return m_i; }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& IteratorOfBoundedLineSubset<INT,DATA_STR>::operator++() { assert( m_i <= m_p->ubound ); return *this = m_p->MinimumGt( m_i ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> IteratorOfBoundedLineSubset<INT,DATA_STR>::operator++( int ) { auto itr = *this; ++( *this ); return itr; }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& IteratorOfBoundedLineSubset<INT,DATA_STR>::operator--() { assert( m_p->begin().m_i <= m_i ); return *this = m_p->MaximumLt( m_i ); }
template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR> IteratorOfBoundedLineSubset<INT,DATA_STR>::operator--( int ) { auto itr = *this; --( *this ); return itr; }

template <typename INT , template <typename...> typename DATA_STR> inline void IteratorOfBoundedLineSubset<INT,DATA_STR>::Next() { assert( m_i < m_p->ubound ); const INT r = m_p->RightEndPointOf( m_i ); *this = m_i <= r ? m_p->MinimumGt( r ) : m_p->end(); }
template <typename INT , template <typename...> typename DATA_STR> inline void IteratorOfBoundedLineSubset<INT,DATA_STR>::Prev() { assert( m_p->lbound < m_i ); const INT l = m_p->LeftEndPointOf( m_i ); *this = l <= m_i ? m_p->MaximumLt( l ) : m_p->end(); }

template <typename INT , template <typename...> typename DATA_STR> inline pair<INT,INT> IteratorOfBoundedLineSubset<INT,DATA_STR>::ConnectedComponent() const { return m_p->ConnectedComponentOf( m_i ); }

template <typename INT , template <typename...> typename DATA_STR> inline IteratorOfBoundedLineSubset<INT,DATA_STR>& IteratorOfBoundedLineSubset<INT,DATA_STR>::erase_from( AbstractBoundedLineSubset<INT,DATA_STR>& S ) { assert( &S == m_p ); auto itr_copy = ( *this )++; S.erase( itr_copy ); return *this; }

