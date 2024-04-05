// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Utility/Set/a_Body.hpp"

template <typename T , template <typename...> typename MAP> inline CoordinateCompress<T,MAP>::CoordinateCompress() : m_a() , m_enum() , m_compressed() , m_size() {}
template <typename T , template <typename...> typename MAP> template <typename U> inline CoordinateCompress<T,MAP>::CoordinateCompress( const vector<U>& a ) : CoordinateCompress() { insert( a ); }

template <typename T , template <typename...> typename MAP> inline void CoordinateCompress<T,MAP>::insert( const T& t ) { m_enum[t]; m_size = m_enum.size(); m_compressed = false; }
template <typename T , template <typename...> typename MAP> template <typename U> inline void CoordinateCompress<T,MAP>::insert( const vector<U>& a ) { const int length = a.size(); if( length > 0 ){ for( int i = 0 ; i < length ; i++ ){ m_enum[ a[i] ]; } m_size = m_enum.size(); m_compressed = false; } }

template <typename T , template <typename...> typename MAP> inline const T& CoordinateCompress<T,MAP>::operator[]( const int& i ) { return GetSmallest( i ); }
template <typename T , template <typename...> typename MAP> inline const T& CoordinateCompress<T,MAP>::GetSmallest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[i]; }
template <typename T , template <typename...> typename MAP> inline const T& CoordinateCompress<T,MAP>::GetLargest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[m_size - i - 1]; }
template <typename T , template <typename...> typename MAP> inline int CoordinateCompress<T,MAP>::GetOrder( const T& t ) { if( ! m_compressed ){ Compress(); } return m_enum.count( t ) == 1 ? m_enum[t] : -1; }
template <typename T , template <typename...> typename MAP> inline const int& CoordinateCompress<T,MAP>::size() { return m_size; }

template <typename T , template <typename...> typename MAP> inline typename MAP<T,int>::iterator CoordinateCompress<T,MAP>::begin() { return m_enum.begin(); }
template <typename T , template <typename...> typename MAP> inline typename MAP<T,int>::iterator CoordinateCompress<T,MAP>::end() { return m_enum.end(); }

template <typename T , template <typename...> typename MAP> inline void CoordinateCompress<T,MAP>::Compress() { m_a.resize( m_size ); m_size = 0; for( auto itr = m_enum.begin() , end = m_enum.end() ; itr != end ; itr++ ){ m_a[itr->second = m_size++] = itr->first; } m_compressed = true; }
