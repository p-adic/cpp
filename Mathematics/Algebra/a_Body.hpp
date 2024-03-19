// c:/Users/user/Documents/Programming/Mathematics/Algebra/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U> inline PointedSet<U>::PointedSet( U b_U ) : m_b_U( move( b_U ) ) {}
template <typename U> inline const U& PointedSet<U>::Point() const noexcept { return m_b_U; }
template <typename U> inline U& PointedSet<U>::Point() noexcept { return m_b_U; }
DEFINITION_OF_CPOINT( Unit );
DEFINITION_OF_CPOINT( Zero );
DEFINITION_OF_CPOINT( One );
DEFINITION_OF_CPOINT( Infty );
DEFINITION_OF_POINT( init );
DEFINITION_OF_POINT( root );

template <typename U , typename F_U> inline AbstractNSet<U,F_U>::AbstractNSet( F_U f_U ) : m_f_U( move( f_U ) ) { static_assert( is_invocable_r_v<U,F_U,U> ); }
template <typename U , typename F_U> inline U AbstractNSet<U,F_U>::Transfer( const U& u ) { return m_f_U( u ); }
template <typename U> inline U VirtualNSet<U>::Inverse( const U& u ) { return Transfer( u ); }

template <typename U , typename M_U> inline AbstractMagma<U,M_U>::AbstractMagma( M_U m_U ) : m_m_U( move( m_U ) ) { static_assert( is_invocable_r_v<U,M_U,U,U> ); }


template <typename U> inline U AdditiveMagma<U>::Product( U u0 , const U& u1 ) { return move( u0 += u1 ); }
template <typename U> inline U MultiplicativeMagma<U>::Product( U u0 , const U& u1 ) { return move( u0 *= u1 ); }
template <typename U , typename M_U> inline U AbstractMagma<U,M_U>::Product( U u0 , const U& u1 ) { return m_m_U( move( u0 ) , u1 ); }
template <typename U> inline U VirtualMagma<U>::Sum( U u0 , const U& u1 ) { return Product( move( u0 ) , u1 ); }

