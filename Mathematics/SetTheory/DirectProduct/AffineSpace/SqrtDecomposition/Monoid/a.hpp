// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/a.hpp

#pragma once
#include "../a_Macro.hpp"

#include "../Sqrt/a.hpp"

// verify:
// https://yukicoder.me/submissions/981581（配列初期化、一点代入、区間積）

// 入力の範囲内で要件
// (1) MがUのモノイド構造である。
// を満たす場合にのみサポート。
// 可換モノイド平方分割の基底クラスのための型でありこれ単体ではMonoidBITの下位互換である。

// M.One()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Product()に関する右区間積取得O(N^{1/2})（IntervalProduct(l,r)でa[l]*...*a[r]を返す）

// 一点代入O(N^{1/2})

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序モノイド構造である。
// (3) m_a,m_bの全ての成分がM.One()以上である。
// を満たす場合にのみサポート。
// M.Product()に関する区間積の値探索O(N^{1/2})
template <typename U , typename MONOID>
class MonoidSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

protected:
  MONOID m_M;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  template <typename...Args> inline MonoidSqrtDecomposition( MONOID M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline MonoidSqrtDecomposition( MONOID M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );

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
  template <typename F> int Search_Body( const int& i_start , const F& f , U product_temp );
  
};
template <typename MONOID , typename...Args> MonoidSqrtDecomposition( MONOID M , Args&&...args ) -> MonoidSqrtDecomposition<inner_t<MONOID>,MONOID>;

// 例えばmaxを演算にする時はMaxSemilattice{ 0LL }などを渡す。
// Searchの大小判定を逆にしたい時は配列を-1倍する。

