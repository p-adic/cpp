// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/DifferenceSequence/a.hpp

#pragma once

// 数列に対するimos法
// https://imoz.jp/algorithms/imos_method.html
// を森V上のモノイドT値関数と羃等演算つき集合Uからの準同型Actionの組(T,U,Action)
// に一般化したデータ構造。
template <typename V , typename T , typename U , int size_max>
class DifferenceSequenceBody
{

protected:
  int m_size;
  U m_a[size_max];
  U m_lazy_addition[size_max];
  bool m_updated;

public:
  inline DifferenceSequenceBody( const int& size );

  // 作用の遅延評価を解消してから値を代入する。
  inline void Set( const V& v , const U& u );
  // 作用の遅延評価を解消してから値を参照する。
  inline const U& Get( const V& v );
  // 作用の遅延評価を解消せずに元々の値を参照する。
  inline U& Ref( const V& v );

  // vでの値にuを遅延評価せずに加算する。
  inline void Add( const V& v , const U& u );

  // 要件
  // (1) v_startからv_finalの各要素への有向パスが存在する。
  // (2) v_finalの要素間の有向パスが存在しない。
  // を満たす場合にのみサポート。
  // 条件
  // (1) v_startからvへの有向パスが存在する。
  // (2) v_finalのいずれの要素からもvへの有向パスが存在しない。
  // を満たすVの各要素vに対し、vでの値にuを遅延評価で加算する。
  void SubTreeAdd( const V& v_start , const list<V>& v_final , const U& u );

  inline DifferenceSequenceBody<V,T,U,size_max>& operator+=( const DifferenceSequenceBody<V,T,U,size_max>& a );

  // 作用の遅延評価を解消する。
  void Update();

private:
  virtual list<V> Edge( const V& v ) const = 0;
  virtual V Edge_inv( const V& v ) const = 0;
  virtual V e( const int& i ) const = 0;
  virtual int e_inv( const V& v ) const = 0;
  virtual const T& Unit() const = 0;
  virtual T& Addition( const T& t0 , T& t1 ) const = 0;
  virtual U Inverse( const U& u ) const = 0;
  virtual T& Action( const U& u , T& t ) const = 0;

};


// 通常の配列上の階差数列。

// 入力の範囲内で要件
// (6) (T,operator+:T^2->T,T(),operator-:T->T)は可換群である。
// が成り立つ場合にのみサポート。

// 0による初期化O(size_max)
// 配列による初期化O(size_max)

// 一点代入O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）
// 一点取得O(size)（作用の遅延評価を解消する。元々作用の遅延評価がない場合はO(1)）

// 一点加算O(1)（作用を遅延評価しない）
// 始切片加算O(1)（作用を遅延評価する）
// 終切片加算O(1)（作用を遅延評価する）
// 区間加算O(1)（作用を遅延評価する）
// 加法O(size)（作用の遅延評価を解消する）
template <typename T , int size_max>
class DifferenceSequence :
  public DifferenceSequenceBody<int,T,T,size_max>
{

public:
  inline DifferenceSequence( const int& size );
  inline DifferenceSequence( const T ( &a )[size_max] , const int& size );
  inline DifferenceSequence( T ( &&a )[size_max] , const int& size );

  inline void InitialSegmentAdd( const int& v_start , const T& u );
  inline void FinalSegmentAdd( const int& v_final , const T& u );
  inline void IntervalAdd( const int& v_start , const int& v_final , const T& u );
  inline void IntervalSubtract( const int& v_start , const int& v_final , const T& u );

private:
  inline list<int> Edge( const int& v ) const;
  inline int Edge_inv( const int& v ) const;
  inline int e( const int& i ) const;
  inline int e_inv( const int& v ) const;
  inline const T& Unit() const;
  inline T& Addition( const T& t0 , T& t1 ) const;
  inline T Inverse( const T& u ) const;
  inline T& Action( const T& u , T& t ) const;

};
