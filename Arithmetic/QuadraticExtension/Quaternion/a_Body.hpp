// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/Quaternion/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline Quaternion<INT>::Quaternion() noexcept : m_a() , m_b() , m_c() , m_d() {}
template <typename INT> template <typename T> inline Quaternion<INT>::Quaternion( const T& a ) noexcept : m_a( a ) , m_b() , m_c() , m_d() {}
template <typename INT> inline Quaternion<INT>::Quaternion( const INT& a , const INT& b ,const INT& c , const INT& d ) noexcept : m_a( a ) , m_b( b ) , m_c( c ) , m_d( d ) {}
template <typename INT> inline Quaternion<INT>::Quaternion( const Quaternion<INT>& n ) noexcept : m_a( n.m_a ) , m_b( n.m_b ) , m_c( n.m_c ) , m_d( n.m_d ) {}

template <typename INT> inline const INT& Quaternion<INT>::GetA() const noexcept { return m_a; }
template <typename INT> inline const INT& Quaternion<INT>::GetB() const noexcept { return m_b; }
template <typename INT> inline const INT& Quaternion<INT>::GetC() const noexcept { return m_c; }
template <typename INT> inline const INT& Quaternion<INT>::GetD() const noexcept { return m_d; }

template <typename INT> inline Quaternion<INT>& Quaternion<INT>::operator+=( const Quaternion<INT>& n ) noexcept { m_a += n.m_a; m_b += n.m_b; m_c += n.m_c; m_d += n.m_d; return *this; }
template <typename INT> template <typename T> inline Quaternion<INT>& Quaternion<INT>::operator+=( const T& a ) noexcept { m_a += a; return *this; }
template <typename INT> inline Quaternion<INT>& Quaternion<INT>::operator-=( const Quaternion<INT>& n ) noexcept { m_a -= n.m_a; m_b -= n.m_b; m_c -= n.m_c; m_d -= n.m_d; return *this; }
template <typename INT> template <typename T> inline Quaternion<INT>& Quaternion<INT>::operator-=( const T& a ) noexcept { m_a -= a; return *this; }
template <typename INT> inline Quaternion<INT>& Quaternion<INT>::operator*=( const Quaternion<INT>& n ) noexcept { const INT a = m_a * n.m_a - m_b * n.m_b - m_c * n.m_c - m_d * n.m_d; const INT b = m_a * n.m_b + m_b * n.m_a + m_c * n.m_d - m_d * n.m_c; const INT c = m_a * n.m_c - m_b * n.m_d + m_c * n.m_a + m_d * n.m_b; m_d = m_a * n.m_d + m_b * n.m_c - m_c * n.m_b + m_d * n.m_a; m_c = c; m_b = b; m_a = a; return *this; }

template <typename INT> template <typename T> inline Quaternion<INT>& Quaternion<INT>::operator*=( const T& a ) noexcept { m_a *= a; m_b *= a; m_c *= a; m_d *= a; return *this; }
template <typename INT> template <typename T> inline Quaternion<INT>& Quaternion<INT>::operator/=( const T& a ) noexcept { m_a /= a; m_b /= a; m_c /= a; m_d /= a; return *this; }
template <typename INT> template <typename T> inline Quaternion<INT>& Quaternion<INT>::operator%=( const T& a ) noexcept { m_a %= a; m_b %= a; m_c %= a; m_d %= a; return *this; }

template <typename INT> inline bool Quaternion<INT>::Equal( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept { return n0.m_a == n1.m_a && n0.m_b == n1.m_b && n0.m_c == n1.m_c && n0.m_d == n1.m_d; }

template <typename INT> inline bool operator==( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept { return Quaternion<INT>::Equal( n0 , n1 ); }
template <typename INT> inline bool operator!=( const Quaternion<INT>& n0 , const Quaternion<INT>& n1 ) noexcept { return ! Quaternion<INT>::Equal( n0 , n1 ); }

template <typename INT> template <typename T> inline Quaternion<INT> operator+( const Quaternion<INT>& n , const T& a ) noexcept { return Quaternion<INT>( n ).operator+=( a ); }
template <typename INT> template <typename T> inline Quaternion<INT> operator-( const Quaternion<INT>& n , const T& a ) noexcept { return Quaternion<INT>( n ).operator-=( a ); }
template <typename INT> template <typename T> inline Quaternion<INT> operator*( const Quaternion<INT>& n , const T& a ) noexcept { return Quaternion<INT>( n ).operator*=( a ); }
template <typename INT> template <typename T> inline Quaternion<INT> operator/( const Quaternion<INT>& n , const T& a ) noexcept { return Quaternion<INT>( n ).operator/=( a ); }
template <typename INT> template <typename T> inline Quaternion<INT> operator%( const Quaternion<INT>& n , const T& a ) noexcept { return Quaternion<INT>( n ).operator%=( a ); }

