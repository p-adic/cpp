// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Power/Constexpr/Inverse/a_Body.hpp

#pragma once
#include "a.hpp"

template <int N> inline constexpr PowerInverse_constexpr<N>::PowerInverse_constexpr() : m_val( 1 ) { while( m_val < N ){ m_val <<= 1; } }
