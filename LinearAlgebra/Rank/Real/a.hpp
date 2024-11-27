// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/Int/a.hpp

#pragma once

// 以下L <= bound_LかつM <= bound_Mの場合のみサポート。


// 左端非零成分が1である階段化（戻り値はrank）

// Aは簡約化で成分の絶対値が(0,epsilon)に入らないL×M行列である。
template <int bound_L , int bound_M>
int RowEchelonForm( double ( &A )[bound_L][bound_M] , const int& L , const int& M , const double& epsilon );
