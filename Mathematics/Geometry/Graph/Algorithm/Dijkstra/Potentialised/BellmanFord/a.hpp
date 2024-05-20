// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/Algorithm/Dijkstra/Potentialised/BellmanFord/a.hpp

#pragma once
#include "../a.hpp"

// GRAPHはグラフG=(V_G,E_G:T->(T \times U)^{< \omega})に相当する型。
// Onは写像on:im(edge)->\{0,1\}に相当する型。

// 入力の範囲内で要件
// (0) Mは全順序アーベル群構造である。
// (1) inftyが「E_Gの値の各成分の第2成分と2点間ポテンシャル差の和」の|V_G|個以下の和で表せるいかなる数よりも大きい。
// (2) 許容する辺はポテンシャルに対し三角不等式を満たす。（従って負の閉路が存在しない）
// が成り立つ場合にのみサポート。

// 負辺を含む場合/含まない場合
// 構築O(|V_G| |E_G|)/O(|V_G|)
// 単一始点全終点最短経路探索／経路復元なしO((min(|V_G|^2+|E_G|,|V_G|+|E_G|)log |V_G|))
// 単一始点全終点最短経路探索／経路復元ありO(|V_G|^2+|E_G|)
template <typename T , typename GRAPH , typename U , typename GROUP , typename On>
class AbstractBellmanFordPotentialisedDijkstra :
  public AbstractPotentialisedDijkstra<T,GRAPH,U,GROUP,On>
{

public:
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on );
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP M , const T& t_start , const U& infty , On on , vector<U> potential );

private:
  inline AbstractBellmanFordPotentialisedDijkstra( GRAPH& G , GROUP& M , const T& t_start , const U& infty , On& on , tuple<vector<bool>,vector<U>> potential );

};

template <typename T , typename GRAPH , typename On>
class BellmanFordPotentialisedDijkstra :
  public AbstractBellmanFordPotentialisedDijkstra<T,GRAPH,ll,AdditiveGroup<>,On>
{

public:
  template <typename...Args> inline BellmanFordPotentialisedDijkstra( GRAPH& G , const T& t_start , On on , Args&&... args );

};
