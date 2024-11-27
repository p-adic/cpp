// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/a.hpp

#pragma once
#include "../a.hpp"

// verify:
// https://yukicoder.me/submissions/1008252 (insert,erase,ConnectedComponentOf)

// 非負に制限したBoundedLineSubsetの定数倍高速化版。

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

template <typename INT , template <typename...> typename DATA_STR>
class AbstractNonNegativeLineSubset :
  virtual public VirtualBoundedLineSubset<INT,const INT&,const INT&,DATA_STR>
{

protected:

public:
  inline AbstractNonNegativeLineSubset( const INT& ubound );

protected:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};

#include "a_Alias.hpp"
