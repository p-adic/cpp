// c:/Users/user/Documents/Programming/Mathematics/Combinatorial/ZetaTransform/Divisor/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "../../../Arithmetic/Prime/Constexpr/a.hpp"

// 古典的な１変数メビウス関数（../../Arithmetic/Prime/Divisor/a_Body.hpp）の２変数化。
// 最初のみO(val_lim log val_lim)で後はO(1)。
// これを用いてmu(const int&,const int&)を
// - t0 <= t1がt1 % t0 == 0で与えられる場合はこのままprimeを渡す。
// - t0 <= t1がt0 % t1 == 0で与えられる場合は変数を反対にしてprimeを渡す。
// と定義してZetaTansformBodyのGet<mu>に渡す。
template <typename INT , INT val_limit , int length_max> int TwoAryMoeviusFunction( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t0 , const int& t1 );

template <typename INT , INT val_limit , int length_max> inline list<int> DivisorEdgeForZetaTransform( const PrimeEnumeration<INT,val_limit,length_max>& prime , const int& t_max , const int& t );
inline list<int> MultipleEdgeForZetaTransform( const int& t_max , const int& t );
