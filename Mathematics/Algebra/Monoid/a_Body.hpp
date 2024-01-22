// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline MultiplicativeMonoid<U>::MultiplicativeMonoid( const U& e_U ) : PointedSet<U>( e_U ) {}
template <typename U , typename M_U> inline AbstractMonoid<U,M_U>::AbstractMonoid( M_U m_U , const U& e_U ) : AbstractMagma<U,M_U>( move( m_U ) ) , PointedSet<U>( e_U ) {}

template <typename U> inline U AdditiveMonoid<U>::Product( const U& u0 , const U& u1 ) { return u0 + u1; }
template <typename U> inline U MultiplicativeMonoid<U>::Product( const U& u0 , const U& u1 ) { return u0 * u1; }
template <typename U , typename M_U> inline U AbstractMonoid<U,M_U>::Product( const U& u0 , const U& u1 ) { return m_m_U( u0 , u1 ); }
