// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Mod/a.hpp

#pragma once
#include "../a.hpp"

// fがgと互いに素である場合にのみサポート。
// O(deg(f) deg(g))でf mod gの逆元を計算。
template <typename T>
Polynomial<T> ModularInverse( Polynomial<T> f , Polynomial<T> g );
