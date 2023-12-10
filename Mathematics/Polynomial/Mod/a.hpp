// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "../a.hpp"

// verify:https://yukicoder.me/submissions/937650

// fがgと互いに素である場合にのみサポート。
// O(deg(f) deg(g))でf mod gの逆元を計算。
template <typename T>
Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g );
