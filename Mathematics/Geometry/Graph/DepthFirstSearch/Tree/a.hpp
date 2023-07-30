// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <int V_max,list<int> E(const int&),int digit = 0>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<V_max,E>
{

private:
  // メモリが厳しい場合、以下で不要なものを消す。
  int m_reversed[V_max];

  list<int> m_children[V_max];
  bool m_set_children;

  int m_depth[V_max];

  int m_height[V_max];
  bool m_set_height;

  int m_weight[V_max];
  bool m_set_weight;

  int m_doubling[digit][V_max];
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( const int& V , const int& root );
  inline void Reset( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i ) const;
  inline const list<int>& Children( const int& i );
  inline const int& Depth( const int& i ) const;
  inline const int& Height( const int& i );
  inline const int& Weight( const int& i );

  // 探索順にノードを番号づける。
  inline const int& Node( const int& i , const bool& reversed = false ) const;

  // 各ノードの高さ < 2^digitの時のみサポート。
  int Ancestor( int i , int n );
  int LCA( int i , int j );
  int LCA( int i , int j , int& i_prev , int& j_prev );
  
private:
  void SetChildren();
  void SetHeight();
  void SetWeight();

  // 各ノードの高さ < 2^digitの時のみサポート。
  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定するため、
  // 遅延評価する../../../../Mathematics/Function/Iteration/Doubling/のダブリングで代用しない。
  void SetDoubling();

};
