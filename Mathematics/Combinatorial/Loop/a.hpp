// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a.hpp

#pragma once

// 要件
// (1) lower_boundとupper_limitのサイズがsize以上である。
// (2) size未満の任意の非負整数dに対しlower_bound[d]<upper_limit[d]である。
// を満たす場合にのみサポート。

// 入れ子の深さdにおけるループは添字が[lower_bound[d],upper_limit[d])の範囲を動くように
// size重のforループを行うように添字ベクトルindexを合計計算量O(D N^D)で更新する。
bool NextLoop( const int& size , const vector<int>& lower_bound , const vector<int>& upper_limit , vector<int>& index );
