// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a_Body.hpp

#pragma once
#include "a.hpp"

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::AbstractIntervalAddBIT() : m_bit_0() , m_bit_1() {}
template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::AbstractIntervalAddBIT( const T ( & a )[N] ) : m_bit_0() , m_bit_1() { operator+=( a ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline T AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::Get( const int& i ) const { return IntervalSum( i , i ); }
template <TEMPLATE_ARGUMENTS_FOR_BIT> inline void AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::Set( const int& i , const T& n ) { Add( i , m_T( i_T( IntervalSum( i , i ) ) , n ) ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>& AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::operator+=( const T ( & a )[N] ) { for( int i = 0 ; i < N ; i++ ){ Add( i , a[i] ); } return *this; }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline void AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::Add( const int& i , const T& n ) { IntervalAdd( i , i , n ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline void AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::IntervalAdd( const int& i_start , const int& i_final , const T& n ) { m_bit_0.Add( i_start , prod( i_T( n ) , ( i_start - 1 ) ) ); m_bit_0.Add( i_final + 1 , prod( n , i_final ) ); m_bit_1.Add( i_start , n ); m_bit_1.Add( i_final + 1 , i_T( n ) ); }


template <TEMPLATE_ARGUMENTS_FOR_BIT> inline T AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::InitialSegmentSum( const int& i_final ) const { return m_T( m_bit_0.InitialSegmentSum( i_final ) , prod( m_bit_1.InitialSegmentSum( i_final ) , i_final ) ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT> inline T AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::IntervalSum( const int& i_start , const int& i_final ) const { return m_T( i_T( InitialSegmentSum( i_start - 1 ) ) , InitialSegmentSum( i_final ) ); }

template <TEMPLATE_ARGUMENTS_FOR_BIT>  inline T AbstractIntervalAddBIT<T,m_T,e_T,i_T,N>::prod( const T& n , int exponent ) const { T answer = AbstractBIT<T,m_T,e_T,i_T,N>::g_e; while( exponent-- != 0 ){ answer = m_T( answer , n ); } return answer; }
