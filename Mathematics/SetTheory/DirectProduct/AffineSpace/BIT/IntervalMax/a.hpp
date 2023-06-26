// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/BIT/IntervalMax/a.hpp

#pragma once
#include "a_Macro.hpp"

// 最大（最小）元による初期化O(N)
// 配列による初期化O(N)

// 一点取得O(1)
// 区間max（min）取得O(log_2 N)

// 一点更新O((log_2 N)^2)
// max（min）による一点更新O(log_2 N)
// max（min）による区間更新O(i_final-i_start+log_2 N)

// t以上（以下）となる要素の添字の最小値の二分探索O(log_2 N)

// そのうちの区間min取得と一点更新は
// M. Dima, R. Ceterchi, Efficient Range Minimum Queries using Binary Indexed Trees, Olympiads in Informatics, 2015, Vol. 9, 39--44
// の手法をもとに実装
DECRALATION_OF_INTERVAL_MAX_BIT( Max );
DECRALATION_OF_INTERVAL_MAX_BIT( Min );
