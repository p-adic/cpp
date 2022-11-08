// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticInteger/a_Body.hpp

#pragma once
#include "a.hpp"

inline QuadraticInteger::QuadraticInteger( const IntTypeForQuadraticInteger& a , const IntTypeForQuadraticInteger& b , const IntTypeForQuadraticInteger* const & p_D ) noexcept : m_a( a ) , m_b( b ) , m_p_D( p_D ) {}
inline QuadraticInteger::QuadraticInteger( const QuadraticInteger& n ) noexcept : m_a( n.m_a ) , m_b( n.m_b ) , m_p_D( n.m_p_D ) {}

inline const IntTypeForQuadraticInteger& QuadraticInteger::GetA() const noexcept { return m_a; }
inline const IntTypeForQuadraticInteger& QuadraticInteger::GetB() const noexcept { return m_b; }
inline const IntTypeForQuadraticInteger& QuadraticInteger::GetD() const noexcept { return *m_p_D; }

inline QuadraticInteger& QuadraticInteger::operator+=( const QuadraticInteger& n ) noexcept { m_a += n.m_a; m_b += n.m_b; return *this; }
inline QuadraticInteger& QuadraticInteger::operator-=( const QuadraticInteger& n ) noexcept { m_a -= n.m_a; m_b -= n.m_b; return *this; }
inline QuadraticInteger& QuadraticInteger::operator*=( const QuadraticInteger& n ) noexcept { m_a = m_a * n.m_a + m_b * n.m_b * ( *m_p_D ); m_b = m_a * n.m_b + m_b * n.m_a; return *this; }
inline QuadraticInteger& QuadraticInteger::operator%=( const IntTypeForQuadraticInteger& a ) noexcept { m_a %= a; m_b %= a; return *this; }

inline bool QuadraticInteger::Equal( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return n0.m_a == n1.m_a && n0.m_b == n1.m_b && n0.m_p_D == n1.m_p_D; }

inline bool operator==( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return QuadraticInteger::Equal( n0 , n1 ); }
inline bool operator!=( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return ! QuadraticInteger::Equal( n0 , n1 ); }

inline QuadraticInteger operator+( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return QuadraticInteger( n0 ).operator+=( n1 ); }
inline QuadraticInteger operator-( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return QuadraticInteger( n0 ).operator-=( n1 ); }
inline QuadraticInteger operator*( const QuadraticInteger& n0 , const QuadraticInteger& n1 ) noexcept { return QuadraticInteger( n0 ).operator*=( n1 ); }
inline QuadraticInteger operator%( const QuadraticInteger& n , const IntTypeForQuadraticInteger& a ) noexcept { return QuadraticInteger( n ).operator%=( a ); }
