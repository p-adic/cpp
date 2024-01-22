// c:/Users/user/Documents/Programming/Mathematics/Algebra/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename U> inline PointedSet<U>::PointedSet( const U& b_U ) : m_b_U( b_U ) {}
template <typename U> inline const U& PointedSet<U>::Point() const noexcept { return m_b_U; }
template <typename U> inline const U& VirtualPointedSet<U>::Unit() const noexcept { return Point(); }
template <typename U> inline const U& VirtualPointedSet<U>::Zero() const noexcept { return Point(); }
template <typename U> inline const U& VirtualPointedSet<U>::One() const noexcept { return Point(); }
template <typename U> inline const U& VirtualPointedSet<U>::Infty() const noexcept { return Point(); }
template <typename U> inline const U& VirtualPointedSet<U>::size() const noexcept { return Point(); }

template <typename U , typename F_U> inline AbstractNSet<U,F_U>::AbstractNSet( F_U f_U ) : m_f_U( move( f_U ) ) { static_assert( is_invocable_r_v<U,F_U,U> ); }
template <typename U , typename F_U> inline U AbstractNSet<U,F_U>::Transfer( const U& u ) { return m_f_U( u ); }
template <typename U> inline U VirtualNSet<U>::Inverse( const U& u ) { return Transfer( u ); }

template <typename U , typename M_U> inline AbstractMagma<U,M_U>::AbstractMagma( M_U m_U ) : m_m_U( move( m_U ) ) { static_assert( is_invocable_r_v<U,M_U,U,U> ); }
template <typename U , typename M_U> inline U AbstractMagma<U,M_U>::Product( const U& u0 , const U& u1 ) { return m_m_U( u0 , u1 ); }
template <typename U> inline U VirtualMagma<U>::Sum( const U& u0 , const U& u1 ) { return Product( u0 , u1 ); }
