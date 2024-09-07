// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/a.hpp

#pragma once

#ifdef DEBUG
  #include "../Debug/a.hpp"
#else
  #include "../a.hpp"
#endif

// 構築O(ubound - lbound)
// 一点挿入O(log(ubound - lbound))
// 一点削除O(log(ubound - lbound))
// 一点帰属判定O(log(ubound - lbound))
// 区間要素数取得O(log(ubound - lbound))

// 先頭イテレータ取得O(log(ubound - lbound))
// 末尾イテレータ取得O(log(ubound - lbound))
// 上限/下限二分探索O(log(ubound - lbound))

// 最大値/最小値取得O(log(ubound - lbound))

// イテレータは要素の重複を無視することに注意。
template <typename INT, template <typename...> typename DATA_STR>
class AbstractBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,DATA_STR>
{
  
public:
  inline AbstractBoundedLineMultiSubset( const INT& lbound , const INT& ubound );
  
  inline void insert( const INT& i , const int& c = 1 );
  inline void erase( const INT& i , const int& c = 1 );
  inline void EraseAll( const INT& i );

  // VVV重複度が非負の場合のみサポート
  // inline bool empty() noexcept;

  // inline iterator begin() noexcept;
  // inline iterator end() const noexcept;

  // inline iterator MaximumLeq( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MaximumLt( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MinimumGeq( const INT& i , const int& k = 0 ) noexcept;
  // inline iterator MinimumGt( const INT& i , const int& k = 0 ) noexcept;

  // inline INT Maximum( const int& k = 0 );
  // inline INT Minimum( const int& k = 0 );
  // AAA重複度が非負の場合のみサポート
  
  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  
};

#include "a_Alias.hpp"

