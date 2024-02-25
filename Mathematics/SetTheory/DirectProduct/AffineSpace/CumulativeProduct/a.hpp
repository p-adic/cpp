// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../../Algebra/Monoid/Group/a.hpp"

// verify:
// https://yukicoder.me/submissions/950143（Abstract、配列初期化、左累積積）
// https://yukicoder.me/submissions/950139（配列初期化、区間和）
// https://atcoder.jp/contests/agc023/submissions/50204861（配列初期化、区間和逆像数え上げ）

// 木上で群に値を持つ関数の累積積を計算する。
template <typename U>
class VirtualCumulativeProduct
{

public:
  // 0 <= i,j < m_sizeの場合のみサポート。
  // iからへのpathがi=v_0->...->v_k=jの時、Setした配列aに対する
  // 右総乗a[v_0]...a[v_k]を計算する。
  virtual U PathProduct( const int& i , const int& j ) = 0;

protected:
  virtual int Parent( const int& i ) = 0;
  virtual int LCA( const int& i , const int& j ) = 0;

};

template <typename U , typename GROUP>
class PathProductImplementation :
  virtual public VirtualCumulativeProduct<U>
{

protected:
  int m_size;
  GROUP m_M;
  vector<U> m_right;
  vector<U> m_left;

public:
  inline PathProductImplementation( const int& size , GROUP M );
  inline U PathProduct( const int& i , const int& j );

};

// 木が特に通常の配列である場合。
// 入力の範囲内で要件
// (1) MがUの群構造である。
// が成り立つ場合にのみサポート。

// M.one()による初期化O(size)
// 配列による初期化O(size)

// 一点左乗算O(size)
// 一点右乗算O(size)

// 右区間積取得O(1)
// 左区間積取得O(1)

// 右区間積逆像数え上げO(size log size)
// 右区間積逆像数え上げO(size log size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.One()より小さくない。
// を満たす場合にのみサポート。
// 左端点を固定した時に左区間積がu以上となる要素の添字の最小値の二分探索O(log_2 size)
// 左端点を固定した時に右区間積がu以上となる要素の添字の最小値の二分探索O(log_2 size)
template <typename U , typename GROUP>
class AbstractCumulativeProduct :
  public PathProductImplementation<U,GROUP>
{

public:
  inline AbstractCumulativeProduct( GROUP M , const vector<U>& a = vector<U>() );

  inline void Set( const vector<U>& a );
  // a[i]をM.Product(a[i],u)に置き変える。
  inline void RightMultiply( const int& i , const U& u );
  // a[i]をM.Product(u,a[i])に置き変える。
  inline void LeftMultiply( const int& i , const U& u );

  // 0 <= iかつi-1 <= j < m_sizeの場合のみサポート。
  // 右区間積a[i]...a[j]をMに関して計算する。
  inline U RightIntervalProduct( const int& i , int j );
  // 左区間積a[j]...a[i]をMに関して計算する。
  inline U LeftIntervalProduct( const int& i , int j );

  // 以下はM.Product()しか使用しないので、M.Product()が群演算でさえあればM.One()とM.Inverse()が無関係な演算でもよい。
  // Mに関する右区間積a[i]...a[j]がuと等しい区間[i,j]の個数を計算する。
  ll CountRightIntervalProductInverseImage( const U& u = One() );
  // Mに関する左区間積a[j]...a[i]がuと等しい区間[i,j]の個数を計算する。
  ll CountLeftIntervalProductInverseImage( const U& u = One() );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( RightIntervalProduct( i_start , i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int RightBinarySearch( const int& i_start , const F& f );
  // f( LeftIntervalProduct( i_start , i ) , i )がtrueとなるi_start以上のiが
  // 存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_CP_BS = nullptr> int LeftBinarySearch( const int& i_start , const F& f );
  // RightIntervalProduct( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  int RightBinarySearch( const int& i_start , const U& u );
  // LeftIntervalProduct( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  int LeftBinarySearch( const int& i_start , const U& u );
  
private:
  inline int Parent( const int& i );
  inline int LCA( const int& i , const int& j );
  inline const U& One() const;

};
template <typename GROUP> AbstractCumulativeProduct( GROUP M ) -> AbstractCumulativeProduct<inner_t<GROUP>,GROUP>;

template <typename U>
class CumulativeSum :
  public AbstractCumulativeProduct<U,AdditiveGroup<U>>
{

public:
  inline CumulativeSum( const int& size = 0 );
  inline CumulativeSum( const vector<U>& a );

  // a[i]をM.Sum(u,a[i])に置き変える。
  inline void Add( const int& i , const U& u );

  // 区間和a[i]+...+a[j]を計算する。
  inline U IntervalSum( const int& i , int j );

  // 区間和a[i]+...+a[j]がuと等しい区間[i,j]の個数を計算する。
  ll CountIntervalSumInverseImage( const U& u = U() );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型またはU。
  // 前者の場合はf( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上のiが、
  // 後者の場合はIntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F> int BinarySearch( const int& i_start , const F& f );

};
