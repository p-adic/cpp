// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/GeometricProgressionMin/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../../Algebra/Monoid/Modulea.hpp"

// verify:
// https://yukicoder.me/submissions/961726

// 自由U加群の構造射と演算の合成
template <typename U>
class GeometricProgressionMinComposition :
  virtual public PointedSet<vector<U>> ,
  virtual public VirtualRSet<pair<int,U>,vector<U>>
{
  
public:
  inline GeometricProgressionMinComposition( const int& size , const U& infty );
  vector<U> Action( const pair<int,U>& y0 , vector<U> y1 );

};

// 自由U加群の左作用構造
template <typename U , typename N_MODULE>
class GeometricProgressionMinAction :
  virtual public VirtualRSet<vector<U>,pair<U,int>>
{
  
private:
  N_MODULE m_M;
  const vector<U>* m_p_memory;

public:
  inline GeometricProgressionMinAction( N_MODULE M , const vector<U>& memory );
  pair<U,int> Action( const vector<U>& y , pair<U,int> u );

};

#include "a_Alias.hpp"

// 入力の範囲内で要件
// (1) Mがbool operator<(const U&,const U&)に関してUの全順序N加群構造である。
// を満たす場合にのみサポート。
// クエリ中の等比数列(r^i y)_iの公比rの種類数をCとおく。

// 零初期化O(N)
// 配列による初期化O(N)

// 一点取得O(C)

// 一点代入O(CN^{1/2})（ただし状況次第でO(1)）
// 等比数列(r^i y)_iによる区間min作用O(N^{1/2})
template <typename U , typename N_MODULE>
class GeometricProgressionMinDualSqrtDecomposition :
  public BaseOfGeometricProgressionMinDualSqrtDecomposition<U,N_MODULE>
{

private:
  vector<U> m_memory;
  
public:
  template <typename...Args> inline GeometricProgressionMinDualSqrtDecomposition( N_MODULE M , const U& infty , vector<U> memory_r , vector<U> a = {} , Args&&... args );

  template <typename...Args> inline void Initialise( Args&&... args );
  inline void Set( const int& i , U u );
  inline void IntervalAct( const int& i_start , const int& i_final , const vector<U>& f ) = delete;
  inline void IntervalSetMin( const int& i_start , const int& i_final , const int& r_num , const U& y );

  inline U operator[]( const int& i );
  inline U Get( const int& i );

private:
  static vector<pair<U,int>> GetGraph( vector<U> a );
  
};
template <typename N_MODULE , typename...Args> GeometricProgressionMinDualSqrtDecomposition( N_MODULE M , Args&&... args ) -> GeometricProgressionMinDualSqrtDecomposition<inner_t<N_MODULE>,N_MODULE>;
