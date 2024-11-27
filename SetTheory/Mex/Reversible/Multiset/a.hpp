// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/Reversible/Multiset/a.hpp

#pragma once

// 構築O(QuerySize log QuerySize)
// 要素検索O(log QuerySize)
// 要素追加O(log QuerySize)
// 要素削除O(log QuerySize)
// mex取得O(1)

// QuerySizeは補集合の初期化にのみ必要。クエリ先読みは不要。

class ReversibleMexMultiset
{

private:
  int m_QuerySize;
  set<int> m_comp;
  map<int,int> m_mult;

public:
  inline ReversibleMexMultiset( const int& QuerySize );

  inline int count( const int& i ) const;
  inline bool in( const int& i ) const;

  inline void insert( const int& i );
  inline void erase( const int& i );
  inline const int& mex() const;

};

