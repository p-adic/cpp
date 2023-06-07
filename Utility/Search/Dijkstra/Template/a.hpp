// c:/Users/user/Documents/Programming/Utility/Search/Dijkstra/Template/a.hpp

#pragma once
#include "../a_Macro.hpp"

// 入力の範囲内で要件
// (1) dの値がe_T()以上またはinftyである。
// (2) inftyがe_T()以上の項size_max個以下の和で表せるいかなる項よりも大きい。
// (3) (T,m_T:T^2->T,e_T:1->T)がbool operator<(const T&,const T&)に関して順序モノイドである。
// が成り立つ場合にのみサポート。
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty );
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T Dijkstra( const map<int,T> ( &d )[size_max] , const int& i_start , const int& i_final , const int& size , const T& infty , list<int>& path );
