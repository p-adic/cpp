// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/919091（RootingDP）
// https://yukicoder.me/submissions/938101（RerootingDP）

// digitはAncestorとLCAにのみ使用。普段は0で良い。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
template <int V_max,list<int> E(const int&),int digit = 0>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<V_max,E>
{

private:
  int m_reversed[V_max];

  vector<vector<int> > m_children;
  vector<int> m_children_num;
  bool m_set_children;

  vector<int> m_depth;
  bool m_set_depth;

  vector<int> m_height;
  bool m_set_height;

  vector<int> m_weight;
  bool m_set_weight;

  vector<int> m_doubling[digit];
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
  // n階の親Parent^n( i )を返す。
  int Ancestor( int i , int n );
  int LCA( int i , int j );
  // LCAからi,j側に進める場合に進んだ先の頂点のラベルをi_prev,j_prevに格納する。
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // 入力の範囲内で要件
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(t1,...,tn)と
  //     その並び換え(s1,...,sn)に対しf((t1,...,tn),i)=f((s1,...,sn),i)である。
  // を満たす場合のみサポート。
  // dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
  // を満たす配列dpの根での値dp[m_init]をO(m_V)で求める。
  template <typename T , T f(const list<T>&,const int&)> T RootingDP();

  // (T,m_T:T^2->T,e_T:1->T)が入力の範囲内で要件
  // (1) (T,m_T:T^2->T,e_T:1->T)がモノイドである
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(t1,...,tn)と
  //     その並び換え(s1,...,sn)に対し
  //     f(m_T(...m_T(t1,t2),...tn),j)=f(m_T(...m_T(s1,s2),...sn),j)である。
  // を満たす場合のみサポート。
  // dp[i][j] = f(iを根とみなした時のjの子ノードkを渡るg(dp[i][k],jはiの子孫,k,j)のm_Tに関する積,j)
  // を満たす二重配列dpの対角成分dp[i][i]をO(m_V)で求めてdに格納する。
  template <typename T , T m_T(const T&,const T&) ,const T& e_T() , T f(const T&,const int&), T g(const T&,const bool&,const int&,const int&)> void RerootingDP( T ( &d )[V_max] );
  // fはノードjごとのデータ、gは有向辺b?(j,k):(k,j)ごとのデータに対応。

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // 各ノードの高さ < 2^digitの場合のみサポート。
  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定するため、
  // 遅延評価する../../../../Mathematics/Function/Iteration/Doubling/のダブリングで代用しない。
  void SetDoubling();

};
