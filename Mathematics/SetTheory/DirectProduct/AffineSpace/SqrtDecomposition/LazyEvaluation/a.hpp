// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) LがRの基点付きマグマ構造である。
// (2) MがUの「Lの基点がUの恒等変換に対応するUの左L作用つきN加群構造」である。
// (3) R!=intである。（L作用とN加群構造の区別のため）
// を満たす場合にのみサポート。
// 区間乗算を追加しても要件と計算量のオーダーは変わらないが、定数倍遅くなる。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})（Mのモノイド性を使う）

// 一点代入O(N^{1/2})（MのN加群性を使う）
// 区間代入O(N^{1/2})（MのN加群性を使う）
// M.Act()による一点作用はなし。
// M.Act()による区間作用O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename R_MODULE>
class LazySqrtDecomposition
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

public:
  inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a );
  inline LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const int& N_sqrt );
  
  template <typename...Args> inline void Reset( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

private:
  inline void Initialise();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  
};
template <typename PT_MAGMA , typename U , typename R_MODULE , typename...Args> LazySqrtDecomposition( PT_MAGMA L , R_MODULE M , vector<U> a , const Args&... args ) -> LazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,U,R_MODULE>;
