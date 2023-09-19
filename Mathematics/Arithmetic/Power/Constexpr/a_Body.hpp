// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , uint exponent_lim> inline constexpr Power_constexpr<T,exponent_lim>::Power_constexpr( const T& t , const T& init ) : m_val() { T power{ init }; for( uint exponent = 0 ; exponent < exponent_lim ; exponent++ ){ m_val[exponent] = power; power *= t; } }
