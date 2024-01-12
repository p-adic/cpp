// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Template/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/942892（零初期化、一点加算、区間加算、一点取得）

// 演算がoperator+=でない場合に使用
// M_Tは乗算m_T:T^2->Tに相当する型。
// I_Tは逆元i_T:T->Tに相当する型。
// O_Tはスカラー倍o_T:N \times T->Tに相当する型。

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,e_T:1->T,o_T:N \times T->T)がN加群である。
// を満たす場合にのみサポート。

// e_T()による初期化O(size)
// 配列による初期化O(size)

// 一点取得O(log_2 size)
// 始切片和取得O(log_2 size)
// 区間和取得O(log_2 size)

// 一点更新O(log_2 size)
// m_Tによる一点更新O(log_2 size)
// m_Tによる区間更新O(log_2 size)
// 配列の加算による全体更新O(size)
template <typename T , typename M_T , typename I_T , typename O_T>
class AbstractIntervalAddBIT
{
private:
  M_T m_m_T;
  T m_e_T;
  I_T m_i_T;
  O_T m_o_T;
  int m_size;
  // 母関数の微分の負の階差数列（(i-1)a_{i-1} - ia_i）の管理
  AbstractBIT<T,M_T,I_T> m_bit_0;
  // 階差数列（a_i - a_{i-1}）の管理
  AbstractBIT<T,M_T,I_T> m_bit_1;
  
public:
  inline AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const int& size = 0 );
  inline AbstractIntervalAddBIT( M_T m_T , T e_T , I_T i_T , O_T o_T , const vector<T>& a );

  inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& operator=( AbstractIntervalAddBIT<T,M_T,I_T,O_T>&& a );

  inline void Set( const int& i , const T& n );
  inline void Set( const vector<T>& a );
  inline void Initialise( const int& size = 0 );

  inline AbstractIntervalAddBIT<T,M_T,I_T,O_T>& operator+=( const vector<T>& a );
  inline void Add( const int& i , const T& n );
  inline void IntervalAdd( const int& i_start , const int& i_final , const T& n );

  // const参照でないことに注意。
  inline T operator[]( const int& i ) const;
  inline T Get( const int& i ) const;
  inline T InitialSegmentSum( const int& i_final ) const;
  inline T IntervalSum( const int& i_start , const int& i_final ) const;
  
};
