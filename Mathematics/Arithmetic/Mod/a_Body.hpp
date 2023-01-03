// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Residue/a_Body.hpp"
// 0除算用の例外
#include "../../../Error/IllegalImput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr int Mod<M>::BinaryDigitUpperBound() noexcept { int answer = 0; int power = 1; while( M > power ){ answer++; power <<= 1; } assert( answer < 32 ); return answer; }
template <INT_TYPE_FOR_MOD M> inline constexpr ull Mod<M>::MontgomeryBasePower( ull&& exponent ) noexcept { ull prod = 1; ull power = M; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? ( prod *= power ) &= g_Montgomery_base_minus : prod; exponent >>= 1; ( power *= power ) &= g_Montgomery_base_minus; } return prod; }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD Mod<M>::MontgomeryForm( const INT_TYPE_FOR_MOD& n ) noexcept { ull n_copy = n; return INT_TYPE_FOR_MOD( move( MontgomeryReduction( n_copy *= g_Montgomery_base_square ) ) ); }
template <INT_TYPE_FOR_MOD M> inline ull& Mod<M>::MontgomeryReduction( ull& n ) noexcept { ull n_sub = n & g_Montgomery_base_minus; return ( ( n += ( ( n_sub *= g_Montgomery_M_neg_inverse ) &= g_Montgomery_base_minus ) *= M ) >>= g_Montgomery_digit ) < M ? n : n -= M; }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD Mod<M>::MontgomeryMultiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return INT_TYPE_FOR_MOD( move( MontgomeryReduction( MontgomeryReduction( n0_copy *= n1 ) *= g_Montgomery_base_square ) ) ); }
template <INT_TYPE_FOR_MOD M> inline INT_TYPE_FOR_MOD& Mod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n < 0 ? n += M : n; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline Mod<M>& Mod<M>::Ref( T&& n ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
// nの書き換えを防ぐために明示的にキャスト
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline Mod<M>::Mod( T& n ) noexcept : m_n( Residue( decay_t<T>( n ) , M ) ) {}
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline Mod<M>::Mod( T&& n ) noexcept : m_n( Residue( forward<T>( n ) , M ) ) {}


template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept { return Ref( m_n = n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n += n.m_n - M ) ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n -= n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { return Ref( m_n =  MontgomeryMultiplication( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const Mod<M>& n ) { return operator*=( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator++() noexcept { return Ref( m_n < g_M_minus ? ++m_n : m_n = 0 ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator++( int ) noexcept { Mod<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator--() noexcept { return Ref( m_n == 0 ? m_n = g_M_minus : --m_n ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator--( int ) noexcept { Mod<M> n{ *this }; operator--(); return n; }
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

template <INT_TYPE_FOR_MOD M> inline Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::SignInvert() noexcept { return Ref( m_n > 0 ? m_n = M - m_n : m_n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { if( m_n == 0 ){ ERR_INPUT( m_n ); } INT_TYPE_FOR_MOD m_n_neg; return m_n < g_memory_length ? Ref( m_n = Inverse( m_n ).m_n ) : ( m_n_neg = M - m_n < g_memory_length ) ? Ref( m_n = M - Inverse( m_n_neg ).m_n ) : PositivePower( INT_TYPE_FOR_MOD( g_M_minus_2 ) ); }

template <> inline Mod<2>& Mod<2>::Invert() { if( m_n == 0 ){ ERR_IMPUT( m_n ); } return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline Mod<M>& Mod<M>::PositivePower( T&& exponent ) noexcept { ull prod = g_Montgomery_base; ull power = MontgomeryForm( m_n ); while( exponent != 0 ){ ( exponent & 1 ) == 1 ? MontgomeryReduction( prod *= power ) : prod; exponent >>= 1; MontgomeryReduction( power *= power ); } return Ref( m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( prod ) ) ) ); }

template <> template <typename T> inline Mod<2>& Mod<2>::PositivePower( T&& exponent ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline Mod<M>& Mod<M>::Power( T&& exponent ) { bool neg = exponent < 0; if( neg && m_n == 0 ){ ERR_IMPUT( m_n , exponent ); } neg ? exponent *= g_M_minus_2_neg : exponent; return m_n == 0 ? *this : ( exponent %= g_M_minus) == 0 ? Ref( m_n = 1 ) : PositivePower( forward<T>( exponent ) );  }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { zero() , one() }; static int length_curr = 2; while( length_curr <= n ){ memory[length_curr].m_n = M - MontgomeryMultiplication( memory[M % length_curr].m_n , M / length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { one() , one() }; static int length_curr = 2; static ull val_curr = g_Montgomery_base; ull val_copy; while( length_curr <= n ){ memory[length_curr].m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( val_copy = MontgomeryReduction( val_curr *= MontgomeryForm( length_curr ) ) ) ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[g_memory_length] = { one() , one() }; static int length_curr = 2; static ull val_curr = g_Montgomery_base; ull val_copy; while( length_curr <= n ){ memory[length_curr].m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( val_copy = MontgomeryReduction( val_curr *= MontgomeryForm( Inverse( length_curr ).m_n ) ) ) ) ); length_curr++; } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M> inline void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static const Mod<M> o{ 1 }; return o; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M , typename T> inline Mod<M> Power( const Mod<M>& n , const T& exponent ) { return move( Mod<M>( n ).Power( T( exponent ) ) ); }
template <typename T> inline Mod<2> Power( const Mod<2>& n , const T& exponent ) { return exponent == 0 ? Mod<2>::one() : n; }

template <> inline Mod<2> Square<Mod<2> >( const Mod<2>& t ) { return t; }

template <INT_TYPE_FOR_MOD M> inline void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
