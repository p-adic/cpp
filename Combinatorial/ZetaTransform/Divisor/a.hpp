// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"

// verify:
// https://yukicoder.me/submissions/1014293 (DivisorZetaTransform)
// https://yukicoder.me/submissions/1016342 (MultipleZetaTransform, Add, InitialSegmentSum, InverseImageSum)

// LDはLeastDivisorを特殊化した型。
template <typename LD>
class DivisorMoeviusFunction
{

private:
  vector<int> m_val;
  
public:
  // O( n_max )
  inline DivisorMoeviusFunction( const LD& ld , const int& n_max );

  // 古典的な１変数メビウス関数muのmu(t1/t0)による２変数化。
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename LD>
class MultipleMoeviusFunction
{

private:
  vector<int> m_val;

public:
  // O( n_max )
  inline MultipleMoeviusFunction( const LD& ld , const int& n_max );

  // 古典的な１変数メビウス関数muのmu(t0/t1)による２変数化。
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename LD>
class DivisorEdge
{

private:
  const LD* m_p_ld;

public:
  inline DivisorEdge( const LD& ld );
  inline vector<int> operator()( const int& t );

};

class MultipleEdge
{

private:
  int m_size;

public:
  inline MultipleEdge( const int& size );
  inline vector<int> operator()( const int& t );

};


// 約数をわたる総和を管理する。

// 入力の範囲内で要件
// (1) Rは非単位的Z代数構造である。
// を満たす場合にのみサポート。一点取得と逆像和取得にのみmuを使う。
// ただし全体加算や一点取得を行わないならばRはダミーのZ作用を持つ非単位的環でも良い。

// R.Zero()による初期化O(size log log size)
// ゼータ変換前の配列による初期化O(size log size)
// ゼータ変換後の配列による初期化O(size log log size)

// 一点加算O(size/t)
// 全体加算O(size)
// 各点加法O(size)
// 全体乗算O(size)
// 畳み込み乗法O(size)

// 一点取得O(d(t)) = O(log t/log log t)
// 始切片和取得O(1)

// 逆像和取得O(d(f_inv_max(r_max)))
// 始切片逆像和取得O(1)
template <typename LD , typename U , typename Z_ALG>
class AbstractDivisorZetaTransform :
  public AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<LD>>
{

public:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed = false );

  // a,bはaがbの約数である定数 in [1,size)として、
  // f_inv_max=id
  // range=aの倍数であるbの約数全体の集合を返す定数関数
  // と定めると、
  // 逆像和InverseImageSum(f_inv_max,range,b)は
  // lcm(a,t)がbの倍数であるsize未満の各正整数tをわたるm_val[t]の総和。

private:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed );

};
template <typename LD , typename Z_ALG , typename...Args> AbstractDivisorZetaTransform( const LD& , Z_ALG , Args&&... ) -> AbstractDivisorZetaTransform<LD,inner_t<Z_ALG>,Z_ALG>;

template <typename LD , typename U>
class DivisorZetaTransform :
  public AbstractDivisorZetaTransform<LD,U,Algebra<int,U>>
{

public:
  inline DivisorZetaTransform( const LD& ld , const U& one , const int& size );
  inline DivisorZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed = false );

};


// 倍数をわたる総和を管理する。

// 入力の範囲内で要件
// (1) Rは非単位的Z代数構造である。
// を満たす場合にのみサポート。一点取得と逆像和取得にのみmuを使う。
// ただし全体加算や一点取得を行わないならばRはダミーのZ作用を持つ非単位的環でも良い。

// R.Zero()による初期化O(size log log size)
// ゼータ変換前の配列による初期化O(size log size)
// ゼータ変換後の配列による初期化O(size log log size)

// 一点加算O(d(t)) = O(log t/log log t)
// 全体加算O(size)
// 各点加法O(size)
// 全体乗算O(size)
// 畳み込み乗法O(size)

// 一点取得O(size/t)
// 始切片和取得O(1)

// 逆像和取得O(size/t)
// 始切片逆像和取得O(1)
template <typename LD , typename U , typename Z_ALG>
class AbstractMultipleZetaTransform :
  public AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<LD>>
{

public:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , vector<U> a , const bool& transformed = false );

  // aを定数in [1,size)として
  // f_inv_max=id
  // range=aの約数全体の集合を返す定数関数
  // と定めると、
  // 逆像和InverseImageSum(f_inv_max,range,b)は
  // aと互いに素なsize未満の各正整数tをわたるm_val[t]の総和。

private:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size , vector<U>& a , const bool& transformed );

};
template <typename LD , typename Z_ALG , typename...Args> AbstractMultipleZetaTransform( const LD& , Z_ALG , Args&&... ) -> AbstractMultipleZetaTransform<LD,inner_t<Z_ALG>,Z_ALG>;

template <typename LD , typename U>
class MultipleZetaTransform :
  public AbstractMultipleZetaTransform<LD,U,Algebra<int,U>>
{

public:
  inline MultipleZetaTransform( const LD& ld , const U& one , const int& size );
  inline MultipleZetaTransform( const LD& ld , const U& one , vector<U> a , const bool& transformed = false );

};
