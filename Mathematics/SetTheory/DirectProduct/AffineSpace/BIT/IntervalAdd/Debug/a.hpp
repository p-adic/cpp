// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp

#pragma once
#include "../../../../../../Algebra/Monoid/Group/Module/a.hpp"


// デバッグ用にIntervalAddBITを愚直な配列に変更したもの。
// 各区間処理の計算量がO(N)になることに注意。

template <typename U , typename Z_MODULE>
class AbstractIntervalAddBIT
{
  
protected:
  Z_MODULE m_M;
  int m_size;
  vector<U> m_a;
  
public:
  AbstractIntervalAddBIT( Z_MODULE M , const int& size = 0 );
  AbstractIntervalAddBIT( Z_MODULE M , const vector<U>& a );

  template <typename...Args> inline void Initialise( const Args&... args );
  inline void Set( const int& i , const U& u );
  inline void Add( const int& i , const U& u );
  inline void IntervalAdd( const int& i_start , const int& i_final , const U& u );

  inline const int& size() const noexcept;
  // const参照でないことに注意。
  inline U operator[]( const int& i );
  inline U Get( const int& i );
  inline U InitialSegmentSum( const int& i_final );
  inline U IntervalSum( const int& i_start , const int& i_final );
  
};
template <typename Z_MODULE> AbstractIntervalAddBIT( Z_MODULE M ) -> AbstractIntervalAddBIT<inner_t<Z_MODULE>,Z_MODULE>;

template <typename U = ll>
class IntervalAddBIT :
  public AbstractIntervalAddBIT<U,Module<int,U>>
{

public:
  template <typename...Args> inline IntervalAddBIT( const Args&... args );
  
};
template <typename U> IntervalAddBIT( const vector<U>& a ) -> IntervalAddBIT<U>;
