// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a.hpp

#pragma once
#include "a_macro.hpp"

#include "Sqrt/a.hpp"

// verify:
// https://yukicoder.me/submissions/981574（零初期化、一点加算、区間和）

// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// を満たす場合にのみサポート。
// ただしM.Inverse()は一点代入にのみ使用するので一点代入をしないならばM.Inverse()を
// 適当に定義すれば良いが、それよりはモノイド平方分割を使えばよい。
// また一点加算以外はHybridBITの下位互換であるので一点加算が不要ならHybridBITを使えば良い。

// M.Zero()による初期化O(N)
// 配列による初期化O(N)

// 一点代入O(1)（可換性と逆元を使う）
// M.Sum()による一点加算O(1)（可換性を使う）

// 一点取得O(1)
// M.Sum()に関する区間和取得O(N^{1/2})

// 以下入力の範囲内で要件
// (2) bool operator<(const U&,const U&)に関してMがUの全順序可換モノイド構造である。
// (3) m_a,m_bの全ての成分がM.Zero()以上である。
// を満たす場合にのみサポート。
// M.Sum()に関する区間和の値探索O(N^{1/2})
template <typename U , typename ABELIAN_GROUP>
class AbstractSqrtDecomposition :
  public SqrtDecompositionCoordinate
{

private:
  ABELIAN_GROUP m_M;
  vector<U> m_a;
  vector<U> m_b;
  
public:
  template <typename...Args> inline AbstractSqrtDecomposition( ABELIAN_GROUP M , const int& N = 0 , const Args&... args );
  template <typename...Args> inline AbstractSqrtDecomposition( ABELIAN_GROUP M , vector<U> a , const Args&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );

  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline U IntervalSum( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  template <typename F , SFINAE_FOR_SD_S = nullptr> inline int Search( const int& i_start , const F& f );
  // u <= IntervalSum( i_start , i )を満たすi_start以上の最小のiを探索。
  // 存在しない場合は-1を返す。
  inline int Search( const int& i_start , const U& u );
  
private:
  void Construct();
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  
};
template <typename ABELIAN_GROUP , typename...Args> AbstractSqrtDecomposition( ABELIAN_GROUP M , Args&&...args ) -> AbstractSqrtDecomposition<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class SqrtDecomposition :
  public AbstractSqrtDecomposition<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline SqrtDecomposition( Args&&... args );
  
};
template <typename U , typename...Args> SqrtDecomposition( vector<U> a , Args&&...args ) -> SqrtDecomposition<U>;
