// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/950346（区間作用、一点取得）
// https://yukicoder.me/submissions/950347（区間作用、一点取得）

// 入力の範囲内で要件
// (1) LがRの基点付きマグマ構造である。
// (2) XがUの「Lの基点がUの恒等変換に対応するUの左L作用構造」である。
// を満たす場合にのみサポート。
// Mに可換性を課す場合は一点作用がO(1)のCommutativeDualSqrtDecompositionを使用。

// 配列による初期化O(N)

// 一点取得O(1)

// 一点代入O(N^{1/2})（ただし状況次第でO(1)）
// X.Action()による一点作用はなし（一点代入か区間作用を使う）
// X.Action()による区間作用O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class DualSqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_MODULE m_X;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<R> m_b;

public:
  inline DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a );
  inline DualSqrtDecomposition( PT_MAGMA L , R_MODULE X , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Act( const int& i , const R& r );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  // 参照返しでないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );

protected:
  // 作用の遅延評価を解消する。
  inline void Update( const int& d );
  
};
template <typename PT_MAGMA , typename U , typename R_MODULE , typename...Args> DualSqrtDecomposition( PT_MAGMA M , R_MODULE X , vector<U> a , Args&&... args ) -> DualSqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,U,R_MODULE>;

