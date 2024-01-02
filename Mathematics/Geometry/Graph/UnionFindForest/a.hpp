// c:/Users/user/Documents/Programming/Utility/VLTree/UnionFindForest/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/941558
// https://yukicoder.me/submissions/941553
// https://yukicoder.me/submissions/941556
// https://atcoder.jp/contests/abc087/submissions/48977983（符号付き重み）

// Tが加法について可換群をなす場合にのみサポート。

// - 構築 O(size)

// - 一点根取得 O(α(size))
// - 全根取得 O(size)
// - 根数取得 O(1)

// - 二点符号付き重み取得 O(α(size))
// - 二点接合 O(α(size))
template <typename T = int>
class UnionFindForest
{

private:
  uint m_node_size;
  uint m_root_size;
  vector<uint> m_pred;
  vector<uint> m_height;
  // m_w[num]はnum番目のnodeがrootならば0、rootでないならば親nodeへ向かうパスの符号付き重み
  vector<T> m_w;
  
public:
  inline UnionFindForest( const uint& size );

  // num番目のnodeのrootを計算して返す。
  const uint& RootOfNode( const uint& num );
  // rootを全て格納する。
  template <template <typename...> typename V> void SetRoot( V<uint>& a ) const;

  // num1番目のnodeからnum0番目のnodeへ向かうパスの符号付き重みを返す。
  inline T Weight( const uint& num0 , const uint& num1 );
  
  inline const uint& SizeOfNode() const noexcept;
  inline const uint& SizeOfRoot() const noexcept;

  // num1番目のnodeからnum0番目のnodeへ符号付き重みwの有向辺を結ぶ操作と整合的に
  // なるようにrootを接合。符号付き重みの整合性が取れない場合はfalseを返す。
  bool Graft( const uint& num0 , const uint& num1 , const T& w = 0 );
  
};
