// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/971281（GetDistance）

// 入力の範囲内で要件
// (1) G1が辺T1->(T1 \times ...)^{< \omega}を持ち閉路を持たない有向グラフである。
// (2) G2が辺T1 \times T2->(T1 \times T2 \times U \times ...)^{< \omega}を持つ
//     有向グラフである。
// (3) vertexは写像T1->T2^{<\omega}であり、任意のt1 \in T1に対しvertex( t1 )は
//     V_{t1}:={t2 \in T2|(t1,t2) \in V_{G2}}の枚挙である。
// (4) 任意の(s1,t1) \in T1^2に対し以下が同値である：
//     (a) G1が有向辺s1->t1を持つ。
//     (b) ある(s2,t2) \in T2^2が存在してG2が有向辺(s1,s2)->(t1,t2)を持つ。
// を満たす場合にのみサポート。
template <typename T1 , typename ACYCLIC_GRAPH , typename T2 , typename U , typename GRAPH , typename VERTEX>
class DoubleDijkstra
{

private:
  ACYCLIC_GRAPH m_G1; // 例えばLinearGraph( H )
  GRAPH m_G2; // 例えばGridGraph( edge )
  VERTEX m_vertex; // 例えば[&]( const int& i ){ return id<int>( W ); }
  vector<T1> m_top_sort;

public:
  inline DoubleDijkstra( ACYCLIC_GRAPH G1 , GRAPH G2 , VERTEX vertex );
  inline DoubleDijkstra( ACYCLIC_GRAPH G1 , GRAPH G2 , VERTEX vertex  , vector<T1> top_sort );

  inline const vector<T1>& GetTopologicalSort() const noexcept;

  // 入力の範囲内で要件
  // (2) Mがoperator<(const U&,const U&)に関してUの順序可換モノイド構造である。
  // を満たす場合にのみサポート。
  // t_startsの点を始点とする最短経路長を
  // O(min(\sum_{t1} |V_{t1}|^2,\sum_{t1} (|V_{t1}|+|E_{t1}|)log_2|E_{t2}|))
  // で計算する。
  template <typename COMM_MONOID> vector<U> GetDistance( const vector<pair<T1,T2>>& t_starts , COMM_MONOID M , const U& infty , const bool& many_edges = false );

};
template <typename ACYCLIC_GRAPH , typename GRAPH , typename VERTEX , typename...Args> DoubleDijkstra( ACYCLIC_GRAPH G1 , GRAPH G2 , VERTEX vertex , Args&&... ) -> DoubleDijkstra<inner_t<ACYCLIC_GRAPH>,ACYCLIC_GRAPH,decldecay_t( declval<inner_t<GRAPH>>().second ),decldecay_t( declval<GRAPH>().Edge( declval<inner_t<GRAPH>>() ).front().second ),GRAPH,VERTEX>;
