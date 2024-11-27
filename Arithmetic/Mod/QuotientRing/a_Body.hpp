// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"

template <typename U , int NUM> inline QuotientRings<U,NUM>::QuotientRings() noexcept : m_n() , m_reduced( true ) {}
template <typename U , int NUM> inline QuotientRings<U,NUM>::QuotientRings( const QuotientRings<U,NUM>& n ) noexcept : m_n( n.m_n ) , m_reduced( n.m_reduced ) {}
template <typename U , int NUM> inline QuotientRings<U,NUM>::QuotientRings( QuotientRings<U,NUM>&& n ) noexcept : m_n( move( n.m_n ) ) , m_reduced( n.m_reduced ) {}
template <typename U , int NUM> inline QuotientRings<U,NUM>::QuotientRings( U n ) noexcept : m_n( move( n %= Constants::g_M ) ) , m_reduced( true ) {}

template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator=( QuotientRings<U,NUM> n ) noexcept { m_reduced = n.m_reduced; m_n = move( n.m_n ); return *this; }

template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator+=( const QuotientRings<U,NUM>& n ) noexcept { m_reduced = Constants::g_embedded; m_n += n.m_n; return *this; }
template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator-=( const QuotientRings<U,NUM>& n ) noexcept { m_reduced = Constants::g_embedded; return *this += -n; }
template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator*=( const QuotientRings<U,NUM>& n ) noexcept { if( !m_reduced ){ Reduce(); } ( m_n *= n.m_reduced ? n.m_n : n.m_n % Constants::g_M ) %= Constants::g_M; return *this; }

template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator/=( QuotientRings<U,NUM> n ) { return operator*=( n.Invert() ); }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator<<=( INT n ) { assert( n >= 0 ); return *this *= QuotientRings<U,NUM>( 2 ).NonNegativePower( move( n ) ); }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator>>=( INT n ) { assert( n >= 0 ); while( n-- > 0 ){ ( ( m_n & 1 ) == 0 ? m_n : m_n += Constants::g_M ) >>= 1; } return *this; }

template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator++() noexcept { m_reduced = Constants::g_embedded; ++m_n; return *this; }
template <typename U , int NUM> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator++( int ) noexcept { QuotientRings<U,NUM> n{ *this }; operator++(); return n; }
template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::operator--() noexcept { m_reduced = Constants::g_embedded; --m_n; return *this; }
template <typename U , int NUM> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator--( int ) noexcept { QuotientRings<U,NUM> n{ *this }; operator--(); return n; }

template <typename U , int NUM> inline bool QuotientRings<U,NUM>::operator==( const QuotientRings<U,NUM>& n ) const noexcept { return m_reduced && n.m_reduced ? m_n == n.m_n : ( *this - n ).m_n % Constants::g_M == 0; }
template <typename U , int NUM> inline bool QuotientRings<U,NUM>::operator!=( const QuotientRings<U,NUM>& n ) const noexcept { return !( *this == n ); }

DEFINITION_OF_ARITHMETIC_FOR_QUOTIENT( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_QUOTIENT( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_QUOTIENT( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_QUOTIENT( / , , n.Invert() , * );
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator^( INT exponent ) const { return move( QuotientRings<U,NUM>( *this ).Power( move( exponent ) ) ); }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator<<( INT n ) const { return move( QuotientRings<U,NUM>( *this ) <<= move( n ) ); }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator>>( INT n ) const { return move( QuotientRings<U,NUM>( *this ) >>= move( n ) ); }

template <typename U , int NUM> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::operator-() const noexcept { return move( QuotientRings<U,NUM>( *this ).SignInvert() ); }
template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::SignInvert() noexcept { m_reduced = Constants::g_embedded; m_n = -m_n; return *this; }

template <typename U , int NUM> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::Invert() { assert( ( m_n %= Constants::g_M ) != 0 ); return NonNegativePower( Constants::g_order_minus_1 ); }

template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::PositivePower( INT exponent ) noexcept { U power{ this->m_n }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? ( *this *= power ).m_n %= Constants::g_M : *this; exponent >>= 1; ( power *= power ) %= Constants::g_M; } return *this; }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? ( m_n = Constants::g_M == 1 ? 0 : 1 , *this ) : PositivePower( move( exponent ) ); }
template <typename U , int NUM> template <typename INT> inline QuotientRings<U,NUM>& QuotientRings<U,NUM>::Power( INT exponent ) { bool neg = exponent < 0; if( !m_reduced ){ Reduce(); } assert( !( neg && m_n != 0 ) ); return neg ? PositivePower( move( exponent *= Constants::g_order_minus_1_neg ) ) : NonNegativePower( move( exponent ) ); }

template <typename U , int NUM> inline void QuotientRings<U,NUM>::swap( QuotientRings<U,NUM>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <typename U , int NUM> inline const bool& QuotientRings<U,NUM>::Reduced() const noexcept { return m_reduced; }
template <typename U , int NUM> inline void QuotientRings<U,NUM>::Reduce() noexcept { m_reduced = true; m_n %= Constants::g_M; }
template <typename U , int NUM> inline const U& QuotientRings<U,NUM>::Represent() noexcept { if( !m_reduced ){ Reduce(); } return m_n; }
template <typename U , int NUM> inline U QuotientRings<U,NUM>::Represent() const noexcept { return m_reduced ? m_n : m_n % Constants::g_M; }
template <typename U , int NUM> inline QuotientRings<U,NUM> QuotientRings<U,NUM>::Derepresent( U n ) noexcept { QuotientRings<U,NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <typename U , int NUM> inline const QuotientRings<U,NUM>& QuotientRings<U,NUM>::zero() noexcept { static const QuotientRings<U,NUM> z{}; return z; }
template <typename U , int NUM> inline const QuotientRings<U,NUM>& QuotientRings<U,NUM>::one() noexcept { static const QuotientRings<U,NUM> o = QuotientRings<U,NUM>::Derepresent( 1 ); return o; }

template <typename U , int NUM> inline const U& QuotientRings<U,NUM>::GetModulo() noexcept { return Constants::g_M; }
template <typename U , int NUM> inline void QuotientRings<U,NUM>::SetModulo( const U& M , const int& order_minus_1 , const bool& embedded ) noexcept { Constants::g_M = M; Constants::g_order_minus_1 = order_minus_1; Constants::g_order_minus_1_neg = -Constants::g_order_minus_1; Constants::g_embedded = embedded; }

template <typename U , int NUM> inline QuotientRings<U,NUM> Inverse( const QuotientRings<U,NUM>& n ) { return move( QuotientRings<U,NUM>( n ).Invert() ); }
template <typename U , int NUM , typename INT> inline QuotientRings<U,NUM> Power( QuotientRings<U,NUM> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <typename U , int NUM> inline void swap( QuotientRings<U,NUM>& n0 , QuotientRings<U,NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <typename U , int NUM> inline string to_string( QuotientRings<U,NUM>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( QuotientRings<U,NUM>::GetConstants() ) + "Z"; }

template <typename U , int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , QuotientRings<U,NUM>& n ) { ll m; is >> m; n = m; return is; }
template <typename U , int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const QuotientRings<U,NUM>& n ) { return os << n.Represent(); }

#include "../Hash/a_Body.hpp"
template <typename U , int NUM> DEFINITION_OF_HASH_FOR_MOD( QuotientRings<U,NUM> );
