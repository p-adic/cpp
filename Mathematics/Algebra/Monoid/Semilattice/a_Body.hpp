// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semilattice/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline U VirtualMeetSemilattice<U>::Meet( const U& u0 , const U& u1 ) { return this->Product( u0 , u1 ); }

template <typename U> inline MinSemilattice<U>::MinSemilattice( const U& infty_U ) : PointedSet<U>( infty_U ) {}

template <typename U> inline U MinSemilattice<U>::Product( const U& u0 , const U& u1 ) { return u0 < u1 ? u0 : u1; }
