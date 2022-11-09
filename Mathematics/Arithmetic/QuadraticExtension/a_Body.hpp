// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline QuadraticExtension<INT>::QuadraticExtension() noexcept : m_a() , m_b() , m_p_D( nullptr ) {}
template <typename INT> template <typename T> inline QuadraticExtension<INT>::QuadraticExtension( const T& a ) noexcept : m_a( a ) , m_b() , m_p_D( nullptr ) {}
template <typename INT> inline QuadraticExtension<INT>::QuadraticExtension( const INT& a , const INT& b , const INT* const & p_D ) noexcept : m_a( a ) , m_b( b ) , m_p_D( p_D ) {}
template <typename INT> inline QuadraticExtension<INT>::QuadraticExtension( const QuadraticExtension<INT>& n ) noexcept : m_a( n.m_a ) , m_b( n.m_b ) , m_p_D( n.m_p_D ) {}

template <typename INT> inline const INT& QuadraticExtension<INT>::GetA() const noexcept { return m_a; }
template <typename INT> inline const INT& QuadraticExtension<INT>::GetB() const noexcept { return m_b; }
template <typename INT> inline const INT& QuadraticExtension<INT>::GetD() const noexcept { return m_p_D == nullptr ? Zero() : *m_p_D; }

template <typename INT> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator+=( const QuadraticExtension<INT>& n ) noexcept { if( m_p_D == nullptr ){ m_p_D = n.m_p_D; } m_a += n.m_a; m_b += n.m_b; return *this; }
template <typename INT> template <typename T> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator+=( const T& a ) noexcept { m_a += a; return *this; }
template <typename INT> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator-=( const QuadraticExtension<INT>& n ) noexcept { if( m_p_D == nullptr ){ m_p_D = n.m_p_D; } m_a -= n.m_a; m_b -= n.m_b; return *this; }
template <typename INT> template <typename T> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator-=( const T& a ) noexcept { m_a -= a; return *this; }
template <typename INT> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator*=( const QuadraticExtension<INT>& n ) noexcept { if( m_p_D == nullptr ){ m_p_D = n.m_p_D; } const INT a = ( m_p_D == nullptr ? m_a * n.m_a : m_a * n.m_a + m_b * n.m_b * ( *m_p_D ) ); m_b = m_a * n.m_b + m_b * n.m_a; m_a = a; return *this; }
template <typename INT> template <typename T> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator*=( const T& a ) noexcept { m_a *= a; m_b *= a; return *this; }
template <typename INT> template <typename T> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator/=( const T& a ) noexcept { m_a /= a; m_b /= a; return *this; }
template <typename INT> template <typename T> inline QuadraticExtension<INT>& QuadraticExtension<INT>::operator%=( const T& a ) noexcept { m_a %= a; m_b %= a; return *this; }

template <typename INT> inline bool QuadraticExtension<INT>::Equal( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept { return n0.m_a == n1.m_a && n0.m_b == n1.m_b && n0.m_p_D == n1.m_p_D; }

template <typename INT> inline const INT& QuadraticExtension<INT>::Zero() noexcept { static const INT zero{ 0 }; return zero; }

template <typename INT> inline bool operator==( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept { return QuadraticExtension<INT>::Equal( n0 , n1 ); }
template <typename INT> inline bool operator!=( const QuadraticExtension<INT>& n0 , const QuadraticExtension<INT>& n1 ) noexcept { return ! QuadraticExtension<INT>::Equal( n0 , n1 ); }

template <typename INT> template <typename T> inline QuadraticExtension<INT> operator+( const QuadraticExtension<INT>& n , const T& a ) noexcept { return QuadraticExtension<INT>( n ).operator+=( a ); }
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator-( const QuadraticExtension<INT>& n , const T& a ) noexcept { return QuadraticExtension<INT>( n ).operator-=( a ); }
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator*( const QuadraticExtension<INT>& n , const T& a ) noexcept { return QuadraticExtension<INT>( n ).operator*=( a ); }
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator/( const QuadraticExtension<INT>& n , const T& a ) noexcept { return QuadraticExtension<INT>( n ).operator/=( a ); }
template <typename INT> template <typename T> inline QuadraticExtension<INT> operator%( const QuadraticExtension<INT>& n , const T& a ) noexcept { return QuadraticExtension<INT>( n ).operator%=( a ); }

template <typename INT> inline QuadraticExtension<INT> Sqrt( const INT& D ) noexcept { return QuadraticExtension<INT>( 0 , 1 , &D ); }

