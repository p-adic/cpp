// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Semirng/Ring/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U, typename GROUP , typename MONOID> inline VirtualRing<U,GROUP,MONOID>::VirtualRing( GROUP R0 , MONOID R1 ) : m_R0( move( R0 ) ) , m_R1( move( R1 ) ) {}
template <typename U> inline Ring<U>::Ring( const U& one_U ) : VirtualRing<U,AdditiveGroup<U>,MultiplicativeMonoid<U>>( AdditiveGroup<U>() , MultiplicativeMonoid<U>( one_U ) ) {}
template <typename U , typename A_U , typename I_U , typename M_U> inline AbstractRing<U,A_U,I_U,M_U>::AbstractRing( A_U& a_U , const U& z_U , I_U& i_U , M_U& m_U , const U& e_U ) : VirtualRing<U,AbstractGroup<U,A_U,I_U>,AbstractMonoid<U,M_U>>( AbstractGroup<U,A_U,I_U>( a_U , z_U , i_U ) , AbstractMonoid<U,M_U>( m_U , e_U ) ) {}

template <typename U, typename GROUP , typename MONOID> inline U VirtualRing<U,GROUP,MONOID>::Sum( const U& u0 , const U& u1 ) { return m_R0.Sum( u0 , u1 ); }
template <typename U, typename GROUP , typename MONOID> inline const U& VirtualRing<U,GROUP,MONOID>::Zero() const noexcept { return m_R0.Zero(); }
template <typename U, typename GROUP , typename MONOID> inline U VirtualRing<U,GROUP,MONOID>::Inverse( const U& u ) { return m_R0.Inverse( u ); }
template <typename U, typename GROUP , typename MONOID> inline U VirtualRing<U,GROUP,MONOID>::Product( const U& u0 , const U& u1 ) { return m_R1.Product( u0 , u1 ); }
template <typename U, typename GROUP , typename MONOID> inline const U& VirtualRing<U,GROUP,MONOID>::One() const noexcept { return m_R1.One(); }
template <typename U, typename GROUP , typename MONOID> inline GROUP& VirtualRing<U,GROUP,MONOID>::AdditiveGroup() noexcept { return m_R0; }
template <typename U, typename GROUP , typename MONOID> inline MONOID& VirtualRing<U,GROUP,MONOID>::MultiplicativeMonoid() noexcept { return m_R1; }
