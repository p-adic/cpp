// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linf/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename INT> inline INT Linfty( const INT& x , const INT& y ) { return max( abs( x ) , abs( y ) ); }
template <typename INT> inline INT Linfty( const pair<INT,INT>& v ) { return Linfty( v.first , v.second ); }

template <typename INT> inline INT Linfty_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 ) { return Linfty( x0 - x1 , y0 - y1 ); }
template <typename INT> inline INT Linfty_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 ) { return Linfty( v0.first - v1.first , v0.second - v1.second ); }
