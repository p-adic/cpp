// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Abstract/a.hpp

#pragma once
#include "../../Abstract/a.hpp"

// verify:
// https://yukicoder.me/submissions/947868（一点加算、区間加算、一点取得）

// 演算がoperator+=などで与えられている場合は特殊化ではなく
// ../a.hpp
// を使うことでファイル容量を削減する。

// 入力の範囲内で要件
// (1) MがUのZ加群構造である。
// を満たす場合にのみサポート。

// 配列による初期化O(size)

// 一点取得O(log_2 size)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// m_M.Sum()による一点更新O(log_2 size)
// m_M.Sum()による区間更新O(log_2 size)
// 配列の加算による全体更新O(size)
template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
private:
  int m_size;
  Z_MODULE m_M;
  // 母関数の微分の負の階差数列（(i-1)a_{i-1} - ia_i）の管理
  AbstractBIT<U,Z_MODULE> m_bit_0;
  // 階差数列（a_i - a_{i-1}）の管理
  AbstractBIT<U,Z_MODULE> m_bit_1;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a = vector<U>() );

  inline void Set( const int& i , const U& u );
  inline void Set( const vector<U>& a );

  inline AbstractIntervalAddBIT<U,Z_MODULE>& operator+=( const vector<U>& a );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );
  
};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;
