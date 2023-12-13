// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/a.hpp

#pragma once

// (T,m_T:T^2->T,e_T:1->T)がモノイドである場合にのみサポート。
// Tの要素の列のm_Tに関する総乗を分割統治で計算し、その結果を第1成分に格納して参照返しする。
// V<T>はeraseを持つ必要がある。
template <typename T , template <typename...> typename V , T m_T(const T&,const T&) , const T& e_T()>
T& MonoidalProd( V<T>& f );
template <typename T , template <typename...> typename V>
T& Sum( V<T>& f );
template <typename T , template <typename...> typename V>
T& Prod( V<T>& f );
