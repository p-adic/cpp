// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/Hybrid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline HybridBIT<T>::HybridBIT( const int& size ) : BIT<T>( size ) , m_a( size ) {}
template <typename T> inline HybridBIT<T>::HybridBIT( const vector<T>& a ) : BIT<T>( a ) , m_a( a ) {}
template <typename T> inline HybridBIT<T>::HybridBIT( vector<T>&& a ) : BIT<T>( a ) , m_a( move( a ) ) {}

template <typename T> inline const T& HybridBIT<T>::operator[]( const int& i ) const { return m_a[i]; }
template <typename T> inline const T& HybridBIT<T>::Get()( const int& i ) const { return m_a[i]; }
template <typename T> inline void HybridBIT<T>::Set( const int& i , const T& n ) { Add( i , n - m_a[i] ); }
template <typename T> inline void HybridBIT<T>::Set( vector<T>&&a ) { BIT<T>::Set( a ); m_a = move( a ); }

template <typename T> inline HybridBIT<T>& HybridBIT<T>::operator+=( const vector<T>& a ) { BIT<T>::operator+=( a ); for( int i = 0 ; i < BIT<T>::m_size ; i++ ){ m_a[i] += a[i]; } return *this; }

template <typename T> inline void HybridBIT<T>::Add( const int& i , const T& n ) { m_a[i] += n; BIT<T>::Add( i , n ); }
