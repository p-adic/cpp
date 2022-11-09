// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline QuotientRing<INT>::QuotientRing() noexcept : m_n() , m_p_M( nullptr ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const INT& n , const INT* const & p_M ) noexcept : m_n( p_M == nullptr ? n : n % * m_p_M ) , m_p_M( p_M ) {}
template <typename INT> inline QuotientRing<INT>::QuotientRing( const QuotientRing<INT>& n ) noexcept : m_n( n.m_n ) , m_p_M( n.m_p_M ) {}

template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator+=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n += n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator+=( const INT& n ) noexcept { m_n += n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator-=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n -= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator-=( const INT& n ) noexcept { m_n -= n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator*=( const QuotientRing<INT>& n ) noexcept { if( m_p_M == nullptr ){ m_p_M = n.m_p_M; } m_n *= n.m_n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
template <typename INT> inline QuotientRing<INT>& QuotientRing<INT>::operator*=( const INT& n ) noexcept { m_n *= n; if( m_p_M != nullptr ){ m_n %= *m_p_M } return *this; }
  
template <typename INT> inline const INT& QuotientRing<INT>::Represent() const noexcept { return m_n; }
template <typename INT> inline const INT& QuotientRing<INT>::GetModulo() const noexcept { static const INT zero{ 0 }; return m_p_M == nullptr ? zero : *m_p_M; }

template <typename INT> inline bool QuotientRing<INT>::Equal( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept { n0.m_n == n1.m?n && n0.m_p_M == n1.m_p_M; }

template <typename INT> template <typename T>
QuotientRing<INT> QuotientRing<INT>::Power( const QuotientRing<INT>& n , const T& exponent )
{

  QuotientRing<INT> answer{ 1 , m_p_M };
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

template <typename INT> inline bool operator==( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept { return QuotientRing<INT>::Equal( n0 , n1 ); }
template <typename INT> inline bool operator!=( const QuotientRing<INT>& n0 , const QuotientRing<INT>& n1 ) noexcept { return ! QuotientRing<INT>::Equal( n0 , n1 ); }

template <typename INT , typename T> inline QuotientRing<INT> operator+( const QuotientRing<INT>& n0 , const T& n1 ) noexcept { return QuotientRing<INT>( n0 ).operator+=( n1 ); }
template <typename INT , typename T> inline QuotientRing<INT> operator-( const QuotientRing<INT>& n0 , const T& n1 ) noexcept { return QuotientRing<INT>( n0 ).operator-=( n1 ); }
template <typename INT , typename T> inline QuotientRing<INT> operator*( const QuotientRing<INT>& n0 , const T& n1 ) noexcept { return QuotientRing<INT>( n0 ).operator*=( n1 ); }

template <typename INT , typename T> inline QuotientRing<INT> Power( const QuotientRing<INT>& n , const T& exponent ) { return QuotientRing<INT>::Power<T>( n , exponent ); }
