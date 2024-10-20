// c:/Users/user/Documents/Programming/Utility/String/RollingHash/Shift/BiModule/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../../../../Mathematics/Algebra/Monoid/Group/Module/a_Body.hpp"

template <typename MODINT , typename INT , typename CODE> inline ShiftableRollingHashBiModule<MODINT,INT,CODE>::ShiftableRollingHashBiModule( const ShiftableRollingHash<MODINT,INT,CODE>& srh ) : PointedSet<CODE>( { 0 , 1 , 0 } ) , m_p_srh{ &srh } { static_assert( is_same_v<CODE,tuple<MODINT,MODINT,INT>> ); }

template <typename MODINT , typename INT , typename CODE> inline CODE ShiftableRollingHashBiModule<MODINT,INT,CODE>::Product( CODE code0 , const CODE& code1 ) { return ShiftableRollingHash<MODINT,INT>::Concatenate( move( code0 ) , code1 ); }
template <typename MODINT , typename INT , typename CODE> inline CODE ShiftableRollingHashBiModule<MODINT,INT,CODE>::Transfer( const CODE& code ) { MODINT p = 1 / get<1>( code ); return { - get<0>( code ) * p , p , -get<2>( code ) }; }
template <typename MODINT , typename INT , typename CODE> inline CODE ShiftableRollingHashBiModule<MODINT,INT,CODE>::LAction( const Mod<26>& l , CODE code ) { return m_p_srh->Shift( l , move( code ) ); }
template <typename MODINT , typename INT , typename CODE> inline CODE ShiftableRollingHashBiModule<MODINT,INT,CODE>::RAction( CODE code , const int& r ) { return ShiftableRollingHash<MODINT,INT>::Fold( move( code ) , r ); }
