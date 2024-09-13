// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a.hpp

#pragma once

// RETはMPなどでも可。
// n以下の各正整数iに対し、answer[i]にm以下のiの正約数dのexponential乗の総和を格納して返す。
// (O(min(n,m) log exponent + n log min(n,m)))
template <typename INT , typename RET> vector<RET> DivisorSum( const INT& n , const INT& m , const int& exponent = 1 );
