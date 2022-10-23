// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/HybridBIT/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../BIT/a_Body.hpp"

template <typename T , int N> inline HybridBIT<T,N>::HybridBIT() : BIT() , m_a() {}
template <typename T , int N> inline HybridBIT<T,N>::HybridBIT( const T ( & a )[N] ) : BIT() , m_a() { operator+=( a ); }

template <typename T , int N> inline const T& HybridBIT<T,N>::operator[]( const int& i ) const { return m_a[i]; }
template <typename T , int N> inline void HybridBIT<T,N>::Set( const int& i , const T& n ) { Add( i , n - m_a[i] ); }

template <typename T , int N> inline HybridBIT<T,N>& HybridBIT<T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <typename T , int N> inline void HybridBIT<T,N>::Add( const int& i , const T& n ) { m_a[i] += n; BIT<T,N>::Add( i , n ); }
