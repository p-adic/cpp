// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Counting/LatticePoint/a.hpp

#pragma once

// e=0.1と置いた時、xy平面内の４点(0,0),(0,a_0/q),(n-e,(a_0+a_1*(n-e))/q)),(n-e,0)を結ぶ
// 台形内の格子点の個数
// sum( i , 0 , n ){ ( a_0 + a_1 * i ) / q }
template <typename INT>
INT FloorSum( const INT& a_0 , const INT& a_1 , const INT& q , const INT& n );
