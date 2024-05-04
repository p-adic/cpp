// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Tree/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957468（Depth,Heaviness,Ancestor,LCA）
// https://yukicoder.me/submissions/957397（RootingDP）
// https://yukicoder.me/submissions/957399（RerootingDP）
// https://yukicoder.me/submissions/957400（RerootingDP）

// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// ただしE_Tは辺V_T -> (V_T \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向グラフとしての木である。
// を満たす場合にのみサポート。

// 構築O(|V_T|)

// 根からの辺の本数（深さ）取得O(|V_T|)（二度目以降はO(1)）
// 葉からの辺の本数の最大／最小値（高さ）取得O(|V_T|)（二度目以降はO(1)）
// 部分木の辺の本数（重さ）取得O(|V_T|)（二度目以降はO(1)）

// 木動的計画法O(|V_T|)
// 全方位木動的計画法O(|V_T|)

// 以下、入力の範囲内で
// (2) 各ノードの葉からの辺の本数 < 2^digit
// を満たす場合にのみサポート。
// 2^16 = 65536
// 2^17 = 131072
// 2^18 = 262144
// 先祖取得O(|V_T| digit)（二度目以降はO(digit)）
// 最近接共通先祖取得O(|V_T| digit)（二度目以降はO(digit)）
template <typename TREE>
class DepthFirstSearchOnTree :
  public DepthFirstSearch<int,TREE>
{

protected:
  // DFS順にノード番号を格納。
  vector<int> m_node_num;

  // 子ノードのノード番号を格納。
  vector<vector<int>> m_children;
  // 親ノードをjとした時m_children[j]の何番目の成分かを格納。
  // ただし親ノードが存在しない時は-1を格納。
  vector<int> m_children_num;
  bool m_set_children;

  // 根からの距離（深さ）を格納。
  vector<int> m_depth;
  bool m_set_depth;

  // 葉からの距離（高さ）を格納。
  vector<int> m_height_max;
  vector<int> m_height_min;
  bool m_set_height;

  // 部分木の辺の本数（サイズ）を格納。
  vector<int> m_heaviness;
  bool m_set_heaviness;

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
  inline const int& Height( const int& i , const bool& maximum = true );
  inline const int& Heaviness( const int& i );

  // 探索順にノードを番号づける。
  inline const int& NodeNumber( const int& i , const bool& reversed = false ) const;
  // 共通の親を持つノード間で昇順に番号づける。
  inline const int& ChildrenNumber( const int& i );  

  // 入力の範囲内で要件
  // (1) 各ノードの高さ < 2^digit
  // を満たす場合のみサポート。
  // n階の親Parent^n( i )を返す。
  int Ancestor( int i , int n );

  // 入力の範囲内で要件
  // (1) 各ノードの高さ < 2^digit
  // を満たす場合のみサポート。
  // iとjの最近接共通祖先を返す。
  inline int LCA( int i , int j );
  // LCAからi,j側に進める場合に進んだ先の頂点のラベルをi_prev,j_prevに格納する。
  int LCA( int i , int j , int& i_prev , int& j_prev );

  // Uは適当な型、Fは写像f:U^{< \omega} \times N -> Uに相当する型。
  // 型推論のためにfはデフォルト引数で呼び出し可能とする。
  // 入力の範囲内で要件
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
  //     その並び換え(v1,...,vn)に対しf((u1,...,un),i)=f((v1,...,vn),i)である。
  // を満たす場合のみサポート。
  // dp[j] = f(jの子ノードkを渡るdp[k]の列,j)
  // を満たす配列dpの根での値dp[root]をO(|V_T|)で求める。
  template <typename F> ret_t<F> RootingDP( F& f );

  // Uは適当な型、Fは写像f:U \times N ->Uに相当する型、
  // Eは写像g:U \times \{0,1\} \times N^2 -> Uに相当する型。
  // 入力の範囲内で要件
  // (1) MがUのモノイド構造である。（以下演算を*と置く）
  // (2) 任意の非負整数n,iとTの要素のみからなる任意の長さnの任意の列(u1,...,un)と
  //     その並び換え(v1,...,vn)に対し
  //     f(u1*u2*...*un,j)=f(v1*v2*...*vn,j)である。
  //     （例えばLがWの可換モノイド構造である）
  // を満たす場合のみサポート。
  // dp[i][j] =
  // f(iを根とみなした時のjの子ノードkを渡るg(dp[i][k],jはiの子孫,k,j)のMに関する積,j)
  // を満たす二重配列dpの対角成分dp[i][i]をO(|V_T|)で求めてdに格納する。
  template <typename U , typename COMM_MONOID , typename F , typename G> void RerootingDP( COMM_MONOID M , F& f , G& g , vector<U>& d );
  // fはノードjごとのデータ（グラフ構造に依存しない）、gは有向辺b?(j,k):(k,j)ごとのデータに対応。
  // 例えば「パスの数」を求める時はm_Tが和、fが+1（葉かどうかに関係ない）、gがidでよい。

private:
  void SetChildren();
  void SetDepth();
  void SetHeight();
  void SetHeaviness();

  // LCA()を呼ぶ前にAncestor()経由で完全にダブリングを設定する。
  // 遅延評価してしまう
  // ../../../../Function/Iteration/Doubling/
  // のダブリングでは代用しない。
  void SetDoubling();

};
