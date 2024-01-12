// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , typename M_T , typename I_T , typename O_T> inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>::AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const int& size ) : m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_i_T( move( i_T ) ) , m_o_T( move( o_T ) ) , m_size( size ) , m_bit_0( m_m_T , m_e_T , m_i_T , m_size ) , m_bit_1( m_m_T , m_e_T , m_i_T , m_size ) { static_assert( is_invocable_r_v<T,M_T,T,T> && is_invocable_r_v<T,I_T,T> && is_invocable_r_v<T,O_T,int,T> ); }
template <typename T , typename M_T , typename I_T , typename O_T> inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>::AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const vector<T>& a ) : m_m_T( move( m_T ) ) , m_e_T( move( e_T ) ) , m_i_T( move( i_T ) ) , m_o_T( move( o_T ) ) , m_size( a.size() ) , m_bit_0( m_m_T , m_e_T , m_i_T ) , m_bit_1( m_m_T , m_e_T , m_i_T ) { static_assert( is_invocable_r_v<T,M_T,T,T> && is_invocable_r_v<T,I_T,T> && is_invocable_r_v<T,O_T,int,T> ); vector<T> diff( m_size ); diff[0] = a[0]; for( int i = 1 ; i < m_size ; i++ ){ diff[i] = m_m_T( a[i] , m_i_T( a[i-1] ) ); } m_bit_0.Set( diff ); for( int i = 1 ; i < m_size ; i++ ){ T& diff_i = diff[i]; diff_i = m_i_T( m_m_T( m_o_T( i - i , diff_i ) , a[i] ) ); } m_bit_1.Set( diff ); }

template <typename T , typename M_T , typename I_T , typename O_T> inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& AbstractIntervalAddBIT<T,M_T,I_T,O_T>::operator=( AbstractIntervalAddBIT<T,M_T,I_T,O_T>&& a ) { m_m_T = move( a.m_m_T ); m_e_T = move( a.m_e_T ); m_i_T = move( a.m_i_T ); m_o_T = move( a.m_o_T ); m_size = a.m_size; m_bit_0 = move( a.m_bit_0 ); m_bit_1 = move( a.m_bit_1 ); }

template <typename T , typename M_T , typename I_T , typename O_T> inline void AbstractIntervalAddBIT<T,M_T,I_T,O_T>::Set( const int& i , const T& n ) { Add( i , m_m_T( m_i_T( IntervalSum( i , i ) ) , n ) ); }
template <typename T , typename M_T , typename I_T , typename O_T> inline void AbstractIntervalAddBIT<T,M_T,I_T,O_T>::Set( const vector<T>& a ) { *this = AbstractIntervalAddBIT<T,M_T,I_T,O_T>( move( m_m_T ) , move( m_e_T ) , move( m_i_T ) , a ); }
template <typename T , typename M_T , typename I_T , typename O_T> inline void AbstractIntervalAddBIT<T,M_T,I_T,O_T>::Initialise( const int& size ) { m_bit_0.Initialise( size ); m_bit_1.Initialise( size ); }

template <typename T , typename M_T , typename I_T , typename O_T> inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& AbstractIntervalAddBIT<T,M_T,I_T,O_T>::operator+=( const vector<T>& a ) { AbstractIntervalAddBIT<T,M_T,I_T,O_T> a_copy{ m_m_T , m_e_T , m_i_T , m_o_T , a }; for( int i = 1 ; i < m_size ; i++ ){ T& m_bit_0i = m_bit_0[i]; m_bit_0i = m_m_T( m_bit_0 , a_copy.m_bit_0[i] ); T& m_bit_1i = m_bit_1[i]; m_bit_1i = m_m_T( m_bit_1i , a_copy.m_bit_1[i] ); } return *this; }

template <typename T , typename M_T , typename I_T , typename O_T> inline void AbstractIntervalAddBIT<T,M_T,I_T,O_T>::Add( const int& i , const T& n ) { IntervalAdd( i , i , n ); }

template <typename T , typename M_T , typename I_T , typename O_T> inline void AbstractIntervalAddBIT<T,M_T,I_T,O_T>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) { m_bit_0.Add( i_start , m_o_T( ( i_start - 1 ) , m_i_T( n ) ) ); m_bit_0.Add( i_final + 1 , m_o_T( i_final , n ) ); m_bit_1.Add( i_start , n ); m_bit_1.Add( i_final + 1 , m_i_T( n ) ); }


template <typename T , typename M_T , typename I_T , typename O_T> inline T AbstractIntervalAddBIT<T,M_T,I_T,O_T>::operator[]( const int& i ) const { assert( 0 <= i && i < m_size ); return IntervalSum( i , i ); }
template <typename T , typename M_T , typename I_T , typename O_T> inline T AbstractIntervalAddBIT<T,M_T,I_T,O_T>::Get( const int& i ) const { return operator[]( i ); }
template <typename T , typename M_T , typename I_T , typename O_T> inline T AbstractIntervalAddBIT<T,M_T,I_T,O_T>::InitialSegmentSum( const int& i_final ) const { return m_m_T( m_bit_0.InitialSegmentSum( i_final ) , m_o_T( i_final , m_bit_1.InitialSegmentSum( i_final ) ) ); }

template <typename T , typename M_T , typename I_T , typename O_T> inline T AbstractIntervalAddBIT<T,M_T,I_T,O_T>::IntervalSum( const int& i_start , const int& i_final ) const { return m_m_T( m_i_T( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }
