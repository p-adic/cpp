// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/L2/a.hpp

#pragma once


// L2ノルム2乗（O(1)）
template <typename INT> inline INT L22( const INT& x , const INT& y );
template <typename INT> inline INT L22( const pair<INT,INT>& v );

// L2距離2乗（O(1)）
template <typename INT> inline INT L22_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline INT L22_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );

// L2ノルム（O(1)）
template <typename INT> inline double L2( const INT& x , const INT& y );
template <typename INT> inline double L2( const pair<INT,INT>& v );

// L2距離（O(1)）
template <typename INT> inline double L2_Distance( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 );
template <typename INT> inline double L2_Distance( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 );
