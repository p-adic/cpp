// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProd/Tree/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Geometry/Graph/DepthFirstSearch/Tree/a.hpp"

// 木上の累積積。

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,i_T:T->T)が群である。
// (2) グラフ(V,E)は無向グラフとして木である。
// (3) 0を根とした時の各ノードの高さが2^digit未満である。
// が成り立つ場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <typename T , T m_T(const T&,const T&) , T i_T(const T&) , list<int> E(const int&) , int size_max , int digit>
class CumulativeProdOnTree :
  public CumulativeProd_Body<T,m_T,i_T>
{

private:
  DepthFirstSearchOnTree<size_max,E,digit> m_dfst;

public:
  template <typename U , SFINAE_FOR_CUMULATIVE_PROD( = nullptr )> inline CumulativeProdOnTree( const vector<U>& a );

private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );

};
