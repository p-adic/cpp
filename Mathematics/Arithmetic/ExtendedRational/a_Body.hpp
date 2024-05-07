// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( const T& n , const T& d ) : m_n( n ) , m_d( d ) { assert( n != 0 || d != 0 ); }
template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( const ExtendedRational<T>& r ) : m_n( r.m_n ) , m_d( r.m_d ) {}
template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( ExtendedRational<T>&& r ) : m_n( move( r.m_n ) ) , m_d( move( r.m_d ) ) {}

template <typename T> inline constexpr ExtendedRational<T>& ExtendedRational<T>::operator=( ExtendedRational<T> r ) noexcept { m_n = move( r.m_n ); m_d = move( r.m_d ); return *this; }

template <typename T> inline constexpr bool ExtendedRational<T>::operator==( const ExtendedRational<T>& r ) const noexcept { return m_d == 0 ? r.m_d == 0 && ( m_n > 0 ) == ( r.m_n > 0 ) : m_n * r.m_d == r.m_n * m_d; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator!=( const ExtendedRational<T>& r ) const noexcept { return !( *this == r ); }
template <typename T> inline constexpr bool ExtendedRational<T>::operator<=( const ExtendedRational<T>& r ) const noexcept { return m_d == 0 ? m_n < 0 : ( m_d > 0 ) == ( r.m_d >= 0 ) ? m_n * r.m_d <= r.m_n * m_d : m_n * r.m_d >= r.m_n * m_d; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator>=( const ExtendedRational<T>& r ) const noexcept { return r <= *this; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator<( const ExtendedRational<T>& r ) const noexcept { return m_d == 0 ? m_n < 0 : ( m_d > 0 ) == ( r.m_d >= 0 ) ? m_n * r.m_d < r.m_n * m_d : m_n * r.m_d > r.m_n * m_d; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator>( const ExtendedRational<T>& r ) const noexcept { return r < *this; }

template <typename T> inline constexpr const T& ExtendedRational<T>::GetNumerator() const noexcept { return m_n; }
template <typename T> inline constexpr const T& ExtendedRational<T>::GetDenominator() const noexcept { return m_d; }

template <typename T> inline constexpr bool operator==( const T& n , const ExtendedRational<T>& r ) noexcept { return n * r.GetDenominator() == r.GetNumerator(); }
template <typename T> inline constexpr bool operator!=( const T& n , const ExtendedRational<T>& r ) noexcept { return !( n == r ); }
template <typename T> inline constexpr bool operator<=( const T& n , const ExtendedRational<T>& r ) noexcept { return r.GetDenominator() >= 0 ? n * r.GetDenominator() <= r.GetNumerator() : n * r.GetDenominator() >= r.GetNumerator(); }
template <typename T> inline constexpr bool operator>=( const T& n , const ExtendedRational<T>& r ) noexcept { return r <= n; }
template <typename T> inline constexpr bool operator<( const T& n , const ExtendedRational<T>& r ) noexcept { return r.GetDenominator() >= 0 ? n * r.GetDenominator() < r.GetNumerator() : n * r.GetDenominator() > r.GetNumerator(); }
template <typename T> inline constexpr bool operator>( const T& n , const ExtendedRational<T>& r ) noexcept { return r < n; }

template <typename T , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ExtendedRational<T>& r ) { r.m_d = 1; return cin >> r.m_n; }
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T>& r ) { return os << r.GetNumerator() << "/" << r.GetDenominator(); }
