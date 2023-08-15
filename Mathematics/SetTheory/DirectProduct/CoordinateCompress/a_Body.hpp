// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/CoordinateCompress/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline CoordinateCompress<T>::CoordinateCompress() : m_a() , m_enum() , m_compressed() , m_size() {}
template <typename T> template <typename U , int length_max> inline CoordinateCompress<T>::CoordinateCompress( const U ( &a )[length_max] , const int& length ) : CoordinateCompress() { Insert( a , length ); }
template <typename T> template <typename U> inline CoordinateCompress<T>::CoordinateCompress( const vector<U>& a ) : CoordinateCompress() { Insert( a ); }

template <typename T> inline void CoordinateCompress<T>::Insert( const T& t ) { m_enum[t]; m_size = m_enum.size(); m_compressed = false; }
template <typename T> template <typename U , int length_max> inline void CoordinateCompress<T>::Insert( const U ( &a )[length_max] , const int& length ) { assert( length <= length_max ); if( length > 0 ){ for( int i = 0 ; i < length ; i++ ){ m_enum[ a[i] ]; } m_size = m_enum.size(); m_compressed = false; } }
template <typename T> template <typename U> inline void CoordinateCompress<T>::Insert( const vector<U>& a ) { const int length = a.size(); if( length > 0 ){ for( int i = 0 ; i < length ; i++ ){ m_enum[ a[i] ]; } m_size = m_enum.size(); m_compressed = false; } }

template <typename T> inline const T& CoordinateCompress<T>::GetSmallest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[i]; }
template <typename T> inline const T& CoordinateCompress<T>::GetLargest( const int& i ) { if( ! m_compressed ){ Compress(); } assert( i < m_size ); return m_a[m_size - i - 1]; }
template <typename T> inline int CoordinateCompress<T>::GetOrder( const T& t ) { if( ! m_compressed ){ Compress(); } return m_enum.count( t ) == 1 ? m_enum[t] : -1; }
template <typename T> inline const int& CoordinateCompress<T>::size() { return m_size; }

template <typename T> inline typename map<T,int>::iterator CoordinateCompress<T>::begin() { return m_enum.begin(); }
template <typename T> inline typename map<T,int>::iterator CoordinateCompress<T>::end() { return m_enum.end(); }

template <typename T> inline void CoordinateCompress<T>::Compress() { m_a.resize( m_size ); m_size = 0; for( auto itr = m_enum.begin() , end = m_enum.end() ; itr != end ; itr++ ){ m_a[itr->second = m_size++] = itr->first; } m_compressed = true; }
