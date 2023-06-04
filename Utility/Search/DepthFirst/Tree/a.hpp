// c:/Users/user/Documents/Programming/Utility/Search/DepthFirst/Tree/a.hpp

#pragma once
#include "../a.hpp"

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
  bool m_set_depth;

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
  inline const int& root() const;

  inline const int& parent( const int& i );
  inline const list<int>& children( const int& i );
  inline const int& depth( const int& i );
  inline const int& height( const int& i );
  inline const int& weight( const int& i );

  // 各ノードの高さ < 2^digitの時のみサポート。
  int Ancestor( int i , int n );
  int LCA( const int& i );

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // 各ノードの高さ < 2^digitの時のみサポート。
  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定するため、
  // 遅延評価する../../../../Mathematics/Function/Iteration/Doubling/のダブリングで代用しない。
  void SetDoubling();

};
