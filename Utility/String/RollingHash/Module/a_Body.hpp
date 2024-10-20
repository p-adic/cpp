// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Group/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename MODINT , typename INT , typename CODE> inline RollingHashModule<MODINT,INT,CODE>::RollingHashModule() : PointedSet<CODE>( { 0 , 1 , 0 } ) { static_assert( is_same_v<CODE,tuple<MODINT,MODINT,INT>> ); }

template <typename MODINT , typename INT , typename CODE> inline CODE RollingHashModule<MODINT,INT,CODE>::Product( CODE code0 , const CODE& code1 ) { return RollingHash<MODINT,INT>::Concatenate( move( code0 ) , code1 ); }
template <typename MODINT , typename INT , typename CODE> inline CODE RollingHashModule<MODINT,INT,CODE>::Transfer( const CODE& code ) { MODINT p = 1 / get<1>( code ); return { - get<0>( code ) * p , p , -get<2>( code ) }; }
template <typename MODINT , typename INT , typename CODE> inline CODE RollingHashModule<MODINT,INT,CODE>::Action( const int& r , CODE code ) { return RollingHash<MODINT,INT>::Fold( move( code ) , r ); }

#include "../a_Body.hpp"
