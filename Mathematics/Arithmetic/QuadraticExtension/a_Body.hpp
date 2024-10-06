// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/QuadraticExtension/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>::QuadraticExtensions() noexcept : m_a() , m_b() {}
template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>::QuadraticExtensions( const INT& a ) noexcept : m_a( a ) , m_b() {}
template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>::QuadraticExtensions( const INT& a , const INT& b ) noexcept : m_a( a ) , m_b( b ) {}
template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>::QuadraticExtensions( const QuadraticExtensions<INT,NUM>& n ) noexcept : m_a( n.m_a ) , m_b( n.m_b ) {}
template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>::QuadraticExtensions( QuadraticExtensions<INT,NUM>&& n ) noexcept : m_a( move( n.m_a ) ) , m_b( move( n.m_b ) ) {}

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::operator=( QuadraticExtensions<INT,NUM> n ) noexcept { m_a = move( n.m_a ); m_b = move( n.m_b ); return *this; }

template <typename INT , int NUM> inline pair<const INT&,const INT&> QuadraticExtensions<INT,NUM>::Get() const noexcept { return { m_a , m_b }; }

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::operator+=( const QuadraticExtensions<INT,NUM>& n ) noexcept { m_a += n.m_a; m_b += n.m_b; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator+=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { m_a += a; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator+=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { return *this += QuadraticExtensions<INT,NUM>( n ); }

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::operator-=( const QuadraticExtensions<INT,NUM>& n ) noexcept { m_a -= n.m_a; m_b -= n.m_b; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator-=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { m_a -= a; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator-=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { return *this -= QuadraticExtensions<INT,NUM>( n ); }

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::operator*=( const QuadraticExtensions<INT,NUM>& n ) noexcept { const INT a = m_a * n.m_a + m_b * n.m_b * Constants::g_D; m_b = m_a * n.m_b + m_b * n.m_a; m_a = a; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator*=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { m_a *= a; m_b *= a; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator*=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { return *this *= QuadraticExtensions<INT,NUM>( n ); }

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::operator/=( QuadraticExtensions<INT,NUM> n ) noexcept { return ( *this *= n.Adjoint() ) /= n.Norm(); }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator/=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { m_a /= a; m_b /= a; return *this; }
template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator/=( const T& n ) noexcept -> enable_if_t<!is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { return *this /= QuadraticExtensions<INT,NUM>( n ); }

template <typename INT , int NUM> template <typename T> inline auto QuadraticExtensions<INT,NUM>::operator%=( const T& a ) noexcept -> enable_if_t<is_constructible_v<INT,T>,QuadraticExtensions<INT,NUM>&> { m_a %= a; m_b %= a; return *this; }

template <typename INT , int NUM> inline bool QuadraticExtensions<INT,NUM>::operator==( const QuadraticExtensions<INT,NUM>& n ) noexcept { return m_a == n.m_a && m_b == n.m_b; }
template <typename INT , int NUM> template <typename T> inline bool QuadraticExtensions<INT,NUM>::operator==( const T& n ) noexcept { return *this == QuadraticExtensions<INT,NUM>( n ); }
template <typename INT , int NUM> template <typename T> inline bool QuadraticExtensions<INT,NUM>::operator!=( const T& n ) noexcept { return !( *this == n ); }

template <typename INT , int NUM> template <typename SINT> inline QuadraticExtensions<INT,NUM> QuadraticExtensions<INT,NUM>::operator^( SINT exponent ) const { return move( QuadraticExtensions<INT,NUM>( *this ).Power( move( exponent ) ) ); }

template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM> QuadraticExtensions<INT,NUM>::operator-() const noexcept { auto answer = *this; answer.m_a = -answer.m_a; answer.m_b = -answer.m_b; return answer; }

template <typename INT , int NUM> inline INT QuadraticExtensions<INT,NUM>::Norm() const noexcept { return m_a * m_a - m_b * m_b * Constants::g_D; }
template <typename INT , int NUM> inline QuadraticExtensions<INT,NUM> QuadraticExtensions<INT,NUM>::Adjoint() const noexcept { return QuadraticExtensions<INT,NUM>( m_a , -m_b ); }

template <typename INT , int NUM> template <typename UINT> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::PositivePower( UINT exponent ) noexcept { QuadraticExtensions<INT,NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <typename INT , int NUM> template <typename UINT> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::NonNegativePower( UINT exponent ) noexcept { return exponent == 0 ? ( m_a = 1 , m_b = 0 , *this ) : PositivePower( move( exponent ) ); }
template <typename INT , int NUM> template <typename SINT> inline QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::Power( SINT exponent ) { return exponent < 0 ? ( *this = Adjoint() / Norm() ).PositivePower( -exponent ) : NonNegativePower( move( exponent ) ); }

template <typename INT , int NUM> inline void QuadraticExtensions<INT,NUM>::swap( QuadraticExtensions<INT,NUM>& n ) noexcept { std::swap( m_a , n.m_a ); std::swap( m_b , n.m_b ); }

template <typename INT , int NUM> inline const QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::zero() noexcept { static const QuadraticExtensions<INT,NUM> zero{}; return zero; }
template <typename INT , int NUM> inline const QuadraticExtensions<INT,NUM>& QuadraticExtensions<INT,NUM>::one() noexcept { static const QuadraticExtensions<INT,NUM> one{ INT( 1 ) }; return one; }

template <typename INT , int NUM> inline const INT& QuadraticExtensions<INT,NUM>::GetD() noexcept { return Constants::g_D; }
template <typename INT , int NUM> inline void QuadraticExtensions<INT,NUM>::SetD( const INT& D ) noexcept { Constants::g_D = D; }

template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator+( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept { return move( n += a ); }
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator-( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept { return move( n -= a ); }
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator*( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept { return move( n *= a ); }
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator/( QuadraticExtensions<INT,NUM> n , T&& a ) noexcept { return move( n /= forward<T>( a ) ); }
template <typename INT , int NUM , typename T> inline QuadraticExtensions<INT,NUM> operator%( QuadraticExtensions<INT,NUM> n , const T& a ) noexcept { return move( n %= a ); }

template <typename INT , int NUM , typename SINT> inline QuadraticExtensions<INT,NUM> Power( QuadraticExtensions<INT,NUM> n , SINT exponent ) { return move( n.Power( move( exponent ) ) ); }
