// c:/Users/user/Documents/Programming/Utility/Search/FloydWarshall/a.hpp

#pragma once

// 入力の範囲内で要件
// (1) (T,m_T:T^2->T,e_T:1->T)がbool operator<(const T&,const T&)に関して順序モノイドである。
// (2) dの値がe_T()以上またはinftyである。
// (3) inftyがe_T()以上の項size_max個以下の和で表せない。
// が成り立つ場合にのみサポート。
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty );
template <typename T , T m_T(const T&,const T&) , const T& e_T() , int size_max>
T FloydWarshall( const T ( &d )[size_max][size_max] , T ( &weight )[size_max][size_max] , const int& size , const T& infty , int ( &path )[size_max][size_max] );
