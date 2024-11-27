// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/TwoDimensional/Debug/a.hpp

#pragma once

// デバッグ用にエラー出力を追加したもの。
// 各範囲更新にO(size_X*size_Y)追加されることに注意。


// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

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

  // デバッグ出力用
  const vector<vector<U>>& Get() const noexcept;

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


// デバッグ出力用
template <class Traits , typename U , typename ABELIAN_GROUP> inline basic_ostream<char,Traits>& operator<<( basic_ostream<char,Traits>& os , const AbstractTwoDimensionalDifferenceSequence<U,ABELIAN_GROUP>& tdds );
