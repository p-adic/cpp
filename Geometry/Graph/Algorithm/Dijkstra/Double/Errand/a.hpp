// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Double/Errand/a.hpp

#pragma once
#include "../a.hpp"

#include "../../../../Linear/a.hpp"

// verify:
// https://yukicoder.me/submissions/982995（direction = 1 , many_edges = false）

// サブゴールの経由が必要な場合の最短経路問題を解くためにグラフを複製したグラフ。

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当するMemorisationGraphでない型。
// SUBGOALは写像subgoal : int \times T -> \{0,1\}に相当する型。
template <typename T , typename GRAPH>
class ErrandEnumeration
{

private:
  GRAPH* m_p_G;
  
public:
  inline ErrandEnumeration( GRAPH& G );
  inline pair<int,T> operator()( const int& i );

};

template <typename T , typename GRAPH>
class ErrandEnumeration_inv
{

private:
  GRAPH* m_p_G;
  
public:
  inline ErrandEnumeration_inv( GRAPH& G );
  inline int operator()( const pair<int,T>& v );

};

template <typename T , typename U , typename GRAPH , typename SUBGOAL>
class ErrandEdge
{

private:
  GRAPH* m_p_G;
  SUBGOAL m_subgoal;
  U m_one;
  int m_goal_num;

public:
  inline ErrandEdge( GRAPH& G , SUBGOAL subgoal , const U& one , const int& goal_num );
  inline vector<pair<pair<int,T>,U>> operator()( const pair<int,T>& v );

};

template <typename T , typename GRAPH>
class ErrandVertex
{

private:
  GRAPH* m_p_G;
  vector<T> m_vertex;
  
public:
  inline ErrandVertex( GRAPH& G );
  inline const vector<T>& operator()( const int& );

};

template <typename T , typename GRAPH , typename U , typename COMM_MONOID , typename SUBGOAL>
class ErrandDijkstra :
  public DoubleDijkstra<int,LinearGraph,T,U,EnumerationGraph<pair<int,T>,ErrandEnumeration<T,GRAPH>,ErrandEnumeration_inv<T,GRAPH>,ErrandEdge<T,U,GRAPH,SUBGOAL>>,ErrandVertex<T,GRAPH>>
{

private:
  GRAPH m_G;
  COMM_MONOID m_M;
  U m_infty;
  
public:
  // 1:正方向
  // 2:負方向
  inline ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const int& goal_num , const U& infty , const int& direction = 1 );

  inline const U& infty() const noexcept;
  
  // 入力の範囲内で要件
  // (0) Mは全順序可換モノイド構造である。
  // (1) E_Gの値の各成分の第2成分がM.One()以上である。
  // (2) inftyがE_Gの値の各成分の第2成分|V_G|個以下の和で表せるいかなる数よりも大きい。
  // が成り立つ場合にのみサポート。
  inline vector<U> GetDistance( const vector<T>& t_starts , const bool& many_edges = true );

};
template <typename GRAPH , typename COMM_MONOID , typename SUBGOAL , typename...Args> ErrandDijkstra( GRAPH G , COMM_MONOID M , SUBGOAL subgoal , const Args&... ) -> ErrandDijkstra<inner_t<GRAPH>,GRAPH,inner_t<COMM_MONOID>,COMM_MONOID,SUBGOAL>;

