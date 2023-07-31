// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// digitはAncestorとLCAにのみ使用。普段は0で良い。
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

  vector<int> m_children[V_max];
  int m_children_num[V_max];
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
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i ) const;
  inline const int& Height( const int& i );
  inline const int& Weight( const int& i );

  // 探索順にノードを番号づける。
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // 共通の親を持つノード間で昇順に番号づける。
  inline const int& ChildrenNumber( const int& i );  

  // 各ノードの高さ < 2^digitの場合のみサポート。
  int Ancestor( int i , int n );
  int LCA( int i , int j );
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // (T,m_T:T^2->T,e_T:1->T)が可換モノイドの場合のみサポート。
  // dp[i][j] = f(iを根とみなした時のjの子ノードkを渡るdp[i][k]のm_Tに関する積,j)
  // を満たす二重配列dpの対角成分dp[i][i]をO(m_V)で求めてdに格納する。
  template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&)> void RerootingDP( T ( &d )[V_max] );
  
private:
  void SetChildren();
  void SetHeight();
  void SetWeight();

  // 各ノードの高さ < 2^digitの場合のみサポート。
  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定するため、
  // 遅延評価する../../../../Mathematics/Function/Iteration/Doubling/のダブリングで代用しない。
  void SetDoubling();

};
