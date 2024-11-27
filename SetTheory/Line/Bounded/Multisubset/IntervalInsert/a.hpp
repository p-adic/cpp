// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Multisubset/IntervalInsert/a.hpp

#pragma once

#include "../a.hpp"

#ifdef DEBUG
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/Debug/a.hpp"
#else
  #include "../../../../DirectProduct/AffineSpace/BIT/IntervalAdd/a.hpp"
#endif

// 構築O(ubound - lbound)
// 一点挿入O(log(ubound - lbound))
// 区間挿入O(log(ubound - lbound))
// 一点削除O(log(ubound - lbound))
// 区間削除O(log(ubound - lbound))
// 一点帰属判定O(log(ubound - lbound))
// 区間要素数取得O(log(ubound - lbound))

// 先頭イテレータ取得O((log(ubound - lbound))^2)
// 末尾イテレータ取得O((log(ubound - lbound))^2)
// 上限/下限二分探索O((log(ubound - lbound))^2)

// 最大値/最小値取得O((log(ubound - lbound))^2)

// イテレータは要素の重複を無視することに注意。
template <typename INT , typename RET_NOR , typename RET_DEN>
class AbstractIntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineMultiSubset<INT,RET_NOR,RET_DEN,IntervalAddBIT>
{
  
public:
  inline void IntervalInsert( const INT& i_start , const INT& i_final , const INT& c = 1 );
  inline void IntervalErase( const INT& i_start , const INT& i_final , const INT& c = 1 );

};

template <typename INT>
class IntervalInsertBoundedLineMultiSubset :
  public AbstractBoundedLineSubset<INT,IntervalAddBIT> ,
  public AbstractIntervalInsertBoundedLineMultiSubset<INT,INT,INT>
{
  
public:
  inline IntervalInsertBoundedLineMultiSubset( const INT& lbound , const INT& ubound );

};
