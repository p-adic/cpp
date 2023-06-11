// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransfom/a.hpp

#pragma once
#include "a_Macro.hpp"

template <typename T , typename U , int size_max>
class ZetaTransformBody
{

private:
  int m_length;
  map<T,int> m_memory;
  vector<T> m_memory_inv;

protected:
  int m_size;
  U m_val[size_max];

public:
  // 仮想継承用にダミーのデフォルトコンストラクタを設定。
  inline ZetaTransformBody( const int& size = 0 );

  inline void Add( const T& t , const U& u );
  inline void AddAll( const U& u );
  inline ZetaTransformBody<T,U,size_max>& operator+=( const ZetaTransformBody<T,U,size_max>& a );
  inline void MultiplyAll( const U& u );
  inline ZetaTransformBody<T,U,size_max>& operator*=( const ZetaTransformBody<T,U,size_max>& a );

  // 子クラスの半順序のメビウス関数のデフォルトの再帰式を使うため、
  // 再帰深度が浅い場合にしか使えない。
  inline U Get( const T& t );
  // muは子クラスの半順序のメビウス関数。
  template <int mu(const T&,const T&)> inline U Get( const T& t );
  inline const U& InitialSegmentSum( const T& t );

  // f_inv_maxは定義域にr(s)を含む部分写像T->Sであり、要件
  // (1) Sは半順序集合である。
  // (2) r(s)は重複を持たない。（よって集合とみなす）
  // (3) sはr(s)の最大元である。
  // (4) 像f_inv_max(s)の要素を上界に持つTの要素全体Rへのfの制限f_Rは順序保存写像R->r(s)である。
  // (5) r(s)の任意の要素tに対しf_inv_max(t)が逆像f_R^{-1}(t)の最大元である。
  // を満たすfが存在する場合にのみ以下の２つをサポート。

  // f( t ) = sを満たすRの要素t全体を渡る総和取得。
  template <typename S , T f_inv_max(const S&) , list<S> r(const S&)> inline U InverseImageSum( const S& s );
  template <typename S , T f_inv_max(const S&) , list<S> r(const S&) , int mu(const T&,const T&)> inline U InverseImageSum( const S& s );
  // f( t ) <= sを満たすRの要素t全体を渡る総和取得。（結果的にrは使わないが要件上はrの存在が必要） 
  template <typename S , T f_inv_max(const S&)> inline const U& IntervalInverseImageSum( const S& s );

  virtual T e( const int& i );
  virtual int e_inv( const T& t );
  
private:
  virtual const U& Zero() const = 0;
  virtual U Sum( const U& u0 , const U& u1 ) const = 0;
  virtual U Prod( const U& u0 , const U& u1 ) const = 0;
  virtual list<T> Sub( const T& t ) const = 0;
  virtual list<T> Sup( const T& t ) const = 0;
  virtual int Moevius( const T& t0 , const T& t1 ) = 0;

};

template <typename T , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class SemiRingForZetaTransform :
  virtual public ZetaTransformBody<T,U,size_max>
{
public:
  inline SemiRingForZetaTransform( const int& dummy );
  
private:
  inline const U& Zero() const;
  inline U Sum( const U& u0 , const U& u1 ) const;
  inline U Prod( const U& u0 , const U& u1 ) const;

};

template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , int size_max>
class PartiallyOrderedSetForZetaTransform :
  virtual public ZetaTransformBody<T,U,size_max>
{

private:
  map<int,map<int,int> > m_moevius;

  inline list<T> Sub( const T& t ) const;
  inline list<T> Sup( const T& t ) const;
  // デフォルトの再帰式であるため、再帰深度が浅い場合にしか使えない。
  inline int Moevius( const T& t0 , const T& t1 );
  
};

template <typename U , int size_max>
class EnumerationForZetaTransform :
  virtual public ZetaTransformBody<int,U,size_max>
{

private:
  inline int e( const int& i );
  inline int e_inv( const int& t );
  
};

// 入力の範囲内で要件
// (1) Eがint上の半順序<のグラフでE_invが(int,>)のグラフである。
// を満たす場合にのみ以下をサポート。

// 0による初期化O(size_max)
// ゼータ変換前の配列による初期化O(始切片のサイズの総和)

// 一点加算O(終切片[t,∞)のサイズ)
// 全体加算O(size)
// 各点加法O(size)
// 全体乗算O(size)
// (int,<)がjoin半束である場合の畳み込み乗法O(size)

// 一点取得O(始切片(-∞,t]のサイズ×メビウス関数の計算量)
// 区間和取得O(1)

// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ×メビウス関数の計算量)
// 区間逆像和取得O(1)
template <list<int> E(const int&) , list<int> E_inv(const int&) , int size_max>
class ZetaTransform :
  public PartiallyOrderedSetForZetaTransform<int,E,E_inv,ll,size_max> ,
  public EnumerationForZetaTransform<ll,size_max>
{

public:
  inline ZetaTransform( const int& size );
  inline ZetaTransform( const int& size , const ll ( &a )[size_max] );

private:
  inline const ll& Zero() const;
  inline ll Sum( const ll& u0 , const ll& u1 ) const;
  inline ll Prod( const ll& u0 , const ll& u1 ) const;

};

