// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline IntervalAddBIT<T>::IntervalAddBIT( const int& size ) : m_bit_0( size ) , m_bit_1( size ) {}
template <typename T> inline IntervalAddBIT<T>::IntervalAddBIT( const vector<T>& a ) : m_bit_0() , m_bit_1() { const int size = a.size(); vector<T> diff( size ); diff[0] = a[0]; for( int i = 1 ; i < size ; i++ ){ diff[i] = a[i] - a[i-1]; } m_bit_0.Set( diff ); for( int i = 1 ; i < size ; i++ ){ ( diff[i] *= 1 - i ) -= a[i]; } m_bit_1.Set( diff ); }

template <typename T> inline IntervalAddBIT<T>& IntervalAddBIT<T>::operator=( IntervalAddBIT<T>&& a ) { m_bit_0 = move( a.m_bit_0 ); m_bit_1 = move( a.m_bit_1 ); }

template <typename T> inline T IntervalAddBIT<T>::Get( const int& i ) const { return IntervalSum( i , i ); }
template <typename T> inline void IntervalAddBIT<T>::Set( const int& i , const T& n ) { Add( i , n - IntervalSum( i , i ) ); }
template <typename T> inline void IntervalAddBIT<T>::Set( const vector<T>& a ) { *this = IntervalAddBIT<T>( a ); }
template <typename T> inline void IntervalAddBIT<T>::Initialise( const int& size ) { m_bit_0.Initialise( size ); m_bit_1.Initialise( size ); }

template <typename T> inline IntervalAddBIT<T>& IntervalAddBIT<T>::operator+=( const vector<T>& a ) { IntervalAddBIT<T> a_copy{ a }; const int size = a.size(); for( int i = 1 ; i < size ; i++ ){ m_bit_0[i] += a_copy.m_bit_0[i]; m_bit_1[i] += a_copy.m_bit_1[i]; } return *this; }

template <typename T> inline void IntervalAddBIT<T>::Add( const int& i , const T& n ) { IntervalAdd( i , i , n ); }

template <typename T> inline void IntervalAddBIT<T>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) { m_bit_0.Add( i_start , - ( i_start - 1 ) * n ); m_bit_0.Add( i_final + 1 , i_final * n ); m_bit_1.Add( i_start , n ); m_bit_1.Add( i_final + 1 , - n ); }


template <typename T> inline T IntervalAddBIT<T>::InitialSegmentSum( const int& i_final ) const { return m_bit_0.InitialSegmentSum( i_final ) + i_final * m_bit_1.InitialSegmentSum( i_final ); }

template <typename T> inline T IntervalAddBIT<T>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }

