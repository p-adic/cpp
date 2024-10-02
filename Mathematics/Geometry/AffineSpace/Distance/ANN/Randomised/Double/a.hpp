// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/Double/a.hpp

#pragma once
#include "a_Macro.hpp"

// https://ebadian.org/publications/ann.pdf をもとに実装。
// ただし傾きにバイアスがあるケースで枝刈りが弱いのでbucket_sizeを指定する。

// Dは2次元空間上の重みdであって射影が縮小写像となるもの（ユークリッド距離など）に相当する型。

// Sの各点sのTにおける最近点を高々１つヒューリスティックに計算する。
template <typename Dist , typename INT> vector<int> TwoDimensionalAllNearestNeighbourRandomised( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound );
template <typename Dist , typename INT> vector<int> TwoDimensionalAllNearestNeighbourRandomised( const Dist& d , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time );
