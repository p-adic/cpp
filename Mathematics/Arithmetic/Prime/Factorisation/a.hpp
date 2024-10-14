// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Prime/Factorisation/a.hpp

#pragma once
#include "../Enumeration/SFINAE/a.hpp"

// 非負整数nの{素因数,素因数の指数}を返す。
// O(√n)
template <typename INT> pair<vector<INT>,vector<int>> PrimeFactorisation( INT n );
// O(π(√n))、特にO(√n/log n)
// PEはPrimeEnumerationなどで、sqrt( n )以下の最大の素数がpeで管理されている時のみサポート。
template <typename PE , typename INT> auto PrimeFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,pair<vector<INT>,vector<int>>>;
// O(nの素因数の指数の総和)、特にO(log n)
// LDはLeastDivisorなどで、n以下の整数の最小の素因数がldで管理されている時のみサポート。
template <typename LD> auto PrimeFactorisation( const LD& ld , int n ) -> enable_if_t<!IsPE<LD>,pair<vector<int>,vector<int>>>;

// 非負整数nの{素因数,素因数の指数,素因数の指数乗}返す。
// O(√n)
template <typename INT> tuple<vector<INT>,vector<int>,vector<INT>> PrimePowerFactorisation( INT n );
// O(π(√n))、特にO(√n/log n)
// PEはPrimeEnumerationなどで、sqrt( n )以下の最大の素数がpeで管理されている時のみサポート。
template <typename PE , typename INT> auto PrimePowerFactorisation( const PE& pe , INT n ) -> enable_if_t<IsPE<PE>,tuple<vector<INT>,vector<int>,vector<INT>>>;
// O(nの素因数の指数の総和)、特にO(log n)
// LDはLeastDivisorなどで、n以下の整数の最小の素因数がldで管理されている時のみサポート。
template <typename LD> auto PrimePowerFactorisation( const LD& ld , int n ) -> enable_if_t<!IsPE<LD>,tuple<vector<int>,vector<int>,vector<int>>>;
