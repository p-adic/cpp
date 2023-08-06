// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Operator/a_Body.hpp"

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>::Mod() noexcept : m_n() {}
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>::Mod( const Mod<M,OPR>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>::Mod( Mod<M,OPR>& n ) noexcept : m_n( n.m_n ) {}
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>::Mod( Mod<M,OPR>&& n ) noexcept : m_n( move( n.m_n ) ) {}
template <INT_TYPE_FOR_MOD M , typename OPR> template <SFINAE_FOR_MOD()> inline constexpr Mod<M,OPR>::Mod( const T& n ) noexcept : m_n( OPR::Residue( n ) ) {}
// nの書き換えを防ぐために明示的にキャスト
template <INT_TYPE_FOR_MOD M , typename OPR> template <SFINAE_FOR_MOD()> inline constexpr Mod<M,OPR>::Mod( T& n ) noexcept : m_n( OPR::Residue( decay_t<T>( n ) ) ) {}
template <INT_TYPE_FOR_MOD M , typename OPR> template <SFINAE_FOR_MOD()> inline constexpr Mod<M,OPR>::Mod( T&& n ) noexcept : m_n( OPR::Residue( move( n ) ) ) {}

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator=( const Mod<M,OPR>& n ) noexcept { return Ref( m_n = n.m_n ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator=( Mod<M,OPR>&& n ) noexcept { return Ref( m_n = move( n.m_n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator+=( const Mod<M,OPR>& n ) noexcept { return Ref( OPR::Add( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator-=( const Mod<M,OPR>& n ) noexcept { return Ref( OPR::Subtract( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator*=( const Mod<M,OPR>& n ) noexcept { return Ref( OPR::Multiply( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR>& Mod<M,OPR>::operator/=( const Mod<M,OPR>& n ) { return Ref( OPR::Devide( m_n , n.m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator<<=( int n ) noexcept { return Ref( OPR::LShift( m_n , n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator>>=( int n ) noexcept { return Ref( OPR::RShift( m_n , n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator++() noexcept { return Ref( OPR::LIncrement( m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::operator++( int ) noexcept { return Construct( OPR::RIncrement( m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::operator--() noexcept { return Ref( OPR::LDecrement( m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::operator--( int ) noexcept { return Construct( OPR::RDecrement( m_n ) ); }

DEFINITION_OF_COMPARISON_FOR_MOD( == );
DEFINITION_OF_COMPARISON_FOR_MOD( != );
DEFINITION_OF_ARITHMETIC_FOR_MOD( + , += *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( - , .SignInvert() += *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( * , *= *this );
DEFINITION_OF_ARITHMETIC_FOR_MOD( / , .Invert() *= *this );

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::operator<<( int n ) const noexcept { return move( Mod<M,OPR>( *this ) <<= n ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::operator>>( int n ) const noexcept { return move( Mod<M,OPR>( *this ) >>= n ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::operator-() const noexcept { return move( Mod<M,OPR>( *this ).SignInvert() ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::SignInvert() noexcept { return Ref( OPR::SignInvert( m_n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::Double() noexcept { return Ref( OPR::Double( m_n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR>& Mod<M,OPR>::Halve() noexcept { return Ref( OPR::Halve( m_n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR>& Mod<M,OPR>::Invert() { return Ref( OPR::Invert( m_n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> template <typename T> inline constexpr Mod<M,OPR>& Mod<M,OPR>::PositivePower( T&& exponent ) noexcept { return OPR::PositivePower( m_n ); }
template <INT_TYPE_FOR_MOD M , typename OPR> template <typename T> inline constexpr Mod<M,OPR>& Mod<M,OPR>::NonNegativePower( T&& exponent ) noexcept { return OPR::NonNegativePower( m_n ); }
template <INT_TYPE_FOR_MOD M , typename OPR> template <typename T> inline Mod<M,OPR>& Mod<M,OPR>::Power( T&& exponent ) { return OPR::Power( m_n ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR> Mod<M,OPR>::Inverse( const INT_TYPE_FOR_MOD& n ) noexcept { return Construct( OPR::Inverse( n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR> Mod<M,OPR>::Factorial( const INT_TYPE_FOR_MOD& n ) noexcept { return Construct( OPR::Factorial( n ) ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR> Mod<M,OPR>::FactorialInverse( const INT_TYPE_FOR_MOD& n ) noexcept { return Construct( OPR::FactorialInverse( n ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr void Mod<M,OPR>::swap( Mod<M,OPR>& n ) noexcept { std::swap( m_n , n.m_n ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr conditional_t<is_same<OPR,OperatorsForMod<M> >::value,const INT_TYPE_FOR_MOD&,INT_TYPE_FOR_MOD> Mod<M,OPR>::Represent() const noexcept { return Deconstruct(); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr const INT_TYPE_FOR_MOD& Mod<M,OPR>::Deconstruct() const noexcept { return m_n; }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::Derepresent( const INT_TYPE_FOR_MOD& n ) noexcept { return Construct( n ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Mod<M,OPR>::Construct( INT_TYPE_FOR_MOD n ) noexcept { Mod<M,OPR> n_copy{}; n_copy.m_n = move( n ); return n_copy; }

template <INT_TYPE_FOR_MOD M , typename OPR> inline const Mod<M,OPR>& Mod<M,OPR>::zero() noexcept { static constexpr const Mod<M,OPR> z{}; return z; }
template <INT_TYPE_FOR_MOD M , typename OPR> inline const Mod<M,OPR>& Mod<M,OPR>::one() noexcept { static constexpr const Mod<M,OPR> o{ Derepresent( 1 ) }; return o; }

template <INT_TYPE_FOR_MOD M , typename OPR> template <typename T> inline constexpr Mod<M,OPR>& Mod<M,OPR>::Ref( T&& n ) noexcept { return *this; }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Twice( Mod<M,OPR> n ) noexcept { return move( n.Double() ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Half( Mod<M,OPR> n ) noexcept { return move( n.Halve() ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline Mod<M,OPR> Inverse( Mod<M,OPR> n ) { return move( n.Invert() ); }
template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr Mod<M,OPR> Inverse_constrexpr( Mod<M,OPR> n ) noexcept { return move( n.NonNegativePower( M - 2 ) ); }

template <INT_TYPE_FOR_MOD M , typename OPR , typename T> inline constexpr Mod<M,OPR> Power( Mod<M,OPR> n , const T& exponent ) { return move( n.Power( T( exponent ) ) ); }
template <> inline constexpr Mod<2> Square<Mod<2> >( const Mod<2>& n ) { return n; }

template <INT_TYPE_FOR_MOD M , typename OPR> inline constexpr void swap( Mod<M,OPR>& n0 , Mod<M,OPR>& n1 ) noexcept { n0.swap( n1 ); }

template <INT_TYPE_FOR_MOD M , typename OPR> inline string to_string( const Mod<M,OPR>& n ) noexcept { return to_string( n.Represent() ) + " + MZ"; }

template<INT_TYPE_FOR_MOD M , typename OPR , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const Mod<M,OPR>& n ) { return os << n.Represent(); }
