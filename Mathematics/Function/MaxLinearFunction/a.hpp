// c:/Users/user/Documents/Programming/Mathematics/Function/MaxLinearFunction/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/981573

// 基本的に下記URLのConvex Hull Trickに準じる。
// https://rsk0315.hatenablog.com/entry/2022/04/29/141726

// 定数関数0による構築O(1)
// 一次関数とのmaxによる全体更新O(log size)
// 一点取得O(log size)
template <typename INT>
class MaxLinearFunction
{

private:
  // m_abc[傾きa] = { y切片b , 最大値を取る区間左端のx座標c } として管理。
  map<INT,pair<INT,INT> > m_abc;
  // m_ca[最大値を取る区間左端のx座標c] = 傾きa として管理。
  map<INT,INT> m_ca;
  INT m_llim_c;
  INT m_ulim_c;

public:
  inline MaxLinearFunction( const INT& llim_c , const INT& ulim_c );

  void SetMax( const INT& a , const INT& b );
  INT Get( const INT& x ) const;

private:
  static INT Intersection( const INT& a0 , const INT& b0 , const INT& a1 , const INT& b1 );
  
};

template <typename INT>
class MinLinearFunction :
  public MaxLinearFunction<INT>
{

public:
  inline MinLinearFunction( const INT& llim_c , const INT& ulim_c );

  inline void SetMin( const INT& a , const INT& b );
  inline INT Get( const INT& x ) const;

};
