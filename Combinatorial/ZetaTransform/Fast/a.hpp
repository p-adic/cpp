// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Fast/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Algebra/Monoid/Semirng/Ring/Algebra/a.hpp"

// verify:
// https://yukicoder.me/submissions/970730（AbstractFastZetaTransform, InitialSegmentSum）

template <typename U , typename Z_ALG> class AbstractFastZetaTransform;

class SubsetEdge
{

  template <typename U , typename Z_ALG> friend class AbstractFastZetaTransform;
  
private:
  const int* m_p_size_minus;

public:
  inline vector<int> operator()( const int& t ) const;

};

class SupsetEdge
{

  template <typename U , typename Z_ALG> friend class AbstractFastZetaTransform;
  
private:
  const int* m_p_size_minus;

public:
  inline vector<int> operator()( const int& t ) const;

};

// 入力の範囲内で要件
// (1) RはUの非単位的Z代数構造である。
// を満たす場合にのみサポート。
// ただし全体加算や一点取得や各点取得を行わないならばRはダミーのZ作用を持つ非単位的環でも良い。

// R.Zero()による初期化O(2^digit)
// ゼータ変換前の配列による初期化O(digit 2^digit)
// ゼータ変換後の配列による初期化O(1)

// 一点加算O(2^digit)
// 全体加算O(2^digit)
// 加法O(2^digit)
// 全体乗算O(2^digit)
// 畳み込み乗法O(2^digit)

// 一点取得O(2^digit)
// 各点取得O(digit 2^digit)
// 始切片和取得O(1)

// 逆像和取得O(始切片(-∞,f_inv_max(r_max)]のサイズ)
// 始切片逆像和取得O(1)
template <typename U , typename Z_ALG>
class AbstractFastZetaTransform :
  public VirtualZetaTransform<int,Graph<SubsetEdge>,Graph<SupsetEdge>,U,Z_ALG>
{

private:
  int m_digit;
  int m_size_minus;
  
public:
  inline AbstractFastZetaTransform( Z_ALG R , const int& digit = 0 );
  inline AbstractFastZetaTransform( Z_ALG R , vector<U> a , const bool& transformed = false );

  // 高速メビウス変換による復元
  vector<U> TotalGet();

private:
  inline AbstractFastZetaTransform( Z_ALG R , const int& size , vector<U>& a , const bool& transformed );
  inline int Moevius( const int& t0 , const int& t1 );

};
template <typename Z_ALG , typename...Args> AbstractFastZetaTransform( Z_ALG R , Args&&... args ) -> AbstractFastZetaTransform<inner_t<Z_ALG>,Z_ALG>;

template <typename U>
class FastZetaTransform :
  public AbstractFastZetaTransform<U,Algebra<int,U>>
{

public:
  template <typename...Args> inline FastZetaTransform( const U& one , Args&&... args );

};
