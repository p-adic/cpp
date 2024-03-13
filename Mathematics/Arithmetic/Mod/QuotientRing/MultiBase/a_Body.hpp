// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/MultiBase/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> const INT* MultiBaseQuotientRing<INT>::g_p_M = nullptr;
template <typename INT> inline MultiBaseQuotientRing<INT>::MultiBaseQuotientRing() noexcept : m_n() , m_p_M( g_p_M ) {}
template <typename INT> inline MultiBaseQuotientRing<INT>::MultiBaseQuotientRing( const INT& n , const INT* const& p_M ) noexcept : m_n( p_M == nullptr ? n : n % *p_M ) , m_p_M( p_M ) {}
template <typename INT> inline MultiBaseQuotientRing<INT>::MultiBaseQuotientRing( const MultiBaseQuotientRing<INT>& n ) noexcept : m_n( n.m_n ) , m_p_M( n.m_p_M ) {}

template <typename INT> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator+=( const MultiBaseQuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n += n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> template <typename T> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator+=( const T& n ) noexcept { m_p_M == nullptr ? m_n += n : ( m_n += n % *m_p_M ) %= *m_p_M; return *this; }
template <typename INT> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator-=( const MultiBaseQuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n -= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> template <typename T> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator-=( const T& n ) noexcept { m_p_M == nullptr ? m_n -= n : ( m_n -= n % *m_p_M ) %= *m_p_M; return *this; }
template <typename INT> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator*=( const MultiBaseQuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n *= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> template <typename T> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator*=( const T& n ) noexcept { m_p_M == nullptr ? m_n *= n : ( m_n *= n % *m_p_M ) %= *m_p_M; return *this; }
template <typename INT> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator/=( const MultiBaseQuotientRing<INT>& n ) { if( m_p_M == nullptr ){ if( n.m_p_M == nullptr ){ assert( n.m_n != 0 ); m_n /= n.m_n; return *this; } else { m_p_M = n.m_p_M; } } return operator*=( Inverse( MultiBaseQuotientRing<INT>( n.m_n , m_p_M ) ) ); }
template <typename INT> template <typename T> inline MultiBaseQuotientRing<INT>& MultiBaseQuotientRing<INT>::operator/=( const T& n ) { if( m_p_M == nullptr ){ assert( n.m_n != 0 ); m_n /= n.m_n; return *this; } return operator*=( Inverse( Q( n.m_n , m_p_M ) ) ); }

template <typename INT> inline bool MultiBaseQuotientRing<INT>::operator==( const MultiBaseQuotientRing<INT>& n ) const noexcept { return m_p_M == n.m_p_M && m_n == n.m_n; }
template <typename INT> template <typename T> inline bool MultiBaseQuotientRing<INT>::operator==( const T& n ) const noexcept { return m_n == n; }
template <typename INT> template <typename T> inline bool MultiBaseQuotientRing<INT>::operator!=( const T& n ) const noexcept { return !operator==( n ); }

template <typename INT> template<typename T> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator+( const T& n ) const noexcept { return MultiBaseQuotientRing<INT>( *this ).operator+=( n ); }
template <typename INT> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator-() const noexcept { return MultiBaseQuotientRing<INT>( -m_n , m_p_M ); }
template <typename INT> template<typename T> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator-( const T& n ) const noexcept { return MultiBaseQuotientRing<INT>( *this ).operator-=( n ); }
template <typename INT> template<typename T> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator*( const T& n ) const noexcept { return MultiBaseQuotientRing<INT>( *this ).operator*=( n ); }
template <typename INT> template<typename T> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator/( const T& n ) const { return MultiBaseQuotientRing<INT>( *this ).operator/=( n ); }
  
template <typename INT> template <typename T>
MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::operator^( T exponent )
{

  MultiBaseQuotientRing<INT> answer{ 1 , m_p_M };
  MultiBaseQuotientRing<INT> power{ *this };
  exponent < 0 ? ( exponent = -exponent , power = Inverse( power ) ) : power;

  while( exponent > 0 ){

    if( ( exponent & 1 ) == 1 ){

      answer *= power;

    }

    power *= power;
    exponent >>= 1;

  }

  return answer;

}

template <typename INT> inline const INT& MultiBaseQuotientRing<INT>::Represent() const noexcept { return m_n; }
template <typename INT> inline const INT& MultiBaseQuotientRing<INT>::GetModulo() const noexcept { static const INT zero{ 0 }; return m_p_M == nullptr ? zero : *m_p_M; }
template <typename INT> inline void MultiBaseQuotientRing<INT>::SetModulo( const INT* const& p_M ) noexcept { m_p_M = p_M; if( m_p_M != nullptr ){ m_n %= *m_p_M; } }
template <typename INT> inline const INT& MultiBaseQuotientRing<INT>::GetStaticModulo() noexcept { static const INT zero{ 0 }; return g_p_M == nullptr ? zero : *g_p_M; }
template <typename INT> inline void MultiBaseQuotientRing<INT>::SetStaticModulo( const INT* const& p_M ) noexcept { g_p_M = p_M; }

template <typename INT> inline MultiBaseQuotientRing<INT> MultiBaseQuotientRing<INT>::Inverse( const MultiBaseQuotientRing<INT>& n ) { assert( n.m_p_M != nullptr ); return n ^ ( *( n.m_p_M ) - 2 ); }

template <typename INT , typename T> inline MultiBaseQuotientRing<INT> Power( const MultiBaseQuotientRing<INT>& n , T exponent ) { return n ^ exponent; }
template <typename INT> inline MultiBaseQuotientRing<INT> Inverse( const MultiBaseQuotientRing<INT>& n ) { return MultiBaseQuotientRing<INT>::Inverse( n ); }

template <typename INT , class Traits> inline basic_istream<char,Traits>& operator>>( basic_istream<char,Traits>& is , MultiBaseQuotientRing<INT>& n ) { INT m; is >> m; n = m; return is; }
template <typename INT , class Traits> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const MultiBaseQuotientRing<INT>& n ) { return os << n.Represent(); }
