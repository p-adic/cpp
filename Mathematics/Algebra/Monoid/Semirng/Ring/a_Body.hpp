// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename GROUP , typename MONOID> inline AbstractRing<U,GROUP,MONOID>::AbstractRing( GROUP R0 , MONOID R1 ) : AbstractSemirng<U,GROUP,MONOID>( move( R0 ) , move( R1 ) ) {}
template <typename U> inline Ring<U>::Ring( U one_U ) :AbstractRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>( AdditiveGroup<U>() , MultiplicativeMonoid<U>( move( one_U ) ) ) {}

template <typename U , typename GROUP , typename MONOID> inline U AbstractRing<U,GROUP,MONOID>::Inverse( const U& u ) { return this->m_R0.Inverse( u ); }
template <typename U , typename GROUP , typename MONOID> inline const U& AbstractRing<U,GROUP,MONOID>::One() const noexcept { return this->m_R1.One(); }

template <typename U , typename GROUP , typename MONOID> inline GROUP& VirtualRing<U,GROUP,MONOID>::AdditiveGroup() noexcept { return this->AdditiveMonoid(); }
template <typename U , typename GROUP , typename MONOID> inline MONOID& VirtualRing<U,GROUP,MONOID>::MultiplicativeMonoid() noexcept { return this->MultiplicativeSemigroup(); }
