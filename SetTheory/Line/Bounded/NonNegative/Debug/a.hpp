// c:/Users/user/Documents/Programming/Mathematics/SetTheory/Line/Bounded/NonNegative/Debug/a.hpp

#pragma once
#include "../../Debug/a.hpp"

// デバッグ用にデバッグ出力とsetを追加したもの。
// 各処理の計算量がO(size)増えることに注意。

template <typename INT>
class NonNegativeLineSubset :
  public VirtualBoundedLineSubset<INT,const INT&,const INT&>
{

public:
  inline NonNegativeLineSubset( const INT& ubound , const bool& output_mode = true );

private:
  inline bool InRange( const INT& i );
  inline constexpr const INT& Normalise( const INT& i );
  inline constexpr const INT& Denormalise( const INT& d );

};
