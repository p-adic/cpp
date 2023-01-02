// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline TwoByOneMatrix<T>::TwoByOneMatrix( const T& M0 , const T& M1 ) noexcept : m_M0( M0 ) , m_M1( M1 ) {}
template <typename T> inline TwoByOneMatrix<T>::TwoByOneMatrix( T&& M0 , T&& M1 ) noexcept : m_M0( move( M0 ) ) , m_M1( move( M1 ) ) {}
template <typename T> inline TwoByOneMatrix<T>::TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept : m_M0( mat.m_M0 ) , m_M1( mat.m_M1 ) {}
template <typename T> inline TwoByOneMatrix<T>::TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept : m_M0( move( mat.m_M0 ) ) , m_M1( move( mat.m_M1 ) ) {}

template <typename T> inline TwoByOneMatrix<T>::TwoByOneMatrix( const Matrix<2,1,T>& mat ) : m_M0() , m_M1() { const TableTypeForMatrix<T>& M = mat.GetTable(); m_M0 = M[0][0]; m_M1 = M[1][0]; }

template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator=( const TwoByOneMatrix<T>& mat ) noexcept { if( &mat != this ){ m_M0 = mat.m_M0; m_M1 = mat.m_M1; } return *this; }

template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator=( TwoByOneMatrix<T>&& mat ) noexcept { m_M0 = move( mat.m_M0 ); m_M1 = move( mat.m_M1 ); return *this; }

template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator*=( const TwoByTwoMatrix<T>& mat ) noexcept { return operator=( Multiply( mat , *this ) ); }


template <typename T> inline Matrix<2,1,T> TwoByOneMatrix<T>::GetMatrix21() const noexcept { return Matrix<2,1,T>( m_M0 , m_M1 ); }

template <typename T> inline TwoByOneMatrix<T> TwoByOneMatrix<T>::Multiply( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 ) { return TwoByOneMatrix<T>( mat1.m_M00 * mat2.m_M0 + mat1.m_M01 * mat2.m_M1 , mat1.m_M10 * mat2.m_M0 + mat1.m_M11 * mat2.m_M1 ); }

template <typename T> inline TwoByOneMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 ) { return TwoByOneMatrix<T>::Multiply( mat1 , mat2 ); }
