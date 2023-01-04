// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../TwoByTwo/a_Body.hpp"

template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( const T& M0 , const T& M1 ) noexcept : m_M0( M0 ) , m_M1( M1 ) {}
template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( T&& M0 , T&& M1 ) noexcept : m_M0( move( M0 ) ) , m_M1( move( M1 ) ) {}
template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept : m_M0( mat.m_M0 ) , m_M1( mat.m_M1 ) {}
template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept : m_M0( move( mat.m_M0 ) ) , m_M1( move( mat.m_M1 ) ) {}

template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator=( const TwoByOneMatrix<T>& mat ) noexcept { if( &mat != this ){ m_M0 = mat.m_M0; m_M1 = mat.m_M1; } return *this; }

template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator=( TwoByOneMatrix<T>&& mat ) noexcept { m_M0 = move( mat.m_M0 ); m_M1 = move( mat.m_M1 ); return *this; }

template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator+=( const TwoByOneMatrix<T>& mat ) noexcept { m_M0 += mat.m_M0; m_M1 += mat.m_M1; return *this; }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator-=( const TwoByOneMatrix<T>& mat ) noexcept { m_M0 -= mat.m_M0; m_M1 -= mat.m_M1; return *this; }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator*=( const TwoByTwoMatrix<T>& mat ) noexcept { return operator=( mat * *this ); }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator*=( const T& scalar ) noexcept { m_M0 *= scalar; m_M1 *= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator*=( const Arg& scalar ) noexcept { return operator*=( T( scalar ) ); }
template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator/=( const T& scalar ) { m_M0 /= scalar; m_M1 /= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator/=( const Arg& scalar ) { return operator/=( T( scalar ) ); }
template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator%=( const T& scalar ) { m_M0 %= scalar; m_M1 %= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator%=( const Arg& scalar ) { return operator%=( T( scalar ) ); }

template <typename T> inline constexpr const T& TwoByOneMatrix<T>::GetEntry( const uint& y ) const noexcept { return y == 0 ? m_M0 : m_M1; }
template <typename T> inline constexpr T& TwoByOneMatrix<T>::RefEntry( const uint& y ) noexcept { return y == 0 ? m_M0 : m_M1; }
