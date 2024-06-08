// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/HeavyLightDecomposition/a.hpp

#pragma once
#include "../a.hpp"


// TREEはGraph<Edge>と表せる、木T=(V_T,E_T)に相当する型。特にV_Tの型はintに限られる。
// ただしE_Tは辺V_T -> (V_T \times ...)^{< \omega}に相当する関数オブジェクト。

// 入力の範囲内で
// (1) Tが無向グラフとしての木である。
// を満たす場合にのみサポート。

// 構築O(|V_T| log |V_T|)

// 根からのパス取得O(1)（参照されるvectorのサイズはO(log |V_T|)）
// 部分木取得O(1)

// パス和取得O((log |V_T|)^2)（メソッドなし。根からのパス取得とLCAとBITなどを併用）
// 部分木和取得O(log |V_T|)（メソッドなし。部分木取得とBITなどを併用）

template <typename TREE>
class HeavyLightDecomposiion :
  public DepthFirstSearchOnTree<TREE>
{

private:
  // m_HL[i]にはHL分解後の配列の第i成分に対応するノード番号を格納。
  vector<int> m_HL;
  vector<int> m_HL_inv;

  // m_path[i]にはrootからiへのパスに対応するm_HLの閉区間[l,r]族を格納。
  vector<vector<pair<int,int>>> m_path;

  // m_subtree[i]にはノード番号iのノードを根とする部分木に対応するm_HLの閉区間[l,r]を格納。
  vector<pair<int,int>> m_subtree;

public:
  inline HeavyLightDecomposiion( TREE& T , const int& root = 0 , const int& digit = 0 );

  inline const int& RearragedNodeNumber( const int& n ) const;
  inline const int& RearragedNodeNumber_inv( const int& i ) const;

  // 一般のpath i->jでの関数fのパス和などを計算したい時は、(f(m_HL[i]))_iをBITなどに乗せ
  // (PathFromRoot(i)でのfの総和)+(PathFromRoot(j)でのfの総和)
  // -(PathFromRoot(LCA(i,j))でのfの総和)
  // を計算すればよい。
  inline const vector<pair<int,int>>& PathFromRoot( const int& i ) const;

  inline const pair<int,int> Subtree( const int& i ) const;
  
};
