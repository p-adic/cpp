// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/a.hpp

#pragma once

// https://www.cs.umd.edu/gvil/papers/jagan_CG07.pdf のアイデアを簡略化。
// （ブロックのlocalityは考えずに点のlocalityを直接分枝限定法で計算）

// D2は[0,∞)上の広義単調増加関数（2乗など）fを用いてf(|x-z|)+f(|y-w|)と表せる
// 重みd2に相当する型。

// Sの各点sのS-{s}における最近点を計算する。
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbour( const Dist2& d2 , const vector<pair<INT,INT>>& S );

// Sの各点sのTにおける最近点を計算する。
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbour( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T );
