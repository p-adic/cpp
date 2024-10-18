// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/IncreasingSequence/a.hpp

#pragma once

// O(val_max-val_min+1)で単調増大列の個数を求める。
// val_max-val_min+1が大きくてsizeが小さい場合は再帰で二項係数を求める方がよい。
template <typename MODINT> inline MODINT CountNonStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max );
template <typename MODINT> inline MODINT CountStrictlyIncreasingSequence( const int& size , const int& val_min , const int& val_max );

