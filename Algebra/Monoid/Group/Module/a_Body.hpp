// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename R , typename MAGMA> inline RegularRSet<R,MAGMA>::RegularRSet( MAGMA magma ) : MAGMA( move( magma ) ) {}
template <typename R , typename U , typename O_U> inline AbstractRSet<R,U,O_U>::AbstractRSet( const R& dummy0 , const U& dummy1 , O_U o_U ) : m_o_U( move( o_U ) ) { static_assert( is_invocable_r_v<U,O_U,R,U> ); }
template <typename R , typename U , typename O_U , typename GROUP> inline AbstractModule<R,U,O_U,GROUP>::AbstractModule( const R& dummy , O_U o_U , GROUP M ) : AbstractRSet<R,U,O_U>( dummy , M.One() , move( o_U ) ) , GROUP( move( M ) ) { static_assert( is_same_v<U,inner_t<GROUP>> ); }

template <typename R , typename U , typename O_U> inline AbstractRSet<R,U,O_U>& AbstractRSet<R,U,O_U>::operator=( const AbstractRSet<R,U,O_U>& ) noexcept { return *this; }

template <typename U , typename MAGMA> inline U RegularRSet<U,MAGMA>::Action( const U& r , U u ) { return this->Product( r , move( u ) ); }
template <typename R , typename U , typename O_U> inline U AbstractRSet<R,U,O_U>::Action( const R& r , U u ) { return m_o_U( r , move( u ) ); }
template <typename R , typename U> inline U Module<R,U>::Action( const R& r , U u ) { return move( u *= r ); }

template <typename R , typename U> inline U VirtualRSet<R,U>::Power( U u , const R& r ) { return Action( r , move( u ) ); }
template <typename R , typename U> inline U VirtualRSet<R,U>::ScalarProduct( const R& r , U u ) { return Action( r , move( u ) ); }