// 入力の範囲内で要件
// (1) 2^digit <= size_max
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)が単位的環である。
// を満たす場合にのみ以下をサポート。

// z_U()による初期化O(size_max)
// ゼータ変換前の配列による初期化O(digit 2^digit)（可換加法モノイド性を使う）

// 一点加算O(2^digit)（可換加法モノイド性を使う）
// 全体加算O(2^digit)（可換加法モノイド性だけでも実装できるが単位的半環性を使う）
// 各点加法O(2^digit)（加法モノイド性を使う）
// 全体乗算O(2^digit)（半環性を使う）
// 畳み込み乗法O(2^digit)（半環性を使う）

// 一点取得O(2^digit)（単位的環性を使う。愚直と同じオーダー）
// 多点取得O(digit 2^digit)（単位的環性を使う）
// 区間和取得O(1)（可換加法モノイド性を使う）
// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ)（単位的環性を使う）
// 区間逆像和取得O(1)（可換加法モノイド性を使う）
template <typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class FastZetaTransform :
  public SemiRingForZetaTransform<int,U,a_U,z_U,m_U,size_max> ,
  public EnumerationForZetaTransform<U,size_max>
{

private:
  int m_digit;
  
public:
  inline FastZetaTransform( const int& digit );
  inline FastZetaTransform( const int& digit , const U ( &a )[size_max] );

  inline FastZetaTransform<U,a_U,z_U,m_U,size_max>& operator+=( const FastZetaTransform<U,a_U,z_U,m_U,size_max>& a );
  inline FastZetaTransform<U,a_U,z_U,m_U,size_max>& operator*=( const FastZetaTransform<U,a_U,z_U,m_U,size_max>& a );

  inline void FastMoeviusTransform( U ( &a )[size_max] );

private:
  inline list<int> Sub( const int& t ) const;
  inline list<int> Sup( const int& t ) const;
  inline int Moevius( const int& t0 , const int& t1 );

};

// 入力の範囲内で要件
// (1) EがT上の半順序<のグラフでE_invが(T,>)のグラフである。
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)が単位的環である。
// を満たす場合にのみ以下をサポート。

// z_U()による初期化O(size_max)

// 一点加算O(終切片[t,∞)のサイズ×log_2(size))（可換加法モノイド性を使う）
// 全体加算O(size)（可換加法モノイド性だけでも実装できるが単位的半環性を使う）
// 各点加法O(size)（加法モノイド性を使う）
// 全体乗算O(size)（半環性を使う）
// (T,<)がjoin半束である場合の畳み込み乗法O(size)（半環性を使う）

// 一点取得O(始切片(-∞,t]のサイズ×メビウス関数の計算量×log_2(size))（単位的環性を使う）
// 区間和取得O(log_2(size))（可換加法モノイド性を使う）

// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ×メビウス関数の計算量×log_2(size))（単位的環性を使う）
// 区間逆像和取得O(log_2(size))（可換加法モノイド性を使う）
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max>
class MemorisationZetaTransform :
  public SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max> ,
  public PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>
{

public:
  inline MemorisationZetaTransform( const int& size );

};

// 入力の範囲内で要件
// (1) EがT上の半順序<のグラフでE_invが(T,>)のグラフである。
// (2) (U,a_U:U^2->U,z_U:1->U,m_U:U^2->U)が単位的環である。
// (3) enum_T:int->Tとenum_T_inv:int->Tが互いに逆写像である。
// を満たす場合にのみ以下をサポート。

// z_U()による初期化O(size_max)

// 一点加算O(終切片[t,∞)のサイズ)（可換加法モノイド性を使う）
// 全体加算O(size)（可換加法モノイド性だけでも実装できるが単位的半環性を使う）
// 各点加法O(size)（加法モノイド性を使う）
// 全体乗算O(size)（半環性を使う）
// (T,<)がjoin半束である場合の畳み込み乗法O(size)（半環性を使う）

// 一点取得O(始切片(-∞,t]のサイズ×メビウス関数の計算量)（単位的環性を使う）
// 区間和取得O(1)（可換加法モノイド性を使う）

// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ×メビウス関数の計算量)（単位的環性を使う）
// 区間逆像和取得O(1)（可換加法モノイド性を使う）
template <typename T , list<T> E(const T&) , list<T> E_inv(const T&) , typename U , U a_U(const U&,const U&) , const U& z_U() , U m_U(const U&,const U&) , int size_max , T enum_T(const int&) , int enum_T_inv(const T&)>
class EnumerationZetaTransform :
  public SemiRingForZetaTransform<T,U,a_U,z_U,m_U,size_max> ,
  public PartiallyOrderedSetForZetaTransform<T,E,E_inv,U,size_max>
{

public:
  inline EnumerationZetaTransform( const int& size );

private:
  inline T e( const int& i );
  inline int e_inv( const T& t );

};

// 古典的なメビウス関数は../../Arithmetic/Prime/Divisor/a_Body.hppで定義

