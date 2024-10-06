// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Function/QuadraticResidue/a.hpp

#pragma once

// pが奇素数の時にO(√|a%p|)で平方剰余記号(a/p)を返す。
// ただしp<1<<31の時はO(log_2 p)のアルゴリズムで計算する。
template <typename INT> int QuadraticResidueSymbol( INT a , const ll& p , const bool& reduced = false );
