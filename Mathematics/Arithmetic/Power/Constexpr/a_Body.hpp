// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int exponent_lim> inline constexpr Power_constexpr<T,exponent_lim>::Power_constexpr( const T& t , const T& init ) : m_val{ init } { for( int exponent = 1 ; exponent < exponent_lim ; exponent++ ){ ( m_val[exponent] = m_val[exponent-1] ) *= t; } }

template <typename T , int exponent_lim> inline constexpr const T& Power_constexpr<T,exponent_lim>::operator[]( const int& i ) const { assert( i < exponent_lim ); return m_val[i]; }

template <typename T , int exponent_lim> inline constexpr const T ( &Power_constexpr<T,exponent_lim>::Get() const )[exponent_lim] { return m_val; }
