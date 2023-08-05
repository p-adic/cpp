// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a.hpp

#pragma once

// 以下L <= bound_LかつM <= bound_Mの場合のみサポート。


// 左端非零成分が列の最大公約数である階段化（戻り値はrank）

// Aは要素の絶対値が十分小さいINT係数L×M行列であり、INTはintかllである。
template <typename INT , int bound_L , int bound_M>
int EuclideanRowEchelonForm( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );
