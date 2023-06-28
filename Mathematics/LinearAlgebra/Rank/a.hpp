// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/Rank/a.hpp

#pragma once


// INT‚Íint‚©ll‚Å‚ ‚èAL <= bound_L‚©‚ÂM <= bound_M‚Å‚ ‚èAA‚Í—v‘f‚Ìâ‘Î’l‚ª\•ª¬‚³‚¢®”ŒW”L~Ms—ñ‚Å‚ ‚éB
template <typename INT , int bound_L , int bound_M>
int Rank( INT ( &A )[bound_L][bound_M] , const int& L , const int& M );

// L <= bound_L‚©‚ÂM <= bound_M‚Å‚ ‚èAA‚ÍF_2ŒW”L~Ms—ñ‚Å‚ ‚éB
template <int bound_L , int bound_M>
int Rank( bitset<bound_M> ( &A )[bound_L] , const int& L , const int& M );

// L <= bound_L‚©‚ÂM <= bound_M‚Å‚ ‚èAA‚ÍF_2ŒW”L~Ms—ñ‚ÆF_2ŒW”LŸcƒxƒNƒgƒ‹‚ğŒ‹‡‚µ‚½s—ñ‚Å‚ ‚éB
template <int bound_L , int bound_M>
int Reduce( bitset<bound_M + 1> ( &A )[bound_L] , bitset<bound_M + 1> &solution , const int& L , const int& M );

