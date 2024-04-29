// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Intersection/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Area/a_Body.hpp"

template <typename INT> inline int Intersect( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 )
{

  static_assert( ! is_same<INT,double>::value );
  const ll sign0 = Area( x0 , y0 , x1 , y1 , z0 , w0 ) * Area( x0 , y0 , x1 , y1 , z1 , w1 );
  const ll sign1 = Area( z0 , w0 , z1 , w1 , x0 , y0 ) * Area( z0 , w0 , z1 , w1 , x1 , y1 );
  return ( sign0 < 0 && sign1 < 0 ) ? 1 : ( sign0 == 0 || sign1 == 0 ) ? 0 : -1;

}

inline int Intersect( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& z0 , const double& w0 , const double& z1 , const double& w1 , const double& epsilon )
{

  const double sign0 = Area( x0 , y0 , x1 , y1 , z0 , w0 ) * Area( x0 , y0 , x1 , y1 , z1 , w1 );
  const double sign1 = Area( z0 , w0 , z1 , w1 , x0 , y0 ) * Area( z0 , w0 , z1 , w1 , x1 , y1 );
  return ( sign0 <= -epsilon && sign1 <= -epsilon ) ? 1 : ( ( -epsilon < sign0 && sign0 < epsilon ) || ( -epsilon < sign1 && sign1 < epsilon ) ) ? 0 : -1;

}

template <typename INT> inline int Intersect( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& w0 , const pair<INT,INT>& w1 ) { return Intersect( v0.first , v0.second , v1.first , v1.second , w0.first , w0.second , w1.first , w1.second ); }

inline int Intersect( const pair<double,double>& v0 , const pair<double,double>& v1 , const pair<double,double>& w0 , const pair<double,double>& w1 , const double& epsilon ) { return Intersect( v0.first , v0.second , v1.first , v1.second , w0.first , w0.second , w1.first , w1.second , epsilon ); }
