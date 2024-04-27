// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Shifted/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"

template <int NUM> inline ShiftedMods<NUM>::ShiftedMods() noexcept : m_n() {}
template <int NUM> inline ShiftedMods<NUM>::ShiftedMods( const ShiftedMods<NUM>& n ) noexcept : m_n( n.m_n ) {}
template <int NUM> inline ShiftedMods<NUM>::ShiftedMods( ShiftedMods<NUM>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <int NUM> template <typename T> inline ShiftedMods<NUM>::ShiftedMods( T n ) noexcept : m_n( Residue( move( n ) ) ) { static_assert( is_constructible_v<uint,decay_t<T> > ); }

template <int NUM> inline ShiftedMods<NUM>& ShiftedMods<NUM>::operator=( ShiftedMods<NUM> n ) noexcept { m_n = move( n.m_n ); return *this; }

template <int NUM> inline ShiftedMods<NUM>& ShiftedMods<NUM>::operator+=( const ShiftedMods<NUM>& n ) noexcept { m_n = Residue( move( m_n += n.m_n ) ); return *this; }
template <int NUM> inline ShiftedMods<NUM>& ShiftedMods<NUM>::operator*=( const ShiftedMods<NUM>& n ) noexcept { m_n = Residue( move( ull( m_n ) * n.m_n ) ); return *this; }

template <int NUM> template <typename INT> inline ShiftedMods<NUM>& ShiftedMods<NUM>::operator<<=( INT n ) { return *this *= ShiftedMods<NUM>( 2 ).Power( move( n ) ); }

template <int NUM> inline ShiftedMods<NUM>& ShiftedMods<NUM>::operator++() noexcept { ++m_n < T( Constants::g_KM ) ? m_n : m_n = Constants::g_K; return *this; }
template <int NUM> inline ShiftedMods<NUM> ShiftedMods<NUM>::operator++( int ) noexcept { ShiftedMods<NUM> n{ *this }; operator++(); return n; }

DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( == );
DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( != );
DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( > );
DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( >= );
DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( < );
DEFINITION_OF_COMPARISON_FOR_SHIFTED_MOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_SHIFTED_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_SHIFTED_MOD( * , noexcept , n , * );
template <int NUM> template <typename INT> inline ShiftedMods<NUM> ShiftedMods<NUM>::operator^( INT exponent ) const { return move( ShiftedMods<NUM>( *this ).Power( move( exponent ) ) ); }
template <int NUM> template <typename INT> inline ShiftedMods<NUM> ShiftedMods<NUM>::operator<<( INT n ) const { return move( ShiftedMods<NUM>( *this ) <<= move( n ) ); }

template <int NUM> template <typename INT> inline ShiftedMods<NUM>& ShiftedMods<NUM>::PositivePower( INT exponent ) noexcept { ShiftedMods<NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <int NUM> template <typename INT> inline ShiftedMods<NUM>& ShiftedMods<NUM>::Power( INT exponent ) { assert( exponent >= 0 ); return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }

template <int NUM> inline void ShiftedMods<NUM>::swap( ShiftedMods<NUM>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <int NUM> inline const uint& ShiftedMods<NUM>::Represent() const noexcept { return m_n; }
template <int NUM> inline ShiftedMods<NUM> ShiftedMods<NUM>::Derepresent( uint n ) noexcept { ShiftedMods<NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <int NUM> template <typename T> inline T ShiftedMods<NUM>::Residue( T n ){ assert( n >= 0 ); return move( n < T( Constants::g_KM ) ? n : ( ( n -= Constants::g_K ) %= Constants::g_M ) += Constants::g_K ); }

template <int NUM> inline const ShiftedMods<NUM>& ShiftedMods<NUM>::Factorial( const uint& n ) { static vector<ShiftedMods<NUM>> memory = { one() , one() }; static uint length_curr = 2; while( length_curr <= n ){ memory.push_back( memory.back() * Derepresent( length_curr ) ); length_curr++; } return memory[n]; }

template <int NUM> inline const ShiftedMods<NUM>& ShiftedMods<NUM>::zero() noexcept { static const ShiftedMods<NUM> z{}; return z; }
template <int NUM> inline const ShiftedMods<NUM>& ShiftedMods<NUM>::one() noexcept { static const ShiftedMods<NUM> o{ 1 }; return o; }

template <int NUM> inline const uint& ShiftedMods<NUM>::GetShift() noexcept { return Constants::g_K; }
template <int NUM> inline const uint& ShiftedMods<NUM>::GetModulo() noexcept { return Constants::g_M; }
template <int NUM> inline void ShiftedMods<NUM>::SetModulo( const uint& K , const uint& M ) noexcept { Constants::g_K = K; Constants::g_M = M; Constants::g_KM = K + M; }

template <int NUM> inline void swap( ShiftedMods<NUM>& n0 , ShiftedMods<NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <int NUM> inline string to_string( const ShiftedMods<NUM>& n ) noexcept { return to_string( n.Represent() ); }

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , ShiftedMods<NUM>& n ) { ll m; is >> m; n = m; return is; }
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const ShiftedMods<NUM>& n ) { return os << n.Represent(); }
