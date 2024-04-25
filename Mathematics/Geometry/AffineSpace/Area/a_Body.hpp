// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Area/a_Body.hpp

#pragma once
#include "a.hpp"

inline ll Area_ll( const ll& x0 , const ll& y0 , const ll& x1 , const ll& y1 , const ll& x2 , const ll& y2 ) { return AREA_OF_TRIANGLE; }
template <typename INT> inline ll Area( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& x2 , const INT& y2 ) { return Area_ll( x0 ,y0 , x1 ,y1 , x2 ,y2 ); }
inline double Area( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& x2 , const double& y2 ) { return AREA_OF_TRIANGLE; }
template <typename INT> inline ll Area( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& v2 ) { return CALL_AREA_OF_TRIANGLE; }
inline double Area( const pair<double,double>& v0 , const pair<double,double>& v1 , const pair<double,double>& v2 ) { return CALL_AREA_OF_TRIANGLE; }
