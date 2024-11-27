// c:/Users/user/Documents/Programming/Mathematics/Analysis/FFT/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T , int exponent_lim> inline constexpr Power3Power_constexpr<T,exponent_lim>::Power3Power_constexpr( const T& t ) : m_val() { T power{ t }; for( uint exponent = exponent_lim - 1 ; exponent + 1 > 0 ; exponent-- ) { m_val[exponent] = -power; m_val[exponent] *= power *= power; } }

template <typename T , int exponent_lim> inline constexpr const T& Power3Power_constexpr<T,exponent_lim>::operator[]( const int& i ) const { assert( i < exponent_lim ); return m_val[i]; }

template <typename T , int exponent_lim> inline constexpr const T ( &Power3Power_constexpr<T,exponent_lim>::Get() const )[exponent_lim] { return m_val; }


