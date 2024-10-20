// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Shift/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

#ifdef DEBUG
  #include "../../../../Mathematics/Arithmetic/Mod/ConstexprModulo/Debug/a_Body.hpp"
#else
  #include "../../../../Mathematics/Arithmetic/Mod/ConstexprModulo/a_Body.hpp"
#endif

#include "../../../../Mathematics/Arithmetic/Divisor/GCD/a_Body.hpp"

template <typename MODINT , typename INT , typename CODE> inline ShiftableRollingHash<MODINT,INT,CODE>::ShiftableRollingHash() : RollingHash<MODINT,INT,CODE>( GetPrimitiveRoot() ) , m_power{ MODINT::Derepresent( 1 ) }
{

  constexpr const decltype( MODINT::GetModulo() ) P = MODINT::GetModulo();
  static_assert( P == 999309403 || P == 999300121 || P == 999300017 );
  m_power[1] = MODINT::Derepresent( P == 999309403 ? 1102168 : P == 999300121 ? 75873362 : 31458519 );
  
  for( int i = 2 ; i < 26 ; i++ ){

    m_power[i] = m_power[i-1] * m_power[1];

  }

}

template <typename MODINT , typename INT , typename CODE> inline CODE ShiftableRollingHash<MODINT,INT,CODE>::Shift( const Mod<26>& shift , CODE c ) const { get<0>( c ) *= m_power[shift.Represent()]; return move( c ); }

template <typename MODINT , typename INT , typename CODE> MODINT ShiftableRollingHash<MODINT,INT,CODE>::Twist( const ll& c ) { assert( 'A' <= c && c <= 'z' ); return m_power[c - ( c < 'a' ? 'A' : 'a' )]; }

template <typename MODINT , typename INT , typename CODE>
MODINT ShiftableRollingHash<MODINT,INT,CODE>::GetPrimitiveRoot()
{

  constexpr const decltype( MODINT::GetModulo() ) P = MODINT::GetModulo();
  constexpr const MODINT pr = MODINT::Derepresent( P == 999309403 ? 2 : P == 999300121 ? 22 : 5 );
  int exponent = GetRand( 1 , P - 1 );
  return Power( pr , move( exponent /= GCD( exponent , P - 1 ) ) );

}
