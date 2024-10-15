// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Reversible/Multiset/a_Body.hpp

#pragma once
#include "a.hpp"

inline ReversibleMexMultiset::ReversibleMexMultiset( const int& QuerySize ) : m_QuerySize( QuerySize ) , m_comp() , m_mult() { for( int i = 0 ; i <= m_QuerySize ; i++ ){ m_comp.insert( i ); } }

inline int ReversibleMexMultiset::count( const int& i ) const { assert( i >= 0 ); auto itr = m_mult.lower_bound( i ); return itr == m_mult.end() || itr->first != i ? 0 : itr->second; }
inline bool ReversibleMexMultiset::in( const int& i ) const { return count( i ) > 0; }
inline void ReversibleMexMultiset::insert( const int& i ) { assert( i >= 0 ); if( i <= m_QuerySize ){ m_comp.erase( i ); } m_mult[i]++; }
inline void ReversibleMexMultiset::erase( const int& i ) { assert( i >= 0 ); auto itr = m_mult.lower_bound( i ); if( itr == m_mult.end() || itr->first != i ){ return; } if( --itr->second == 0 ){ m_mult.erase( itr ); if( i <= m_QuerySize ){ m_comp.insert( i ); } } }
inline const int& ReversibleMexMultiset::mex() const { assert( !m_comp.empty() ); return *( m_comp.begin() ); }
