// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/Commutative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/964782（零初期化、一点乗算、区間積）

// 入力の範囲内で要件
// (1) MがUの可換モノイド構造である。
// を満たす場合にのみサポート。
// 一点乗算以外はMonoidBITの下位互換であるので一点乗算が不要ならMonoidBITを使えば良い。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})

// 一点代入O(N^{1/2})
// M.Product()による一点乗算O(1)（可換性を使う）

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序モノイド構造である。
// (3) m_a,m_bの全ての成分がM.One()以上である。
// を満たす場合にのみサポート。
// M.Product()に関する区間積の値探索O(N^{1/2})
template <typename U , typename COMM_MONOID>
class CommutativeMonoidSqrtDecomposition :
  virtual public MonoidSqrtDecomposition<U,COMM_MONOID>
{
  
public:
  template <typename...Args> inline CommutativeMonoidSqrtDecomposition( COMM_MONOID M , Args&&... args );

  inline void Multiply( const int& i , const U& u );
  
};
template <typename COMM_MONOID , typename...Args> CommutativeMonoidSqrtDecomposition( COMM_MONOID M , Args&&...args ) -> CommutativeMonoidSqrtDecomposition<inner_t<COMM_MONOID>,COMM_MONOID>;
