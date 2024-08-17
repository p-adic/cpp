// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Mod/a.hpp

#pragma once
#include "a_Macro.hpp"

// 以下MODINTは素数を法とする整数型である場合のみサポート。


// 階段化

// AがL×M行列である場合に、
// Aを左端非零成分が1である階段化しrankを返す（O(LM min{L,M})）。
template <typename MODINT> int RowEchelonForm( vector<vector<MODINT>>& A );


// 拡大係数行列の簡約階段化

// AがL×M行列とL次縦ベクトルN個を結合した拡大係数行列である場合に、
// Aに対し係数行列の簡約化＋拡大係数行列の左端非零成分が1である階段化を施し、
// {係数行列の階数,「対応する連立一次方程式が全て解を持つ」の真偽}を返す（O(L(M+N)min{L,M+N})）。
// 解の一意存在性は係数行列の階数がMか否かで判定可能、その際の解は縱ベクトル部分。
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , const int& N = 1 );
// 解が少なくとも１つ存在する場合はそれをsolution/solutionsに格納する。
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<MODINT>& solution );
template <typename MODINT> pair<int,bool> ExtendedReducedRowEchelonForm( vector<vector<MODINT>>& A , vector<vector<MODINT>>& solutions , const int& N );


// 簡約化

// AがL×M行列でありかつ簡約化である場合に、
// Aを簡約化しrankを返す（O(LM min{L,M})）。
template <typename MODINT> inline int ReducedRowEchelonForm( vector<vector<MODINT>>& A );


// 正則性判定

// AはL次正方行列である場合に、
// Aが正則ならばAの逆行列を格納し、正則でないならば0次正方行列を返す（O(L^3)）。
template <typename MODINT> vector<vector<MODINT>> Inverse( const vector<vector<MODINT>>& A );

