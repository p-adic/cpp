// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "Residue/a_Body.hpp"
// 0除算用の例外
#include "../../../Error/IllegalImput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Mod<M>::MontgomeryForm( const INT_TYPE_FOR_MOD& n ) noexcept { ull n_copy = n; return INT_TYPE_FOR_MOD( move( MontgomeryReduction( n_copy *= ConstantsForMod<M>::g_Montgomery_base_square ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& Mod<M>::MontgomeryReduction( ull& n ) noexcept { ull n_sub = n & ConstantsForMod<M>::g_Montgomery_base_minus; return ( ( n += ( ( n_sub *= ConstantsForMod<M>::g_Montgomery_M_neg_inverse ) &= ConstantsForMod<M>::g_Montgomery_base_minus ) *= M ) >>= ConstantsForMod<M>::g_Montgomery_digit ) < M ? n : n -= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Mod<M>::MontgomeryMultiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return INT_TYPE_FOR_MOD( move( MontgomeryReduction( MontgomeryReduction( n0_copy *= n1 ) *= ConstantsForMod<M>::g_Montgomery_base_square ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD& Mod<M>::Normalise( INT_TYPE_FOR_MOD& n ) noexcept { return n >= M ? n -= M : n; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Ref( T&& n ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( const Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>::Mod( Mod<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
// nの書き換えを防ぐために明示的にキャスト
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Mod<M>::Mod( T& n ) noexcept : m_n( Residue( decay_t<T>( n ) , M ) ) {}
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MOD()> inline constexpr Mod<M>::Mod( T&& n ) noexcept : m_n( Residue( forward<T>( n ) , M ) ) {}


template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator=( const Mod<M>& n ) noexcept { return Ref( m_n = n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator+=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n += n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator-=( const Mod<M>& n ) noexcept { return Ref( Normalise( m_n += M - n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::operator*=( const Mod<M>& n ) noexcept { return Ref( m_n =  MontgomeryMultiplication( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::operator/=( const Mod<M>& n ) { return operator*=( Mod<M>( n ).Invert() ); }

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

DEFINITION_OF_ARITHMETIC_FOR_MOD( + , Mod<M>( forward<T>( n ) ) += *this , Add , INT_TYPE_FOR_MOD( Residue_constexpr( ull( m_n ) + n.m_n , M ) ) );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , Mod<M>( forward<T>( n ) ).SignInvert() += *this , Substract , INT_TYPE_FOR_MOD( Residue_constexpr( ull( m_n ) + ( M - n.m_n ) , M ) ) );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , Mod<M>( forward<T>( n ) ) *= *this , Multiply , INT_TYPE_FOR_MOD( Residue_constexpr( ull( m_n ) * n.m_n , M ) ) );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , Mod<M>( forward<T>( n ) ).Invert() *= *this , Devide , Multiply_constexpr( Inverse_constexpr( n ) ).m_n );

template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::operator-() const noexcept { return move( Mod<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M>& Mod<M>::SignInvert() noexcept { return Ref( m_n > 0 ? m_n = M - m_n : m_n ); }

template <INT_TYPE_FOR_MOD M> inline Mod<M>& Mod<M>::Invert() { if( m_n == 0 ){ ERR_INPUT( m_n ); } INT_TYPE_FOR_MOD m_n_neg; return m_n < ConstantsForMod<M>::g_memory_length ? Ref( m_n = Inverse( m_n ).m_n ) : ( m_n_neg = M - m_n < ConstantsForMod<M>::g_memory_length ) ? Ref( m_n = M - Inverse( m_n_neg ).m_n ) : PositivePower( INT_TYPE_FOR_MOD( ConstantsForMod<M>::g_M_minus_2 ) ); }
template <> inline Mod<2>& Mod<2>::Invert() { if( m_n == 0 ){ ERR_IMPUT( m_n ); } return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::PositivePower( T&& exponent ) noexcept { ull prod = ConstantsForMod<M>::g_Montgomery_base; ull power = MontgomeryForm( m_n ); while( exponent != 0 ){ ( exponent & 1 ) == 1 ? MontgomeryReduction( prod *= power ) : prod; exponent >>= 1; MontgomeryReduction( power *= power ); } return Ref( m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( prod ) ) ) ); }

template <> template <typename T> inline constexpr Mod<2>& Mod<2>::PositivePower( T&& exponent ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M>& Mod<M>::Power( T&& exponent ) { bool neg = exponent < 0; if( neg && m_n == 0 ){ ERR_IMPUT( m_n , exponent ); } neg ? exponent *= ConstantsForMod<M>::g_M_minus_2_neg : exponent; return m_n == 0 ? *this : ( exponent %= ConstantsForMod<M>::g_M_minus) == 0 ? Ref( m_n = 1 ) : PositivePower( forward<T>( exponent ) ); }
template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Mod<M> Mod<M>::NonNegativePower_constexpr( const Mod<M>& repetitive_square , T&& exponent ) noexcept { Mod<M> repetitive_square_next{ Multiply_constexpr( repetitive_square , repetitive_square ) }; Mod<M> one_constexpr{ Derepresent( 1 ) }; return move( exponent == 0 ? one_constexpr : Multiply_constexpr( move( ( exponent & 1 ) == 1 ? repetitive_square : one_constexpr ) , NonNegativePower_constexpr( repetitive_square_next , exponent >> 1 ) ) ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr].m_n = M - MontgomeryMultiplication( memory[M % length_curr].m_n , M / length_curr ); length_curr++; } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; static ull val_curr = ConstantsForMod<M>::g_Montgomery_base; ull val_copy; while( length_curr <= n ){ memory[length_curr].m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( val_copy = MontgomeryReduction( val_curr *= MontgomeryForm( length_curr ) ) ) ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Mod<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; static ull val_curr = ConstantsForMod<M>::g_Montgomery_base; ull val_copy; while( length_curr <= n ){ memory[length_curr].m_n = INT_TYPE_FOR_MOD( move( MontgomeryReduction( val_copy = MontgomeryReduction( val_curr *= MontgomeryForm( Inverse( length_curr ).m_n ) ) ) ) ); length_curr++; } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline constexpr const INT_TYPE_FOR_MOD& Mod<M>::Represent() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M> inline constexpr void Mod<M>::swap( Mod<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::zero() noexcept { static constexpr const Mod<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Mod<M>& Mod<M>::one() noexcept { static constexpr const Mod<M> o{ Derepresent( 1 ) }; return o; }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Mod<M>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { Mod<M> n_copy{}; n_copy.m_n = n; return n_copy; }

template <INT_TYPE_FOR_MOD M> inline Mod<M> Inverse( const Mod<M>& n ) { return move( Mod<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Inverse_constrexpr( const INT_TYPE_FOR_MOD& n ) noexcept { return Mod<M>::NonNegativePower_constexpr( Mod<M>::Derepresent( Residue_constexpr( n , M ) ) , M - 2 ); }

template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Mod<M> Power( const Mod<M>& n , const T& exponent ) { return move( Mod<M>( n ).Power( T( exponent ) ) ); }
template <typename T> inline constexpr Mod<2> Power( const Mod<2>& n , const T& exponent ) { return exponent == 0 ? Mod<2>::Derepresent( 1 ) : n; }

template <> inline constexpr Mod<2> Square<Mod<2> >( const Mod<2>& t ) { return t; }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Mod<M>& n0 , Mod<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Mod<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M>& n ) { return os << n.Represent(); }
