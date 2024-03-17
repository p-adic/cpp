// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Bitset/a.hpp

#pragma once

// verify:
// https://yukicoder.me/submissions/961465（ReducedRowEchelonForm）

// 非型テンプレート引数をintやuintにしてしまうと実引数からテンプレート実引数が推論できないことに注意。
// （手元の環境ならuintでも通るがオンライン実行環境では通らない）
// 以下M <= bound_MかつM + N <= bound_M_Nの場合のみサポート。


// 階段化

// A.size()をLと置く。
// AはF_2係数L×M行列である場合にのみサポート。
// Aに対し左端非零成分が1である階段化を施しrankを返す。（O(bound_M L min{L,M})）
template <size_t bound_M> size_t RowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M );


// 拡大係数行列の簡約階段化

// A.size()をLと置く。
// AがF_2係数L×M行列（係数行列）とF_2係数L次縦ベクトルN個（非斉次項行列）を結合した
// 拡大係数行列である場合にのみサポート。
// Aに対し係数行列部分の簡約化＋拡大係数行列の左端非零成分が1である階段化を施し
// { 係数行列の階数 , 「対応する連立一次方程式が全て解を持つ」の真偽 } を返す。
// （O(bound_M_N L min{L,M+N})）
template <size_t bound_M_N> pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N );
// Aに対し係数行列部分の簡約化＋拡大係数行列の左端非零成分が1である階段化を施し
// solutionに連立一次方程式の解を格納し
// { 係数行列の階数 , 「対応する連立一次方程式が全て解を持つ」の真偽 } を返す。
// （O(bound_M_N L min{L,M+N})）
template <size_t bound_N , size_t bound_M_N> pair<size_t,bool> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , vector<bitset<bound_N>>& solution , const size_t& M , const size_t& N );


// 簡約化

// AがF_2係数L×M行列である場合にのみサポート。
// Aに簡約化を施しrankを返す。（O(bound_M L min{L,M})）
template <size_t bound_M> inline size_t ReducedRowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M );


// 線形独立性判定

// AがF_2係数L×M行列である場合にのみサポート。
// 「Aの各行が線形独立」の真偽を返す。（O(bound_M min{L,M}^2)）
template <size_t bound_L , size_t bound_M> inline bool LinearlyIndependent( const vector<bitset<bound_M>>& A , const size_t& M );


// 正則性判定

// AがF_2係数L次正方行列である場合にのみサポート。
// A_invにAの逆行列を格納し「L>0かつAが正則」の真偽を返す。（O(bound_L L^2)）
template <size_t bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const size_t& L );

