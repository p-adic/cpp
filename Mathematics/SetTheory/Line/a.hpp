// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/a.hpp

#pragma once
#include "Iterator/a.hpp"

// verify:
// https://yukicoder.me/submissions/1002789（insert, erase, ConnectedComponentOf）

// 構築O(1)
// 一点挿入O(log Q)
// 区間挿入O(log Q)（均し）
// 一点削除O(log Q)
// 区間削除O(log Q)（均し）
// 一点帰属判定O(log Q)
// サイズ取得O(1)

// 先頭イテレータ取得O(1)
// 末尾イテレータ取得O(1)
// 上限/下限二分探索O(log Q)

// 最大値/最小値取得O(1)

// 一点連結成分取得O(log Q)

template <typename INT>
class LineSubset
{

private:
  // 区間[l,r]ごとにm_l[r] = lとして直線の部分集合を管理する。
  map<INT,INT> m_l;
  int m_size;

public:
  using iterator = IteratorOfLineSubset<INT>;
  
  void insert( const INT& i ) noexcept;
  void IntervalInsert( const INT& i_start , const INT& i_final ) noexcept;
  void erase( const INT& i ) noexcept;
  void IntervalErase( const INT& i_start , const INT& i_final ) noexcept;
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) const noexcept;
  bool find( const INT& i ) const noexcept;

  inline const int& size() const noexcept;
  inline bool empty() const noexcept;

  inline iterator begin() const noexcept;
  inline iterator end() const noexcept;

  inline iterator MaximumLeq( const INT& i ) const noexcept;
  inline iterator MaximumLt( const INT& i ) const noexcept;
  inline iterator MinimumGeq( const INT& i ) const noexcept;
  inline iterator MinimumGt( const INT& i ) const noexcept;

  inline INT Maximum() const;
  inline INT Minimum() const;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  pair<INT,INT> ConnectedComponentOf( const INT& i ) const noexcept;

  inline const map<INT,INT>& GetConnectedComponent() const noexcept;
  
};
