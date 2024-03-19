// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Semilattice/a_Body.hpp"

template <typename U , typename SEMIGROUP> inline AbstractTropicalSemirng<U,SEMIGROUP>::AbstractTropicalSemirng( U infty_U , SEMIGROUP M ) : AbstractSemirng<U,MinSemilattice<U>,SEMIGROUP>( MinSemilattice<U>( move( infty_U ) ) , move( M ) ) {}
template <typename U> inline AdditiveTropicalSemirng<U>::AdditiveTropicalSemirng( U infty_U ) : AbstractTropicalSemirng<U,AdditiveMagma<U>>( move( infty_U ) , AdditiveMagma<U>() ) {}
template <typename U> inline MultiplicativeTropicalSemirng<U>::MultiplicativeTropicalSemirng( U infty_U ) : AbstractTropicalSemirng<U,MultiplicativeMagma<U>>( move( infty_U ) , MultiplicativeMagma<U>() ) {}

template <typename U , typename MEET_SEMILATTICE , typename SEMIGROUP> inline const U& VirtualMeetSemirng<U,MEET_SEMILATTICE,SEMIGROUP>::Infty() { return this->Zero(); }
template <typename U , typename MEET_SEMILATTICE , typename SEMIGROUP> inline U VirtualMeetSemirng<U,MEET_SEMILATTICE,SEMIGROUP>::Meet( U u0 , const U& u1 ) { return this->Sum( move( u0 ) , u1 ); }
template <typename U , typename SEMIGROUP> inline U AbstractTropicalSemirng<U,SEMIGROUP>::Product( U u0 , const U& u1 ) { const U& infty = this->Infty(); return u0 < infty && u1 < infty ? this->MultiplicativeSemigroup().Product( move( u0 ) , u1 ) : infty; }
