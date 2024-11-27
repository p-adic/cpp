// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../../Algebra/Monoid/Group/a.hpp"

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。
// Onは写像on:im(edge)->\{0,1\}に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序アーベル群構造である。
// (1) inftyが「E_Gの値の各成分の第2成分と2点間ポテンシャル差の和」の|V_G|個以下の和で表せるいかなる数よりも大きい。
// (2) 許容する辺はポテンシャルに対し三角不等式を満たす。（従って負の閉路が存在しない）
// が成り立つ場合にのみサポート。

// 負辺を許容する場合はポテンシャルを自分で渡す必要あり。
// BellmanFord法で自動で計算する場合はAbstractBellmanFordPotentialisedDijkstraを用いる。

// 構築O(|V_G|)
// 単一始点全終点最短経路探索／経路復元なしO((min(|V_G|^2+|E_G|,|V_G|+|E_G|)log |V_G|))
// 単一始点全終点最短経路探索／経路復元ありO(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename U , typename GROUP , typename On>
class AbstractPotentialisedDijkstra :
  public PointedSet<U>
{

private:
  GRAPH& m_G;
  GROUP m_M;
  T m_t_start;
  // どの辺を許容するかを決める関数オブジェクト。
  On m_on;
  // （次にSetPotentialをするまでの間に）許容しうる辺を全て許容する場合の始点からのコスト。
  vector<U> m_potential;

public:
  // potentialのデフォルト引数使用は（次にSetPotentialをするまでの間に）負辺を許容しない
  // 場合のみサポート。
  inline AbstractPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential = {} );

  inline const vector<U>& Potential() const noexcept;
  inline void SetPotential( vector<U> potential );

  // 「到達可能?最短経路長:infty」を格納した配列を返す。
  template <typename...Args> vector<U> GetDistance( Args&&... args );
  // 「到達可能?最短経路長:infty」を格納した配列を第1成分に、
  // 「到達可能?最短経路:空列」を格納した配列を第2成分に返す。
  template <typename...Args> pair<vector<U>,vector<list<T>>> GetPath( Args&&... args );
  // 返り値の都合、t_finalが１つである特殊化は存在せず、配列化したt_finalsを渡す。

};

template <typename T , typename GRAPH , typename On>
class PotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>
{

public:
  template <typename...Args> inline PotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );
  
};
