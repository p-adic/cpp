// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"
// 0èúéZópÇÃó·äO
#include "../../../../../Error/IllegalInput/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Montgomery<M>::Form( const INT_TYPE_FOR_MOD& n ) noexcept { ull n_copy = n; return INT_TYPE_FOR_MOD( move( Reduction( n_copy *= ConstantsForMod<M>::g_Montgomery_base_square_mod ) ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& Montgomery<M>::Reduction( ull& n ) noexcept { ull n_sub = n & ConstantsForMod<M>::g_Montgomery_base_minus; return ( ( n += ( ( n_sub *= ConstantsForMod<M>::g_Montgomery_M_neg_inverse ) &= ConstantsForMod<M>::g_Montgomery_base_minus ) *= M ) >>= ConstantsForMod<M>::g_Montgomery_digit ) < M ? n : n -= M; }
template <INT_TYPE_FOR_MOD M> inline constexpr ull& Montgomery<M>::ReducedMultiplication( ull& n , const INT_TYPE_FOR_MOD& m ) noexcept { return Reduction( n *= m ); }
template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Montgomery<M>::Multiplication( const INT_TYPE_FOR_MOD& n0 , const INT_TYPE_FOR_MOD& n1 ) noexcept { ull n0_copy = n0; return INT_TYPE_FOR_MOD( move( ReducedMultiplication( ReducedMultiplication( n0_copy , n1 ) , ConstantsForMod<M>::g_Montgomery_base_square_mod ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr uint Montgomery<M>::BaseSquareTruncation( INT_TYPE_FOR_MOD& n ) noexcept { const uint n_u = n >> ConstantsForMod<M>::g_Montgomery_digit_half; n &= ConstantsForMod<M>::g_Montgomery_base_sqrt_minus; return n_u; }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>::Montgomery() noexcept : Mod<M>() { static_assert( ! ConstantsForMod<M>::g_even ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>::Montgomery( const Montgomery<M>& n ) noexcept : Mod<M>( n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>::Montgomery( Montgomery<M>& n ) noexcept : Mod<M>( n ) {}
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>::Montgomery( Montgomery<M>&& n ) noexcept : Mod<M>( move( n ) ) {}
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MONTGOMERY()> inline constexpr Montgomery<M>::Montgomery( const T& n ) noexcept : Mod<M>( n ) { static_assert( ! ConstantsForMod<M>::g_even ); Mod<M>::m_n = Form( Mod<M>::m_n ); }
template <INT_TYPE_FOR_MOD M> template <SFINAE_FOR_MONTGOMERY()> inline constexpr Montgomery<M>::Montgomery( T&& n ) noexcept : Mod<M>( forward<T>( n ) ) { static_assert( ! ConstantsForMod<M>::g_even ); Mod<M>::m_n = Form( Mod<M>::m_n ); }


template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator=( const Montgomery<M>& n ) noexcept { return Ref( Mod<M>::operator=( n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator=( Montgomery<M>&& n ) noexcept { return Ref( Mod<M>::operator=( move( n ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator+=( const Montgomery<M>& n ) noexcept { return Ref( Mod<M>::operator+=( n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator-=( const Montgomery<M>& n ) noexcept { return Ref( Mod<M>::operator-=( n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator*=( const Montgomery<M>& n ) noexcept { ull m_n_copy = Mod<M>::m_n; return Ref( Mod<M>::m_n = move( ReducedMultiplication( m_n_copy , n.m_n ) ) ); }

template <INT_TYPE_FOR_MOD M> inline Montgomery<M>& Montgomery<M>::operator/=( const Montgomery<M>& n ) { return operator*=( Montgomery<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator<<=( int n ) noexcept { return Ref( Mod<M>::operator<<=( n ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator>>=( int n ) noexcept { return Ref( Mod<M>::operator>>=( n ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator++() noexcept { return Ref( Mod<M>::Normalise( Mod<M>::m_n += ConstantsForMod<M>::g_Montgomery_base_mod ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::operator++( int ) noexcept { Montgomery<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::operator--() noexcept { return Ref( Mod<M>::m_n < ConstantsForMod<M>::g_Montgomery_base_mod ? ( ( Mod<M>::m_n += M ) -= ConstantsForMod<M>::g_Montgomery_base_mod ) : Mod<M>::m_n -= ConstantsForMod<M>::g_Montgomery_base_mod ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::operator--( int ) noexcept { Montgomery<M> n{ *this }; operator--(); return n; }

DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( + , Montgomery<M>( forward<T>( n ) ) += *this );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( - , Montgomery<M>( forward<T>( n ) ).SignInvert() += *this );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( * , Montgomery<M>( forward<T>( n ) ) *= *this );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( / , Montgomery<M>( forward<T>( n ) ).Invert() *= *this );
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::operator<<( int n ) const noexcept { return move( Montgomery<M>( *this ) <<= n ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::operator>>( int n ) const noexcept { return move( Montgomery<M>( *this ) >>= n ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::operator-() const noexcept { return move( Montgomery<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::SignInvert() noexcept { return Ref( Mod<M>::m_n > 0 ? Mod<M>::m_n = M - Mod<M>::m_n : Mod<M>::m_n ); }


template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::Double() noexcept { return Ref( Mod<M>::Double() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::Halve() noexcept { return Ref( Mod<M>::Halve() ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M>& Montgomery<M>::Invert() { if( Mod<M>::m_n == 0 ){ ERR_INPUT( Mod<M>::m_n ); } return PositivePower( INT_TYPE_FOR_MOD( ConstantsForMod<M>::g_M_minus_2 ) ); }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Montgomery<M>& Montgomery<M>::PositivePower( T&& exponent ) noexcept { Montgomery<M> power{ *this }; ( --exponent ) %= ConstantsForMod<M>::g_M_minus_2; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? operator*=( power ) : *this; exponent >>= 1; power *= power; } return *this; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Montgomery<M>& Montgomery<M>::NonNegativePower( T&& exponent ) noexcept { return exponent == 0 ? Ref( Mod<M>::m_n = 1 ) : PositivePower( forward<T>( exponent ) ); }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Montgomery<M>& Montgomery<M>::Power( T&& exponent ) { bool neg = exponent < 0; assert( !( neg && Mod<M>::m_n == 0 ) ); return neg ? PositivePower( forward<T>( exponent *= ConstantsForMod<M>::g_M_minus_2_neg ) ) : NonNegativePower( forward<T>( exponent ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr INT_TYPE_FOR_MOD Montgomery<M>::Represent() const noexcept { ull m_n_copy = Mod<M>::m_n; return move( Reduction( m_n_copy ) ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Mod<M> Montgomery<M>::Reduce() const noexcept { ull m_n_copy = Mod<M>::m_n; return Mod<M>::Derepresent( move( Reduction( m_n_copy ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Montgomery<M>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { return Montgomery<M>( Mod<M>::Derepresent( n ) ); }

template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::Formise( const INT_TYPE_FOR_MOD& n ) noexcept { static Montgomery<M> memory[ConstantsForMod<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr] = Derepresent( length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Montgomery<M> memory[ConstantsForMod<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; while( length_curr <= n ){ memory[length_curr] = Montgomery<M>( Mod<M>::Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { static Montgomery<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; static Montgomery<M> val_curr{ one() }; static Montgomery<M> val_last{ one() }; while( length_curr <= n ){ memory[length_curr++] = val_curr *= ++val_last; } return memory[n]; }
template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { static Montgomery<M> memory[ConstantsForMod<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MOD length_curr = 2; static Montgomery<M> val_curr{ one() }; static Montgomery<M> val_last{ one() }; while( length_curr <= n ){ memory[length_curr] = val_curr *= Inverse( length_curr ); length_curr++; } return memory[n]; }

template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::zero() noexcept { static constexpr const Montgomery<M> z{}; return z; }
template <INT_TYPE_FOR_MOD M> inline const Montgomery<M>& Montgomery<M>::one() noexcept { static constexpr const Montgomery<M> o{ Derepresent( 1 ) }; return o; }

template <INT_TYPE_FOR_MOD M> template <typename T> inline constexpr Montgomery<M>& Montgomery<M>::Ref( T&& n ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Twice( const Montgomery<M>& n ) noexcept { return move( Montgomery<M>( n ).Double() ); }
template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Half( const Montgomery<M>& n ) noexcept { return move( Montgomery<M>( n ).Halve() ); }

template <INT_TYPE_FOR_MOD M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n ) { return move( Montgomery<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MOD M , typename T> inline constexpr Montgomery<M> Power( const Montgomery<M>& n , const T& exponent ) { return move( Montgomery<M>( n ).Power( T( exponent ) ) ); }

template <INT_TYPE_FOR_MOD M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M> inline string to_string( const Montgomery<M>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n ) { return os << n.Represent(); }
