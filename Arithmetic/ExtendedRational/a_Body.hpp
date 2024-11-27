// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/ExtendedRational/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../Utility/Set/a_Body.hpp"

#include "../Prime/Divisor/GCD/a_Body.hpp"
#include "../../../Utility/Random/a_Body.hpp"

template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( const T& n , const T& d , const bool& reduced ) : m_n( n ) , m_d( d ) { assert( m_n != 0 || m_d != 0 ); if( m_d == 0 ){ m_n = 1; } else { if( m_d != 1 && !reduced ){ const T gcd = GCD( m_n , m_d ); assert( gcd != 0 ); m_n /= gcd; m_d /= gcd; } if( m_d < 0 ){ m_n *= -1; m_d *= -1; } } }
template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( const ExtendedRational<T>& r ) : m_n( r.m_n ) , m_d( r.m_d ) {}
template <typename T> inline constexpr ExtendedRational<T>::ExtendedRational( ExtendedRational<T>&& r ) : m_n( move( r.m_n ) ) , m_d( move( r.m_d ) ) {}

template <typename T> inline constexpr ExtendedRational<T>& ExtendedRational<T>::operator=( ExtendedRational<T> r ) noexcept { m_n = move( r.m_n ); m_d = move( r.m_d ); return *this; }

template <typename T> inline constexpr bool ExtendedRational<T>::operator==( const ExtendedRational<T>& r ) const noexcept { return m_n == r.m_n && m_d == r.m_d; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator!=( const ExtendedRational<T>& r ) const noexcept { return !( *this == r ); }
template <typename T> inline constexpr bool ExtendedRational<T>::operator<=( const ExtendedRational<T>& r ) const noexcept { return *this == r || *this < r; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator>=( const ExtendedRational<T>& r ) const noexcept { return r <= *this; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator<( const ExtendedRational<T>& r ) const noexcept { return m_d != 0 && ( r - *this ).m_n > 0; }
template <typename T> inline constexpr bool ExtendedRational<T>::operator>( const ExtendedRational<T>& r ) const noexcept { return r < *this; }

DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( + );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( - );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( * );
DEFINITION_OF_OPERATOR_FOR_EXTENDED_RATIONAL( / );
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::operator+( const ExtendedRational<T>& r ) const noexcept { const T gcd = GCD( m_d , r.m_d ) , d = gcd == 0 ? gcd : r.m_d / gcd; return gcd == 0 ? *this : ExtendedRational<T>{ m_n * d + r.m_n * ( m_d / gcd ) , m_d * d }; }
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::operator-() const noexcept { return ExtendedRational<T>{ -m_n , m_d , true }; }
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::operator-( const ExtendedRational<T>& r ) const noexcept { return *this + ( -r ); }
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::operator*( const ExtendedRational<T>& r ) const noexcept { const T gcd1 = GCD( m_n , r.m_d ) , gcd2 = GCD( m_d , r.m_n ); return gcd1 == 0 ? r : gcd2 == 0 ? *this : ExtendedRational<T>{ ( m_n / gcd1 ) * ( r.m_n / gcd2 ) , ( m_d / gcd2 ) * ( r.m_d / gcd1 ) , true }; }
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::Inverse() const noexcept { return ExtendedRational<T>{ m_d , m_n , true }; }
template <typename T> inline constexpr ExtendedRational<T> ExtendedRational<T>::operator/( const ExtendedRational<T>& r ) const noexcept { return *this * r.Inverse(); }

template <typename T> inline constexpr const T& ExtendedRational<T>::GetNumerator() const noexcept { return m_n; }
template <typename T> inline constexpr const T& ExtendedRational<T>::GetDenominator() const noexcept { return m_d; }

template <typename T> inline constexpr bool operator==( const T& n , const ExtendedRational<T>& r ) noexcept { return n * r.GetDenominator() == r.GetNumerator(); }
template <typename T> inline constexpr bool operator!=( const T& n , const ExtendedRational<T>& r ) noexcept { return !( n == r ); }
template <typename T> inline constexpr bool operator<=( const T& n , const ExtendedRational<T>& r ) noexcept { return n * r.GetDenominator() <= r.GetNumerator(); }
template <typename T> inline constexpr bool operator>=( const T& n , const ExtendedRational<T>& r ) noexcept { return r <= n; }
template <typename T> inline constexpr bool operator<( const T& n , const ExtendedRational<T>& r ) noexcept { return n * r.GetDenominator() < r.GetNumerator(); }
template <typename T> inline constexpr bool operator>( const T& n , const ExtendedRational<T>& r ) noexcept { return r < n; }


DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( + ) { const T& d = r.GetDenominator(); return ExtendedRational( t * d + r.GetNumerator() , d , true ); }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( - ) { const T& d = r.GetDenominator(); return ExtendedRational( t * d - r.GetNumerator() , d , true ); }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( * ) { return ExtendedRational<T>( t ) * r; }
DECLARATION_OF_NON_MEMBER_OPERATOR_FOR_EXTENDED_RATIONAL( / ) { return ExtendedRational<T>( t ) / r; }

template <typename T , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ExtendedRational<T>& r ) { T temp; cin >> temp; r = temp; return cin; }
template <typename T , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ExtendedRational<T>& r ) { return os << r.GetNumerator() << "/" << r.GetDenominator(); }


template <typename T> inline size_t hash<ExtendedRational<T>>::operator()( const ExtendedRational<T>& r ) const { static const size_t seed = ( GetRand( 1e3 , 1e8 ) << 1 ) | 1; static const hash<T> h; return ( h( r.GetNumerator() ) * seed ) ^ h( r.GetDenominator() ); }
