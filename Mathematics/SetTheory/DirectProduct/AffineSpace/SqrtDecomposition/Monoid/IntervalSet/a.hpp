// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/IntervalSet/a.hpp

#pragma once
#include "../../a_Macro.hpp"

#include "../../Sqrt/a_Body.hpp"

// verify:
// https://yukicoder.me/submissions/964805（配列初期化、一点代入、区間積）
// https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I（零初期化、区間代入、区間積取得）
// https://yukicoder.me/submissions/964836（配列初期化、区間代入、区間積取得）

// 入力の範囲内で要件
// (1) MがUの非可換N加群構造である。
// を満たす場合にのみサポート。
// コンストラクタ以外の多くの実装がモノイド平方分割と異なるため継承しない。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})

// 一点代入O(N^{1/2})（区間代入を使う）
// 区間代入O(N^{1/2})（非可換N加群構造を使う）
template <typename U , typename NON_COMM_N_MODULE>
class IntervalSetSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  NON_COMM_N_MODULE m_M;
  vector<U> m_a;
  vector<U> m_b;
  vector<U> m_lazy_substitution;
  vector<bool> m_suspended;
  
public:
  // MonoidSqrtDecompositionのコンストラクタとm_lazy_substitution,m_suspendedの零初期化
  template <typename...Args> inline IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalSet( const int& i_start , const int& i_final , const U& u );

  // 参照返しでないことに注意
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
  inline void IntervalSet_Body( const int& i_min , const int& i_ulim , const U& u );
  inline U IntervalProduct_Body( const int& i_min , const int& i_ulim );
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );
  
};
template <typename NON_COMM_N_MODULE , typename...Args> IntervalSetSqrtDecomposition( NON_COMM_N_MODULE M , Args&&... args ) -> IntervalSetSqrtDecomposition<inner_t<NON_COMM_N_MODULE>,NON_COMM_N_MODULE>;
