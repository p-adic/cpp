// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/TimeSeriesAdd/a.hpp

#pragma once
#include "../../../../../Algebra/Monoid/Group/Module/Interval/a_Body.hpp"

// verify:
// https://yukicoder.me/submissions/977887（配列初期化、Set）

// 入力の範囲内で要件
// (1) Rは全順序集合である。Rの定める圏をCと置く。
// (2) MはUのC作用付き可換群構造である。
// を満たす場合にのみサポート。

// 配列の各成分を指定した傾き（単位時間当たりの変化量）で変化させた時の
// 傾きとy切片を管理するデータ構造。

// 配列のサイズをN、傾き変更イベントの個数をE、区間和取得クエリの個数をQと置く。

// 零初期化O(1)
// 配列初期化O(N + E log E)

// 傾き変更イベント追加O(log E)

// 区間和取得クエリオンライン処理O((E+Q)log N + (sorted?1:Q log Q))
template <typename R , typename U , typename C_MODULE>
class AbstractTimeSeriesAddBIT
{

private:
  C_MODULE m_M;
  // 初期時刻を格納
  R m_init;

  int m_N;
  // 初期値を格納
  vector<U> m_a;
  // {傾き変更時刻,変更対象のindex,傾き}を格納
  // （傾き変更時刻ちょうどは変更後の傾きの寄与が0であることに注意）
  map<pair<R,int>,U> m_event;

public:
  inline AbstractTimeSeriesAddBIT( C_MODULE M , R init , const int& N = 0 );
  inline AbstractTimeSeriesAddBIT( C_MODULE M , R init , vector<U> a , const vector<tuple<R,int,U>>& event = {} );

  template <typename...Args> inline void Initialise( Args&&... args );

  // 時刻に関するa[i]のグラフの傾きを時刻tからduに変更する。
  // （元々の傾きが0でない場合は時刻tちょうどまでの加算が行われることに注意）
  inline void Set( const R& t , const int& i , const U& du );

  // 各{t,l,r}ごとに、時刻tにおける区間[l,r]での総和を取得。
  template <typename INT> vector<U> IntervalSum( const vector<tuple<R,INT,INT>>& query , const bool& sorted = false );

};
template <typename R , typename C_MODULE , typename...Args> AbstractTimeSeriesAddBIT( C_MODULE , R , Args&&... ) -> AbstractTimeSeriesAddBIT<R,inner_t<C_MODULE>,Args...>;

template <typename U>
class TimeSeriesAddBIT :
  public AbstractTimeSeriesAddBIT<ll,U,IntervalModule<ll,U>>
{

public:
  inline TimeSeriesAddBIT( const int& N = 0 );
  template <typename...Args> inline TimeSeriesAddBIT( vector<U> a , Args&&... args );

};
