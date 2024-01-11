// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/942772（一点更新／区間max取得）
// https://yukicoder.me/submissions/942771（配列による初期化／区間max取得）

// 最大（最小）元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// LSB切片取得O(1)（left:max(a[j-(j&-j)],...,a[j-1])、right:max(a[j-1],...,a[j+(j&-j)-1])）
// 区間max（min）取得O(log_2 N)

// 一点更新O((log_2 N)^2)
// max（min）による一点更新O(log_2 N)
// max（min）による区間更新O(i_final-i_start+log_2 N)

// n以上（以下）となる要素の添字の最小値の二分探索O(log_2 N)
// （存在しない場合はN以上の最小の2羃×2-1を返すので、N以上であることで判定可能）

// そのうちの区間min取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法をもとに実装
DECLARATION_OF_INTERVAL_MAX_BIT( Max );
DECLARATION_OF_INTERVAL_MAX_BIT( Min );

