// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/a.hpp

#pragma once

// 構築O(QuerySize)
// 要素追加O(1)
// mex取得クエリ合計O(QuerySize)

// QuerySizeは補集合の初期化にのみ必要。クエリ先読みは不要。
// 要素追加O(1)を実現するためにQuerySize以外の要素を無視するので
// countやinは持たない。それらが必要な場合はReversibleMexSetを使う。

class MexSet
{

private:
  int m_QuerySize;
  vector<bool> m_in;
  int m_mex;

public:
  inline MexSet( const int& QuerySize );

  inline void insert( const int& i );

  inline const int& mex() const noexcept;

};
