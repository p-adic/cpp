// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Constant/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_non_negative( true ) , m_n() , m_d( 1 ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_non_negative( n.m_non_negative ) , m_n( n.m_n ) , m_d( n.m_d ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_non_negative( n.m_non_negative ) , m_n( move( n.m_n ) ) , m_d( move( n.m_d ) ) {}
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>::Mod( T n ) noexcept : m_non_negative( n >= 0 ) , m_n( uint( move( ( m_non_negative ? n : n *= -1 ) %= M ) ) ) , m_d( 1 ) { static_assert( is_constructible_v<uint,decay_t<T> > ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( Mod<M> n ) noexcept { m_non_negative = n.m_non_negative; m_n = move( n.m_n ); m_d = move( n.m_d ); return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { ull m_n0 = ull( m_n ) * n.m_d , m_n1 = n.m_n * ull( m_d ) , m_n_copy = m_non_negative == n.m_non_negative ? move( m_n0 += m_n1 ) : m_n0 == m_n1 ? 0 : m_n0 > m_n1 ? move( m_n0 -= m_n1 ) : ( m_non_negative = !m_non_negative , move( m_n1 -= m_n0 ) ); ull m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); m_n = uint( move( ( m_n_copy /= gcd ) %= M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= M ) ); return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { ull m_n0 = ull( m_n ) * n.m_d , m_n1 = n.m_n * ull( m_d ) , m_n_copy = m_non_negative != n.m_non_negative ? move( m_n0 += m_n1 ) : m_n0 == m_n1 ? 0 : m_n0 > m_n1 ? move( m_n0 -= m_n1 ) : ( m_non_negative = !m_non_negative , move( m_n1 -= m_n0 ) ); ull m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); m_n = uint( move( ( m_n_copy /= gcd ) %= M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= M ) ); return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { ull m_n_copy = ull( m_n ) * n.m_n , m_d_copy = ull( m_d ) * n.m_d; ull gcd = GCD( m_n_copy , m_d_copy ); m_n = uint( move( ( m_n_copy /= gcd ) %= M ) ); m_d = uint( move( ( m_d_copy /= gcd ) %= M ) ); m_non_negative = m_n == 0 || m_non_negative == n.m_non_negative; return *this; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( Mod<M> n ) { return operator*=( n.Invert() ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator<<=( INT n ) { assert( n >= 0 ); return *this *= Mod<M>( 2 ).NonNegativePower( move( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator>>=( INT n ) { assert( n >=0 ); while( n-- > 0 ){ ( m_n & 1 ) == 0 ? m_n >>= 1 : m_d << 1 < M ? m_d <<= 1 : ( m_n += M ) >>= 1; } return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator++() noexcept { return *this += 1; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator++( int ) noexcept { Mod<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator--() noexcept { return *this -= 1; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator--( int ) noexcept { Mod<M> n{ *this }; operator--(); return n; }

template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator==( const Mod<M>& n ) const noexcept { const uint n0 = ull( m_n ) * n.m_d % M , n1 = n.m_n * ull( m_d ) % M; return m_non_negative == n.m_non_negative ? n0 == n1 : ( n0 == 0 && n1 == 0 ) || n0 + n1 == M; }
template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator!=( const Mod<M>& n ) const noexcept { return !( *this == n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator<( const Mod<M>& n ) const noexcept { return ( !m_non_negative && n.m_non_negative ) || ( m_non_negative == n.m_non_negative && m_non_negative == ( ull( m_n ) * n.m_d < n.m_n * ull( m_d ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator<=( const Mod<M>& n ) const noexcept { return *this == n || *this < n; }
template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator>( const Mod<M>& n ) const noexcept { return n < *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr bool Mod<M>::operator>=( const Mod<M>& n ) const noexcept { return n <= *this; }

DEFINITION_OF_ARITHMETIC_FOR_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , , n.Invert() , * );
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator^( INT exponent ) const { return move( Mod<M>( *this ).Power( move( exponent ) ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator<<( INT n ) const { return move( Mod<M>( *this ) <<= move( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator>>( INT n ) const { return move( Mod<M>( *this ) >>= move( n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::SignInvert() noexcept { m_non_negative = m_n == 0 || !m_non_negative; return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { assert( m_n != 0 ); std::swap( m_n , m_d ); return *this; }

template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::PositivePower( INT exponent ) noexcept { Mod<M> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? ( m_n = m_d = 1 , *this ) : PositivePower( move( exponent ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::Power( INT exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return neg ? PositivePower( move( exponent *= Constants::g_order_minus_1_neg ) ) : NonNegativePower( move( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const uint& n ) { static vector<Mod<M>> memory = { zero() , one() }; static uint length_curr = 2; memory.reserve( n + 1 ); while( length_curr <= n ){ memory.push_back( 1 ); memory.back().m_d = length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const uint& n ) { static vector<Mod<M>> memory = { one() , one() }; static uint length_curr = 2; if( M <= n ){ return zero(); } memory.reserve( n + 1 ); while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_n; temp = ull( temp ) * length_curr++ % M; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const uint& n ) { static vector<Mod<M>> memory = { one() , one() }; static uint length_curr = 2; memory.reserve( n + 1 ); while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_d; temp = ull( temp ) * length_curr++ % M; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::Combination( const uint& n , const uint& i ) { return i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <INT_TYPE_FOR_MOD M> inline constexpr const bool& Mod<M>::GetSign() const noexcept { return m_non_negative; }
template <INT_TYPE_FOR_MOD M> inline constexpr const uint& Mod<M>::GetNumerator() const noexcept { return m_n; }
template <INT_TYPE_FOR_MOD M> inline constexpr const uint& Mod<M>::GetDenominator() const noexcept { return m_d; }
template <INT_TYPE_FOR_MOD M> inline constexpr uint Mod<M>::Represent() const noexcept { Mod<M> d_inv = Mod<M>::Derepresent( m_d ).NonNegativePower( Constants::g_order_minus_1 ); return  ull( m_non_negative ? m_n : M - m_n ) * d_inv.m_n % M; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( uint n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static const Mod<M> o{ 1 }; return o; }

template <INT_TYPE_FOR_MOD M> constexpr ull Mod<M>::GCD( ull n0 , ull n1 ) noexcept
{

  while( n1 != 0 ){

    ull n2 = n0 %= n1;
    n0 = n1;
    n1 = move( n2 );

  }

  return n0;

}

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr Mod<M> Power( Mod<M> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return ( n.GetSign() ? "" : "-" ) + to_string( n.GetNumerator() ) + "/" + to_string( n.GetDenominator() ) + " + " + to_string( M ) + "Z ( = " + to_string( n.Represent() ) + " + " + to_string( M ) + "Z )"; }

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n ) { ll m; is >> m; n = m; return is; }
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << ( n.GetSign() ? "" : "-" ) << n.GetNumerator() << "/" << n.GetDenominator() << " ( ß " << n.Represent() << " )"; }

#include "../../Hash/a_Body.hpp"
template <INT_TYPE_FOR_MOD M> DEFINITION_OF_HASH_FOR_MOD( Mod<M> );
