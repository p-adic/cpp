// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/972299（配列初期化、区間和）
// https://atcoder.jp/contests/agc023/submissions/52375150（配列初期化、区間和逆像数え上げ）
// https://yukicoder.me/submissions/972330（Abstract、配列初期化、左累積積）

// 入力の範囲内で要件
// (1) MがUの群構造である。
// が成り立つ場合にのみサポート。

// 群に値を持つ配列の累積積を計算する。
// ただし区間積か区間積の二分探索を用いない場合はモノイド構造にidなどのダミーで
// Inverseを定めたものでよい。

// 木構造に抽象化する場合は
// - 可換群で部分木和が必要ならばAbstractDifferenceSequence
// - 可換群で区間和が必要ならばAbstractReversedDifferenceSequence
// - モノイドで経路和が必要ならばDepthFirstSearchOnWeightedTree
// を用いるので、ここでは非可換群と配列に特化させた累積積を扱う。


// M.one()による初期化O(size)（モノイド構造を使う）
// 配列による初期化O(size)（半群構造を使う）

// 一点代入O(size)（半群構造を使う）
// 一点右乗算O(size)（半群構造を使う）
// 一点左乗算O(size)（半群構造を使う）

// 右始切片積取得O(1)（モノイド構造を使う）
// 左始切片積取得O(1)（モノイド構造を使う）

// 右区間積取得O(1)（群構造を使う）
// 左区間積取得O(1)（群構造を使う）

// 右区間積逆像数え上げO(size log size)（半群構造を使う）
// 左区間積逆像数え上げO(size log size)（半群構造を使う）

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序群構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// 左始切片積がu以上となる要素の添字の最小値の二分探索O(log_2 size)（全順序モノイド構造を使う）
// 右始切片積がu以上となる要素の添字の最小値の二分探索O(log_2 size)（全順序モノイド構造を使う）
// 左区間積がu以上となる要素の添字の最小値の二分探索O(log_2 size)（全順序群構造を使う）
// 右区間積がu以上となる要素の添字の最小値の二分探索O(log_2 size)（全順序群構造を使う）
template <typename U , typename GROUP>
class AbstractCumulativeProduct
{

private:
  GROUP m_M;
  int m_size;
  // 元の配列を格納。
  vector<U> m_a;
  // 右区間積a[0]*...*a[i-1]を格納。
  vector<U> m_right;
  // 左区間積a[0]*...*a[i-1]を格納。
  vector<U> m_left;

public:
  inline AbstractCumulativeProduct( GROUP M , const int& size = 0 );
  inline AbstractCumulativeProduct( GROUP M , vector<U> a );

  template <typename...Args> inline void Initialise( Args&&... args );
  // a[i]をuに置き変える。
  inline void Set( const int& i , U u );
  // a[i]をM.Product(a[i],u)に置き変える。
  inline void RightMultiply( const int& i , const U& u );
  // a[i]をM.Product(u,a[i])に置き変える。
  inline void LeftMultiply( const int& i , U u );

  // 0 <= i_final < m_sizeの場合のみサポート。
  // 右始切片積a[0]...a[i_final]をMに関して計算する。
  inline const U& RightInitialSegmentProduct( int i_final );
  // 左始切片積a[i_final]...a[0]をMに関して計算する。
  inline const U& LeftInitialSegmentProduct( int i_final );

  // 0 <= i_startかつi_start-1 <= i_final < m_sizeの場合のみサポート。
  // 右区間積a[i_start]...a[i_final]をMに関して計算する。
  inline U RightIntervalProduct( const int& i_start , int i_final );
  // 左区間積a[i_final]...a[i_start]をMに関して計算する。
  inline U LeftIntervalProduct( const int& i_start , int i_final );

  // Mに関する右区間積a[i]...a[j]がuと等しい区間[i,j]の個数を計算する。
  ll CountRightIntervalProductInverseImage( const U& u );
  // Mに関する左区間積a[j]...a[i]がuと等しい区間[i,j]の個数を計算する。
  ll CountLeftIntervalProductInverseImage( const U& u );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( RightInitialSegmentProduct( i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const F& f );
  // f( LeftInitialSegmentProduct( i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const F& f );
  // f( RightIntervalProduct( i_start , i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const int& i_start , const F& f );
  // f( LeftIntervalProduct( i_start , i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const int& i_start , const F& f );
  // RightInitialSegmentProduct( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  int RightBinarySearch( const U& u );
  // LeftInitialSegmentProduct( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  int LeftBinarySearch( const U& u );
  // RightIntervalProduct( i_start , i )がu以上となるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。存在しない場合はNを返す。
  int RightBinarySearch( const int& i_start , const U& u );
  // LeftIntervalProduct( i_start , i )がu以上となるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。存在しない場合はNを返す。
  int LeftBinarySearch( const int& i_start , const U& u );
  
};
template <typename GROUP , typename...Args> AbstractCumulativeProduct( GROUP M , Args&&... args ) -> AbstractCumulativeProduct<inner_t<GROUP>,GROUP>;

template <typename U>
class CumulativeSum :
  public AbstractCumulativeProduct<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline CumulativeSum( Args&&... args );

  // a[i]をM.Sum(u,a[i])に置き変える。
  inline void Add( const int& i , const U& u );

  // 始切片和a[0]+...+a[i_final]を計算する。
  inline const U& InitialSegmentSum( int i_final );

  // 区間和a[i_start]+...+a[i_final]を計算する。
  inline U IntervalSum( const int& i_start , int i_final );

  // 区間和a[i]+...+a[j]がuと等しい区間[i,j]の個数を計算する。
  ll CountIntervalSumInverseImage( const U& u = U() );

  template <typename...Args> int BinarySearch( const Args&... args );

};
template <typename U> CumulativeSum( vector<U> ) -> CumulativeSum<U>;


// 乗法群に使いたい状況と乗法モノイドに使いたい状況が同程度であるため
// 非AbstractなCumulativeProductは定義せずAbstractを使う。
