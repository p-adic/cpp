// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Intersection/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/978050（Intersect）

// xy平面内の２線分（１点に潰れている場合含む）の交差判定
// 返り値1：交差する
// 返り値0：交差しないが、接触するか線分が１点に潰れている
// 返り値-1：接触しないかつ線分が１点に潰れてもいない
template <typename INT> inline int Intersect( const INT& x0 , const INT& y0 , const INT& x1 , const INT& y1 , const INT& z0 , const INT& w0 , const INT& z1 , const INT& w1 );
inline int Intersect( const double& x0 , const double& y0 , const double& x1 , const double& y1 , const double& z0 , const double& w0 , const double& z1 , const double& w1 , const double& epsilon );
template <typename INT> inline int Intersect( const pair<INT,INT>& v0 , const pair<INT,INT>& v1 , const pair<INT,INT>& w0 , const pair<INT,INT>& w1 );
inline int Intersect( const pair<double,double>& v0 , const pair<double,double>& v1 , const pair<double,double>& w0 , const pair<double,double>& w1 , const double& epsilon );
