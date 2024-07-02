// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Tuple/a.hpp"

// verify: https://atcoder.jp/contests/math-and-algorithm/submissions/55155204

// koturn, C++のラムダで再帰する(https://koturn.hatenablog.com/entry/2018/06/10/060000), koturnの日記, Hatena Blog, 2018-06-10.
// を元に実装。

template <typename REC>
class MemorisationRecursion : REC
{

public:
  inline MemorisationRecursion( REC rec );
  template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,Args&&...>& operator()( Args&&... args );

};
