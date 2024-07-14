// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linf/a.hpp

#pragma once

// L∞ノルム（O(1)）
template <typename INT> inline INT Linfty( const INT& x , const INT& y );
template <typename INT> inline INT Linfty( const pair<INT,INT>& v );

// L∞距離（O(1)）
template <typename INT> inline INT Linfty_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT Linfty_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
