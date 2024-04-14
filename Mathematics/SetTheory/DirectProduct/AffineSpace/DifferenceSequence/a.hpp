// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once

#include "../../../../Geometry/Graph/Array/Prev/a.hpp"

// verify:
// https://yukicoder.me/submissions/972270（零初期化、部分木加算、一点取得）
// https://yukicoder.me/submissions/972289（Abstract、零初期化、部分木加算、一点取得）

// 数列に対するimos法
// https://imoz.jp/algorithms/imos_method.html
// を森上の可換群に値を持つ関数に一般化したデータ構造。
// 根からの（高階）階差数列を管理する。

// 入力の範囲内で要件
// (1) MはUの可換群構造である。
// (2) GはTの有向グラフとしての森構造である。
// (3) prevはG.Enumeration_invに関する親ノードとの対応N->N \cup {-1}を返す関数オブジェクト
//     であり、ただし根ノードに対応する番号に対しては-1を返すものである。
// (4) G.Enumerationは順序同型である、
//     つまりi <= jとG.Enumeration(i) <- G.Enumeration(j)は同値である。
// が成り立つ場合にのみサポート。
// (3)でprevを配列で前計算すると|E_G|が大きい場合に遲いことに注意。
// (4)が成り立たない場合はTopologicalSortedForest(G)を使ってグラフを変更する。

// M.Zero()による初期化O(size)
// 配列による初期化O(size)

// 一点代入O(|m_degree|*size)
// 一点加算O(|m_degree|*size)
// 終切片加算O(|m_degree-1|*size)
// 部分木加算O(t_outside.size() + |m_degree-1|*size)

// 一点取得O(|m_degree|*size)
// 始切片和取得O(|m_degree+1|*size)
// 区間和取得O(|m_degree+1|*size)
template <typename T , typename FOREST , typename PREV , typename U , typename GROUP>
class AbstractDifferenceSequence
{

protected:
  // 探索アルゴリズムと違って外部からのグラフの変更を許さない。
  FOREST m_G;
  // m_G.Enumeration_invに関する親ノードとの対応を返す関数オブジェクト。
  PREV m_prev;
  GROUP m_M;

  // 根からの階差数列を管理。
  vector<U> m_a;
  // 階差数列の階数（-1の時は累積和）を管理。
  int m_degree;

public:
  inline AbstractDifferenceSequence( FOREST G , PREV prev , GROUP M , int degree = 1 );
  inline AbstractDifferenceSequence( FOREST G , PREV prev , GROUP M , vector<U> a , int degree = 0 );

  template <typename...Args> inline void Initialise( Args&&... args );

  inline void Set( const T& t , const U& u , const int& degree = 0 );
  // degree階の階差数列のtでの値にuを加算する。
  inline void Add( const T& t , const U& u , const int& degree = 0 );

  // degree+1階の階差数列を用いてdegree階の階差数列の値にuを加算する。
  inline void FinalSegmentAdd( const T& t_start , const U& u , const int& degree = 0 );
  inline void SubtreeAdd( const T& t_start , const vector<T>& t_outisde , const U& u , const int& degree = 0 );

  // 0階の値を取得する。
  inline const U& operator[]( const T& t );
  // degree階の階差数列の値を取得する。
  inline const U& Get( const T& t , const int& degree = 0 );

  inline const U& InitialSegmentSum( const T& t_final , const int& degree = 0 );
  // 要件
  // (1) t_startからt_outsidesの各要素への有向パスが存在する。
  // (2) t_outsidesの要素を根とする部分木間の交わりが空である。
  // を満たす場合にのみサポート。
  // t_startを根とする部分木から「t_finalの各成分を根とする部分木」を除いたものの各頂点を渡り
  // degree-1階の階差数列を用いてdegree階の階差数列の値の総和を取得する。
  inline U IntervalSum( const T& t_start , const T& t_final , const int& degree = 0 );

private:
  inline AbstractDifferenceSequence( FOREST& G , PREV& prev , GROUP& M , vector<U> a , int degree , int dummy );

  inline void Shift( const int& degree );
  inline void Shift( const int& degree_min , const int& degree_max );
  void Integrate();
  void Differentiate();

};
template <typename FOREST , typename PREV , typename GROUP , typename...Args> AbstractDifferenceSequence( FOREST G , PREV orev , GROUP M , Args&&... args ) -> AbstractDifferenceSequence<inner_t<FOREST>,FOREST,PREV,inner_t<GROUP>,GROUP>;

// 通常の配列上の階差数列を右から取ったもの。
// 入力の範囲内で要件
// (2) MはUの可換群構造である。
// が成り立つ場合にのみサポート。

// M.Zero()による初期化O(size_max)
// 配列による初期化O(size_max)

// 一点代入O(|m_degree|*size)
// 一点加算O(|m_degree|*size)
// 終切片加算O(|m_degree-1|*size)
// 区間加算O(|m_degree-1|*size)

// 一点取得O(|m_degree|*size)
// 区間和取得O(|m_degree+1|*size)
template <typename U = ll>
class DifferenceSequence :
  virtual public AbstractDifferenceSequence<int,LinearGraph,LinearPrev,U,AdditiveGroup<U>>
{

public:
  inline DifferenceSequence( const int& size = 0 , int degree = 1 );
  inline DifferenceSequence( vector<U> a , int degree = 0 );

  inline void IntervalAdd( const int& t_start , const int& t_final , const U& u , const int& degree = 0 );

  
private:
  inline DifferenceSequence( const int& size , vector<U>& a , int degree );
  
};

