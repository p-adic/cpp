// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// 一般の木上の累積積。
// 入力の範囲内で要件
// (1) MがUの群構造である。
// (2) Tが無向グラフとして木である。
// (3) 0を根とした時のTの各ノードの高さが2^digit未満である。
// が成り立つ場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename TREE , typename GROUP>
class CumulativeProdOnTree :
  public PathProdImplementation<inner_t<GROUP>,GROUP>
{

private:
  DepthFirstSearchOnTree<TREE> m_dfst;

public:
  template <typename V> inline CumulativeProdOnTree( TREE T , const vector<V>& a , const int& digit , GROUP M );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
