// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a.hpp

#pragma once
#include "../a_Macro.hpp"
// verify:
// https://yukicoder.me/submissions/955169（零初期化、一点乗算、区間積）
// https://yukicoder.me/submissions/950344（配列初期化、一点代入、区間積）

// 入力の範囲内で要件
// (1) MがUの可換モノイド構造である。
// を満たす場合にのみサポート。
// 一点乗算以外はMonoidBITの下位互換であるので一点乗算が不要ならMonoidBITを使えば良い。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する区間積取得O(N^{1/2})

// 一点代入O(N^{1/2})
// M.Product()による一点乗算O(1)（可換性を使う）

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序可換モノイド構造である。
// (3) m_a,m_bの全ての成分がM.One()以上である。
// を満たす場合にのみサポート。
// M.Product()に関する区間積の値探索O(N^{1/2})
template <typename U , typename COMM_MONOID>
class MonoidSqrtDecomposition
{

protected:
  COMM_MONOID m_M;
  int m_N;
  int m_N_sqrt;
  int m_N_d;
  int m_N_m;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  inline MonoidSqrtDecomposition( COMM_MONOID M , const int& N );
  inline MonoidSqrtDecomposition( COMM_MONOID M , const int& N , const int& N_sqrt );
  inline MonoidSqrtDecomposition( COMM_MONOID M , vector<U> a );
  inline MonoidSqrtDecomposition( COMM_MONOID M , vector<U> a , const int& N_sqrt );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Multiply( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( i_start , i ) , i )がtrueとなるi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalProduct( i_start , i )を満たすi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  inline int Search( const int& i_start , const U& u );
  
private:
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  
};
template <typename COMM_MONOID , typename...Args> MonoidSqrtDecomposition( COMM_MONOID M , Args&&...args ) -> MonoidSqrtDecomposition<inner_t<COMM_MONOID>,COMM_MONOID>;
