// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline QuotientRing<INT>::QuotientRing() noexcept : m_n() , m_p_M( nullptr ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const INT& n , const INT* const& p_M ) noexcept : m_n( p_M == nullptr ? n : n % *p_M ) , m_p_M( p_M ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const QuotientRing<INT>& n ) noexcept : m_n( n.m_n ) , m_p_M( n.m_p_M ) {}

template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator+=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n += n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator+=( const INT& n ) noexcept { m_n += n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator-=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n -= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator-=( const INT& n ) noexcept { m_n -= n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator*=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n *= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator*=( const INT& n ) noexcept { m_n *= n; if( m_p_M != nullptr ){ m_n %= *m_p_M; } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator/=( const QuotientRing<INT>& n ) { if( m_p_M == nullptr ){ if( n.m_p_M == nullptr ){ assert( n.m_n != 0 ); m_n /= n.m_n; return *this; } else { m_p_M = n.m_p_M; } } return operator*=( Inverse( QuotientRing<INT>( n.m_n , m_p_M ) ) ); }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator/=( const INT& n ) { if( m_p_M == nullptr ){ assert( n.m_n != 0 ); m_n /= n.m_n; return *this; } return operator*=( Inverse( Q( n.m_n , m_p_M ) ) ); }

template <typename INT> inline bool QuotientRing<INT>::operator==( const QuotientRing<INT>& n ) const noexcept { return m_p_M == n.m_p_M && m_n == n.m_n; }
template <typename INT> inline bool QuotientRing<INT>::operator!=( const QuotientRing<INT>& n ) const noexcept { return !operator==( n ); }

template <typename INT> template<typename T> inline QuotientRing<INT> QuotientRing<INT>::operator+( const T& n ) const noexcept { return QuotientRing<INT>( *this ).operator+=( n ); }
template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::operator-() const noexcept { return QuotientRing<INT>( -m_n , m_p_M ); }
template <typename INT> template<typename T> inline QuotientRing<INT> QuotientRing<INT>::operator-( const T& n ) const noexcept { return QuotientRing<INT>( *this ).operator-=( n ); }
template <typename INT> template<typename T> inline QuotientRing<INT> QuotientRing<INT>::operator*( const T& n ) const noexcept { return QuotientRing<INT>( *this ).operator*=( n ); }
template <typename INT> template<typename T> inline QuotientRing<INT> QuotientRing<INT>::operator/( const T& n ) const { return QuotientRing<INT>( *this ).operator/=( n ); }
  
template <typename INT> inline const INT& QuotientRing<INT>::Represent() const noexcept { return m_n; }
template <typename INT> inline const INT& QuotientRing<INT>::GetModulo() const noexcept { static const INT zero{ 0 }; return m_p_M == nullptr ? zero : *m_p_M; }
template <typename INT> inline void QuotientRing<INT>::SetModulo( const INT* const& p_M ) noexcept { m_p_M = p_M; if( m_p_M != nullptr ){ m_n %= *m_p_M; } }

template <typename INT> template <typename T>
QuotientRing<INT> QuotientRing<INT>::Power( const QuotientRing<INT>& n , T exponent )
{

  QuotientRing<INT> answer{ 1 , n.m_p_M };
  QuotientRing<INT> power{ n };

  while( exponent != 0 ){

    if( exponent % 2 == 1 ){

      answer *= power;

    }

    power *= power;
    exponent /= 2;

  }

  return answer;

}

template <typename INT> inline QuotientRing<INT> QuotientRing<INT>::Inverse( const QuotientRing<INT>& n ) { assert( n.m_p_M != nullptr ); return Power( n , *( n.m_p_M ) - 2 ); }

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , T exponent ) { return QuotientRing<INT>::template Power<T>( n , exponent ); }
template <typename INT> inline QuotientRing<INT> Inverse( const QuotientRing<INT>& n ) { return QuotientRing<INT>::Inverse( n ); }
