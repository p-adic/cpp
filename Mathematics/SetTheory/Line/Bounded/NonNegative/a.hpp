// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/NonNegative/a.hpp

#pragma once
#include "Iterator/a.hpp"
#include "../../DirectProduct/AffineSpace/BIT/a.hpp"

// 非負に制限したBoundedLineSubsetの定数倍高速化版。

// 構築O(ubound)
// 一点挿入O(log ubound)
// 一点削除O(log ubound)
// 一点帰属判定O(log ubound)
// 区間サイズ取得O(log ubound)

// 先頭イテレータ取得O(log ubound)
// 末尾イテレータ取得O(log ubound)
// 上限/下限二分探索O(log ubound)

// 最大値/最小値取得O(log ubound)

// 一点連結成分取得O(log ubound)
// 全連結成分取得O(連結成分数 log ubound)

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset
{

protected:
  INT m_ubound;
  DATA_STR<INT> m_ds;

public:
  inline AbstractNonNegativeLineSubset( const INT& ubound );
  
  using iterator = IteratorOfNonNegativeLineSubset<INT,DATA_STR>;
  
  inline void insert( const INT& i );
  inline void erase( const INT& i );
  // itrをインクリメントして書き換え、それへの参照を返す。
  inline iterator& erase( iterator& itr );

  inline int count( const INT& i ) noexcept;
  bool find( const INT& i ) noexcept;

  inline int InitialSegmentSize( const INT& i_final ) noexcept;
  inline int IntervalSize( const INT& i_start , const INT& i_final ) noexcept;
  inline bool empty() noexcept;

  inline iterator begin() noexcept;
  inline iterator end() const noexcept;

  inline iterator MaximumLeq( const INT& i ) noexcept;
  inline iterator MaximumLt( const INT& i ) noexcept;
  inline iterator MinimumGeq( const INT& i ) noexcept;
  inline iterator MinimumGt( const INT& i ) noexcept;

  inline INT Maximum();
  inline INT Minimum();

  // iを含む連結成分の右端を返す。存在しない場合はi-1を返す。
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept;
  // iを含む連結成分の左端を返す。存在しない場合はi+1を返す。
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept;

  // iを含む連結成分を返す。存在しない場合は[1+1,i-1]を返す。
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept;

  vector<pair<INT,INT>> GetConnectedComponent() noexcept;

  inline const INT& ubound() const noexcept;

  // Fは積順序に関して単調な写像f:U \times int -> {0,1}に相当する型。
  // f( m_ds.InitialSegmentSum( i ) , i )がtrueとなるiが存在する場合にその最小値を返す。
  template <typename F> virtual int Search( const F& f );

};

#include "a_Alias.hpp"
