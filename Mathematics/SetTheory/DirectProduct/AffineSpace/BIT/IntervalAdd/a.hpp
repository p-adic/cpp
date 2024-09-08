// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// https://yukicoder.me/submissions/982716（一点加算、区間加算、一点取得）

// 入力の範囲内で要件
// (1) MがUのZ加群構造である。
// を満たす場合にのみサポート。

// 配列による初期化O(size)

// 一点取得O(log_2 size)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点代入O(log_2 size)
// m_M.Sum()による一点加算O(log_2 size)
// m_M.Sum()による区間加算O(log_2 size)

// 以下は入力の範囲内で要件
// (2) operator<(const U&,const U&)に関してMがUの全順序可換群構造である。
// (3) 各成分がM.Zero()より小さくない。
// を満たす場合にのみサポート。
// U.Sum()による始切片和がu以上となる要素の添字の最小値の二分探索O((log_2 size)^2)
// 左端点を固定した時にU.Sum()による区間和がu以上となる要素の添字の最小値の二分探索O((log_2 size)^2)
template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
  
protected:
  Z_MODULE m_M;
  // 次数を1ずらした負の階差数列の微分（-(i-1)(a_i - a_{i-1})）をBITで管理
  AbstractBIT<U,Z_MODULE> m_bit_0;
  // 階差数列（a_i - a_{i-1}）をBITで管理
  AbstractBIT<U,Z_MODULE> m_bit_1;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const int& size = 0 );
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( InitialSegmentSum( i ) , i )がtrueとなるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はN以上の最小の2羃×2-1を返す（N以上であることで判別可能）。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> int Search( const F& f );
  // f( IntervalSum( i_start , i ) , i )がtrueとなるi_start以上のiが存在する場合に
  // その最小値を2進法で探索。存在しない場合はNを返す。
  template <typename F , SFINAE_FOR_BIT_BS = nullptr> inline int Search( const int& i_start , const F& f );

  // InitialSegmentSum( i )がu以上となるiが存在する場合にその最小値を2進法で探索。
  // 存在しない場合はNを返す。
  inline int Search( const U& u );
  // IntervalSum( i_start , i )がu以上となるi_start以上のiが存在する場合にその最小値を
  // 2進法で探索。存在しない場合はNを返す。
  inline int Search( const int& i_start , const U& u );

};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddBIT :
  public AbstractIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddBIT( const Args&... args );
  
};
template <typename U> IntervalAddBIT( const vector<U>& a ) -> IntervalAddBIT<U>;
