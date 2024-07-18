// c:/Users/user/Documents/Programming/Mathematics/Function/MaxTwoAryHierarchy/LinearFunction/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename INT> inline constexpr INT LinearFunction<INT>::operator()( const INT& u , const INT& v , const INT& x ) { return u * x + v; }
template <typename INT> inline INT LinearFunctionIntersection<INT>::Intersection( const INT& u0 , const INT& v0 , const INT& u1 , const INT& v1 ) { assert( u0 < u1 ); auto diff_u = u1 - u0; return ( v0 - v1 + diff_u - 1 ) / diff_u; }
template <typename INT> inline INT LinearFunctionIntersection<INT>::Intersection( const Reversed<INT>& u0 , const Reversed<INT>& v0 , const Reversed<INT>& u1 , const Reversed<INT>& v1 ) { assert( u0 < u1 ); auto diff_u = u1 - u0; return ( ( v0 - v1 + diff_u - 1 ) / diff_u ).Get(); }

template <typename INT> inline MaxLinearFunction<INT>::MaxLinearFunction( const INT& x_min , const INT& x_max ) : VirtualMaxTwoAryHierarchy<INT,INT,INT,LinearFunction<INT>>( LinearFunction<INT>() , x_min , x_max , x_min , x_max ) , LinearFunctionIntersection<INT>() {}
template <typename INT> inline MinLinearFunction<INT>::MinLinearFunction( const INT& x_min , const INT& x_max ) : VirtualMinTwoAryHierarchy<INT,INT,INT,LinearFunction<INT>>( LinearFunction<INT>() , x_min , x_max , x_min , x_max ) , LinearFunctionIntersection<INT>() {}
