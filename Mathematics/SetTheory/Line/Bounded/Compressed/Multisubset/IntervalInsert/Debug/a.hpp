// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/IntervalInsert/Debug/a.hpp

#pragma once
#include "../../../../Multisubset/IntervalInsert/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT>
class IntervalInsertCompressedSortedMultiSet :
  virtual public VirtualIntervalInsertBoundedLineMultiSubset<INT,const INT&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  map<INT,int> m_sorted_coord_inv;

public:
  inline IntervalInsertCompressedSortedMultiSet( const vector<INT>& query );


protected:
  inline bool InRange( const INT& i );
  inline const INT& Normalise( const INT& i );
  inline const INT& Denormalise( const INT& d );

};
