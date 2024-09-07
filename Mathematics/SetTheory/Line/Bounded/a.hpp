// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/a.hpp

#pragma once
#include "Iterator/a.hpp"

#ifdef DEBUG
  #include "../../DirectProduct/AffineSpace/BIT/Debug/a.hpp"
#else
  #include "../../DirectProduct/AffineSpace/BIT/a.hpp"
#endif

// verify:
// https://yukicoder.me/submissions/1002456 (insert, erase, ConnectedComponentOf)

// 構築O(ubound - lbound)
// 一点挿入O(log (ubound - lbound))
// 一点削除O(log (ubound - lbound))
// 一点帰属判定O(log (ubound - lbound))
// 区間要素数取得O(log (ubound - lbound))

// 先頭イテレータ取得O(log (ubound - lbound))
// 末尾イテレータ取得O(log (ubound - lbound))
// 上限/下限二分探索O(log (ubound - lbound))

// 最大値/最小値取得O(log (ubound - lbound))

// 一点連結成分取得O(log (ubound - lbound))
// 全連結成分取得O(連結成分数 log (ubound - lbound))

template <typename INT , template <typename...> typename DATA_STR>
class AbstractBoundedLineSubset
{

protected:
  INT m_lbound;
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  inline AbstractBoundedLineSubset( const INT& lbound , const INT& ubound );
  
  using iterator = IteratorOfBoundedLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i );
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentCount( const INT& i_final ) noexcept;
  inline int IntervalCount( const INT& i_start , const INT& i_final ) noexcept;
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() noexcept;

  inline iterator MaximumLeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MaximumLt( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGeq( const INT& i , const int& k = 0 ) noexcept;
  inline iterator MinimumGt( const INT& i , const int& k = 0 ) noexcept;

  inline INT Maximum( const int& k = 0 );
  inline INT Minimum( const int& k = 0 );

  // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept;
  // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept;

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& lbound() const noexcept;
  inline const INT& ubound() const noexcept;

};

#include "a_Alias.hpp"
