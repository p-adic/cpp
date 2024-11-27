// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U> inline MultiplicativeMonoid<U>::MultiplicativeMonoid( U e_U ) : PointedSet<U>( move( e_U ) ) {}
template <typename U , typename M_U> inline AbstractMonoid<U,M_U>::AbstractMonoid( M_U m_U , U e_U ) : AbstractMagma<U,M_U>( move( m_U ) ) , PointedSet<U>( move( e_U ) ) {}
