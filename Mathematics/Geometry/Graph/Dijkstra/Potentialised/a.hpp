// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Dijkstra/Potentialised/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Algebra/Monoid/Group/a.hpp"

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。
// Onは写像on:im(edge)->\{0,1\}に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序アーベル群構造である。
// (1) inftyが「E_Gの値の各成分の第2成分と2点間ポテンシャル差の和」の|V_G|個以下の和で表せるいかなる数よりも大きい。
// が成り立つ場合にのみサポート。

// 負辺を含む場合/含まない場合
// 構築O(|V_G| |E_G|)/O(|V_G|)
// 単一始点全終点最短経路探索／経路復元なしO((min(|V_G|^2+|E_G|,|V_G|+|E_G|)log |V_G|))
// 単一始点全終点最短経路探索／経路復元ありO(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename GROUP , typename U , typename On>
class AbstractPotentialisedDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  GROUP m_M;
  T m_t_start;
  // どの辺を許容するかを決める関数オブジェクト。
  On m_on;
  // 「全ての辺を許容する場合に始点から負のループに到達可能でない」の真偽。
  bool m_valid;
  // 全ての辺を許容する場合の始点からのコスト。
  vector<U> m_potential;

public:
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& negative = true );
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , const bool& valid , vector<U> potential );

  inline const bool& Valid() const noexcept;
  inline const vector<U>& Potential() const noexcept;
  inline void SetPotential( const bool& valid , vector<U> potential );

  // 「到達可能かつ負の閉路を経由できない」の真偽を格納した配列を第1成分に、
  // 「到達可能?負の閉路が存在する?辺の本数path_length以下での最短経路長:最短経路長:infty」を
  //  格納した配列を第2成分に返す。
  template <typename...Args> tuple<vector<bool>,vector<U>> GetDistance( Args&&... args );
  // 「到達可能かつ負の閉路を経由できない」の真偽を格納した配列を第1成分に、
  // 「到達可能?負の閉路を経由する?辺の本数path_length以下での最短経路長:最短経路長:infty」を
  //  格納した配列を第2成分に、
  // 「到達可能かつ負の閉路を経由できない?最短経路:空列」を格納した配列を第3成分に返す。
  template <typename...Args> tuple<vector<bool>,vector<U>,vector<list<T>>> GetPath( Args&&... args );
  // 返り値の都合、t_finalが１つである特殊化は存在せず、配列化したt_finalsを渡す。

};

template <typename T , typename GRAPH , typename On>
class PotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,AdditiveGroup<>,ll,On>
{

public:
  template <typename...Args> inline PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );
};
