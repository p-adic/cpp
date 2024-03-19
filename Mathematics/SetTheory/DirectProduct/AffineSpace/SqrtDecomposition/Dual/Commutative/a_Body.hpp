// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename R , typename PT_COMM_MAGMA , typename U , typename R_SET> template <typename...Args> inline CommutativeDualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_SET>::CommutativeDualSqrtDecomposition( PT_COMM_MAGMA L , R_SET X , Args&&... args ) : DualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_SET>( move( L ) , move( X ) , forward<decay_t<Args>>( args )... ) {}

template <typename R , typename PT_COMM_MAGMA , typename U , typename R_SET> inline void CommutativeDualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_SET>::Act( const int& i , const R& r ) { this->Update( i / this->m_N_sqrt ); U& m_ai = this->m_a[i]; m_ai = this->m_X.Action( r , move( m_ai ) ); }
