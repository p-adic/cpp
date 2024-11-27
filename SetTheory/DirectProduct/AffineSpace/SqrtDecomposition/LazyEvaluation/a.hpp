// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/LazyEvaluation/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../Sqrt/a.hpp"

//verify:
// https://onlinejudge.u-aizu.ac.jp/status/users/padic/submissions/1/DSL_2_I/judge/9389144/C++17（零初期化、区間代入、区間積取得）
// https://yukicoder.me/submissions/1021517 (配列初期化、区間作用、区間積探索)

// 入力の範囲内で要件
// (1) LはRの基点付きマグマ構造である。
// (2) MはUの左L作用付き非可換N加群構造であって、Lの基点がMの恒等変換に対応する。
// (3) R=intならばMの左L作用と非可換N加群構造が整合的である。
// を満たす場合にのみサポート。
// 作用を使わない場合はより要件の緩いIntervalSetSqrtDecompositionが使用可能。
// 区間乗算を追加しても要件と計算量のオーダーは変わらないが、定数倍遅くなる。

// 区間作用を行わない場合もm_L.Point()の作用を区間積に用いるため、
// dummyにせずRegularRSet(MultiplicativeMonoid(1))などを用いる必要があることに注意。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点代入O(N^{1/2})（Mの非可換N加群性を使う。何も遅延評価されていない時はO(1)）
// 区間代入O(N^{1/2})（Mの非可換N加群性を使う）
// M.Act()による一点作用はなし。
// M.Act()による区間作用O(N^{1/2})

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})（Mのモノイド性を使う）

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序可換モノイド構造である。
// (3) m_a,m_bの全ての成分がM.One()以上である。
// を満たす場合にのみサポート。
// M.Product()に関する区間積の値探索O(N^{1/2})
template <typename R , typename PT_MAGMA , typename U , typename RN_BIMODULE>
class LazySqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  PT_MAGMA m_L;
  RN_BIMODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  // 代入の遅延評価。過去の作用の遅延評価を棄却する。
  // 区間作用はここに即座に適用する。
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  // 作用の遅延評価。
  vector<R> m_lazy_action;

public:
  // vectorを構築する時は
  // vector t( N , LazySqrtDecomposition{L,M} );
  // としてInitialiseすればよい。
  template <typename...Args> inline LazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline LazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , vector<U> a , const Args&... args );
  
  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );
  inline void IntervalAct( const int& i_start , const int& i_final , const R& r );

  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( i_start , i ) , i )がtrueとなるi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f , const bool& reversed = false );
  // u <= IntervalProduct( i_start , i )を満たすi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  inline int Search( const int& i_start , const U& u , const bool& reversed = false );

private:
  inline void Construct();
  inline void SetProduct( const int& i );
  inline void SolveSuspendedSubstitution( const int& d , const U& u );
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  // 細かく区間を指定した方が速いが、そのi_minとi_ulimの位置関係でバグらせやすいのでこのまま。
  inline void SolveSuspendedAction( const int& d );
  inline void IntervalAct_Body( const int& i_min , const int& i_ulim , const R& r );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );

  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );
  
};
template <typename PT_MAGMA , typename RN_BIMODULE , typename...Args> LazySqrtDecomposition( PT_MAGMA L , RN_BIMODULE M , const Args&... args ) -> LazySqrtDecomposition<inner_t<PT_MAGMA>,PT_MAGMA,inner_t<RN_BIMODULE>,RN_BIMODULE>;

// 例えば
// LazySqrtDecomposition lsd{ MultiplicativeMonoid<int>{ 1 } , Module<int,ll>() , N };
// LazySqrtDecomposition lsd{ MultiplicativeMonoid<U>{ 1 } , BiModule<U,int,U>() , N };
// で区間スカラー倍更新と区間和取得が可能。
