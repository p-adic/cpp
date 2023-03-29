// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Sqrt/a_Body.hpp

#pragma once
#include "a.hpp"

template <int N> inline constexpr SqrtCalculation<N>::SqrtCalculation() : m_val( 1 ) { int m_val2 = 1; while( ( m_val2 << 2 ) <= N ){ m_val <<= 1; m_val2 <<= 2; } while( m_val2 < N ){ m_val++; m_val2 = m_val * m_val; } }
