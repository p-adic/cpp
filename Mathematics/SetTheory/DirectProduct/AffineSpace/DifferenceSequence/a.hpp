// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../../Graph/Array/a.hpp"

// verify:
// https://yukicoder.me/submissions/950084（Abstract、零初期化、一点取得、部分木加算）
// https://yukicoder.me/submissions/953509（Abstract、零初期化、一点取得、部分木加算）

// 数列に対するimos法
// https://imoz.jp/algorithms/imos_method.html
// を森上の可換群に値を持つ関数に一般化したデータ構造。
// 累積和やBITと違って、通常の配列で管理した時にオーバーフローしないならば
// imos法でもあまりオーバーフローしないのでU = intでも良い。
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
// (2) PrevはGの親ノードを返す関数オブジェクトである。
// (3) MはUの可換群構造である。
// (4) GのEumeration_invは順序保存である。
//     つまり任意の辺v_0->v_1に対しG.Enumeration_inv(v_0)<G.Enumeration_inv(v_1)である。
// が成り立つ場合にのみサポート。
// (2),(3)はUpdate()の定数倍高速化に使用。これらが成り立たなくても計算量のオーダーを変えずに
// 実装できるが非常に遲く実用てきでない。

// M.Zero()による初期化O(size)
// 配列による初期化O(size)

// 一点代入O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 部分木加算O(1)（作用を遅延評価する）
// 加法O(size)（作用を遅延評価しない）
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
class AbstractDifferenceSequence
{

protected:
  // 探索アルゴリズムと違って外部からのグラフの変更を許さない。
  FOREST m_G;
  PREV m_Prev;
  GROUP m_M;
  vector<U> m_a;
  vector<U> m_lazy_addition;
  bool m_updated;

public:
  inline AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M );
  inline AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M , vector<U> a );

  inline void Initialise( vector<U> a );
  // 作用の遅延評価を解消してから値を代入する。
  inline void Set( const T& t , const U& u );
  // 作用の遅延評価を解消してから値を参照する。
  inline const U& Get( const T& t );
  // 作用の遅延評価を解消せずに元々の値を参照する。
  inline U& Ref( const T& t );

  // tでの値にuを遅延評価せずに加算する。
  inline void Add( const T& t , const U& u );
  // t_startを根とする部分木から「t_finalの各成分を根とする部分木から根を除いたもの」を除いたもの
  // の各頂点での値にuを遅延評価して加算する。
  void SubTreeAdd( const T& t_start , const list<T>& t_final , const U& u );

  inline AbstractDifferenceSequence<T,FOREST,PREV,U,GROUP>& operator+=( const vector<U>& a );

private:
  // 作用の遅延評価を解消する。
  void Update();

};
template <typename FOREST , typename PREV , typename GROUP> AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,PREV,inner_t<GROUP>,GROUP>;
template <typename FOREST , typename PREV , typename U , typename GROUP> AbstractDifferenceSequence( FOREST G , PREV Prev , GROUP M , vector<U> ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,PREV,U,GROUP>;

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
template <typename U>
class DifferenceSequence :
  virtual public AbstractDifferenceSequence<int,LinearGraph,int(const int&) noexcept,U,AdditiveGroup<U>>
{

public:
  inline DifferenceSequence( const int& size = 0 );
  inline DifferenceSequence( vector<U> a );

  inline void InitialSegmentAdd( const int& t_start , const U& u );
  inline void FinalSegmentAdd( const int& t_final , const U& u );
  inline void IntervalAdd( const int& t_start , const int& t_final , const U& u );

private:
  static inline int PrevOf( const int& t_start ) noexcept;
  
};

