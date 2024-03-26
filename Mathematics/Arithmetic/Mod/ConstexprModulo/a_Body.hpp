// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>::Mod( T n ) noexcept : m_n( Residue<M>( move( n ) ) ) { static_assert( is_constructible_v<INT_TYPE_FOR_MOD,decay_t<T> > ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( Mod<M> n ) noexcept { return Ref( m_n = move( n.m_n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n += n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { return Ref( m_n < n.m_n ? ( m_n += M ) -= n.m_n : m_n -= n.m_n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { return Ref( m_n = Residue<M>( move( ull( m_n ) *= n.m_n ) ) ); }
template <> inline constexpr Mod<998244353>& Mod<998244353>::operator*=( const Mod<998244353>& n ) noexcept { ull m_n_copy = m_n; return Ref( m_n = move( ( m_n_copy *= n.m_n ) < 998244353 ? m_n_copy : Residue998244353( m_n_copy ) ) ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( Mod<M> n ) { return operator*=( n.Invert() ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator<<=( INT n ) { assert( n >= 0 ); return *this *= Mod<M>( 2 ).NonNegativePower( move( n ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::operator>>=( INT n ) { assert( n >=0 ); while( n-- > 0 ){ ( ( m_n & 1 ) == 0 ? m_n : m_n += M ) >>= 1; } return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator++() noexcept { return Ref( m_n < ConstantsForMod<M>::g_M_minus ? ++m_n : m_n = 0 ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator++( int ) noexcept { Mod<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator--() noexcept { return Ref( m_n == 0 ? m_n = ConstantsForMod<M>::g_M_minus : --m_n ); }
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

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { assert( m_n != 0 ); INT_TYPE_FOR_MOD m_n_neg; return m_n < ConstantsForMod<M>::g_memory_length ? Ref( m_n = Inverse( m_n ).m_n ) : ( ( m_n_neg = M - m_n ) < ConstantsForMod<M>::g_memory_length ) ? Ref( m_n = M - Inverse( m_n_neg ).m_n ) : PositivePower( INT_TYPE_FOR_MOD( ConstantsForMod<M>::g_M_minus_2 ) ); }

template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::PositivePower( INT exponent ) noexcept { Mod<M> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? Ref( m_n = 1 ) : Ref( PositivePower( move( exponent ) ) ); }
template <INT_TYPE_FOR_MOD M> template <typename INT> inline constexpr Mod<M>& Mod<M>::Power( INT exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return neg ? PositivePower( move( exponent *= ConstantsForMod<M>::g_M_minus_2_neg ) ) : NonNegativePower( move( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) { assert( n < ConstantsForMod<M>::g_memory_length ); static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr].m_n = M - memory[M % length_curr].m_n * ull( M / length_curr ) % M; length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) { assert( n < ConstantsForMod<M>::g_memory_length ); static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ ( memory[length_curr] = memory[length_curr - 1] ) *= length_curr; length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ ( memory[length_curr] = memory[length_curr - 1] ) *= Inverse( length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::Combination( const INT_TYPE_FOR_MOD& n , const INT_TYPE_FOR_MOD& i ) { return i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = n; return n_copy; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static constexpr const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static constexpr const Mod<M> o{ 1 }; return o; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Ref( T&& n ) noexcept { return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& Mod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n < M ? n : n -= M; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Inverse_constexpr( Mod<M> n ) { return move( n.NonNegativePower( M - 2 ) ); }

template <INT_TYPE_FOR_MOD M , typename INT> inline constexpr Mod<M> Power( Mod<M> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( M ) + "Z"; }

template <INT_TYPE_FOR_MOD M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Mod<M>& n ) { ll m; is >> m; n = m; return is; }
template <INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
