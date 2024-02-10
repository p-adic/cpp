// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/949989（Dijstra、GetDistance、many_edges=true）
// https://yukicoder.me/submissions/949990（Dijstra、GetDistance、many_edges=false）
// https://yukicoder.me/submissions/949988（AbstractDijkstraa、GetDistance、many_edges=true）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序可換モノイド構造である。
// (1) E_Gの値の各成分の第2成分がM.Zero()以上である。
// (2) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点単一終点最短経路探索／経路復元ありO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点全終点最短経路探索／経路復元なしO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点全終点最短経路探索／経路復元ありO(|V_G|^2+|E_G|)
template <typename GRAPH , typename MONOID , typename U>
class AbstractDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  MONOID m_M;

public:
  inline AbstractDijkstra( GRAPH& G , MONOID M , const U& infty );

  // 経路が存在しない場合の返り値はinfty
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = true );
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true );
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = true );
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start );
  
};

template <typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline Dijkstra( GRAPH& G );

};
