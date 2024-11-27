// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/Linear/a.hpp

#pragma once
//verify:
// https://yukicoder.me/submissions/977275（Distance）

// 数直線上の点と点群の距離（O(log #x1)）
template <typename INT> INT Distance( const INT& x0 , const set<INT>& x1 );

// 数直線上の点と点群の距離（第length最小値まで）の多点評価
// （O(#x0(log #x0 + length log length) + #x1(log #x1 + (1+length)log(1+length)))）
template <typename INT> vector<set<pair<INT,int>>> Multipoint_Distance( const vector<INT>& x0 , const vector<INT>& x1 , const int& length = 1 );
