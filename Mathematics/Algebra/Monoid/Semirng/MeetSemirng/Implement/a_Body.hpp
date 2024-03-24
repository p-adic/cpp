// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/Implement/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U> U ZeroForTrop<U>::g_zero{};
template <typename U> inline Trop<U>::Trop( const U& n ) : m_n( n ) {}

template <typename U> inline Trop<U>& Trop<U>::operator+=( const Trop<U>& n ) { n.m_n == ZeroForTrop<U>::g_zero ? m_n : m_n = ( m_n == ZeroForTrop<U>::g_zero ? n.m_n : max( m_n , n.m_n ) ); return *this; }
template <typename U> inline Trop<U>& Trop<U>::operator*=( const Trop<U>& n ) { m_n == ZeroForTrop<U>::g_zero ? m_n : m_n = ( n.m_n == ZeroForTrop<U>::g_zero ? ZeroForTrop<U>::g_zero : m_n + n.m_n ); return *this; }
template <typename U> inline Trop<U> Trop<U>::operator+( const Trop<U>& n ) const { return move( Trop<U>( *this ) += n ); }
template <typename U> inline Trop<U> Trop<U>::operator*( const Trop<U>& n ) const { return move( Trop<U>( *this ) *= n ); }

template <typename U> inline void Trop<U>::Set( const U& n ) noexcept { m_n = n; }
template <typename U> inline const U& Trop<U>::Get() const noexcept { return m_n; }

template <typename U> inline void Trop<U>::SetZero( const U& zero ) noexcept { ZeroForTrop<U>::g_zero = zero; };

template <class Traits , typename U> inline basic_istream<char,Traits>& operator>>( basic_ostream<char,Traits>& is , const Trop<U>& n ) noexcept { U temp; is >> temp; n.Set( temp ); return is; }
template <class Traits , typename U> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Trop<U>& n ) noexcept { return os << n.Get(); }

