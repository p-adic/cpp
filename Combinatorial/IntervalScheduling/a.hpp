// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IntervalScheduling/a.hpp

#pragma once

// verify: https://yukicoder.me/submissions/931520

// 入力の範囲内で要件
// (1) bool operator<=(const T&,const T&)が全順序である。
// (2) bool operator<(const T&,const T&)が<=に付随する狭義全順序である。
// を満たす場合にのみサポート。

// 区間追加O(log m_size)
// 区間削除O(log m_size)
// 先頭区間取得O(1)
// 後続区間取得O(log m_size)
// 全後続区間取得O(m_size)
// 最多排他的区間列取得O(m_size)
template <typename T>
class IntervalScheduling
{
  
private:
  int m_count;
  vector<T> m_l;
  vector<T> m_r;
  vector<bool> m_valid;
  set<tuple<T,T,int>> m_rli;
  int m_size;
  T m_l_max;

public:
  inline void insert( const T& l , const T& r );
  inline void erase( const tuple<T,T,int>& v );

  inline const int& count() const noexcept;
  inline const T& GetL( const int& i ) const;
  inline const T& GetR( const int& i ) const;
  // const参照でないことに注意
  inline bool GetValid( const int& i ) const;
  inline const int& size() const noexcept;

  inline const int& Init() const;
  // イベントiを選択した後にイベント数を最多にするために次に選択するべきイベント番号を取得
  int Next( const int& i ) const;
  // イベント数を最多にするようなイベント処理順を格納
  void SetNext( vector<int>& a ) const noexcept;
  // イベントiを選択した後にイベント数を最多にするようなイベント処理順を取得
  void SetMaximal( list<int>& a , const int& i = -1 ) const;
  
};
