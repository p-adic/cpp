// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/IntervalAdd/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/961746（一点加算、区間加算、一点取得）

// 入力の範囲内で要件
// (1) MがUのZ加群構造である。
// を満たす場合にのみサポート。

// M.Zero()による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// M.Sum()に関する区間和取得O(N^{1/2})

// 一点代入O(1)（可換群構造を使う）
// M.Sum()による一点加算O(1)（可換性を使う）
// M.Sum()による区間加算O(N^{1/2})（N加群構造を使う）
template <typename U , typename Z_MODULE>
class IntervalAddAbstractSqrtDecomposition :
  public AbstractSqrtDecomposition<U,Z_MODULE>
{

protected:
  vector<U> m_lazy_addition;
  
public:
  template <typename...Args> inline IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  // 参照返しでないことに注意
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U IntervalSum( const int& i_start , const int& i_final );

  template <typename F , SFINAE_FOR_SD_S> inline int Search( const int& i_start , const F& f , const bool& reversed = false );
  inline int Search( const int& i_start , const U& u , const bool& reversed = false );

private:
  template <typename F> int Search_Body( const int& i_start , const F& f , U sum_temp );
  template <typename F> int SearchReverse_Body( const int& i_final , const F& f , U sum_temp );

};
template <typename Z_MODULE , typename...Args> IntervalAddAbstractSqrtDecomposition( Z_MODULE M , Args&&... args ) -> IntervalAddAbstractSqrtDecomposition<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddSqrtDecomposition :
  public IntervalAddAbstractSqrtDecomposition<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddSqrtDecomposition( Args&&... args );
  
};
template <typename U , typename...Args> IntervalAddSqrtDecomposition( vector<U> a , Args&&...args ) -> IntervalAddSqrtDecomposition<U>;
