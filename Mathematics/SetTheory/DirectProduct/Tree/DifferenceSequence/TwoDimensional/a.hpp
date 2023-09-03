// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// 2次元配列上の階差数列。基本的に2次元imos法
// https://imoz.jp/algorithms/imos_method.html
// に準拠。

// 入力の範囲内で要件
// (6) (T,operator+:T^2->T,T(),operator-:T->T)は可換群である。
// が成り立つ場合にのみサポート。

// initによる初期化O(size_X*size_Y)
// 配列による初期化O(size_X*size_Y)

// 一点代入O(size_X*size_Y)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size_X*size_Y)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 始矩形加算O(1)（作用を遅延評価する）
// 矩形加算O(1)（作用を遅延評価する）
// 加法O(size_X*size_Y)（作用の遅延評価を解消する）
template <typename T>
class TwoDimensionalDifferenceSequence
{

private:
  int m_size_X;
  int m_size_Y;
  vector<vector<T> > m_a;
  vector<vector<T> > m_lazy_addition;
  bool m_updated;
  
public:
  inline TwoDimensionalDifferenceSequence( const vector<vector<T> >& a );
  inline TwoDimensionalDifferenceSequence( vector<vector<T> >&& a );
  inline TwoDimensionalDifferenceSequence( const int& size_X , const int& size_Y );
  template <int size_X_max , int size_Y_max> inline TwoDimensionalDifferenceSequence( const T ( &a )[size_X_max][size_Y_max] , const int& size_X , const int& size_Y );

  
  // 作用の遅延評価を解消してから値を代入する。
  inline void Set( const int& i_x , const int& i_y , const T& t );
  // 作用の遅延評価を解消してから値を参照する。
  inline const T& Get( const int& i_x , const int& i_y );
  // 作用の遅延評価を解消せずに元々の値を参照する。
  inline T& Ref( const int& i_x , const int& i_y );

  // (i_x,i_y)での値にyを遅延評価せずに加算する。
  inline void Add( const int& i_x , const int& i_y , const T& t );

  // tを遅延評価で加算する。
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t );
  // tを遅延評価で減算する。
  inline void RectangleSubtract( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const T& t );

  // 作用の遅延評価を解消してから全体を加算する。
  inline TwoDimensionalDifferenceSequence<T>& operator+=( const TwoDimensionalDifferenceSequence<T>& a );

  // 作用の遅延評価を解消する。
  void Update();

};
