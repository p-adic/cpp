// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a.hpp

#pragma once

#ifdef DEBUG
  #include "../../Debug/a.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"
#else
  #include "../../a.hpp"
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp"
#endif

// 構築O(ubound - lbound)
// 一点挿入O(log(ubound - lbound))
// 一点削除O(log(ubound - lbound))
// 一点帰属判定O(log(ubound - lbound))
// 区間要素数取得O(log(ubound - lbound))

// 先頭イテレータ取得O((log(ubound - lbound))^2)
// 末尾イテレータ取得O((log(ubound - lbound))^2)
// 上限/下限二分探索O((log(ubound - lbound))^2)

// 最大値/最小値取得O((log(ubound - lbound))^2)

// イテレータは要素の重複を無視することに注意。
template <typename INT, template <typename...> typename DATA_STR>
class AbstractIntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,DATA_STR>
{
  
public:
  inline AbstractIntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound );
  
  inline void insert( const INT& i , const int& c = 1 );
  inline void IntervalInsert( const INT& i_start , const INT& i_final , const int& c = 1 );
  inline void erase( const INT& i , const int& c = 1 );
  inline void EraseAll( const INT& i );
  inline void IntervalErase( const INT& i_start , const INT& i_final , const int& c = 1 );

  INT RightEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  INT LeftEndPointOf( const INT& i , const bool& in = false ) noexcept = delete;
  inline pair<INT,INT> ConnectedComponentOf( const INT& i , bool in = false ) noexcept = delete;
  vector<pair<INT,INT>> GetConnectedComponent() noexcept = delete;
  
};

#include "a_Alias.hpp"

