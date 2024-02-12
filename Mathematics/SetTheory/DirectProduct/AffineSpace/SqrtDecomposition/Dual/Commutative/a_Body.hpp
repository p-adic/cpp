// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Dual/Commutative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename R , typename PT_COMM_MAGMA , typename U , typename R_MODULE> template <typename...Args> inline CommutativeDualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_MODULE>::CommutativeDualSqrtDecomposition( PT_COMM_MAGMA L , R_MODULE X , vector<U> a , Args&&... args ) : DualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_MODULE>( move( L ) , move( X ) , move( a ) , forward<Args>( args )... ) {}

template <typename R , typename PT_COMM_MAGMA , typename U , typename R_MODULE> inline void CommutativeDualSqrtDecomposition<R,PT_COMM_MAGMA,U,R_MODULE>::Act( const int& i , const R& r ) { this->Update( i / this->m_N_sqrt ); U& m_ai = this->m_a[i]; m_ai = this->m_X.Action( r , m_ai ); }
