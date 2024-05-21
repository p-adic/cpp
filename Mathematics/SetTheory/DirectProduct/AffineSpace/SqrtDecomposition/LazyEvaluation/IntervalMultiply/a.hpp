// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/a.hpp

#pragma once
#include "../../Sqrt/a.hpp"

// verify:
// https://judge.yosupo.jp/submission/209796（配列初期化、区間作用、区間乗算、区間積取得）
// https://yukicoder.me/submissions/959027（配列初期化、区間代入、区間乗算、区間積取得）

// 入力の範囲内で要件
// (1) LがRの基点付き左作用構造（例えば基点付きマグマの正則左加群構造）である。
// (2) MがUの左L作用つき非可換N加群構造であって以下を満たす：
//     (2-1) Lの基点がMの恒等変換に対応する。
//     (2-2) Lの左作用とMの左L作用が結合的である。（例えばマグマ作用である）
// (3) R=intならばL作用とN加群構造が整合的である。
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
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class IntervalMultiplyLazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  vector<R> m_lazy_action;
  vector<U> m_lazy_multiplication;

public:
  // vectorを構築する時は
  // vector t( N , IntervalMultiplyLazySqrtDecomposition{L,M} );
  // としてInitialiseすればよい。
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );
  inline void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

private:
  inline void Construct();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline void IntervalMultiply_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
};
template <typename PT_MAGMA , typename R_MODULE , typename...Args> IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const Args&... args ) -> IntervalMultiplyLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<R_MODULE>,R_MODULE>;
