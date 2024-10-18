// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/SubSequence/a.hpp

#pragma once
#include "a.hpp"

// O(S.size() T.size())でTと等しいSの（連続とは限らない）部分列の個数を求める。
INT CountSubSequence( const VEC& S , const VEC& T );
// 連続部分列の個数はRollingHash::CountContain()を用いる。

