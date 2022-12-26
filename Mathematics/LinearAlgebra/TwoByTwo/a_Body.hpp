// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"

template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( const T& M00 , const T& M01 , const T& M10 , const T& M11 ) noexcept : m_M00( M00 ) , m_M01( M01 ) , m_M10( M10 ) , m_M11( M11 ) {}
template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( T&& M00 , T&& M01 , T&& M10 , T&& M11 ) noexcept : m_M00( move( M00 ) ) , m_M01( move( M01 ) ) , m_M10( move( M10 ) ) , m_M11( move( M11 ) ) {}
template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( const T& n ) noexcept : m_M00( n ) , m_M01() , m_M10() , m_M11( n ) {}
template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( const int& n ) noexcept : TwoByTwoMatrix( T( n ) ) {}
template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept : m_M00( mat.m_M00 ) , m_M01( mat.m_M01 ) , m_M10( mat.m_M10 ) , m_M11( mat.m_M11 ) {}
template <typename T> inline TwoByTwoMatrix<T>::TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept : m_M00( move( mat.m_M00 ) ) , m_M01( move( mat.m_M01 ) ) , m_M10( move( mat.m_M10 ) ) , m_M11( move( mat.m_M11 ) ) {}

template <typename T>
TwoByTwoMatrix<T>::TwoByTwoMatrix( const Matrix<2,2,T>& mat )
  : m_M00() , m_M01() , m_M10() , m_M11()
{

  const TableTypeForMatrix<T>& M = mat.GetTable();
  const LineTypeForMatrix<T>& M0 = M[0];
  const LineTypeForMatrix<T>& M1 = M[1];
  m_M00 = M0[0];
  m_M01 = M0[1];
  m_M10 = M1[0];
  m_M11 = M1[1];

}

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator=( const TwoByTwoMatrix<T>& mat ) noexcept { if( &mat != this ){ m_M00 = mat.m_M00; m_M01 = mat.m_M01; m_M10 = mat.m_M10; m_M11 = mat.m_M11; } return *this; }

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator=( TwoByTwoMatrix<T>&& mat ) noexcept { m_M00 = move( mat.m_M00 ); m_M01 = move( mat.m_M01 ); m_M10 = move( mat.m_M10 ); m_M11 = move( mat.m_M11 ); return *this; }

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const TwoByTwoMatrix<T>& mat ) noexcept { return operator=( Multiply( *this , mat ) ); }


template <typename T> inline Matrix<2,2,T> TwoByTwoMatrix<T>::GetMatrix22() const noexcept { return Matrix<2,2,T>( m_M00 , m_M01 , m_M10 , m_M11 ); }

template <typename T> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::Multiply( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) { return TwoByTwoMatrix<T>( mat1.m_M00 * mat2.m_M00 + mat1.m_M01 * mat2.m_M10 , mat1.m_M00 * mat2.m_M01 + mat1.m_M01 * mat2.m_M11 , mat1.m_M10 * mat2.m_M00 + mat1.m_M11 * mat2.m_M10 , mat1.m_M10 * mat2.m_M01 + mat1.m_M11 * mat2.m_M11 ); }

template <typename T> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::Square( const TwoByTwoMatrix<T>& mat ) { return TwoByTwoMatrix<T>( mat.m_M00 * mat.m_M00 + mat.m_M01 * mat.m_M10 , ( mat.m_M00 + mat.m_M11 ) * mat.m_M01 , mat.m_M10 * ( mat.m_M00 + mat.m_M11 ) , mat.m_M10 * mat.m_M01 + mat.m_M11 * mat.m_M11 ); }

template <typename T> inline TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) { return TwoByTwoMatrix<T>::Multiply( mat1 , mat2 ); }

template <typename T> inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat ) { return TwoByTwoMatrix<T>::Square( mat ); }
