// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a.hpp"

// verify:
// https://judge.yosupo.jp/submission/209796（配列初期化、区間作用、区間乗算、区間積取得）
// https://yukicoder.me/submissions/959027（配列初期化、区間代入、区間乗算、区間積取得）

// 入力の範囲内で要件
// (1) LはRの基点付きマグマ構造である。
// (2) MはUの左L作用付き可換N加群構造であって、Lの基点がMの恒等変換に対応する。
// (3) R=intならばUの左L作用と可換N加群構造が整合的である。
// を満たす場合にのみサポート。

// 区間作用を行わない場合もm_L.Point()の作用を区間積に用いるため、
// dummyにせずRegularRSet(MultiplicativeMonoid(1))などを用いる必要があることに注意。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})（Mのモノイド性を使う）

// 一点代入O(N^{1/2})（Mの非可換N加群性を使う。何も遅延評価されていない時はO(1)）
// 区間代入O(N^{1/2})（Mの非可換N加群性を使う）
// M.Product()による一点乗算はなし。
// M.Product()による区間乗算O(N^{1/2})（Mの可換性を使う）
// M.Act()による一点作用はなし。
// M.Act()による区間作用O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE>
class IntervalMultiplyLazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  RN_BIMODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  // 代入の遅延評価。他の遅延評価を棄却する。
  // 最後に適用するように管理するため、区間作用や区間乗法はここに即座に適用する。
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  // 作用の遅延評価。
  vector<R> m_lazy_action;
  // 乗算の遅延評価。
  // (乗算(作用(成分)))の順に適用するように管理するため、区間作用はここに即座に適用する。
  vector<U> m_lazy_multiplication;

public:
  // vectorを構築する時は
  // vector t( N , IntervalMultiplyLazySqrtDecomposition{L,M} );
  // としてInitialiseすればよい。
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , vector<U> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( i_start , i ) , i )がtrueとなるi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalProduct( i_start , i )を満たすi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  inline int Search( const int& i_start , const U& u );

private:
  inline void Construct();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  // 作用と乗算の遅延評価をこの順に解消する。
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline void IntervalMultiply_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );

};
template <typename PT_MAGMA , typename RN_BIMODULE , typename...Args> IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const Args&... args ) -> IntervalMultiplyLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<RN_BIMODULE>,RN_BIMODULE>;
