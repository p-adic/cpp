// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/Tree/DifferenceSequence/TwoDimensional/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/947058（零初期化、一点取得、矩形加算）
// https://yukicoder.me/submissions/947062（零初期化、一点取得、矩形加算）

// ２次元配列上の階差数列。基本的に２次元imos法
// https://imoz.jp/algorithms/imos_method.html
// に準拠。

// 入力の範囲内で要件
// (1) MはUの可換群構造である。
// が成り立つ場合にのみサポート。

// M.Zero()による初期化O(size_X*size_Y)
// 配列による初期化O(size_X*size_Y)

// 一点代入O(size_X*size_Y)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size_X*size_Y)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 始矩形加算O(1)（作用を遅延評価する）
// 矩形加算O(1)（作用を遅延評価する）
// 加法O(size_X*size_Y)（作用の遅延評価を解消する）
template <typename U , typename GROUP>
class TwoDimensionalDifferenceSequence
{

private:
  int m_size_X;
  int m_size_Y;
  vector<vector<U>> m_a;
  vector<vector<U>> m_lazy_addition;
  GROUP m_M;
  bool m_updated;
  
public:
  inline TwoDimensionalDifferenceSequence( vector<vector<U>> a , GROUP M );
  inline TwoDimensionalDifferenceSequence( const int& size_X , const int& size_Y , GROUP M );
  
  // 作用の遅延評価を解消してから値を代入する。
  inline void Set( const int& i_x , const int& i_y , const U& u );
  // 作用の遅延評価を解消してから値を参照する。
  inline const U& Get( const int& i_x , const int& i_y );
  // 作用の遅延評価を解消せずに元々の値を参照する。
  inline U& Ref( const int& i_x , const int& i_y );

  // (i_x,i_y)での値にyを遅延評価せずに加算する。
  inline void Add( const int& i_x , const int& i_y , const U& u );

  // tを遅延評価で加算する。
  inline void RectangleAdd( const int& i_start_x , const int& i_start_y , const int& i_final_x , const int& i_final_y , const U& u );

  // 作用の遅延評価を解消してから全体を加算する。
  inline TwoDimensionalDifferenceSequence<U,GROUP>& operator+=( const TwoDimensionalDifferenceSequence<U,GROUP>& a );

  // 作用の遅延評価を解消する。
  void Update();

};
template <typename GROUP> TwoDimensionalDifferenceSequence( const int& size_X , const int& size_Y , GROUP M ) -> TwoDimensionalDifferenceSequence<inner_t<GROUP>,GROUP>;
