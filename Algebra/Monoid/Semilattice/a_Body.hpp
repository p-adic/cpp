// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline U VirtualMeetSemilattice<U>::Meet( U u0 , const U& u1 ) { return this->Product( move( u0 ) , u1 ); }
template <typename U> inline MinSemilattice<U>::MinSemilattice( U infty_U ) : PointedSet<U>( move( infty_U ) ) {}
template <typename U> inline MaxSemilattice<U>::MaxSemilattice( U zero_U ) : PointedSet<U>( move( zero_U ) ) {}

template <typename U> inline U MinSemilattice<U>::Product( U u0 , const U& u1 ) { return u0 < u1 ? move( u0 ) : u1; }
template <typename U> inline U MaxSemilattice<U>::Product( U u0 , const U& u1 ) { return u1 < u0 ? move( u0 ) : u1; }
