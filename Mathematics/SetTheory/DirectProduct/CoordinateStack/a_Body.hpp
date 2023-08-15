// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateStack/a_Body.hpp

#pragma once
#include "a.hpp"

inline CoordinateStack::CoordinateStack( const int& size ) : m_length( 1 + size ) , m_size( size ) {}

inline int& CoordinateStack::length( const int& n ) { assert( n < m_size ); return m_length[1 + n]; }
inline const int& CoordinateStack::size() const noexcept { return m_size; }

inline void CoordinateStack::push_back( const int& length ) { m_length.push_back( m_length.back() + length ); m_size++; }
inline void CoordinateStack::pop_back() { assert( m_size > 0 ); m_length.pop_back(); m_size--; }
inline void CoordinateStack::resize( const int& size ) { m_length.resize( 1 + size ); m_size = size; }

inline int CoordinateStack::GetOrder( const int& n , const int& i ) const { return m_length[n] + i; }
inline pair<int,int> CoordinateStack::GetOrder( const int& n , const int& i , const int& j ) const { const int& length_n = m_length[n]; return { length_n + i , length_n + j }; }
