// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalMultiply/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961755（一点乗算、区間乗算、一点取得）

// 入力の範囲内で要件
// (1) MがUのN加群構造である。
// を満たす場合にのみサポート。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})

// 一点代入O(N^{1/2})
// M.Product()による一点乗算O(1)（可換性を使う）
// M.Product()による区間乗算O(N^{1/2})（N加群構造を使う）
template <typename U , typename N_MODULE>
class IntervalMultiplySqrtDecomposition :
  public MonoidSqrtDecomposition<U,N_MODULE>
{

protected:
  vector<U> m_lazy_multiplication;
  
public:
  template <typename...Args> inline IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  // 参照返しでないことに注意
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  template <typename F , SFINAE_FOR_SD_S> inline int Search( const int& i_start , const F& f ) = delete;
  inline int Search( const int& i_start , const U& u ) = delete;

};
template <typename N_MODULE , typename...Args> IntervalMultiplySqrtDecomposition( N_MODULE M , Args&&... args ) -> IntervalMultiplySqrtDecomposition<inner_t<N_MODULE>,N_MODULE>;
