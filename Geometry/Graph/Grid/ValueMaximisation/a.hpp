// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Grid/ValueMaximisation/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/1028604 (GridValueMaximisation)
// https://yukicoder.me/submissions/1028601 (CompressedGridValueMaximisation)

// 入力の範囲内で
// (1) UがMとoperator<に関して全順序モノイドをなす。
// を満たす場合にのみサポート。

// H×Wのグリッド上でvに格納された各(i,j,w)ごとに(i,j)に価値wが与えられているとし、
// (0,0)から正方向に移動する際に通る頂点の価値の、Mの演算に関する総乗の最大値を
// O(H log W)で求める。
template <typename INT , typename U , typename MONOID> U AbstractGridValueMaximisation( MONOID M , const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );
template <typename INT , typename U> inline U GridValueMaximisation( const INT& W , const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );
template <typename INT , typename U> inline U CompressedGridValueMaximisation( const vector<tuple<INT,INT,U>>& v , const bool& skippable = true , const U& min_U = U() );

