// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../TwoByOne/a_Body.hpp"

template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const T& M00 , const T& M01 , const T& M10 , const T& M11 ) noexcept : m_M00( M00 ) , m_M01( M01 ) , m_M10( M10 ) , m_M11( M11 ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( T&& M00 , T&& M01 , T&& M10 , T&& M11 ) noexcept : m_M00( move( M00 ) ) , m_M01( move( M01 ) ) , m_M10( move( M10 ) ) , m_M11( move( M11 ) ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const T& n ) noexcept : m_M00( n ) , m_M01() , m_M10() , m_M11( n ) {}
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const Arg& n ) noexcept : TwoByTwoMatrix( T( n ) ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept : m_M00( mat.m_M00 ) , m_M01( mat.m_M01 ) , m_M10( mat.m_M10 ) , m_M11( mat.m_M11 ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept : m_M00( move( mat.m_M00 ) ) , m_M01( move( mat.m_M01 ) ) , m_M10( move( mat.m_M10 ) ) , m_M11( move( mat.m_M11 ) ) {}

template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator=( const TwoByTwoMatrix<T>& mat ) noexcept { if( &mat != this ){ m_M00 = mat.m_M00; m_M01 = mat.m_M01; m_M10 = mat.m_M10; m_M11 = mat.m_M11; } return *this; }

template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator=( TwoByTwoMatrix<T>&& mat ) noexcept { m_M00 = move( mat.m_M00 ); m_M01 = move( mat.m_M01 ); m_M10 = move( mat.m_M10 ); m_M11 = move( mat.m_M11 ); return *this; }

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator+=( const TwoByTwoMatrix<T>& mat ) noexcept { m_M00 += mat.m_M00; m_M01 += mat.m_M01; m_M10 += mat.m_M10; m_M11 += mat.m_M11; return *this; }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator-=( const TwoByTwoMatrix<T>& mat ) noexcept { m_M00 -= mat.m_M00; m_M01 -= mat.m_M01; m_M10 -= mat.m_M10; m_M11 -= mat.m_M11; return *this; }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const TwoByTwoMatrix<T>& mat ) noexcept { return operator=( *this * mat ); }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const T& scalar ) noexcept { m_M00 *= scalar; m_M01 *= scalar; m_M10 *= scalar; m_M11 *= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const Arg& scalar ) noexcept { return operator*=( T( scalar ) ); }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const TwoByTwoMatrix<T>& mat ) { return operator=( *this / mat ); }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const T& scalar ) { return operator*=( T( 1 ) / scalar ); }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const Arg& scalar ) { return operator/=( T( scalar ) ); }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator%=( const T& scalar ) { m_M00 %= scalar; m_M01 %= scalar; m_M10 %= scalar; m_M11 %= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator%=( const Arg& scalar ) { return operator%=( T( scalar ) ); }

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::Invert() { const T det_inv{ T( 1 ) / ( m_M00 * m_M11 - m_M01 * m_M10 ) }; swap( m_M00 , m_M11 ); m_M01 = T() - m_M01; m_M11 = T() - m_M10; return operator*=( det_inv ); }

template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator*( const TwoByTwoMatrix<T>& mat ) const noexcept { return TwoByTwoMatrix<T>( m_M00 * mat.m_M00 + m_M01 * mat.m_M10 , m_M00 * mat.m_M01 + m_M01 * mat.m_M11 , m_M10 * mat.m_M00 + m_M11 * mat.m_M10 , m_M10 * mat.m_M01 + m_M11 * mat.m_M11 ); }

template <typename T> inline constexpr TwoByOneMatrix<T> TwoByTwoMatrix<T>::operator*( const TwoByOneMatrix<T>& mat ) const noexcept { return TwoByOneMatrix<T>( m_M00 * mat.m_M0 + m_M01 * mat.m_M1 , m_M10 * mat.m_M0 + m_M11 * mat.m_M1 ); }

template <typename T> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator/( const TwoByTwoMatrix<T>& mat ) const { const T det_inv{ T( 1 ) / ( mat.m_M00 * mat.m_M11 - mat.m_M01 * mat.m_M10 ) }; return TwoByTwoMatrix<T>( ( m_M00 * mat.m_M11 - m_M01 * mat.m_M10 ) * det_inv , ( m_M01 * mat.m_M00 - m_M00 * mat.m_M01 ) * det_inv , ( m_M10 * mat.m_M11 - m_M11 * mat.m_M10 ) * det_inv , ( m_M11 * mat.m_M00 - m_M10 * mat.m_M01 ) * det_inv ); }

template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::Square() const noexcept { return TwoByTwoMatrix<T>( m_M00 * m_M00 + m_M01 * m_M10 , ( m_M00 + m_M11 ) * m_M01 , m_M10 * ( m_M00 + m_M11 ) , m_M10 * m_M01 + m_M11 * m_M11 ); }

template <typename T> inline constexpr const T& TwoByTwoMatrix<T>::GetEntry( const uint& y , const uint& x ) const noexcept { return y == 0 ? x == 0 ? m_M00 : m_M01 : x == 0 ? m_M10 : m_M11; }
template <typename T> inline constexpr T& TwoByTwoMatrix<T>::RefEntry( const uint& y , const uint& x ) noexcept { return y == 0 ? x == 0 ? m_M00 : m_M01 : x == 0 ? m_M10 : m_M11; }

template <typename T> inline TwoByTwoMatrix<T> operator+( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept { return move( TwoByTwoMatrix<T>( mat1 ) += mat2 ); }
template <typename T> inline TwoByTwoMatrix<T> operator-( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept { return move( TwoByTwoMatrix<T>( mat1 ) -= mat2 ); }
template <typename T> inline constexpr TwoByTwoMatrix<T> operator*( const T& scalar , const TwoByTwoMatrix<T>& mat ) noexcept { return move( TwoByTwoMatrix<T>( mat ) *= scalar ); }
template <typename T , SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T> operator*( const Arg& scalar , const TwoByTwoMatrix<T>& mat ) noexcept { return T( scalar ) * mat; }
template <typename T> inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat , const T& scalar ) noexcept { return move( TwoByTwoMatrix<T>( mat ) *= scalar ); }
template <typename T , SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat , const Arg& scalar ) noexcept { return mat * T( scalar ); }
template <typename T> inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat , const T& scalar ) { return move( TwoByTwoMatrix<T>( mat ) /= scalar ); }
template <typename T , SFINAE_FOR_MATRIX()> inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat , const Arg& scalar ) { return mat / T( scalar ); }
template <typename T> inline TwoByTwoMatrix<T> operator%( const TwoByTwoMatrix<T>& mat , const T& scalar ) { return move( TwoByTwoMatrix<T>( mat ) %= scalar ); }
template <typename T , SFINAE_FOR_MATRIX()> inline TwoByTwoMatrix<T> operator%( const TwoByTwoMatrix<T>& mat , const Arg& scalar ) { return mat % T( scalar ); }

template <typename T> inline constexpr TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat ) noexcept { return mat.Square(); }
