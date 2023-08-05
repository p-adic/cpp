// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once


// 以下L <= bound_LかつM <= bound_MかつN <= bound_Nの場合のみサポート。


// 左端非零成分が1である階段化（戻り値はrank）

// AはF_2係数L×M行列である。
template <int bound_L , int bound_M>
int RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );


// 係数行列の簡約化＋拡大係数行列の左端非零成分が1である階段化
// { 係数行列の階数 , 「対応する連立一次方程式が全て解を持つ」の真偽 } を返す。

// AはF_2係数L×M行列とF_2係数L次縦ベクトルN個を結合した拡大係数行列である。
template <int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const int& L , const int& M , const int& N );
template <int bound_L , int bound_M , int bound_N , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const int& L , const int& M , const int& N );

// 簡約化（戻り値はrank）

// AはF_2係数L×M行列である。
template <int bound_L , int bound_M> inline int ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );


// 逆行列（戻り値は「L>0かつAが正則」の真偽）

// AはF_2係数L次正方行列である。
template <int bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const int& L );
