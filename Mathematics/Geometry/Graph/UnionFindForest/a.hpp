// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/UnionFindForest/a.hpp

#pragma once
#include "../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/50885973（ポテンシャル）

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。

// - 構築 O(size)

// - 一点根取得 O(α(size))
// - 全根取得 O(size)
// - 根数取得 O(1)

// - 二点間ポテンシャル取得 O(α(size))
// - 二点接合 O(α(size))
template <typename U , typename GROUP>
class AbstractUnionFindForest
{

private:
  GROUP m_M;
  int m_node_size;
  int m_root_size;
  vector<int> m_pred;
  vector<int> m_height;
  // m_w[num]はnum番目のnodeがrootならば0、rootでないならば親nodeからのパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する場合にはx[num]-x[親node]を返すことと等価。
  vector<U> m_w;
  
public:
  inline AbstractUnionFindForest( const int& size , GROUP M );

  // num番目のnodeのrootを計算して返す。
  const int& RootOfNode( const int& num );
  // rootを全て格納する。
  template <template <typename...> typename V> void SetRoot( V<int>& a ) const;

  // num1番目のnodeからnum0番目のnodeへ向かうパスの符号付き重みを返す。
  // Graftと整合的な解xが存在する時のx[num0]-x[num1]の取得と等価。
  inline U Potential( const int& num0 , const int& num1 );

  // 
  inline const int& size( const bool& node = true ) const noexcept;

  // num1番目のnodeからnum0番目のnodeへ符号付き重みwの有向辺を結ぶ操作と整合的に
  // なるようにrootを接合。符号付き重みの整合性が取れない場合はfalseを返す。
  // 返り値はx[num0]-x[num1]=wの解の有無と等価。
  bool Graft( const int& num0 , const int& num1 , const U& w = 0 );
  
};
template <typename GROUP> AbstractUnionFindForest( const int& size , GROUP M ) -> AbstractUnionFindForest<inner_t<GROUP>,GROUP>;

template <typename U = int>
class UnionFindForest :
  public AbstractUnionFindForest<U,AdditiveGroup<U>>
{

public:
  inline UnionFindForest( const int& size );

};
