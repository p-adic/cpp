// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once
#include "../../../../Graph/Array/a.hpp"

// 数列に対するimos法
// https://imoz.jp/algorithms/imos_method.html
// を森上の可換群に値を持つ関数に一般化したデータ構造。
template <typename T , typename U>
class VirtualDifferenceSequence
{

public:
  // 作用の遅延評価を解消してから値を代入する。
  virtual void Set( const T& t , const U& u ) = 0;
  // 作用の遅延評価を解消してから値を参照する。
  virtual const U& Get( const T& t ) = 0;
  // 作用の遅延評価を解消せずに元々の値を参照する。
  virtual U& Ref( const T& t ) = 0;

  // vでの値にuを遅延評価せずに加算する。
  virtual void Add( const T& t , const U& u ) = 0;

  // 要件
  // (1) t_startからt_finalの各要素への有向パスが存在する。
  // (2) t_finalの要素間の有向パスが存在しない。
  // を満たす場合にのみサポート。
  // 条件
  // (1) t_startからtへの有向パスが存在する。
  // (2) t_finalのいずれの要素からもtへの有向パスが存在しない。
  // を満たすTの各要素tに対し、tでの値にuを遅延評価で加算する。
  virtual void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u ) = 0;

};

// 一般の森上の階差数列。
// 入力の範囲内で要件
// (1) GはTの有向グラフとしての森構造である。
// (2) MはUの可換群構造である。
// が成り立つ場合にのみサポート。
template <typename T , typename FOREST , typename U , typename GROUP>
class AbstractDifferenceSequence
{

protected:
  FOREST m_G;
  list<T> m_root;
  vector<int> m_prev;
  vector<U> m_a;
  vector<U> m_lazy_addition;
  GROUP m_M;
  bool m_updated;

public:
  inline AbstractDifferenceSequence( FOREST G , GROUP M );
  inline AbstractDifferenceSequence( FOREST G , vector<U> a , GROUP M );
  // 作用の遅延評価を解消してから値を代入する。
  inline void Set( const T& t , const U& u );
  // 作用の遅延評価を解消してから値を参照する。
  inline const U& Get( const T& t );
  // 作用の遅延評価を解消せずに元々の値を参照する。
  inline U& Ref( const T& t );

  // tでの値にuを遅延評価せずに加算する。
  inline void Add( const T& t , const U& u );
  // t_startを根とする部分木から「t_finalの各成分を根とする部分木から根を除いたもの」を除いたもの
  // の各頂点での値にuを遅延評価せずに加算する。
  void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u );

  inline DifferenceSequenceBody<T,U>& operator+=( const DifferenceSequenceBody<T,U>& a );

private:
  // 作用の遅延評価を解消する。
  void Update();

};
template <typename FOREST , typename GROUP> AbstractDifferenceSequence( FOREST G , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,inner_t<GROUP>,GROUP>;
template <typename FOREST , typename U , typename GROUP> AbstractDifferenceSequence( FOREST G , vector<U> a , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,U,GROUP>;

// 通常の配列上の階差数列。
// 入力の範囲内で要件
// (2) MはUの可換群構造である。
// が成り立つ場合にのみサポート。

// M.Zero()による初期化O(size_max)
// 配列による初期化O(size_max)

// 一点代入O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 始切片加算O(1)（作用を遅延評価する）
// 終切片加算O(1)（作用を遅延評価する）
// 区間加算O(1)（作用を遅延評価する）
// 加法O(size)（作用の遅延評価を解消する）
template <typename U , typename GROUP>
class DifferenceSequence :
  virtual public AbstractDifferenceSequence<LinearGraph,U>
{

public:
  inline DifferenceSequence( const int& size , GROUP M );
  inline DifferenceSequence( vector<U> a , GROUP M );

  inline void InitialSegmentAdd( const int& t_start , const U& u );
  inline void FinalSegmentAdd( const int& t_final , const U& u );
  inline void IntervalAdd( const int& t_start , const int& t_final , const U& u );

};

