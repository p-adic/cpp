// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int size_max> inline CoordinateCompress<T,size_max>::CoordinateCompress() : m_a() , m_enum() , m_compressed() , m_size() {}
template <typename T , int size_max> template <typename U , int length_max> inline CoordinateCompress<T,size_max>::CoordinateCompress( const U ( &a )[length_max] , const int& length ) : CoordinateCompress() { Insert( a , length ); }

template <typename T , int size_max> template <typename U , int length_max> inline void CoordinateCompress<T,size_max>::Insert( const U ( &a )[length_max] , const int& length ) { assert( length <= length_max ); if( length > 0 ){ for( int i = 0 ; i < length ; i++ ){ m_enum[ a[i] ]; } assert( ( m_size = m_enum.size() ) <= size_max ); m_compressed = false; } }

template <typename T , int size_max> inline const T& CoordinateCompress<T,size_max>::GetSmallest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[i]; }
template <typename T , int size_max> inline const T& CoordinateCompress<T,size_max>::GetLargest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[m_size - i - 1]; }
template <typename T , int size_max> inline int CoordinateCompress<T,size_max>::GetOrder( const T& t ) { if( ! m_compressed ){ Compress(); } return m_enum.count( t ) == 1 ? m_enum[t] : -1; }
template <typename T , int size_max> inline const int& CoordinateCompress<T,size_max>::size() { return m_size; }

template <typename T , int size_max> inline typename map<T,int>::iterator CoordinateCompress<T,size_max>::begin() { return m_enum.begin(); }
template <typename T , int size_max> inline typename map<T,int>::iterator CoordinateCompress<T,size_max>::end() { return m_enum.end(); }

template <typename T , int size_max> inline void CoordinateCompress<T,size_max>::Compress() { m_size = 0; for( auto itr = m_enum.begin() , end = m_enum.end() ; itr != end ; itr++ ){ m_a[m_size] = itr->first; itr->second = m_size++; } m_compressed = true; }
