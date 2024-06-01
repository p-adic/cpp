// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Montgomery/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../../Function/Residue/a_Body.hpp"

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>::Montgomery() noexcept : m_n() { static_assert( !ConstantsForMontgomery<M>::g_even ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>::Montgomery( const Montgomery<M>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>::Montgomery( Montgomery<M>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MONTGOMERY M> template <typename T> inline constexpr Montgomery<M>::Montgomery( T n ) noexcept : m_n( Form( Residue<M>( move( n ) ) ) ) { static_assert( !ConstantsForMontgomery<M>::g_even && is_constructible_v<INT_TYPE_FOR_MONTGOMERY,decay_t<T> > ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator=( Montgomery<M> n ) noexcept { return Ref( m_n = move( n.m_n ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator+=( const Montgomery<M>& n ) noexcept { return Ref( Normalise( m_n += n.m_n ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator-=( const Montgomery<M>& n ) noexcept { return Ref( m_n < n.m_n ? ( m_n += M ) -= n.m_n : m_n -= n.m_n ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator*=( const Montgomery<M>& n ) noexcept { ull m_n_copy = m_n; return Ref( m_n = move( ReducedMultiplication( m_n_copy , n.m_n ) ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline Montgomery<M>& Montgomery<M>::operator/=( Montgomery<M> n ) { return operator*=( Montgomery<M>( n ).Invert() ); }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M>& Montgomery<M>::operator<<=( INT n ) { return assert( n >= 0 ); return *this *= Montgomery<M>( two() ).NonNegativePower( move( n ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M>& Montgomery<M>::operator>>=( INT n ) { assert( n >=0 ); while( n-- > 0 ){ ( ( m_n & 1 ) == 0 ? m_n : m_n += M ) >>= 1; } return *this; }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator++() noexcept { return Ref( Normalise( m_n += ConstantsForMontgomery<M>::g_Montgomery_base_mod ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Montgomery<M>::operator++( int ) noexcept { Montgomery<M> n{ *this }; operator++(); return n; }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::operator--() noexcept { return Ref( ( m_n < ConstantsForMontgomery<M>::g_Montgomery_base_mod ? m_n += M : m_n ) -= ConstantsForMontgomery<M>::g_Montgomery_base_mod ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Montgomery<M>::operator--( int ) noexcept { Montgomery<M> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_MONTGOMERY( == );
DEFINITION_OF_COMPARISON_FOR_MONTGOMERY( != );

DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_MONTGOMERY( / , , n.Invert() , * );
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M> Montgomery<M>::operator^( INT exponent ) const { return move( Montgomery<M>( *this ).Power( move( exponent ) ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M> Montgomery<M>::operator<<( INT n ) const { return move( Montgomery<M>( *this ) <<= move( n ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M> Montgomery<M>::operator>>( INT n ) const { return move( Montgomery<M>( *this ) >>= move( n ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Montgomery<M>::operator-() const noexcept { return move( Montgomery<M>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::SignInvert() noexcept { return Ref( m_n > 0 ? m_n = M - m_n : m_n ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M>& Montgomery<M>::Invert() { assert( m_n != 0 ); return PositivePower( INT_TYPE_FOR_MONTGOMERY( ConstantsForMontgomery<M>::g_M_minus_2 ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M>& Montgomery<M>::PositivePower( INT exponent ) noexcept { Montgomery<M> power{ *this }; ( --exponent ) %= ConstantsForMontgomery<M>::g_M_minus_2; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M>& Montgomery<M>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? Ref( m_n = ConstantsForMontgomery<M>::g_Montgomery_base_mod ) : PositivePower( move( exponent ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> template <typename INT> inline constexpr Montgomery<M>& Montgomery<M>::Power( INT exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return neg ? PositivePower( move( exponent *= ConstantsForMontgomery<M>::g_M_minus_2_neg ) ) : NonNegativePower( move( exponent ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr void Montgomery<M>::swap( Montgomery<M>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr INT_TYPE_FOR_MONTGOMERY Montgomery<M>::Represent() const noexcept { ull m_n_copy = m_n; return move( Reduction( m_n_copy ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Montgomery<M>::Derepresent( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept { Montgomery<M> n_copy{}; n_copy.m_n = Form( n ); return n_copy; }

template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::Inverse( const INT_TYPE_FOR_MONTGOMERY& n ) { assert( n < ConstantsForMontgomery<M>::g_memory_length ); static INT_TYPE_FOR_MONTGOMERY memory0[ConstantsForMontgomery<M>::g_memory_length] = { 0 , 1 }; static Montgomery<M> memory1[ConstantsForMontgomery<M>::g_memory_length] = { zero() , one() }; static INT_TYPE_FOR_MONTGOMERY length_curr = 2; while( length_curr <= n ){ memory1[length_curr].m_n = Form( memory0[length_curr] = M - memory0[M % length_curr] * ull( M / length_curr ) % M ); length_curr++; } return memory1[n]; }
template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::Factorial( const INT_TYPE_FOR_MONTGOMERY& n ) { assert( n < ConstantsForMontgomery<M>::g_memory_length ); static Montgomery<M> memory[ConstantsForMontgomery<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MONTGOMERY length_curr = 2; static Montgomery<M> val_curr{ one() }; static Montgomery<M> val_last{ one() }; while( length_curr <= n ){ memory[length_curr++] = val_curr *= ++val_last; } return memory[n]; }
template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::FactorialInverse( const INT_TYPE_FOR_MONTGOMERY& n ) { static Montgomery<M> memory[ConstantsForMontgomery<M>::g_memory_length] = { one() , one() }; static INT_TYPE_FOR_MONTGOMERY length_curr = 2; static Montgomery<M> val_curr{ one() }; static Montgomery<M> val_last{ one() }; while( length_curr <= n ){ memory[length_curr] = val_curr *= Inverse( length_curr ); length_curr++; } return memory[n]; }
template <INT_TYPE_FOR_MONTGOMERY M> inline Montgomery<M> Montgomery<M>::Combination( const INT_TYPE_FOR_MONTGOMERY& n , const INT_TYPE_FOR_MONTGOMERY& i ) { return i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::zero() noexcept { static constexpr const Montgomery<M> z{}; return z; }
template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::one() noexcept { static constexpr const Montgomery<M> o{ 1 }; return o; }
template <INT_TYPE_FOR_MONTGOMERY M> inline const Montgomery<M>& Montgomery<M>::two() noexcept { static constexpr const Montgomery<M> t{ 2 }; return t; }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr INT_TYPE_FOR_MONTGOMERY Montgomery<M>::Form( const INT_TYPE_FOR_MONTGOMERY& n ) noexcept { ull n_copy = n; return INT_TYPE_FOR_MONTGOMERY( move( Reduction( n_copy *= ConstantsForMontgomery<M>::g_Montgomery_base_square_mod ) ) ); }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr ull& Montgomery<M>::Reduction( ull& n ) noexcept { ull n_sub = n & ConstantsForMontgomery<M>::g_Montgomery_base_minus; return ( ( n += ( ( n_sub *= ConstantsForMontgomery<M>::g_Montgomery_M_neg_inverse ) &= ConstantsForMontgomery<M>::g_Montgomery_base_minus ) *= M ) >>= ConstantsForMontgomery<M>::g_Montgomery_digit ) < M ? n : n -= M; }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr ull& Montgomery<M>::ReducedMultiplication( ull& n , const INT_TYPE_FOR_MONTGOMERY& m ) noexcept { return Reduction( n *= m ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr uint Montgomery<M>::BaseSquareTruncation( INT_TYPE_FOR_MONTGOMERY& n ) noexcept { const uint n_u = n >> ConstantsForMontgomery<M>::g_Montgomery_digit_half; n &= ConstantsForMontgomery<M>::g_Montgomery_base_sqrt_minus; return n_u; }

template <INT_TYPE_FOR_MONTGOMERY M> template <typename T> inline constexpr Montgomery<M>& Montgomery<M>::Ref( T&& n ) noexcept { return *this; }
template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr INT_TYPE_FOR_MONTGOMERY& Montgomery<M>::Normalise( INT_TYPE_FOR_MONTGOMERY& n ) noexcept { return n < M ? n : n -= M; }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr Montgomery<M> Inverse( const Montgomery<M>& n ) { return move( Montgomery<M>( n ).Invert() ); }

template <INT_TYPE_FOR_MONTGOMERY M , typename INT> inline constexpr Montgomery<M> Power( Montgomery<M> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline constexpr void swap( Montgomery<M>& n0 , Montgomery<M>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MONTGOMERY M> inline string to_string( const Montgomery<M>& n ) noexcept { return to_string( n.Represent() ) + to_string( M ) + "Z"; }

template <INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , Montgomery<M>& n ) { ll m; is >> m; n = m; return is; }
template<INT_TYPE_FOR_MONTGOMERY M , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Montgomery<M>& n ) { return os << n.Represent(); }

#include "../../Hash/a_Body.hpp"
template <INT_TYPE_FOR_MOD M> DEFINITION_OF_HASH_FOR_MOD( Montgomery<M> );
