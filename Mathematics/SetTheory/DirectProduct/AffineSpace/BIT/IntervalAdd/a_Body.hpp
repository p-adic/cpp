// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline IntervalAddBIT<U>::IntervalAddBIT( const int& size ) : m_bit_0( size ) , m_bit_1( size ) {}
template <typename U> inline IntervalAddBIT<U>::IntervalAddBIT( const vector<U>& a ) : m_bit_0() , m_bit_1() { const int size = a.size(); vector<U> diff( size ); diff[0] = a[0]; for( int i = 1 ; i < size ; i++ ){ diff[i] = a[i] - a[i-1]; } m_bit_0.Set( diff ); for( int i = 1 ; i < size ; i++ ){ ( diff[i] *= 1 - i ) -= a[i]; } m_bit_1.Set( diff ); }

template <typename U> inline void IntervalAddBIT<U>::Set( const int& i , const U& u ) { Add( i , u - IntervalSum( i , i ) ); }
template <typename U> inline void IntervalAddBIT<U>::Set( const vector<U>& a ) { *this = IntervalAddBIT<U>( a ); }
template <typename U> inline void IntervalAddBIT<U>::Initialise( const int& size ) { m_bit_0.Initialise( size ); m_bit_1.Initialise( size ); }

template <typename U> inline IntervalAddBIT<U>& IntervalAddBIT<U>::operator+=( const vector<U>& a ) { IntervalAddBIT<U> a_copy{ a }; m_bit_0 += a_copy.m_bit_0; m_bit_1 += a_copy.m_bit_1; return *this; }

template <typename U> inline void IntervalAddBIT<U>::Add( const int& i , const U& u ) { IntervalAdd( i , i , u ); }

template <typename U> inline void IntervalAddBIT<U>::IntervalAdd( const int& i_start , const int& i_final , const U& u ) { m_bit_0.Add( i_start , - ( i_start - 1 ) * u ); m_bit_0.Add( i_final + 1 , i_final * u ); m_bit_1.Add( i_start , u ); m_bit_1.Add( i_final + 1 , - u ); }

template <typename U> inline const int& IntervalAddBIT<U>::size() const noexcept { return m_bit_0.size(); }
template <typename U> inline U IntervalAddBIT<U>::operator[]( const int& i ) const { assert( 0 <= i && i < size() ); return IntervalSum( i , i ); }
template <typename U> inline U IntervalAddBIT<U>::Get( const int& i ) const { return operator[]( i ); }
template <typename U> inline U IntervalAddBIT<U>::InitialSegmentSum( const int& i_final ) const { return m_bit_0.InitialSegmentSum( i_final ) + i_final * m_bit_1.InitialSegmentSum( i_final ); }

template <typename U> inline U IntervalAddBIT<U>::IntervalSum( const int& i_start , const int& i_final ) const { return InitialSegmentSum( i_final ) - InitialSegmentSum( i_start - 1 ); }

