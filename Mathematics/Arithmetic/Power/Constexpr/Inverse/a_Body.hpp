// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/Inverse/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , uint exponent_lim> inline constexpr Power_constexpr<T,exponent_lim>::Power_constexpr( const T& t , const T& init ) : m_val() { T power{ init }; for( uint exponent = 0 ; exponent < exponent_lim ; exponent++ ){ m_val[exponent] = power; power *= t; } }

template <int N> inline constexpr PowerInverse_constexpr<N>::PowerInverse_constexpr() : m_val( 1 ) { while( m_val < N ){ m_val <<= 1; } }