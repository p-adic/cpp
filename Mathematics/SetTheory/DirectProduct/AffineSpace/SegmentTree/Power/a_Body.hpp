// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SegmentTree/Power/a_Body.hpp

#pragma once
#include "a.hpp"

template <int N> inline constexpr PowerCalculation<N>::PwerCalculation() : m_val( 1 ) { while( m_val < N ){ m_val <<= 1; } }
