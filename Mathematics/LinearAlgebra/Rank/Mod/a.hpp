// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

// 以下L <= bound_LかつM <= bound_MかつN <= bound_Nの場合のみサポート。
// INTはintかllであり、Pは素数である。


// 左端非零成分が1である階段化（戻り値はrank）

// AはINT係数L×M行列である。
template <typename INT1 , typename INT2 , int bound_L , int bound_M>
int RowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P );


// 係数行列の簡約化＋拡大係数行列の左端非零成分が1である階段化
// { 係数行列の階数 , 「対応する連立一次方程式が全て解を持つ」の真偽 } を返す。

// AはINT係数L×M行列とINT係数L次縦ベクトルN個を結合した拡大係数行列である。
template <typename INT1 , typename INT2 , int bound_L , int bound_M_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , const int& L , const int& M , const int& N , const INT2& P );
template <typename INT1 , typename INT2 , int bound_L , int bound_M , int bound_N, int bound_M_N = bound_M + bound_N>
pair<int,bool> ExtendedReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M_N] , INT1 ( &solution )[bound_M][bound_N] , const int& L , const int& M , const int& N , const INT2& P );


// 簡約化（戻り値はrank）

// AはINT係数L×M行列である。
template <typename INT1 , typename INT2 , int bound_L , int bound_M> inline int ReducedRowEchelonForm( INT1 ( &A )[bound_L][bound_M] , const int& L , const int& M , const INT2& P );

// 逆行列（戻り値は「L>0かつAが正則」の真偽）

// AはINT係数L次正方行列である。
template <typename INT1 , typename INT2 , int bound_L>
bool Invertible( const INT1 ( &A )[bound_L][bound_L] , INT1 ( &A_inv )[bound_L][bound_L] , const int& L , const INT2& P );

