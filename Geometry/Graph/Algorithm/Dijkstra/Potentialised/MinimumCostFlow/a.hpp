// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/MinimumCostFlow/a.hpp

#pragma once
#include "../../../../../../Algebra/Monoid/Semirng/Ring/a.hpp"

// verify:
// https://yukicoder.me/submissions/973370（many_edges=false）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U(コスト) \times U(容量))^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Rは全順序環構造である。
// (1) E_Gの値の各成分の第2成分がM.Zero()以上である。
// (2) inftyが「E_Gの値の各成分の第2成分と2点間ポテンシャル差の和」の|V_G|個以下の和のf倍で表せる
//     いかなる数よりも大きい。
// (3) Vの各要素u,vに対し、辺u->vが複数存在しない。
// が成り立つ場合にのみサポート。

// 構築O(|V_G|^2)
// 単一始点単一終点最小費用流路探索O(|V_G|^2 + F min(|V_G|^2+|E_G|,(|V_G|+|E_G|)log |V_G|))
template <typename T , typename GRAPH , typename U , typename RING>
class AbstractMinimumCostFlow
{

private:
  GRAPH& m_G;
  RING m_R;

  U m_infty;
  // m_full[i]に、m_G.Enumeration(i)を始点とする辺m_G.Enumeration(i)->m_G.Enumeration(j)
  // または辺m_G.Enumeration(j)->m_G.Enumeration(i)の反転ごとに
  // {j,重み,まだ流せる量,m_flow[反転?j:i]における位置}のデータを格納する。
  vector<vector<tuple<int,U,U,int>>> m_full;
  // m_flow[i]に、m_G.Enumeration(i)を始点とする辺m_G.Enumeration(i)->m_G.Enumeration(j)
  // ごとに{m_G.Enumeration(j),既に流した量}のデータを格納する。
  vector<vector<tuple<T,U>>> m_flow;
  vector<vector<int>> m_edge_num;
  vector<vector<int>> m_edge_rev_num;

public:
  inline AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty );

  // 入力の範囲内で要件
  // (1) many_edges=trueかつpath_length!=-1ならば、始点からのパスの辺の本数はpath_length以下。
  // (2) many_edges=falseならば、path_length=-1。
  // を満す場合にのみサポート。
  // 第1成分にコスト総和の最小値、第2成分に
  // 第i成分に「viを始点とする辺vi->vjごとに{vj,既に流した量}のデータを格納した配列」を格納した配列
  // を返す。
  pair<U,vector<vector<tuple<T,U>>>> GetFlow( const T& t_start , const T& t_final , U f , const bool& many_edges = false , int path_length = -1 );

};
template <typename GRAPH , typename U , typename RING>  AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty ) -> AbstractMinimumCostFlow<inner_t<GRAPH>,GRAPH,U,RING>;

template <typename T , typename GRAPH , typename U>
class MinimumCostFlow :
  public AbstractMinimumCostFlow<T,GRAPH,U,Ring<U>>
{

public:
  inline MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty );

};
template <typename GRAPH , typename U> MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty ) -> MinimumCostFlow<inner_t<GRAPH>,GRAPH,U>;
