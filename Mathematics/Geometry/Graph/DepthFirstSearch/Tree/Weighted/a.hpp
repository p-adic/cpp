// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/DepthFirstSearch/Weighted/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/957446（重み不使用のWDepth,WHeaviness,WAncestor,WLCA）
// https://yukicoder.me/submissions/957499（WLCA）

// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// E_Tは重み付き辺V_T -> (V_T \times U \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向グラフとしての木である。
// (2) MがUのモノイド構造である。
// を満たす場合にのみサポート。

// 構築O(|V_T|)

// 根からの辺の本数（深さ）取得O(|V_T|)（二度目以降はO(1)）
// 葉からの辺の本数の最大／最小値（高さ）取得O(|V_T|)（二度目以降はO(1)）
// 部分木の辺の本数（サイズ）取得O(|V_T|)（二度目以降はO(1)）

// 根からの辺の重み総乗（重み付き深さ）取得O(|V_T|)（二度目以降はO(1)）
// Mが全順序モノイド構造である場合に葉からの辺の重み総乗の最大／最小値（重み付き高さ）取得
//   O(|V_T|)（二度目以降はO(1)）
// Mが可換な場合に部分木の辺の重み総乗（重み付きサイズ）取得O(|V_T|)（二度目以降はO(1)）

// 木動的計画法O(|V_T|)
// 全方位木動的計画法O(|V_T|)

// 以下、入力の範囲内で
// (3) 各ノードの葉からの辺の本数 < 2^digit
// を満たす場合にのみサポート。
// 先祖取得O(|V_T| digit)（二度目以降はO(digit)）
// 最近接共通先祖取得O(|V_T| digit)（二度目以降はO(digit)）
template <typename TREE , typename U , typename MONOID>
class DepthFirstSearchOnWeightedTree :
  public DepthFirstSearchOnTree<TREE>
{

private:
  MONOID m_M;

  // 親ノードへの辺の重みを格納。
  // ただし親ノードが存在しない場合はM.One()を格納。
  vector<U> m_wprev;
  
  // 根からの辺の重みの右／左総乗（深さ）を格納。
  vector<U> m_wdepth_r;
  vector<U> m_wdepth_l;
  bool m_set_wdepth;

  // 葉からの辺の重みの右／左総乗（高さ）を格納。
  vector<U> m_wheight_max_r;
  vector<U> m_wheight_max_l;
  vector<U> m_wheight_min_r;
  vector<U> m_wheight_min_l;
  bool m_set_wheight;

  // 部分木の辺の重みの総乗（重さ）を格納。
  vector<U> m_wheaviness;
  bool m_set_wheaviness;

  // ダブリングで{先祖ノード,辺の重さの右総乗,辺の重さの左総乗}を格納。
  vector<vector<tuple<int,U,U>>> m_wdoubling;
  bool m_set_wdoubling;

public:
  inline DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const int& root = 0 , const int& digit = 0 );

  inline const U& WDepth( const int& i , const bool& right = true );
  inline const U& WHeight( const int& i , const bool& maximum = true , const bool& right = true );
  inline const U& WHeaviness( const int& i );

  // n階の親Parent^n( i )とiからそこまでの辺の重みの右／左総乗を返す。
  pair<int,U> WAncestor( int i , int n , const bool& right = true );
  // {iとjの最近接共通祖先k,iからkまでの辺の重みの右総乗,jからkまでの辺の重みの左総乗}を返す。
  tuple<int,U,U> WLCA( int i , int j );
  // 更にLCAからi,j側に進める場合に進んだ先の頂点のラベルをi_prev,j_prevに格納する。
  tuple<int,U,U> WLCA( int i , int j , int& i_prev , int& j_prev );

private:
  void SetWDepth();
  void SetWHeight();
  void SetWHeaviness();
  void SetWDoubling();

};
template <typename TREE , typename MONOID , typename...Args> DepthFirstSearchOnWeightedTree( TREE& T , MONOID M , const Args&... args ) -> DepthFirstSearchOnWeightedTree<TREE,inner_t<MONOID>,MONOID>;
