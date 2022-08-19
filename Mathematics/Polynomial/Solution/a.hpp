// c:/Users/user/Documents/Programming/Mathematics/Polynomial/Solution/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Arithmetic/Mod/a.hpp"

// Pが素数である場合のみサポート
template <INT_TYPE_FOR_MOD P uint D>
void Solve( vector<Polinomial<Mod<P>,D> >& F , AffineSpace<Mod<P>,D>& x , bool& solvable );

template <INT_TYPE_FOR_MOD P uint D>
void Solve( vector<Polinomial<Mod<P>,D> >& F , vector<PolynomialIndex<D> >& LT_F , vector<Mod<P> >& LC_F , uint& size_F , AffineSpace<Mod<P>,D>& x , bool& solvable );
