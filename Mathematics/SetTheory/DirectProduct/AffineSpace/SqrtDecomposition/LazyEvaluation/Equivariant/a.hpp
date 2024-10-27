// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/Equivariant/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a.hpp"

//verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/9389155/C++17（零初期化、区間代入、区間積取得）

// TRANSは写像trans:U \times S \times N ->Uに相当する型である。

// 入力の範囲内で要件
// (1) LはRの基点付きマグマ構造である。
// (2) M0はSの左L集合構造であって、Lの基点がSの恒等変換に対応する。
// (3) M1はUの左L作用付き非可換N加群構造であって、Lの基点がMの恒等変換に対応する。
// (4) R=intならばUのL作用と非可換N加群構造が整合的である。
// (5) あるL同変写像univ:S->Uが存在して、任意の(u,s,n) in U \times S \times N
//     に対してtrans(u,s,n) = u*univ(s)*nである。
// を満たす場合にのみサポート。

// 区間作用を行わない場合もm_L.Point()の作用を区間積に用いるため、
// dummyにせずRegularRSet(MultiplicativeMonoid(1))などを用いる必要があることに注意。

// 配列による初期化O(N)

// 一点代入O(N^{1/2})はなし。
// 区間代入O(N^{1/2})（M1の非可換N加群性を使う）
// M0.Act()による一点作用はなし。
// M0.Act()による区間作用O(N^{1/2})（univのL同変性を使う）

// 一点取得O(1)
// transに関する区間積取得O(N^{1/2})（M1のモノイド性を使う）

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序可換モノイド構造である。
// (3) m_a,m_bの全ての成分がM.One()以上である。
// を満たす場合にのみサポート。
// M.Product()に関する区間積の値探索O(N^{1/2})
template <typename R , typename PT_MAGMA , typename S , typename R_SET , typename U , typename RN_BIMODULE , typename TRANS>
class EquivariantLazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  R_SET m_M0;
  RN_BIMODULE m_M1;
  TRANS m_trans;
  vector<S> m_a;
  vector<U> m_b;
  // 代入の遅延評価。過去の作用の遅延評価を棄却する。
  // 区間作用はここに即座に適用する。
  vector<S> m_lazy_substitution;
  vector<bool> m_suspended;
  // 作用の遅延評価。
  vector<R> m_lazy_action;

public:
  // vectorを構築する時は
  // vector t( N , EquivariantLazySqrtDecomposition{L,M0,M1,vector<S>()} );
  // としてInitialiseすればよい。
  template <typename...Args> inline EquivariantLazySqrtDecomposition( PT_MAGMA L , R_SET M0 , RN_BIMODULE M1 , TRANS trans , vector<S> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const S& s );
  inline void IntervalSet( const int& i_start , const int& i_final , const S& s );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline S operator[]( const int& i );
  inline S Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( i_start , i ) , i )がtrueとなるi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f , const bool& reversed = false );
  // u <= IntervalProduct( i_start , i )を満たすi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  inline int Search( const int& i_start , const U& u , const bool& reversed = false );

private:
  inline U Univ( const S& s , const int& n );
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const S& s );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const S& s );
  // 細かく区間を指定した方が速いが、そのi_minとi_ulimの位置関係でバグらせやすいのでこのまま。
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );

  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );
  
};
template <typename PT_MAGMA , typename S , typename R_SET , typename RN_BIMODULE , typename TRANS , typename...Args> EquivariantLazySqrtDecomposition( PT_MAGMA L , R_SET M0 , RN_BIMODULE M1 , TRANS trans , vector<S> a , const Args&... args ) -> EquivariantLazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,S,R_SET,inner_t<RN_BIMODULE>,RN_BIMODULE,TRANS>;
