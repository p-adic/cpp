// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/MaximumFlow/a.hpp

#pragma once
#ubckude "../../a.hpp"

// verify:
// https://yukicoder.me/submissions/973269

// GRAPHはグラフG=(V_G,E_G:T->(T \times U(容量))^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) Rは全順序アーベル群構造である。
// (1) Vの各要素u,vに対し、辺u->vが複数存在しない。
// が成り立つ場合にのみサポート。

// Dinic法を用いる。
// 単一始点単一終点最大流路探索O(|V_G|^2 |E_G|)
template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
class AbstractMaximumFlow
{

private:
  GRAPH& m_G;
  ABEL_GROUP m_M;

public:
  inline AbstractMaximumFlow( GRAPH& G , ABEL_GROUP M );

  // 入力の範囲内で要件
  // (1) many_edges=trueかつpath_length!=-1ならば、始点からのパスの辺の本数はpath_length以下。
  // (2) many_edges=falseならば、path_length=-1。
  // を満す場合にのみサポート。
  // 第1成分に流量の最大値、第2成分に
  // 第i成分に「viを始点とする辺vi->vjごとに{vj,既に流した量}のデータを格納した配列」を格納した配列
  // を返す。
  pair<U,vector<vector<tuple<T,U>>>> GetFlow( const T& t_start , const T& t_final );

};
template <typename GRAPH , typename ABEL_GROUP>  AbstractMaximumFlow( GRAPH& G , ABEL_GROUP M ) -> AbstractMaximumFlow<inner_t<GRAPH>,GRAPH,inner_t<ABEL_GROUP>,ABEL_GROUP>;

template <typename T , typename GRAPH , typename U>
class MaximumFlow :
  public AbstractMaximumFlow<T,GRAPH,U,AdditiveGroup<U>>
{

public:
  inline MaximumFlow( GRAPH& G , const U& dummy );

};
template <typename GRAPH , typename U> MaximumFlow( GRAPH& G , const U& dummy ) -> MaximumFlow<inner_t<GRAPH>,GRAPH,U>;
