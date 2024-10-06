// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Sqrt/TonelliShanks/a.hpp

#pragma once

// pが素数である場合のみサポート。

// O(√|a%p|+(log_2 p)^2)でaの法p平方根を[0,p)の範囲で1つ計算する。存在しない時は-1を返す。
template <typename INT1 , typename INT2> ll TonelliShanks( INT1 a , const INT2& p , const bool& reduced = false );
