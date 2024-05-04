// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Constant/a_Body.hpp"
#include "../Function/Residue/a_Body.hpp"

template <int NUM> inline DynamicMods<NUM>::DynamicMods() noexcept : m_n() {}
template <int NUM> inline DynamicMods<NUM>::DynamicMods( const DynamicMods<NUM>& n ) noexcept : m_n( n.m_n ) {}
template <int NUM> inline DynamicMods<NUM>::DynamicMods( DynamicMods<NUM>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <int NUM> template <typename T> inline DynamicMods<NUM>::DynamicMods( T n ) noexcept : m_n( Residue( uint( move( n ) ) , Constants::g_M ) ) { static_assert( is_constructible_v<uint,decay_t<T> > ); }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator=( DynamicMods<NUM> n ) noexcept { m_n = move( n.m_n ); return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator+=( const DynamicMods<NUM>& n ) noexcept { ( m_n += n.m_n ) < Constants::g_M ? m_n : m_n -= Constants::g_M; return *this; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator-=( const DynamicMods<NUM>& n ) noexcept { m_n < n.m_n ? ( m_n += Constants::g_M ) -= n.m_n : m_n -= n.m_n; return *this; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator*=( const DynamicMods<NUM>& n ) noexcept { m_n = Residue( move( ull( m_n ) * n.m_n ) , Constants::g_M ); return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator/=( DynamicMods<NUM> n ) { return operator*=( n.Invert() ); }
template <int NUM> template <typename INT> inline DynamicMods<NUM>& DynamicMods<NUM>::operator<<=( INT n ) { assert( n >= 0 ); return *this *= DynamicMods<NUM>( 2 ).NonNegativePower( move( n ) ); }
template <int NUM> template <typename INT> inline DynamicMods<NUM>& DynamicMods<NUM>::operator>>=( INT n ) { assert( n >= 0 ); while( n-- > 0 ){ ( ( m_n & 1 ) == 0 ? m_n : m_n += Constants::g_M ) >>= 1; } return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator++() noexcept { m_n < Constants::g_M_minus ? ++m_n : m_n = 0; return *this; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator++( int ) noexcept { DynamicMods<NUM> n{ *this }; operator++(); return n; }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::operator--() noexcept { m_n == 0 ? m_n = Constants::g_M_minus : --m_n; return *this; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator--( int ) noexcept { DynamicMods<NUM> n{ *this }; operator--(); return n; }

DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( == );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( != );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( > );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( >= );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( < );
DEFINITION_OF_COMPARISON_FOR_DYNAMIC_MOD( <= );

DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( + , noexcept , n , + );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( - , noexcept , n.SignInvert() , + );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( * , noexcept , n , * );
DEFINITION_OF_ARITHMETIC_FOR_DYNAMIC_MOD( / , , n.Invert() , * );
template <int NUM> template <typename INT> inline DynamicMods<NUM> DynamicMods<NUM>::operator^( INT exponent ) const { return move( DynamicMods<NUM>( *this ).Power( move( exponent ) ) ); }
template <int NUM> template <typename INT> inline DynamicMods<NUM> DynamicMods<NUM>::operator<<( INT n ) const { return move( DynamicMods<NUM>( *this ) <<= move( n ) ); }
template <int NUM> template <typename INT> inline DynamicMods<NUM> DynamicMods<NUM>::operator>>( INT n ) const { return move( DynamicMods<NUM>( *this ) >>= move( n ) ); }

template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::operator-() const noexcept { return move( DynamicMods<NUM>( *this ).SignInvert() ); }
template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::SignInvert() noexcept { m_n > 0 ? m_n = Constants::g_M - m_n : m_n; return *this; }

template <int NUM> inline DynamicMods<NUM>& DynamicMods<NUM>::Invert() { assert( m_n != 0 ); return NonNegativePower( Constants::g_order_minus_1 ); }

template <int NUM> template <typename INT> inline DynamicMods<NUM>& DynamicMods<NUM>::PositivePower( INT exponent ) noexcept { DynamicMods<NUM> power{ *this }; exponent--; while( exponent != 0 ){ ( exponent & 1 ) == 1 ? *this *= power : *this; exponent >>= 1; power *= power; } return *this; }
template <int NUM> template <typename INT> inline DynamicMods<NUM>& DynamicMods<NUM>::NonNegativePower( INT exponent ) noexcept { return exponent == 0 ? ( m_n = 1 , *this ) : PositivePower( move( exponent ) ); }
template <int NUM> template <typename INT> inline DynamicMods<NUM>& DynamicMods<NUM>::Power( INT exponent ) { bool neg = exponent < 0; assert( !( neg && m_n == 0 ) ); return neg ? PositivePower( move( exponent *= Constants::g_order_minus_1_neg ) ) : NonNegativePower( move( exponent ) ); }

template <int NUM> inline void DynamicMods<NUM>::swap( DynamicMods<NUM>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::Inverse( const uint& n ) { static vector<DynamicMods<NUM>> memory = { zero() , one() }; static uint length_curr = 2; while( length_curr <= n ){ memory.push_back( Derepresent( Constants::g_M - memory[Constants::g_M % length_curr].m_n * ull( Constants::g_M / length_curr ) % Constants::g_M ) ); length_curr++; } return memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::Factorial( const uint& n ) { static vector<DynamicMods<NUM>> memory = { one() , one() }; static uint length_curr = 2; if( Constants::g_M <= n ){ return zero(); } while( length_curr <= n && memory.back().m_n != 0 ){ memory.push_back( memory.back() * Derepresent( length_curr ) ); length_curr++; } return length_curr <= n ? memory.back() : memory[n]; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::FactorialInverse( const uint& n ) { static vector<DynamicMods<NUM>> memory = { one() , one() }; static uint length_curr = 2; while( length_curr <= n ){ memory.push_back( memory[length_curr - 1] * Inverse( length_curr ) ); length_curr++; } return memory[n]; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::Combination( const uint& n , const uint& i ) { return i <= n ? Factorial( n ) * FactorialInverse( i ) * FactorialInverse( n - i ) : zero(); }

template <int NUM> inline const uint& DynamicMods<NUM>::Represent() const noexcept { return m_n; }
template <int NUM> inline DynamicMods<NUM> DynamicMods<NUM>::Derepresent( uint n ) noexcept { DynamicMods<NUM> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::zero() noexcept { static const DynamicMods<NUM> z{}; return z; }
template <int NUM> inline const DynamicMods<NUM>& DynamicMods<NUM>::one() noexcept { static const DynamicMods<NUM> o{ 1 }; return o; }

template <int NUM> inline const uint& DynamicMods<NUM>::GetModulo() noexcept { return Constants::g_M; }
template <int NUM> inline void DynamicMods<NUM>::SetModulo( const uint& M , const int& order_minus_1 ) noexcept { Constants::g_M = M; Constants::g_M_minus = M - 1; Constants::g_order_minus_1 = order_minus_1 == -1 ? M - 2 : order_minus_1; Constants::g_order_minus_1_neg = -Constants::g_order_minus_1; }

template <int NUM> inline DynamicMods<NUM> Inverse( const DynamicMods<NUM>& n ) { return move( DynamicMods<NUM>( n ).Invert() ); }
template <int NUM , typename INT> inline DynamicMods<NUM> Power( DynamicMods<NUM> n , INT exponent ) { return move( n.Power( move( exponent ) ) ); }

template <int NUM> inline void swap( DynamicMods<NUM>& n0 , DynamicMods<NUM>& n1 ) noexcept { n0.swap( n1 ); }

template <int NUM> inline string to_string( const DynamicMods<NUM>& n ) noexcept { return to_string( n.Represent() ) + " + " + to_string( DynamicMods<NUM>::GetModulo() ) + "Z"; }

template <int NUM , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , DynamicMods<NUM>& n ) { ll m; is >> m; n = m; return is; }
template <int NUM , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const DynamicMods<NUM>& n ) { return os << n.Represent(); }

#include "../Hash/a_Body.hpp"
template <int NUM> DEFINITION_OF_HASH_FOR_MOD( DynamicMods<NUM> );
