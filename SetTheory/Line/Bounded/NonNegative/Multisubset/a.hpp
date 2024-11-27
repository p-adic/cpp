// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Multisubset/a.hpp"

// verify:
// https://yukicoder.me/submissions/1008610（insert, InitialSegmentCount, IntervalCount）

// BoundedLineMultiSubsetの定数倍高速化。

// 構築O(ubound)
// 一点挿入O(log ubound)
// 一点削除O(log ubound)
// 一点帰属判定O(log ubound)
// 区間要素数取得O(log ubound)

// 先頭イテレータ取得O(log ubound)
// 末尾イテレータ取得O(log ubound)
// 上限/下限二分探索O(log ubound)

// 最大値/最小値取得O(log ubound)

// 一点連結成分取得O(log ubound)
// 全連結成分取得O(連結成分数 log ubound)

// イテレータは要素の重複を無視することに注意。

template <typename INT>
class NonNegativeLineMultiSubset :
  public NonNegativeLineSubset<INT> ,
  public AbstractBoundedLineMultiSubset<INT,const INT&,const INT&,BIT>
{
  
public:
  inline NonNegativeLineMultiSubset( const INT& ubound );

};
