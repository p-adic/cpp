// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/961729（区間作用、一点取得）
// https://yukicoder.me/submissions/961738（非結合的マグマ、区間作用、一点取得）

// 入力の範囲内で要件
// (1) LがRの基点付き左作用構造（例えば基点付きマグマの正則左加群構造）である。
// (2) XがUの左L作用構造であって以下を満たす：
//     (2-1) Lの基点がXの恒等変換に対応する。
//     (2-2) Lの左作用とXの左作用が結合的である。（例えばマグマ作用である）
// を満たす場合にのみサポート。
// Lに可換マグマ性を課す場合は一点作用がO(1)のCommutativeDualSqrtDecompositionが使用可。

// 配列による初期化O(N)

// 一点取得O(1)

// 一点代入O(N^{1/2})（ただし状況次第でO(1)）
// X.Action()による一点作用はなし（一点代入か区間作用を使う）
// X.Action()による区間作用O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_SET>
class DualSqrtDecomposition
{

protected:
  PT_MAGMA m_L;
  R_SET m_X;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<R> m_b;

public:
  inline DualSqrtDecomposition( PT_MAGMA L , R_SET X , vector<U> a = {} );
  inline DualSqrtDecomposition( PT_MAGMA L , R_SET X , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  // ArgはL.Actionの第1引数として有効な型。
  template <typename Arg> inline void IntervalAct( const int& i_start , const int& i_final , const Arg& r );

  // 参照返しでないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );

protected:
  // 作用の遅延評価を解消する。
  inline void Update( const int& d );
  
};
template <typename PT_MAGMA , typename R_SET , typename...Args> DualSqrtDecomposition( PT_MAGMA M , R_SET X , Args&&... args ) -> DualSqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<R_SET>,R_SET>;

