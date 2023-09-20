// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../BIT/a_Body.hpp"

template <typename T , int N> inline IntervalAddBIT<T,N>::IntervalAddBIT() : m_bit_0() , m_bit_1() {}
template <typename T , int N> inline IntervalAddBIT<T,N>::IntervalAddBIT( const T ( &a )[N] ) : m_bit_0() , m_bit_1() { operator+=( a ); }

template <typename T , int N> inline T IntervalAddBIT<T,N>::Get( const int& i ) const { return IntervalSum( i , i ); }
template <typename T , int N> inline void IntervalAddBIT<T,N>::Set( const int& i , const T& n ) { Add( i , n - IntervalSum( i , i ) ); }
template <typename T , int N> inline void IntervalAddBIT<T,N>::Set( const T ( &a )[N] ) { IntervalAddBIT<T,N> a_copy{ a }; swap( m_bit_0 , a_copy.m_bit_0 ); swap( m_bit_1 , a_copy.m_bit_1 ); }
template <typename T , int N> inline void IntervalAddBIT<T,N>::Initialise() { m_bit_0.Initialise(); m_bit_1.Initialise(); }

template <typename T , int N> inline IntervalAddBIT<T,N>& IntervalAddBIT<T,N>::operator+=( const T ( &a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <typename T , int N> inline void IntervalAddBIT<T,N>::Add( const int& i , const T& n ) { IntervalAdd( i , i , n ); }

template <typename T , int N> inline void IntervalAddBIT<T,N>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) { m_bit_0.Add( i_start , - ( i_start - 1 ) * n ); m_bit_0.Add( i_final + 1 , i_final * n ); m_bit_1.Add( i_start , n ); m_bit_1.Add( i_final + 1 , - n ); }


template <typename T , int N> inline T IntervalAddBIT<T,N>::InitialSegmentSum( const int& i_final ) const { return m_bit_0.InitialSegmentSum( i_final ) + i_final * m_bit_1.InitialSegmentSum( i_final ); }

template <typename T , int N> inline T IntervalAddBIT<T,N>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }

