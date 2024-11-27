// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename MONOID , typename SEMIGROUP> inline AbstractSemirng<U,MONOID,SEMIGROUP>::AbstractSemirng( MONOID R0 , SEMIGROUP R1 ) : m_R0( move( R0 ) ) , m_R1( move( R1 ) ) {}
template <typename U> inline Semirng<U>::Semirng() : AbstractSemirng<U,AdditiveMonoid<U>,MultiplicativeMagma<U>>( AdditiveMonoid<U>() , MultiplicativeMagma() ) {}

template <typename U , typename MONOID , typename SEMIGROUP> inline U AbstractSemirng<U,MONOID,SEMIGROUP>::Sum( U u0 , const U& u1 ) { return m_R0.Sum( move( u0 ) , u1 ); }
template <typename U , typename MONOID , typename SEMIGROUP> inline const U& AbstractSemirng<U,MONOID,SEMIGROUP>::Zero() const noexcept { return m_R0.Zero(); }
template <typename U , typename MONOID , typename SEMIGROUP> inline U AbstractSemirng<U,MONOID,SEMIGROUP>::Product( U u0 , const U& u1 ) { return m_R1.Product( move( u0 ) , u1 ); }
template <typename U , typename MONOID , typename SEMIGROUP> inline MONOID& AbstractSemirng<U,MONOID,SEMIGROUP>::AdditiveMonoid() noexcept { return m_R0; }
template <typename U , typename MONOID , typename SEMIGROUP> inline SEMIGROUP& AbstractSemirng<U,MONOID,SEMIGROUP>::MultiplicativeSemigroup() noexcept { return m_R1; }
