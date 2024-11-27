// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Mo/a.hpp

#pragma once
// verify:
// https://yukicoder.me/submissions/954977（Get）
// https://atcoder.jp/contests/abc174/submissions/50552834（Solve）

// 入力の範囲内で要件
// (1) Fは写像f:N^2 -> Rに相当する型である。
// (2) DFxは写像dfx:R \times N^3 -> Rに相当する型である。
// (3) DFyは写像dfy:R \times N^3 -> Rに相当する型である。
// (4) いかなる(x,y,x') in N^3に対してもf(x',y) = dfx(f(x,y),x,y,x')である。
// (5) いかなる(x,y,y') in N^3に対してもf(x,y') = dfy(f(x,y),x,y,y')である。
// を満たす場合にのみサポート。

// 零初期化O(1)
// オフラインクエリ初期化O(min(ΔX+Q,Q log Q))

// 全クエリ回答取得O((ΔX+Q)sqrt(ΔY))
// （ただしdfx(r,x,y,x')とdfy(r,x,y,y')の計算量をO(|x-x'|+sqrt(ΔY))とO(|y-y'|)と仮定する）

class Mo
{

private:
  int m_Q;
  int m_Y_d;
  vector<vector<tuple<int,int,int>>> m_query;

public:
  inline Mo() = default;
  inline Mo( const vector<pair<int,int>>& query , int y_dif_sqrt = 0 );

  inline void Set( const vector<pair<int,int>>& query , int y_dif_sqrt = 0 );
  inline const vector<vector<tuple<int,int,int>>>& Get() const noexcept;

  // 莫のアルゴリズムで各クエリ(x,y)に対するf(x,y)を計算。
  template <typename F , typename DFx , typename DFy> vector<ret_t<F,int,int>> Solve( F& f , DFx& dfx , DFy& dfy ) const;

private:
  inline void IntroSort( const vector<pair<int,int>>& query , const int& y_start , const int& y_dif_sqrt );
  inline void BucketSort( const vector<pair<int,int>>& query , const int& x_start , const int& x_dif , const int& y_start , const int& y_dif_sqrt );
  template <typename R , typename DFx , typename DFy> void Solve_Body( vector<R>& answer , R& temp , int& x , int& y , DFx& dfx , DFy& dfy , , const int& d , const int& i_start ) const;
  
};
