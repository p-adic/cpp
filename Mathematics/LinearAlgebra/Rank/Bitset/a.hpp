// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961450（ReducedRowEchelonForm）

// 非型テンプレート引数をintにしてしまうと実引数からテンプレート実引数が推論できないことに注意。
// 以下L <= bound_LかつM <= bound_MかつN <= bound_Nの場合のみサポート。

// AはF_2係数L×M行列である場合にのみサポート。
// Aに対し左端非零成分が1である階段化を施しrankを返す。
template <uint bound_L , uint bound_M>
uint RowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M );

// AがF_2係数L×M行列とF_2係数L次縦ベクトルN個を結合した拡大係数行列である場合にのみサポート。
// Aに対し係数行列部分の簡約化＋拡大係数行列の左端非零成分が1である階段化を施し
// { 係数行列の階数 , 「対応する連立一次方程式が全て解を持つ」の真偽 } を返す。
template <uint bound_L , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , const uint& L , const uint& M , const uint& N );
template <uint bound_L , uint bound_M , uint bound_N , uint bound_M_N>
pair<uint,bool> ExtendedReducedRowEchelonForm( bitset<bound_M_N> ( &A )[bound_L] , bitset<bound_N> ( &solution )[bound_M] , const uint& L , const uint& M , const uint& N );

// AがF_2係数L×M行列である場合にのみサポート。
// Aに簡約化を施しrankを返す。
template <uint bound_L , uint bound_M> inline uint ReducedRowEchelonForm( bitset<bound_M> ( &A )[bound_L] , const uint& L , const uint& M );

// AがF_2係数L次正方行列である場合にのみサポート。
// A_invにAの逆行列を格納し「L>0かつAが正則」の真偽を返す。
template <uint bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const uint& L );
