// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/a.hpp

#pragma once
#include "a_Macro.hpp"

// 単なる２乗だが、T次第ではオーバーロードしてより高速なものに置き換える
template <typename T> inline T Square( const T& t );

// T(1)が乗法的単位元である場合のみサポート。
// t ^ num
template <typename T , typename UINT>
T Power( T t , UINT exponent );

// init * ( t ^ num )
template <typename T , typename UINT>
T Power( T t , UINT exponent , T init );

