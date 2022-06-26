// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Enumeration/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Dimension/a_Body.hpp"
#include "../../../Utility/List/a_Body.hpp"

inline void BijSum12( const uint& n , uint& n_1 , uint& n_2 ) { BijSum12( infty() , infty() , n , n_1 , n_2 ); }

inline uint BijSum21( const uint& n_1 , const uint& n_2 ) { return BijSum21( infty() , infty() , n_1 , n_2 ); }

inline void BijProd12( const uint& n , uint& n_1 , uint& n_2 ) { BijProd12( infty() , infty() , n , n_1 , n_2 ); }

inline uint BijProd21( const uint& n_1 , const uint& n_2 ) { return BijProd21( infty() , infty() , n_1 , n_2 ); }
