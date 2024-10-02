// c:/Users/user/Documents/Programming/Mathematics/Geometry/AffineSpace/Distance/ANN/Randomised/a.hpp

#pragma once
#include "a_Macro.hpp"

// TwoDimensionalAllNearestNeighbourRandomisedDoubleの重みを整数の範囲におさめて
// 等号が評価できるようにして最近点を全て選べるようにしたもの。
// 枝刈りがなくなるため少し遅くなる。

// D2は2次元空間上の重みd2に相当する型。

// Sの各点sのTにおける最近点をヒューリスティックに計算する。
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const int& success_count_bound );
template <typename Dist2 , typename INT> vector<vector<int>> TwoDimensionalAllNearestNeighbourRandomised( const Dist2& d2 , const vector<pair<INT,INT>>& S , const vector<pair<INT,INT>>& T , const int& bucket_size , const double& time );
// bucket_sizeはsuccess_count_boundを小さく抑える場合（傾きにバイアスが少ない場合）
// √T.size()程度、大きめにするならlog T.size()程度。

// √T.size()程度とlog T.size()程度で２回計算すれば傾きにバイアスがあるケースも多少対応可能。
