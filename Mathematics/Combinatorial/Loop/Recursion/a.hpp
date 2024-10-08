// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/Loop/Recursion/a.hpp

#pragma once

// BEFOREはArg(&before)(const int&,const int&,const Arg&)に相当する型。
// AFTEREはvoid(&after)(const int&,const int&,const Arg&)に相当する型。

// 要件
// (1) lower_boundとupper_limitのサイズがsize以上である。
// (2) size未満の任意の非負整数dに対しlower_bound[d]<upper_limit[d]である。
// を満たす場合にのみサポート。

// 入れ子の深さdにおけるループは添字iが[lower_bound[d],upper_limit[d])の範囲を動き、
// その内部でbefore(d,i,arg)とafter(d,i,arg)を入れ子の前後で実行するようなsize重のforループを
// 合計計算量O(size N^size)で行う。
template <typename INT , typename Arg , typename BEFORE , typename AFTER> Arg ExecuteLoop( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_limit , const int& d , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoop( const vector<INT>& lower_bound , const vector<INT>& upper_limit , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> Arg ExecuteLoopEq( const int& size , const vector<INT>& lower_bound , const vector<INT>& upper_bound , const int& d , const Arg& arg , const BEFORE& before , const AFTER& after );
template <typename INT , typename Arg , typename BEFORE , typename AFTER> inline Arg ExecuteLoopEq( const vector<INT>& lower_bound , const vector<INT>& upper_bound , const Arg& arg , const BEFORE& before , const AFTER& after );
