// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Mex/a.hpp

#pragma once

// 構築O(QuerySize)
// 要素追加O(1)
// mex取得クエリ合計O(QuerySize)
class MexSet
{

private:
  int m_QuerySize;
  vector<bool> m_in;
  int m_mex;

public:
  inline MexSet( const int& QuerySize );
  
  inline void insert( const int& i );
  inline const int& Get() const noexcept;

};
