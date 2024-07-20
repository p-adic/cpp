// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"
#include "../../../Arithmetic/Divisor/Constexpr/a.hpp"
#include "../../../Arithmetic/Divisor/Moevius/Constexpr/a.hpp"

// verify:
// https://yukicoder.me/submissions/970736（MultipleZetaTransform, Add, InitialSegmentSum, InverseImageSum）

// MUはMoeviusFunctionを特殊化した型。
// LDはLeastDivisorを特殊化した型。

template <typename MU>
class DivisorMoeviusFunction
{

private:
  const MU* m_p_mu;
  
public:
  // O( size )
  inline constexpr DivisorMoeviusFunction( const MU& mu );

  // 古典的な１変数メビウス関数muのmu(t1/t0)による２変数化。
  inline int operator()( const int& t0 , const int& t1 );

};

template <typename MU>
class MultipleMoeviusFunction
{

private:
  const MU* m_p_mu;

public:
  // O( size )
  inline constexpr MultipleMoeviusFunction( const MU& mu );

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
template <typename LD , typename MU , typename U , typename Z_ALG>
class AbstractDivisorZetaTransform :
  public AbstractZetaTransform<int,Graph<DivisorEdge<LD>>,Graph<MultipleEdge>,U,Z_ALG,DivisorMoeviusFunction<MU>>
{

private:
  MU m_mu;

public:
  inline AbstractDivisorZetaTransform( const LD& ld , Z_ALG R , const int& size = 0 );
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
template <int val_limit , typename Z_ALG , typename...Args> AbstractDivisorZetaTransform( const LeastDivisor<int,val_limit>& , Z_ALG , Args&&... ) -> AbstractDivisorZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,inner_t<Z_ALG>,Z_ALG>;

template <int val_limit , typename U>
class DivisorZetaTransform :
  public AbstractDivisorZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>
{

public:
  template <typename...Args> inline DivisorZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args );

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
template <typename LD , typename MU , typename U , typename Z_ALG>
class AbstractMultipleZetaTransform :
  public AbstractZetaTransform<int,Graph<MultipleEdge>,Graph<DivisorEdge<LD>>,U,Z_ALG,MultipleMoeviusFunction<MU>>
{

private:
  MU m_mu;

public:
  inline AbstractMultipleZetaTransform( const LD& ld , Z_ALG R , const int& size = 0 );
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
template <int val_limit , typename Z_ALG , typename...Args> AbstractMultipleZetaTransform( const LeastDivisor<int,val_limit>& , Z_ALG , Args&&... ) -> AbstractMultipleZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,inner_t<Z_ALG>,Z_ALG>;

template <int val_limit , typename U>
class MultipleZetaTransform :
  public AbstractMultipleZetaTransform<LeastDivisor<int,val_limit>,MoeviusFunction<int,val_limit>,U,Algebra<int,U>>
{

public:
  template <typename...Args> inline MultipleZetaTransform( const LeastDivisor<int,val_limit>& ld , const U& one , Args&&... args );

};
