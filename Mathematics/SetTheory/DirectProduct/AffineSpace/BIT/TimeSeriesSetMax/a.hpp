// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesSetMax/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../../../Algebra/Monoid/Group/Module/a.hpp"

// verify:
// https://atcoder.jp/contests/abc351/submissions/52928503（MaxIntervalSum+AbstractBIT）

// 入力の範囲内で要件
// (1) bool operator<(const R&,const R&)は全順序である。
// (2) bool operator<(const U&,const U&)は全順序である。
// (3) MはUのZ加群構造である。（<と整合的である必要はない）
// を満たす場合にのみサポート。
// ただしABSTRACT_BITとしてAbstractMonoidBITやAbstractSegtreeを使う場合は(2)の代わりに
// (3)' MはUのN加群構造である。
// を満たせば良い。

// 配列の各成分を全体max更新させた時に更新済みか否かを管理するデータ構造。

// 配列のサイズをN、全体max更新イベントの個数をE、区間和取得クエリの個数をQと置く。

// 零初期化O(1)
// 配列初期化O(N + E log E)

// 全体max更新イベント追加O(log E)

// 区間和取得クエリオンライン処理O((N+Q)log N + E + (sorted?1:Q log Q))
template <typename R , typename U , typename Z_MODULE>
class AbstractTimeSeriesSetMaxBIT
{

private:
  Z_MODULE m_M;

  int m_N;
  // 初期値を格納
  vector<U> m_a;
  // {全体max更新時刻,更新値}を格納
  map<R,U> m_event;

public:
  inline AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy , const int& N = 0 );
  inline AbstractTimeSeriesSetMaxBIT( Z_MODULE M , const R& dummy ,  vector<U> a , const vector<pair<R,U>>& event = {} );

  template <typename...Args> inline void Initialise( Args&&... args );

  // 時刻tにuでの全体max更新を行う。
  inline void Set( const R& t , const U& u );

  // 各クエリ{t,l,r}ごとに、時刻t（全体max更新後）における区間[l,r]での総和を取得。
  template <typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Z_MODULE>> vector<U> IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted = false );

};
template <typename R , typename Z_MODULE , typename...Args> AbstractTimeSeriesSetMaxBIT( Z_MODULE , R , Args&&... ) -> AbstractTimeSeriesSetMaxBIT<R,inner_t<Z_MODULE>,Args...>;

template <typename U>
class TimeSeriesSetMaxBIT :
  public AbstractTimeSeriesSetMaxBIT<ll,U,Module<ll,U>>
{

public:
  inline TimeSeriesSetMaxBIT( const int& N = 0 );
  template <typename...Args> inline TimeSeriesSetMaxBIT( vector<U> a , Args&&... args );

};

// 入力の範囲内で要件
// (1) bool operator<(const U&,const U&)は全順序である。
// (2) MはUのZ加群構造である。（<と整合的である必要はない）
// を満たす場合にのみサポート。
// ただしABSTRACT_BITとしてAbstractMonoidBITやAbstractSegtreeを使う場合は(2)の代わりに
// (2)' MはUのN加群構造である。
// を満たせば良い。

// 各クエリ{u,l,r}ごとに、max(a[-],u)の区間[l,r]での総和を取得。（O((N+Q)log N + Q log Q)）
template <typename U , typename Z_MODULE , typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Z_MODULE>> vector<U> AbstractMaxIntervalSum( Z_MODULE M , vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted = false );
template <typename U , typename INT , typename ABSTRACT_BIT = AbstractBIT<U,Module<int,U>>> inline vector<U> MaxIntervalSum( vector<U> a , const vector<tuple<U,INT,INT>>& query , const bool& sorted = false );
