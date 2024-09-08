// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/a.hpp

#pragma once
#include "../a.hpp"
#include "../../../Multisubset/IntervalInsert/a.hpp"

// 構築O(ubound)
// 一点挿入O(log ubound)
// 区間挿入O(log ubound)
// 一点削除O(log ubound)
// 区間削除O(log ubound)
// 一点帰属判定O(log ubound)
// 区間要素数取得O(log ubound)

// 先頭イテレータ取得O((log ubound)^2)
// 末尾イテレータ取得O((log ubound)^2)
// 上限/下限二分探索O((log ubound)^2)

// 最大値/最小値取得O((log ubound)^2)

// イテレータは要素の重複を無視することに注意。
template <typename INT>
class IntervalInsertNonNegativeLineMultiSubset :
  public AbstractNonNegativeLineSubset<INT,IntervalAddBIT> ,
  public AbstractIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{
  
public:
  inline IntervalInsertNonNegativeLineMultiSubset( const INT& ubound );

};

