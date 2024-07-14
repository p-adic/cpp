// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L2/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../../../../Utility/Tuple/a_Body.hpp"

template <typename INT> inline INT L22( const INT& x , const INT& y ) { return x * x + y * y; }
template <typename INT> inline INT L22( const pair<INT,INT>& v ) { return L22( v.first , v.second ); }

template <typename INT> inline INT L22_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return L22( x0 - x1 , y0 - y1 ); }
template <typename INT> inline INT L22_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return L22( v0 - v1 ); }

template <typename INT> inline double L2( const INT& x , const INT& y ) { return sqrt( L22( x , y ) ); }
template <typename INT> inline double L2( const pair<INT,INT>& v ) { return sqrt( L22( v ) ); }

template <typename INT> inline double L2_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return sqrt( L22_Distance( x0 , y0 , x1 , y1 ) ); }
template <typename INT> inline double L2_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return sqrt( L22_Distance( v0 , v1 ) ); }
