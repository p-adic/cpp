// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/CumulativeProd/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/950030（矩形和）

// ２次元配列上の累積和。
// 入力の範囲内で要件
// (1) MがUの可換群構造である。
// が成り立つ場合のみサポート。

// 配列による初期化O(size_X*size_Y)

// 始矩形和O(1)
// 矩形和O(1)
template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalCumulativeSum
{

private:
  ABELIAN_GROUP m_M;
  int m_size_X;
  int m_size_Y;
  vector<vector<U>> m_a;

public:
  AbstractTwoDimensionalCumulativeSum( ABELIAN_GROUP M , const vector<vector<U>>& a = vector<vector<U>>() );

  inline void Set( const vector<vector<U>>& a );
  
  // 条件
  // (1) -1 <= i_final_x < m_size_X
  // (2) -1 <= i_final_y < m_size_Y
  // を満たす場合のみサポート。
  // a[0][i_start_y]...a[i_final_x][i_start_y]...
  // a[0][i_final_y]...a[i_final_x][i_final_y]
  // をMに関して計算する。
  inline const U& InitialRectangleSum( const int& i_x , const int& i_y ) const;

  // 条件
  // (1) 0 <= i_start_xかつi_start_x-1 <= i_final_x < m_size_X
  // (2) 0 <= i_start_yかつi_start_y-1 <= i_final_y < m_size_Y
  // を満たす場合のみサポート。
  // a[i_start_x][i_start_y]...a[i_final_x][i_start_y]...
  // a[i_start_x][i_final_y]...a[i_final_x][i_final_y]
  // をMに関して計算する。
  inline U RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y );

};

template <typename U = ll>
class TwoDimensionalCumulativeSum :
  public AbstractTwoDimensionalCumulativeSum<U,AdditiveGroup<U>>
{

public:
  inline TwoDimensionalCumulativeSum( const vector<vector<U>>& a = vector<vector<U>>() );
  
};
