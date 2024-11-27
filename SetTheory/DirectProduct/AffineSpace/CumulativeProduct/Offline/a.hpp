// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/Offline/a.hpp

#pragma once

// ARRAYは写像a:int->U1に相当する型。
// HOMは写像U1->U2の族h:T \times U1 -> U2に相当する型。
// queryのサイズをQと置く。

// 入力の範囲内で要件
// (1) M1がU1のモノイド構造である。
// (2) M2がU2の群構造である。
// (3) 各t in Tに対しh(t,-)が群準同型である。
// (4) Q未満の各qに対しquery[q]=(l_q,r_q,t_q)と置くと0 <= l_q <= r_q + 1である。
// が成り立つ場合にのみサポート。

// Q未満の各qに対するh(t_q,a(l_q))*...*h(t_q,a(r_q))をオフライン処理で求める。
// 左右両方向きの累積積を管理することも可能だがメモリ削減のために右向きのみ扱う。


// 初期化O(1)

// 右区間積総取得O(max_q r_q + Q log Q)
template <typename U1 , typename MONOID , typename U2 , typename GROUP , typename ARRAY , typename HOM , typename T>
class OfflineCumulativeProduct
{

private:
  MONOID m_M1;
  GROUP m_M2;
  ARRAY m_a;
  HOM& m_h;

public:
  inline OfflineCumulativeProduct( MONOID M1 , GROUP M2 , ARRAY a , HOM& h , const T& dummy );

  inline vector<U2> TotalIntervalProduct( const vector<tuple<int,int,T>>& query );
  
};
template <typename MONOID , typename GROUP , typename ARRAY , typename HOM , typename T> OfflineCumulativeProduct( MONOID M1 , GROUP M2 , ARRAY a , HOM& h , const T& dummy ) -> OfflineCumulativeProduct<inner_t<MONOID>,MONOID,inner_t<GROUP>,GROUP,ARRAY,HOM,T>;
