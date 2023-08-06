// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "Montgomery/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"
// 0除算用の例外
#include "../../../../Error/IllegalInput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Mod<M>::Mod( const T& n ) noexcept : m_n( Residue<M>( n ) ) {}
// nの書き換えを防ぐために明示的にキャスト
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Mod<M>::Mod( T& n ) noexcept : m_n( Residue<M>( decay_t<T>( n ) ) ) {}
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Mod<M>::Mod( T&& n ) noexcept : m_n( Residue<M>( forward<T>( n ) ) ) {}


template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept { return Ref( m_n = n.m_n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( Mod<M>&& n ) noexcept { return Ref( m_n = move( n.m_n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n += n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { return Ref( m_n < n.m_n ? ( m_n += M ) -= n.m_n : m_n -= n.m_n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { return Ref( m_n = ConstantsForMod<M>::g_even ? Residue<M>( ull( m_n ) * n.m_n ) : Montgomery<M>::Multiplication( m_n , n.m_n ) ); }
template <> inline constexpr Mod<998244353>& Mod<998244353>::operator*=( const Mod<998244353>& n ) noexcept { ull m_n_copy = m_n; return Ref( m_n = move( ( m_n_copy *= n.m_n ) < 998244353 ? m_n_copy : Residue998244353( m_n_copy ) ) ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const Mod<M>& n ) { return operator*=( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator<<=( int n ) noexcept { while( n-- > 0 ){ Normalise( m_n <<= 1 ); } return *this; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator>>=( int n ) noexcept { while( n-- > 0 ){ ( ( m_n & 1 ) == 0 ? m_n : m_n += M ) >>= 1; } return *this; }

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

DEFINITION_OF_ARITHMETIC_FOR_MOD( + , Mod<M>( forward<T>( n ) ) += *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , Mod<M>( forward<T>( n ) ).SignInvert() += *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , Mod<M>( forward<T>( n ) ) *= *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , Mod<M>( forward<T>( n ) ).Invert() *= *this );
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator<<( int n ) const noexcept { return move( Mod<M>( *this ) <<= n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator>>( int n ) const noexcept { return move( Mod<M>( *this ) >>= n ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::SignInvert() noexcept { return Ref( m_n > 0 ? m_n = M - m_n : m_n ); }


template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::Double() noexcept { return Ref( Normalise( m_n <<= 1 ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::Halve() noexcept { return Ref( ( ( m_n & 1 ) == 0 ? m_n : m_n += M ) >>= 1 ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { if( m_n == 0 ){ ERR_INPUT( m_n ); } INT_TYPE_FOR_MOD m_n_neg; return m_n < ConstantsForMod<M>::g_memory_length ? Ref( m_n = Inverse( m_n ).m_n ) : ( m_n_neg = M - m_n < ConstantsForMod<M>::g_memory_length ) ? Ref( m_n = M - Inverse( m_n_neg ).m_n ) : PositivePower( INT_TYPE_FOR_MOD( ConstantsForMod<M>::g_M_minus_2 ) ); }
template <> inline Mod<2>& Mod<2>::Invert() { if( m_n == 0 ){ ERR_INPUT( m_n ); } return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::PositivePower( T&& exponent ) noexcept { Mod<M> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? operator*=( power ) : *this; exponent >>= 1; power *= power; } return *this; }
template <> template <typename T> inline constexpr Mod<2>& Mod<2>::PositivePower( T&& exponent ) noexcept { return *this; }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::NonNegativePower( T&& exponent ) noexcept { return exponent == 0 ? Ref( m_n = 1 ) : Ref( PositivePower( forward<T>( exponent ) ) ); }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Power( T&& exponent ) { bool neg = exponent < 0; if( neg && m_n == 0 ){ ERR_INPUT( m_n , exponent ); } neg ? exponent *= ConstantsForMod<M>::g_M_minus_2_neg : exponent; return m_n == 0 ? *this : ( exponent %= ConstantsForMod<M>::g_M_minus ) == 0 ? Ref( m_n = 1 ) : PositivePower( forward<T>( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr].m_n = M - Montgomery<M>::Multiplication( memory[M % length_curr].m_n , M / length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr] = Montgomery<M>::Factorial( length_curr ).Reduce(); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr] = Montgomery<M>::FactorialInverse( length_curr ).Reduce(); length_curr++; } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = n; return n_copy; }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& Mod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n < M ? n : n -= M; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static constexpr const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static constexpr const Mod<M> o{ Derepresent( 1 ) }; return o; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Ref( T&& n ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Twice( const Mod<M>& n ) noexcept { return move( Mod<M>( n ).Double() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Half( const Mod<M>& n ) noexcept { return move( Mod<M>( n ).Halve() ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Inverse_constrexpr( const INT_TYPE_FOR_MOD& n ) noexcept { return move( Mod<M>::Derepresent( Residue<M>( n ) ).NonNegativePower( M - 2 ) ); }

template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power( const Mod<M>& n , const T& exponent ) { return move( Mod<M>( n ).Power( T( exponent ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
