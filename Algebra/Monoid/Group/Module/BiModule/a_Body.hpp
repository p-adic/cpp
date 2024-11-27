// c:/Users/user/Documents/Programming/Mathematics/Algebra/Monoid/Group/Module/BiModule/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../a_Body.hpp"

template <typename L , typename R , typename U , typename O_U_L , typename O_U_R , typename GROUP> inline AbstractBiModule<L,R,U,O_U_L,O_U_R,GROUP>::AbstractBiModule( const L& dummy_l , const R& dummy_r , O_U_L o_U_L , O_U_R o_U_R , GROUP M ) : GROUP( move( M ) ) , m_o_U_L( move( o_U_L ) ) , m_o_U_R( move( o_U_R ) ) { static_assert( is_same_v<U,inner_t<GROUP>> && is_invocable_r_v<U,O_U_L,const L&,U> && is_invocable_r_v<U,O_U_R,U,const R&> ); }

template <typename L , typename R , typename U , typename O_U_L , typename O_U_R , typename GROUP> inline U AbstractBiModule<L,R,U,O_U_L,O_U_R,GROUP>::LAction( const L& l , U u ) { return m_o_U_L( l , move( u ) ); }
template <typename L , typename R , typename U> inline U BiModule<L,R,U>::LAction( const L& l , U u ) { return move( u *= l ); }

template <typename L , typename R , typename U , typename O_U_L , typename O_U_R , typename GROUP> inline U AbstractBiModule<L,R,U,O_U_L,O_U_R,GROUP>::RAction( U u , const R& r ) { return m_o_U_R( move( u ) , r ); }
template <typename L , typename R , typename U> inline U BiModule<L,R,U>::RAction( U u , const R& r ) { return move( u *= r ); }

template <typename L , typename R , typename U> inline U VirtualBiModule<L,R,U>::ScalarProduct( const L& l , U u ) { return LAction( l , move( u ) ); }
template <typename L , typename R , typename U> inline U VirtualBiModule<L,R,U>::Power( U u , const R& r ) { return RAction( move( u ) , r ); }
