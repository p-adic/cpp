// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/a.hpp

#pragma once
#include "a_Macro.hpp"

// 入力の範囲内で要件
// (1) dの値が0以上またはinftyである。
// (2) inftyが0以上の数size_max個以下の和で表せるいかなる数よりも大きい。（-1などは不適）
// が成り立つ場合にのみサポート。
template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty );
template <int size_max>
int Dijkstra( const map<int,int> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const int& infty , list<int>& path );
