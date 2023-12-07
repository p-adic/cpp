// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/CRT/a.hpp

#pragma once

// b_0とb_1が

// gcd(b_0,b_1)を返し、u_0,u_1にu_0*b_0+u_1*b_1==gcd(b_0,b_1)を満たす値を格納する。
template <typename INT>
INT PartitionOfUnity( const INT& b_0 , const INT& b_1 , INT& u_0 ,  INT& u_1 );

// (x-c_0)%b_0==0かつ(x-c_1)%b_1==0を満たす非負整数xが存在すればそのようなxを返し、
// 存在しないならば-1を返す。
template <typename INT>
INT ChineseRemainderTheorem( const INT& b_0 , const INT& c_0 , const INT& b_1 , const INT& c_1 );
