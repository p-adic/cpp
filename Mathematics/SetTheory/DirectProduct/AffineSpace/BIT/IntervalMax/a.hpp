// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "../a_Macro.hpp"
#include "../../../../../Algebra/Monoid/Semilattice/a.hpp"

// verify:
// https://yukicoder.me/submissions/982703（IntervalMaxBIT、SetMax, IntervalMax）
// https://yukicoder.me/submissions/979134（IntervalMinBIT、SetMin, IntervalMin）

// 入力の範囲内で要件
// (1) MがUの可換羃等モノイド構造である。
// を満たす場合にのみサポート。

// 配列による初期化O(size)

// 一点取得O(1)
// M.Product()に関するLSB切片積取得O(1)（left:a[j-(j&-j)]*...*a[j-1]、right:a[j-1]*...*a[j+(j&-j)-1]）
// M.Product()に関する区間積取得O(log_2 size)

// 一点代入O((log_2 size)^2)
// M.Product()に関する一点乗算O(log_2 size)（可換性と羃等性を用いる）
// M.Product()に関する区間乗算O(i_final-i_start+log_2 size)（可換性と羃等性を用いる）

// uを吸収する（uに吸収される）要素の添字の最小値の二分探索O(log_2 size)
// （存在しない場合はsize以上の最小の2羃×2-1を返すので、size以上であることで判定可能）

// そのうちの区間積取得と一点乗算は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法を一般の可換羃等モノイドに拡張することで実装
template <typename U , typename COMM_IDEM_MONOID>
class IdempotentMonoidBIT
{
private:
  COMM_IDEM_MONOID m_M;
  int m_size;
  vector<U> m_a;
  vector<U> m_fenwick_0;
  vector<U> m_fenwick_1;
  int m_power;

public:
  inline IdempotentMonoidBIT( COMM_IDEM_MONOID M , const int& size = 0 );
  inline IdempotentMonoidBIT( COMM_IDEM_MONOID M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  void Set( const int& i , const U& u );

  void Multiply( const int& i , const U& u );
  void IntervalMultiply( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  inline const U& operator[]( const int& i ) const;
  inline const U& Get( const int& i ) const;
  inline const U& LSBSegmentProduct( const int& j , const bool& left = true ) const;
  U IntervalProduct( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( IntervalProduct( 0 , i ) , i )がtrueとなるiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int BinarySearch( const F& f );
  // IntervalProduct( 0 , i )がuを吸収する（max演算ならu以上、min演算ならu以下となる）
  // iが存在する場合にその最小値を2進法で探索。存在しない場合はNを返す。
  int BinarySearch( const U& u );

private:
  inline void Construct();
  
};
template <typename COMM_IDEM_MONOID> IdempotentMonoidBIT( COMM_IDEM_MONOID M ) -> IdempotentMonoidBIT<inner_t<COMM_IDEM_MONOID>,COMM_IDEM_MONOID>;

// 以下は入力の範囲で要件
// (1)' bool operator<(const U&,const U&)が全順序である。
// を満たす場合にのみサポート。
template <typename U>
class IntervalMaxBIT :
  public IdempotentMonoidBIT<U,MaxSemilattice<U>>
{

public:
  template <typename...Args> inline IntervalMaxBIT( const U& zero_U , Args&&... args );
  inline void SetMax( const int& i , const U& u );
  inline void IntervalSetMax( const int& i_start , const int& i_final , const U& u );
  inline const U& LSBSegmentMax( const int& j , const bool& left = true ) const;
  inline U IntervalMax( const int& i_start , const int& i_final );

};

template <typename U>
class IntervalMinBIT :
  public IdempotentMonoidBIT<U,MinSemilattice<U>>
{

public:
  template <typename...Args> inline IntervalMinBIT( const U& infty_U , Args&&... args );
  inline void SetMin( const int& i , const U& u );
  inline void IntervalSetMin( const int& i_start , const int& i_final , const U& u );
  inline const U& LSBSegmentMin( const int& j , const bool& left = true ) const;
  inline U IntervalMin( const int& i_start , const int& i_final );

};
