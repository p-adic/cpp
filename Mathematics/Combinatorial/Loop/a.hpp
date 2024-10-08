// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/a.hpp

#pragma once

// 要件
// (1) lower_boundとupper_limitとindexのサイズがsize以上である。
// (2) size未満の任意の非負整数dに対しlower_bound[d]<upper_limit[d]である。
// を満たす場合にのみサポート。

// 入れ子の深さdにおけるループは添字が[lower_bound[d],upper_limit[d])の範囲を動くように
// size重のforループを行うように添字ベクトルindexを合計計算量O(size N^size)で更新する。
template <typename INT> bool NextLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index );
template <typename INT> bool NextLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , vector<INT>& index );
template <typename INT> bool NextLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index );
template <typename INT> bool NextLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , vector<INT>& index );
