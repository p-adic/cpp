// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HopcroftKarp/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/911317

// (S,T,edge)が二部グラフである場合のみサポート。
// edgeのサイズをeと置く。最大二部マッチング問題を
// 時間計算量O((S+T+e)√(S+T))
// 空間計算量O(S+T+e)
// で解く。特に
// - eがO(ST)の時は時間計算量O(ST√(S+T))
// - eがO(S+T)の時は時間計算量O((S+T)√(S+T))
// で解く。
class HopcroftKarp
{

public:
  template <typename Edge> vector<pair<int,int>> GetMaximumMatching( const int& S , const int& T , Edge edge );

};

