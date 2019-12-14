// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Dimension/a_Body.hpp"
#include "../../../Utility/List/a_Body.hpp"

inline uint BijSum21( const uint& n_1 , const uint& n_2 ) { return BijSum21( *infty() , *infty() , n_1 , n_2 ); }
inline void BijSum12( const uint& m , uint& n_1 , uint& n_2 ) { BijSum12( *infty() , *infty() , m , n_1 , n_2 ); }
inline uint BijSumN1( const uint& N , const uint& n_1 , const uint& n_2 ) { return BijSumN1( copy( N , *infty() ) , n_1 , n_2 ); }
inline void BijSum1N( const uint& N , const uint& m , uint& n_1 , uint& n_2 ) { return BijSum1N( copy( N , *infty() ) , m , n_1 , n_2 ); }

inline uint BijProd21( const uint& n_1 , const uint& n_2 ) { return BijProd21( *infty() , *infty() , n_1 , n_2 ); }
inline void BijProd12( const uint& m , uint& n_1 , uint& n_2 ) { BijProd12( *infty() , *infty() , m , n_1 , n_2 ); }
inline uint BijProdN1( const list<uint>& a_n ) { return BijProdN1( copy( Length( a_n ) , *infty() ) , a_n ); }
inline list<uint> BijProd1N( const uint& N , const uint& m ) { return BijProd1N( copy( N , *infty() ) , m ); }
inline void BijProd1N( const uint& N , const uint& m , list<uint>& a_n ) { BijProd1N( copy( N , *infty() ) , m , a_n ); }
