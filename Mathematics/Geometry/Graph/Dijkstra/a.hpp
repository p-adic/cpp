// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/961782（GetDistance、many_edges=false）
// https://yukicoder.me/submissions/961784（GetDistance、many_edges=true）
// https://yukicoder.me/submissions/961385（SetDistance、many_edges=true）
// https://yukicoder.me/submissions/961826（GetPath、many_edged=false）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序可換モノイド構造である。
// (1) E_Gの値の各成分の第2成分がM.One()以上である。
// (2) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 単一始点単一終点最短経路探索／経路復元なしO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点単一終点最短経路探索／経路復元ありO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点全終点最短経路探索／経路復元なしO(min(|V_G|^2+|E_G|),(|V_G|+|E_G|)log |E_G|))
// 単一始点全終点最短経路探索／経路復元ありO(|V_G|^2+|E_G|)
template <typename GRAPH , typename COMM_MONOID , typename U>
class AbstractDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  COMM_MONOID m_M;

public:
  inline AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty );

  // 入力の範囲内で要件
  // (1) many_edges=trueかつwalk_length!=-1ならば、始点からの歩道の辺の本数はwalk_length以下。
  // (2) many_edges=falseならば、walk_length=-1。
  // を満す場合にのみサポート。
  // 経路が存在しない場合はinftyを返す。
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true , int walk_length = -1 );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  // 最短経路長の確定している点集合をfixedで指定し、weightに既に格納されている値を重みとする
  // t_startからの有向辺を追加した時の最短経路長を格納し直す。
  void SetDistance( vector<U>& weight , vector<bool>& fixed , const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = true , int walk_length = -1 );
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = true , int walk_length = -1 );
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges = true , int walk_length = -1 );
  
};

template <typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<GRAPH,AdditiveMonoid<>,ll>
{

public:
  inline Dijkstra( GRAPH& G );

};
