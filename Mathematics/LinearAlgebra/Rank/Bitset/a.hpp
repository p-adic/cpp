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

// AがF_2係数L×M行列（係数行列）とF_2係数L次縦ベクトルN個（非斉次項行列）を結合した
// 拡大係数行列である場合に
// Aに対し係数行列部分の簡約化＋拡大係数行列の左端非零成分が1である階段化を施し、
// {係数行列の階数,解が存在する?解:0次正方行列}を返す（O(L bound_M_N min{L,M+N})）。
// 解が存在する場合の一意性は係数行列の階数がMか否かで判定可能。
template <size_t bound_M_N> pair<size_t,vector<bool>> ExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N );
// {係数行列の階数,解の有無のベクトル,解を横に並べた行列}を返す（O(L bound_M_N min{L,M+N})）。
template <size_t bound_N , size_t bound_M_N> tuple<size_t,vector<bool>,vector<bitset<bound_N>>> MultiExtendedReducedRowEchelonForm( vector<bitset<bound_M_N>>& A , const size_t& M , const size_t& N );


// 簡約化

// AがF_2係数L×M行列である場合にのみサポート。
// Aに簡約化を施しrankを返す。（O(bound_M L min{L,M})）
template <size_t bound_M> inline size_t ReducedRowEchelonForm( vector<bitset<bound_M>>& A , const size_t& M );


// 正則性判定

// AがF_2係数L次正方行列である場合にのみサポート。
// A_invにAの逆行列を格納し「L>0かつAが正則」の真偽を返す。（O(bound_L L^2)）
template <size_t bound_L>
bool Invertible( const bitset<bound_L> ( &A )[bound_L] , bitset<bound_L> ( &A_inv )[bound_L] , const size_t& L );


// 一次関係式計算

// AがF_2係数L×M行列である場合にのみサポート。Aを簡約化し、
// {階数,一次従属?非自明な一次関係式の係数:空列}を返す（O(bound_M min{L,M}^2)）。
template <size_t bound_L , size_t bound_M> vector<bool> LinearRelation( const vector<bitset<bound_M>>& A , const size_t& M );
