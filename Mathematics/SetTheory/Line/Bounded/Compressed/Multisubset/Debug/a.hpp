// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/Compressed/Multisubset/Debug/a.hpp

#pragma once
#include "../../../Multisubset/Debug/a.hpp"

// デバッグ用にデバッグ出力とmultisetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT>
class CompressedLineMultiSubset :
  public VirtualBoundedLineMultiSubset<INT,const INT&,const INT&>
{

protected:
  vector<INT> m_sorted_coord;
  Map<INT,int> m_sorted_coord_inv;

public:
  inline CompressedLineMultiSubset( const vector<INT>& query );

protected:
  inline bool InRange( const INT& i );
  inline const INT& Normalise( const INT& i );
  inline const INT& Denormalise( const INT& d );

};

