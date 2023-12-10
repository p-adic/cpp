// c:/Users/user/Documents/Programming/Mathematics/Polynomial/ParallelTranslation/a.hpp

#pragma once
#include "../a.hpp"

// O(deg(f) log deg(f))でf(x)をf(x+t)に変換する。
template <typename T> void Shift( Polynomial<T>& f , const T& t , const bool& exponential = false );
