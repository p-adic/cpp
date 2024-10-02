// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/NonBalanced/a.hpp

#pragma once

// D2は[0,∞)上の広義単調増加関数（2乗など）fを用いてf(|x-z|)+f(|y-w|)と表せる
// 重みd2に相当する型。

// Sの各点sのTにおける最近点を計算する。
template <typename Dist2 , typename INT>
vector<vector<int>> TwoDimensionalAllNearestNeighbourNonBalanced( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T );
