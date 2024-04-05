// c:/Users/user/Documents/Programming/Utility/Set/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Contest/Random/a_Body.hpp"

template <typename T , template <typename...> typename MOD> inline size_t hash<MOD<T>>::operator()( const MOD<T>& n ) const { static const hash<T> h; return h( n.Represent() ); }
template <typename T0 , typename T1 , template <typename...> typename PAIR> inline size_t hash<PAIR<T0,T1>>::operator()( const PAIR<T0,T1>& n ) const { static const size_t seed = GetRand( 1e3 , 1e8 ); static const hash<T0> h0; static const hash<T1> h1; return ( h0( get<0>( n ) ) + seed ) ^ h1( get<1>( n ) ); }
template <typename T0 , typename T1 , typename T2> inline size_t hash<tuple<T0,T1,T2>>::operator()( const tuple<T0,T1,T2>& n ) const { static const size_t seed = GetRand( 1e3 , 1e8 ); static const hash<pair<T0,T1>> h01; static const hash<T2> h2; return ( h01( { get<0>( n ) , get<1>( n ) } ) + seed ) ^ h2( get<2>( n ) ); }
