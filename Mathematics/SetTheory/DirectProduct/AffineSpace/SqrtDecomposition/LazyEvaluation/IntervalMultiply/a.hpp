// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/IntervalMultiply/a.hpp

#pragma once
// verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/8901822/C++17（零初期化、区間代入、区間積取得）
// https://judge.yosupo.jp/submission/190200（配列初期化、区間作用、区間乗算、区間積取得）

// 入力の範囲内で要件
// (1) LがRの基点付きマグマ構造である。
// (2) MがUの「Lの基点がUの恒等変換に対応するUの左L作用つきN加群構造」である。
// (3) R=intならばL作用とN加群構造が整合的である。
// を満たす場合にのみサポート。

// 区間作用を行わない場合もm_L.Point()の作用を区間積に用いるため、
// dummyにせずMultiplicativeMonoid(1)などを用いる必要があることに注意。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})（Mのモノイド性を使う）

// 一点代入O(N^{1/2})（MのN加群性を使う）
// 区間代入O(N^{1/2})（MのN加群性を使う）
// M.Product()による一点乗算はなし。
// M.Product()による区間乗算O(N^{1/2})（Mの可換性を使う）
// M.Act()による一点作用はなし。
// M.Act()による区間作用O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class IntervalMultiplyLazySqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_M;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
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
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N = 0 );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , const int& N , const int& N_sqrt );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a );
  inline IntervalMultiplyLazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const int& N_sqrt );
  
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
