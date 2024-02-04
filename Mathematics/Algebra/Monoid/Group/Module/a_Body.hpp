// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename R , typename U , typename O_U , typename M_U , typename I_U> inline AbstractModule<R,U,O_U,M_U,I_U>::AbstractModule( const R& dummy , O_U& o_U , M_U& m_U , const U& e_U , I_U& i_U ) : AbstractGroup<U,M_U,I_U>( m_U , e_U , i_U ) , m_o_U( o_U ) { static_assert( is_invocable_r_v<U,O_U,R,U> ); }

template <typename R , typename U , typename O_U , typename M_U , typename I_U> inline U AbstractModule<R,U,O_U,M_U,I_U>::Act( const R& r , const U& u ) { return m_o_U.Act( r , u ); }
template <typename R , typename U> inline U Module<R,U>::Act( const R& r , const U& u ) { return r * u; }
