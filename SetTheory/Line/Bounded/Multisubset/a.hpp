// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a.hpp

#pragma once
#include "../a.hpp"

// 構築O(ubound - lbound)
// 一点挿入O(log(ubound - lbound))
// 一点削除O(log(ubound - lbound))
// 一点帰属判定O(log(ubound - lbound))
// 区間要素数取得O(log(ubound - lbound))

// 先頭イテレータ取得O(log(ubound - lbound))
// 末尾イテレータ取得O(log(ubound - lbound))
// 上限/下限二分探索O(log(ubound - lbound))

// 最大値/最小値取得O(log(ubound - lbound))

template <typename INT , typename RET_NOR , typename RET_DEN , template <typename...> typename DATA_STR>
class AbstractBoundedLineMultiSubset :
  virtual public VirtualBoundedLineSubset<INT,RET_NOR,RET_DEN,DATA_STR>
{
  
public:
  inline void insert( const INT& i , const INT& c = 1 );
  inline void erase( const INT& i , const INT& c = 1 );
  inline void EraseAll( const INT& i );

  // VVV重複度が非負の場合のみサポート
  // deleteされていないものはVirtualBoundedLineSubset内で定義されている。
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() noexcept;

  // inline iterator MaximumLeq( const INT& i , const INT& k = 0 );
  // inline iterator MaximumLt( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGeq( const INT& i , const INT& k = 0 );
  // inline iterator MinimumGt( const INT& i , const INT& k = 0 );

  // inline INT Maximum( const INT& k = 0 );
  // inline INT Minimum( const INT& k = 0 );
  
  INT RightEndPointOf( const INT& i , const bool& in = false ) = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  // AAA重複度が非負の場合のみサポート

};

template <typename INT>
class BoundedLineMultiSubset :
  public BoundedLineSubset<INT> ,
  public AbstractBoundedLineMultiSubset<INT,INT,INT,BIT>
{
  
public:
  inline BoundedLineMultiSubset( const INT& lbound , const INT& ubound );

};
