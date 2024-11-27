// c:/Users/user/Documents/Programming/Mathematics/Polynomial/LagrangeInterpolation/a.hpp

#pragma once
#include "../a.hpp"

// Tが体である場合のみサポート。
// argとvalのサイズをMとして、O(M^2 log M)でラグランジュ補間を計算する。
template <typename T> Polynomial<T> LagrangeInterpolation( const vector<T>& arg , const vector<T>& val );

