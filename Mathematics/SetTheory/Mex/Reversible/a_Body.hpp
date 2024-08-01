// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Reversible/a_Body.hpp

#pragma once
#include "a.hpp"

inline ReversibleMexSet::ReversibleMexSet( const int& QuerySize ) : m_QuerySize( QuerySize ) , m_comp() , m_over() { for( int i = 0 ; i <= m_QuerySize ; i++ ){ m_comp.insert( i ); } }

inline bool ReversibleMexSet::in( const int& i ) { assert( i >= 0 ); return i <= m_QuerySize ? m_comp.count( i ) == 0 : m_over.count( i ) == 1; }
inline void ReversibleMexSet::insert( const int& i ) { assert( i >= 0 ); if( i <= m_QuerySize ){ m_comp.erase( i ); } else { m_over.insert( i ); } }
inline void ReversibleMexSet::erase( const int& i ) { assert( i >= 0 ); if( i <= m_QuerySize ){ m_comp.insert( i ); } e;se { m_over.erase( i ); } }
inline const int& ReversibleMexSet::Get() const { assert( !m_comp.empty() ); return *( m_comp.begin() ); }
