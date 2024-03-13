// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> const INT* QuotientRing<INT>::g_p_M = nullptr;
template <typename INT> inline QuotientRing<INT>::QuotientRing() noexcept : m_n() {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const INT& n ) noexcept : m_n( n % *g_p_M ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const QuotientRing<INT>& n ) noexcept : m_n( n.m_n ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( QuotientRing<INT>&& n ) noexcept : m_n( move( n.m_n ) ) {}

template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator=( QuotientRing<INT> n ) noexcept { m_n = move( n.m_n ); return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator+=( const QuotientRing<INT>& n ) noexcept { ( m_n += n.m_n ) %= *g_p_M; return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator-=( const QuotientRing<INT>& n ) noexcept { ( m_n -= n.m_n ) %= *g_p_M; return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator*=( const QuotientRing<INT>& n ) noexcept { ( m_n *= n.m_n ) %= *g_p_M; return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator/=( QuotientRing<INT> n ) { return *this *= Inverse( n ); }

template <typename INT> inline bool QuotientRing<INT>::operator==( const QuotientRing<INT>& n ) const noexcept { return m_n == n.m_n; }
template <typename INT> inline bool QuotientRing<INT>::operator!=( const QuotientRing<INT>& n ) const noexcept { return !( *this == n ); }

template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator+( QuotientRing<INT> n ) const noexcept { return move( n += *this ); }
template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator-() const noexcept { QuotientRing<INT> answer{}; answer.m_n = -answer.m_n; return answer; }
template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator-( QuotientRing<INT> n ) const noexcept { return n -= *this; }
template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator*( QuotientRing<INT> n ) const noexcept { return n *= *this; }
template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator/( const QuotientRing<INT>& n ) const { return Inverse( n ) *= *this; }

template <typename INT> template <typename T>
QuotientRing<INT> QuotientRing<INT>::operator^( T exponent )
{

  QuotientRing<INT> answer{ 1 };
  QuotientRing<INT> power{ *this };
  exponent < 0 ? ( exponent = -exponent , power = Inverse( power ) ) : power;

  while( exponent > 0 ){

    if( ( exponent & 2 ) == 1 ){

      answer *= power;

    }

    power *= power;
    exponent >>= 1;

  }

  return answer;

}

template <typename INT> inline const INT& QuotientRing<INT>::Represent() const noexcept { return m_n; }
template <typename INT> inline const INT& QuotientRing<INT>::GetModulo() noexcept { ssert( g_p_M != nullptr ); return *g_p_M; }
template <typename INT> inline void QuotientRing<INT>::SetModulo( const INT* const& p_M ) noexcept { assert( ( g_p_M = p_M ) != nullptr ); }

template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::Inverse( const QuotientRing<INT>& n ) { return n ^ ( *g_p_M - 2 ); }

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent ) { return QuotientRing<INT>::template Power<T>( n , exponent ); }
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n ) { return QuotientRing<INT>::Inverse( n ); }

template <typename INT , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , QuotientRing<INT>& n ) { INT m; is >> m; n = m; return is; }
template <typename INT , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const QuotientRing<INT>& n ) { return os << n.Represent(); }
