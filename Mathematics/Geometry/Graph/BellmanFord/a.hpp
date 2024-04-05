// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/BellmanFord/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"
#include "../../../Algebra/Monoid/a.hpp"

// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/GRL_1_B/judge/9062333/C++17（GetDistance）
// https://yukicoder.me/submissions/969226（GetDistance）

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。

// 入力の範囲内で要件
// (0) MはUの全順序可換モノイド構造である。
// (1) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 単一始点全終点最短経路探索／経路復元なしO(|V_G| |E_G|)
// 単一始点全終点最短経路探索／経路復元ありO(|V_G| |E_G|)
template <typename T , typename GRAPH , typename U , typename MONOID>
class AbstractBellmanFord :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  // コンストラクタに引数が必要なMultiplicativeMonoidなどはstaticメンバ関数による
  // 参照返しがしにくく、コンストラクタの返り値である右辺値を受け取ることを許容したいので
  // 左辺値参照にはしない。
  MONOID m_M;
  // AbstractDijkstraと違って|E_G|が小さい場合にしか適用しないので
  // E_Gの前計算を許容する。
  vector<tuple<int,int,U>> m_edge;

public:
  AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty );

  // 入力の範囲内で要件
  // (1) many_edges=trueかつpath_length!=-1ならば、始点からのパスの辺の本数はpath_length以下。
  // (2) many_edges=falseならば、path_length=-1。
  // を満す場合にのみサポート。
  // 「到達可能ならば負の閉路を経由できない」の真偽を格納した配列を第1成分に、
  // 「到達可能?負の閉路が存在する?辺の本数path_length以下での最短経路長:最短経路長:infty」を
  //  格納した配列を第2成分に返す。
  tuple<vector<bool>,vector<U>> GetDistance( const T& t_start , const bool& many_edges = true , int path_length = -1 );
  
  // t_finalsに属すとは限らない（注意！）各点に対し
  //   「到達可能ならば負の閉路を経由できない」の真偽を格納した配列を第1成分に、
  // t_finalsに属すとは限らない（注意！）各点に対し
  //   「到達可能?負の閉路を経由する?辺の本数path_length以下での最短経路長:最短経路長:infty」を
  //    格納した配列を第2成分に、
  // t_finalsに属す各点に対し
  //   「到達可能かつ負の閉路を経由できない?最短経路:空列」を格納した配列を第3成分に返す。
  template <template <typename...> typename V> tuple<vector<bool>,vector<U>,vector<list<T>>> GetPath( const T& t_start , const V<T>& t_finals , const bool& many_edges = true , int path_length = -1 );
  // 各点に対し
  //   「到達可能ならば負の閉路を経由できない」の真偽を格納した配列を第1成分に、
  // 各点に対し
  //   「到達可能?負の閉路を経由する?辺の本数path_length以下での最短経路長:最短経路長:infty」を
  //    格納した配列を第2成分に、
  // 各点に対し
  //   「到達可能かつ負の閉路を経由できない?最短経路:空列」を格納した配列を第3成分に返す。
  tuple<vector<bool>,vector<U>,vector<list<T>>> GetPath( const T& t_start , const bool& many_edges = true , int path_length = -1 );
  // AbstractDijkstraに合わせてt_finalが１つの特殊化を用意しても
  // AbstractPotentialisedDijkstraで特殊化できないので用意しない。
  
};
template <typename GRAPH , typename U , typename MONOID> AbstractBellmanFord( GRAPH& G , MONOID M , const U& infty ) -> AbstractBellmanFord<inner_t<GRAPH>,GRAPH,U,MONOID>;

template <typename T , typename GRAPH>
class BellmanFord :
  public AbstractBellmanFord<T,GRAPH,ll,AdditiveMonoid<>>
{

public:
  inline BellmanFord( GRAPH& G );
  
};
template <typename GRAPH> BellmanFord( GRAPH& G ) -> BellmanFord<inner_t<GRAPH>,GRAPH>;
