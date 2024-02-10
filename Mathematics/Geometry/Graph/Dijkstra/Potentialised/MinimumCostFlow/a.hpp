// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/MinimumCostFlow/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/a.hpp"

// verify:
// https://yukicoder.me/submissions/949995（MinimumCostFlow、many_edges=false）
// https://yukicoder.me/submissions/949996（AbstractMinimumCostFlow、many_edges=false）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U(コスト) \times U(容量))^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Rは全順序環構造である。
// (1) E_Gの値の各成分の第2成分がM.Zero()以上である。
// (2) inftyが「E_Gの値の各成分の第2成分と2点間ポテンシャル差の和」の|V_G|個以下の和のf倍で表せるいかなる数よりも大きい。
// (3) Vの各要素u,vに対し、辺u->vが複数存在しない。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最小費用流路探索O(F min(|V_G|^2+|E_G|,(|V_G|+|E_G|)log |V_G|))
template <typename GRAPH , typename RING , typename U>
class AbstractMinimumCostFlow :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  RING m_R;

public:
  inline AbstractMinimumCostFlow( GRAPH& G , RING R , const U& infty );
  pair<U,vector<vector<tuple<inner_t<GRAPH>,U>>>> GetFlow( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , U f , const bool& many_edges = true );

};

template <typename GRAPH , typename U>
class MinimumCostFlow :
  public AbstractMinimumCostFlow<GRAPH,Ring<U>,U>
{

public:
  inline MinimumCostFlow( GRAPH& G , const U& one_U , const U& infty );

};
