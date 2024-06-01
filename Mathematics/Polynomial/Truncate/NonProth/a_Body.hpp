// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Truncate/NonProth/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"


// プロス素数以外の法で畳み込みをFFTで計算したい場合、このマクロで完全特殊化する。
// - 2663300644以下の法で高々8388607次以下の多項式の積（高々16777214次）
// - 2^{32}    未満の法で高々6451200次以下の多項式の積（高々12902400次）
// が計算可能。一般には
// - 0以上31以下の整数を係数に持つ高々10^6次の多項式の積は998244353を法とする。
// - 0以上10^6以下の整数を係数に持つ高々10^6次の多項式の積はガーナーのアルゴリズムで
//   最後に法を取らないように変更する。
// など、このマクロそのものを使わない方法も検討。
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_ARBITRARY_MOD( 1000000007 , Mod );

DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ll );
DEFINITION_OF_PARTIAL_SPECIALISATION_OF_MULTIPLICATION_OF_POLYNOMIAL_NON_MOD( ull );
