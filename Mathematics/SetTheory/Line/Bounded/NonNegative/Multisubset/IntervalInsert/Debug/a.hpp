// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../../Multisubset/IntervalInsert/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT>
class IntervalInsertNonNegativeLineMultiSubset :
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{

public:
  inline IntervalInsertNonNegativeLineMultiSubset( const INT& ubound );


protected:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};
