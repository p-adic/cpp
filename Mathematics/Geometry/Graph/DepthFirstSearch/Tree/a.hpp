// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/953264（RootingDP）
// https://yukicoder.me/submissions/953265（RerootingDP）
// https://yukicoder.me/submissions/953266（RerootingDP）

// digitはAncestorとLCAにのみ使用。普段は0で良い。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144

// inner_t<TREE>==intでありTREEがGraphでありTが無向グラフとしての木である場合にのみサポート。
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE>
{

private:
  vector<int> m_reversed;

  vector<vector<int>> m_children;
  vector<int> m_children_num;
  bool m_set_children;

  vector<int> m_depth;
  bool m_set_depth;

  vector<int> m_height;
  bool m_set_height;

  vector<int> m_weight;
  bool m_set_weight;

  int m_digit;
  vector<vector<int>> m_doubling;
  bool m_set_doubling;

public:
  inline DepthFirstSearchOnTree( TREE& T , const int& root = 0 , const int& digit = 0 );
  inline void Initialise( ) = delete;
  inline void Initialise( const int& init ) = delete;
  inline void Shift( const int& init ) = delete;

  inline const int& Root() const;
  inline const int& Parent( const int& i );
  inline const vector<int>& Children( const int& i );
  inline const int& Depth( const int& i );
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

  // Uを適当な型とし、
  // Fは写像f:U^{< \omega} \times N -> Uに相当する型。
  // 型推論のためにfはデフォルト引数で呼び出し可能とする。

  // 入力の範囲内で要件
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
  //     その並び換え(v1,...,vn)に対しf((u1,...,un),i)=f((v1,...,vn),i)である。
  // を満たす場合のみサポート。
  // dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
  // を満たす配列dpの根での値dp[m_init]をO(m_V)で求める。
  template <typename F> ret_t<F> RootingDP( F& f );

  // Uを適当な型とし、
  // Fは写像f:U \times N ->Uに相当する型。
  // Eは写像g:U \times \{0,1\} \times N^2 -> Uに相当する型。

  // 入力の範囲内で要件
  // (1) MがUのモノイド構造である。（以下演算を*と置く）
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
  //     その並び換え(v1,...,vn)に対し
  //     f(u1*u2*...*un,j)=f(v1*v2*...*vn,j)である。
  // を満たす場合のみサポート。
  // dp[i][j] =
  // f(iを根とみなした時のjの子ノードkを渡るg(dp[i][k],jはiの子孫,k,j)のMに関する積,j)
  // を満たす二重配列dpの対角成分dp[i][i]をO(|V_T|)で求めてdに格納する。
  template <typename MONOID , typename F , typename G> void RerootingDP( MONOID M , F& f , G& g , vector<inner_t<MONOID>>& d );
  // fはノードjごとのデータ（グラフ構造に依存しない）、gは有向辺b?(j,k):(k,j)ごとのデータに対応。
  // 例えば「パスの数」を求める時はm_Tが和、fが+1（葉かどうかに関係ない）、gがidでよい。

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetWeight();

  // 各ノードの高さ < 2^digitの場合のみサポート。
  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定するため、
  // 遅延評価してしまう
  // ../../../../Mathematics/Function/Iteration/Doubling/
  // のダブリングでは代用しない。
  void SetDoubling();

};
