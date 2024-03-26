// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Constant/a_Body.hpp"
#include "../../Function/Residue/a_Body.hpp"
#include "../../../Prime/Divisor/GCD/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_n() , m_d( 1 ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) , m_d( n.m_d ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) , m_d( move( n.m_d ) ) {}
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>::Mod( T n ) noexcept : m_n( Residue<M>( move( n ) ) ) , m_d( 1 ) { static_assert( is_constructible_v<INT_TYPE_FOR_MOD,decay_t<T> > ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( Mod<M> n ) noexcept { m_n = move( n.m_n ); return Ref( m_d = move( n.m_d ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { Normalise( m_n = uint( Residue<M>( ull( m_n ) * n.m_d ) ) + uint( Residue<M>( n.m_n * ull( m_d ) ) ) ); return Ref( m_d = Residue<M>( ull( m_d ) * n.m_d ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { Normalise( m_n = uint( Residue<M>( ull( m_n ) * n.m_d ) ) + uint( Residue<M>( ( M - n.m_n ) * ull( m_d ) ) ) ); return Ref( m_d = Residue<M>( ull( m_d ) * n.m_d ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { m_n = Residue<M>( ull( m_n ) * n.m_n ); return Ref( m_d = Residue<M>( ull( m_d ) * n.m_d ) ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( Mod<M> n ) { return operator*=( n.Invert() ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator<<=( INT n ) { assert( n >= 0 ); return *this *= Mod<M>( 2 ).NonNegativePower( move( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator>>=( INT n ) { assert( n >=0 ); while( n-- > 0 ){ ( m_n & 1 ) == 0 ? m_n >>= 1 : m_d << 1 < M ? m_d <<= 1 : ( m_n += M ) >>= 1; } return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator++() noexcept { return Ref( m_n += m_d < M ? m_n : m_n -= M ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator++( int ) noexcept { Mod<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator--() noexcept { return Ref( ( m_n < m_d ? m_n += M : m_n ) -= m_d ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator--( int ) noexcept { Mod<M> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_MOD( == );
DEFINITION_OF_COMPARISON_FOR_MOD( != );
DEFINITION_OF_COMPARISON_FOR_MOD( > );
DEFINITION_OF_COMPARISON_FOR_MOD( >= );
DEFINITION_OF_COMPARISON_FOR_MOD( < );
DEFINITION_OF_COMPARISON_FOR_MOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , , n.Invert() , * );
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator^( INT exponent ) const { return move( Mod<M>( *this ).Power( move( exponent ) ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator<<( INT n ) const { return move( Mod<M>( *this ) <<= move( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M> Mod<M>::operator>>( INT n ) const { return move( Mod<M>( *this ) >>= move( n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::SignInvert() noexcept { return Ref( m_n > 0 ? m_n = M - m_n : m_n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { assert( m_n != 0 ); std::swap( m_n , m_d ); return *this; }

template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::PositivePower( INT exponent ) noexcept { Mod<M> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? Ref( m_n = m_d = 1 ) : Ref( PositivePower( move( exponent ) ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::Power( INT exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return neg ? PositivePower( move( exponent *= ConstantsForMod<M>::g_M_minus_2_neg ) ) : NonNegativePower( move( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) { assert( n < ConstantsForMod<M>::g_memory_length ); static vector<Mod<M>> memory = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory.push_back( 1 ); memory.back().m_d = length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) { assert( n < ConstantsForMod<M>::g_memory_length ); static vector<Mod<M>> memory = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_n; temp = Residue<M>( ull( temp ) * length_curr++ ); } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] ); auto& temp = memory.back().m_d; temp = Residue<M>( ull( temp ) * length_curr++ ); } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::Combination( const INT_TYPE_FOR_MOD& n , const INT_TYPE_FOR_MOD& i ) { return i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::GetNumerator() const noexcept { return m_n; }
template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::GetDenominator() const noexcept { return m_d; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Mod<M>::Represent() const noexcept { Mod<M> d_inv = Inverse_constexpr( Mod<M>::Derepresent( m_d ) ); return Residue<M>( ull( m_n ) * d_inv.m_n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = n; return n_copy; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static constexpr const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static constexpr const Mod<M> o{ 1 }; return o; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Ref( T&& n ) noexcept { auto gcd = GCD( m_n , m_d ); m_n /= gcd; m_d /= gcd; return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& Mod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n < M ? n : n -= M; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Inverse_constexpr( Mod<M> n ) { return move( n.NonNegativePower( M - 2 ) ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr Mod<M> Power( Mod<M> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.GetNumerator() ) + "/" + to_string( n.GetDenominator() ) + " + " + to_string( M ) + "Z ( = " + to_string( n.Represent() ) + " + " + to_string( M ) + "Z )"; }

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n ) { ll m; is >> m; n = m; return is; }
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.GetNumerator() << "/" << n.GetDenominator() << " ( ß " << n.Represent() << " )"; }
