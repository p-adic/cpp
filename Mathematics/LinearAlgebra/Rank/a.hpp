// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/a.hpp

#pragma once


// INTはintかllであり、L <= bound_LかつM <= bound_Mであり、Aは要素の絶対値が十分小さい整数係数L×M行列である。
template <typename INT , int bound_L , int bound_M>
int Rank( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );

// L <= bound_LかつM <= bound_Mであり、AはF_2係数L×M行列である。
template <int bound_L , int bound_M>
int Rank( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );

// L <= bound_LかつM <= bound_Mであり、AはF_2係数L×M行列とF_2係数L次縦ベクトルを結合した行列である。
template <int bound_L , int bound_M>
int Reduce( bitset<bound_M + 1> ( &A )[bound_L] , bitset<bound_M + 1> &solution , const int& L , const int& M );

