// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Divisor/Sum/a.hpp

#pragma once

// n_max以下の各正整数nに対し、answer[n]にd_max以下の正の約数のexponential乗の総和を
// 格納して返す。(O(min(n_max,d_max) log exponent + n_max log min(n_max,d_max)))
template <typename INT> vector<INT> DivisorSum( const INT& n_max , const INT& d_max , const int& exponent = 1 );
