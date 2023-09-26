// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/PowerPower/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int exponent_lim> inline constexpr PowerPower_constexpr<T,exponent_lim>::PowerPower_constexpr( const T& t ) : m_val{ t } { for( int exponent = 1 ; exponent < exponent_lim ; exponent++ ){ ( m_val[exponent] = m_val[exponent-1] ) *= m_val[exponent]; } }

template <typename T , int exponent_lim> inline constexpr const T& PowerPower_constexpr<T,exponent_lim>::operator[]( const int& i ) const { assert( i < exponent_lim ); return m_val[i]; }

template <typename T , int exponent_lim> inline constexpr const T ( &PowerPower_constexpr<T,exponent_lim>::Get() const )[exponent_lim] { return m_val; }
