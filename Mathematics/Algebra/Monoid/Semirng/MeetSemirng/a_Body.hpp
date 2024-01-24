// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/MeetSemirng/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../Semilattice/a_Body.hpp"

template <typename U , typename SEMIGROUP> inline AbstractTropicalSemirng<U,SEMIGROUP>::AbstractTropicalSemirng( const U& infty_U , SEMIGROUP M ) : AbstractSemirng<U,MinSemilattice<U>,SEMIGROUP>( MinSemilattice<U>( infty_U ) , move( M ) ) {}
template <typename U> inline AdditiveTropicalSemirng<U>::AdditiveTropicalSemirng( const U& infty_U ) : AbstractTropicalSemirng<U,AdditiveMagma<U>>( infty_U , AdditiveMagma<U>() ) {}
template <typename U> inline MultiplicativeTropicalSemirng<U>::MultiplicativeTropicalSemirng( const U& infty_U ) : AbstractTropicalSemirng<U,MultiplicativeMagma<U>>( infty_U , MultiplicativeMagma<U>() ) {}

template <typename U , typename MEET_SEMILATTICE , typename SEMIGROUP> inline const U& VirtualMeetSemirng<U,MEET_SEMILATTICE,SEMIGROUP>::Infty() { return this->Zero(); }
template <typename U , typename MEET_SEMILATTICE , typename SEMIGROUP> inline U VirtualMeetSemirng<U,MEET_SEMILATTICE,SEMIGROUP>::Meet( const U& u0 , const U& u1 ) { return this->Sum( u0 , u1 ); }
template <typename U , typename SEMIGROUP> inline U AbstractTropicalSemirng<U,SEMIGROUP>::Product( const U& u0 , const U& u1 ) { const U& infty = this->Infty(); return u0 < infty && u1 < infty ? this->MultiplicativeSemigroup().Product( u0 , u1 ) : infty; }
