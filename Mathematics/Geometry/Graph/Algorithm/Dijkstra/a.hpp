// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../a.hpp"
#include "../../../../Algebra/Monoid/a.hpp"

// verify:
// https://yukicoder.me/submissions/969250（GetDistance、many_edges=false）
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
template <typename T , typename GRAPH , typename U , typename COMM_MONOID>
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
  // (1) many_edges=trueかつpath_length!=-1ならば、始点からのパスの辺の本数はpath_length以下。
  // (2) many_edges=falseならば、path_length=-1。
  // を満す場合にのみサポート。
  // 経路が存在する場合は最短径路長を、存在しない場合はinftyを返す。
  U GetDistance( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = false , int path_length = -1 );
  vector<U> GetDistance( const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );
  // 最短経路長の確定している点集合をfixedで指定し、weightに既に格納されている値を重みとする
  // t_startからの有向辺を追加した時の最短経路長を格納し直す。
  void SetDistance( vector<U>& weight , vector<bool>& fixed , const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );

  // 経路が存在する場合は最短径路長を、存在しない場合はinftyを第1成分に、
  // 経路が存在する場合は最短径路を、存在しない場合は空列を第2成分に返す。
  pair<U,list<inner_t<GRAPH>>> GetPath( const inner_t<GRAPH>& t_start , const inner_t<GRAPH>& t_final , const bool& many_edges = false , int path_length = -1 );
  // t_finalsに属すとは限らない（注意！）各点に対し
  //   「経路が存在する?最短径路長:infty」を格納した配列を第1成分に、
  // t_finalsに属す各点に対し
  //   「経路が存在する?最短径路:空列」を格納した配列を第2成分に返す。
  template <template <typename...> typename V> pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const V<inner_t<GRAPH>>& t_finals , const bool& many_edges = false , int path_length = -1 );
  // 各点に対し「経路が存在する?最短径路長:infty」を格納した配列を第1成分に、
  // 各点に対し「経路が存在する?最短径路:空列」を格納した配列を第2成分に返す。
  pair<vector<U>,vector<list<inner_t<GRAPH>>>> GetPath( const inner_t<GRAPH>& t_start , const bool& many_edges = false , int path_length = -1 );
  
};
template <typename GRAPH , typename U , typename COMM_MONOID> AbstractDijkstra( GRAPH& G , COMM_MONOID M , const U& infty ) -> AbstractDijkstra<inner_t<GRAPH>,GRAPH,U,COMM_MONOID>;

template <typename T , typename GRAPH>
class Dijkstra :
  public AbstractDijkstra<T,GRAPH,ll,AdditiveMonoid<>>
{

public:
  inline Dijkstra( GRAPH& G );

};
template <typename GRAPH> Dijkstra( GRAPH& G ) -> Dijkstra<inner_t<GRAPH>,GRAPH>;
