// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/999929（零初期化、一点取得、矩形加算、矩形取得）
// https://yukicoder.me/submissions/961857（零初期化、一点取得、矩形加算）

// ２次元配列上の階差数列の高階化。基本的に２次元imos法
// https://imoz.jp/algorithms/imos_method.html
// に準拠。範囲更新が不要な場合は代わりにファイル容量の小さい２次元累積和を使用。

// 入力の範囲内で要件
// (1) MはUの可換群構造である。
// が成り立つ場合にのみサポート。

// M.Zero()による初期化O(size_X*size_Y)
// 配列による初期化O(size_X*size_Y)

// 一点代入O(|m_degree|*size_X*size_Y)
// 一点加算O(|m_degree|*size_X*size_Y)
// 始矩形加算O(|m_degree-1|*size_X*size_Y)
// 矩形加算O(|m_degree-1|*size_X*size_Y)

// 一点取得O(|m_degree|*size_X*size_Y)
// 始矩形取得O(|m_degree+1|*size_X*size_Y)
// 矩形取得O(|m_degree+1|*size_X*size_Y)

template <typename U , typename ABELIAN_GROUP>
class AbstractTwoDimensionalDifferenceSequence
{

private:
  ABELIAN_GROUP m_M;
  int m_size_X;
  int m_size_Y;

  // (0,0)からの階差数列を管理。
  vector<vector<U>> m_a;
  // 階差数列の階数（-1の時は累積和）を管理。
  int m_degree;
  
public:
  inline AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y , int degree = 1 );
  inline AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const vector<vector<U>>& a = {} , int degree = 0 );

  template <typename...Args> inline void Initialise( Args&&... args );
  const int& size_X() const noexcept;
  const int& size_Y() const noexcept;

  // degree階の階差数列の(i_x,i_y)での値にuを代入する。
  inline void Set( const int& i_x , const int& i_y , const U& u , const int& degree = 0 );
  // degree階の階差数列の(i_x,i_y)での値にuを加算する。
  inline void Add( const int& i_x , const int& i_y , const U& u , const int& degree = 0 );

  // degree+1階の階差数列を用いてdegree階の階差数列の(i_x,i_y)での値にuを加算する。
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u , const int& degree = 0 );

  // degree階の階差数列の値を取得する。
  inline const U& Get( const int& i_x , const int& i_y , const int& degree = 0 );

  // 条件
  // (1) -1 <= i_final_x < m_size_X
  // (2) -1 <= i_final_y < m_size_Y
  // を満たす場合のみサポート。degree-1階の階差数列を用いてdegree階の階差数列の値の総和
  // a[0][i_start_y]...a[i_final_x][i_start_y]...
  // a[0][i_final_y]...a[i_final_x][i_final_y]
  // をMに関して計算する。
  inline const U& InitialRectangleSum( const int& i_x , const int& i_y , const int& degree = 0 );

  // 条件
  // (1) 0 <= i_start_xかつi_start_x-1 <= i_final_x < m_size_X
  // (2) 0 <= i_start_yかつi_start_y-1 <= i_final_y < m_size_Y
  // を満たす場合のみサポート。degree-1階の階差数列を用いてdegree階の階差数列の値の総和
  // a[i_start_x][i_start_y]...a[i_final_x][i_start_y]...
  // a[i_start_x][i_final_y]...a[i_final_x][i_final_y]
  // をMに関して計算する。
  inline U RectangleSum( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const int& degree = 0 );

private:
  inline void Shift( const int& degree );
  void Integrate();
  void Differentiate();
  
};
template <typename ABELIAN_GROUP> AbstractTwoDimensionalDifferenceSequence( ABELIAN_GROUP M , const int& size_X , const int& size_Y ) -> AbstractTwoDimensionalDifferenceSequence<inner_t<ABELIAN_GROUP>,ABELIAN_GROUP>;

template <typename U = ll>
class TwoDimensionalDifferenceSequence :
  public AbstractTwoDimensionalDifferenceSequence<U,AdditiveGroup<U>>
{

public:
  template <typename...Args> inline TwoDimensionalDifferenceSequence( Args&&... args );

};
