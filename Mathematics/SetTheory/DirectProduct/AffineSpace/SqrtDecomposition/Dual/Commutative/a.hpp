// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961727（一点作用、区間作用、一点取得）

// 入力の範囲内で要件
// (1) LがRの基点付き可換マグマ構造である。
// (2) XがUの「Lの基点がUの恒等変換に対応する左L作用構造」である。
// を満たす場合にのみサポート。

// 配列による初期化O(N)

// 一点取得O(1)

// 一点代入O(N^{1/2})（ただし状況次第でO(1)）
// X.Action()による一点作用O(1)（可換性を使う）
// X.Action()による区間作用O(N^{1/2})
template <typename R , typename PT_COMM_MAGMA , typename U , typename R_SET>
class CommutativeDualSqrtDecomposition :
  public DualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_SET>
{

public:
  template <typename...Args> inline CommutativeDualSqrtDecomposition( PT_COMM_MAGMA L , R_SET X , Args&&... args );

  inline void Act( const int& i , const R& r );
  
};
template <typename PT_COMM_MAGMA , typename R_SET , typename...Args> CommutativeDualSqrtDecomposition( PT_COMM_MAGMA M , R_SET X , Args&&... args ) -> CommutativeDualSqrtDecomposition<inner_t<PT_COMM_MAGMA>,PT_COMM_MAGMA,inner_t<R_SET>,R_SET>;

