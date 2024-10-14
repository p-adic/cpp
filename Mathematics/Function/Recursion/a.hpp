// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../../../Utility/Tuple/a.hpp"

// verify:
// https://yukicoder.me/submissions/998766（Recursion）
// https://atcoder.jp/contests/math-and-algorithm/submissions/56175446（MemoRecursion）

// Recursion( int , f , const int& n ){
//   return n <= 1 ? n : ( f( n - 1 ) + f( n - 2 ) ) % 1000000007;
// };

// MemoRecursion( int , f , const int& n ){
//   return n <= 1 ? n : ( f( n - 1 ) + f( n - 2 ) ) % 1000000007;
// };

// koturn, C++のラムダで再帰する(https://koturn.hatenablog.com/entry/2018/06/10/060000), koturnの日記, Hatena Blog, 2018-06-10.
// を元に実装。

template <typename REC>
class NonMemorisationRecursion : REC
{

public:
  inline NonMemorisationRecursion( REC rec );
  template <typename...Args> inline ret_t<REC,NonMemorisationRecursion<REC>&,const Args&...> operator()( const Args&... args );

};

template <typename REC>
class MemorisationRecursion : REC
{

private:
  int m_num;
  
public:
  inline MemorisationRecursion( REC rec );
  template <typename...Args> inline const ret_t<REC,MemorisationRecursion<REC>&,const Args&...>& operator()( const Args&... args );

};
