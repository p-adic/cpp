// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/a.hpp

#pragma once
#include "../Discrete/a.hpp"
#include "../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/50885973（ポテンシャル）

// GRAPHは辺Edge:T->(T \times ...)^{< \omega}を持つグラフに相当する型。

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。

// - 構築 O(|V_G| + |E_G| α(|V_G|))

// - 一点根取得 O(α(|V_G|))
// - 全根取得 O(|V_G|)
// - 根数取得 O(1)

// - 二点間ポテンシャル取得 O(α(|V_G|))
// - 二点接合 O(α(|V_G|))
template <typename T , typename GRAPH , typename U , typename ABEL_GROUP>
class AbstractUnionFindForest
{

private:
  GRAPH& m_G;
  ABEL_GROUP m_M;
  int m_root_size;
  vector<int> m_pred;
  vector<int> m_height;
  // m_w[num]はnum番目のnodeがrootならば0、rootでないならば親nodeからのパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する場合にはx[num]-x[親node]を返すことと等価。
  vector<U> m_w;
  
public:
  AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M );

  // tのrootを計算して返す。
  const decltype( ( declval<GRAPH>().Enumeration(0) ) ) RootOfNode( const T& );
  // rootを全て返す。
  template <template <typename...> typename V> vector<T> GetRoot() const;

  // t1からt0へ向かうパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する時のx[t0]-x[t1]の取得と等価。
  inline U Potential( const T& t0 , const T& t1 );

  // nodeかrootのサイズを返す。
  inline const int& size( const bool& node = true ) const noexcept;

  // t1からt0へ符号付き重みwの有向辺を結ぶ操作と整合的に
  // なるようにrootを接合。符号付き重みの整合性が取れない場合はfalseを返す。
  // 返り値はx[t0]-x[t1]=wの解の有無と等価。
  bool Graft( const T& t0 , const T& t1 , const U& w = U() );
  template <typename PATH> inline bool Graft( const T& t0 , const PATH& t1 );
  
};
template <typename GRAPH , typename ABEL_GROUP> AbstractUnionFindForest( GRAPH& G , ABEL_GROUP M ) -> AbstractUnionFindForest<inner_t<GRAPH>,GRAPH,inner_t<ABEL_GROUP>,ABEL_GROUP>;

template <typename U = int>
class UnionFindForest :
  public AbstractUnionFindForest<int,DiscreteGraph,U,AdditiveGroup<U>>
{

public:
  inline UnionFindForest( const int& size );

};
