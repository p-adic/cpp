// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Monoid/Commutative/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename U , typename COMM_MONOID> template <typename...Args> inline CommutativeMonoidSqrtDecomposition<U,COMM_MONOID>::CommutativeMonoidSqrtDecomposition( COMM_MONOID M , Args&&... args ) : MonoidSqrtDecomposition<U,COMM_MONOID>( move( M ) , forward<Args>( args )... ) {}

template <typename U , typename COMM_MONOID> inline void CommutativeMonoidSqrtDecomposition<U,COMM_MONOID>::Multiply( const int& i , const U& u ) { U& m_ai = this->m_a[i]; U& m_bd = this->m_b[i / this->m_N_sqrt]; m_bd = this->m_M.Product( move( m_bd ) , u ); m_ai = this->m_M.Product( move( m_ai ) , u ); }
