// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a_Body.hpp

#pragma once
#include "a.hpp"

template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( T M00 , T M01 , T M10 , T M11 ) noexcept : m_M00( move( M00 ) ) , m_M01( move( M01 ) ) , m_M10( move( M10 ) ) , m_M11( move( M11 ) ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const T& scalar ) noexcept : m_M00( scalar ) , m_M01() , m_M10() , m_M11( scalar ) {}
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const Arg& scalar ) noexcept : TwoByTwoMatrix( T( scalar ) ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept : m_M00( mat.m_M00 ) , m_M01( mat.m_M01 ) , m_M10( mat.m_M10 ) , m_M11( mat.m_M11 ) {}
template <typename T> inline constexpr TwoByTwoMatrix<T>::TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept : m_M00( move( mat.m_M00 ) ) , m_M01( move( mat.m_M01 ) ) , m_M10( move( mat.m_M10 ) ) , m_M11( move( mat.m_M11 ) ) {}

template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator=( TwoByTwoMatrix<T> mat ) noexcept { m_M00 = move( mat.m_M00 ); m_M01 = move( mat.m_M01 ); m_M10 = move( mat.m_M10 ); m_M11 = move( mat.m_M11 ); return *this; }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator+=( const TwoByTwoMatrix<T>& mat ) noexcept { m_M00 += mat.m_M00; m_M01 += mat.m_M01; m_M10 += mat.m_M10; m_M11 += mat.m_M11; return *this; }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator-=( const TwoByTwoMatrix<T>& mat ) noexcept { m_M00 -= mat.m_M00; m_M01 -= mat.m_M01; m_M10 -= mat.m_M10; m_M11 -= mat.m_M11; return *this; }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const TwoByTwoMatrix<T>& mat ) noexcept { return *this = *this * mat; }
template <typename T> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const T& scalar ) noexcept { m_M00 *= scalar; m_M01 *= scalar; m_M10 *= scalar; m_M11 *= scalar; return *this; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator*=( const Arg& scalar ) noexcept { return *this *= T( scalar ); }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const TwoByTwoMatrix<T>& mat ) { return *this = *this / mat; }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const T& scalar ) { return *this *= T( 1 ) / scalar; }
template <typename T> template <SFINAE_FOR_MATRIX()> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator/=( const Arg& scalar ) { return *this /= T( scalar ); }
template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::operator%=( const T& scalar ) { m_M00 %= scalar; m_M01 %= scalar; m_M10 %= scalar; m_M11 %= scalar; return *this; }

template <typename T> inline TwoByTwoMatrix<T>& TwoByTwoMatrix<T>::Invert() { ::swap( m_M00 , m_M11 ); m_M01 = -m_M01; m_M10 = -m_M10; return *this /= det(); }
template <typename T> TwoByTwoMatrix<T> TwoByTwoMatrix<T>::Inverse() const { return move( TwoByTwoMatrix<T>( *this ).invert() ); }

template <typename T> inline constexpr bool TwoByTwoMatrix<T>::operator==( const TwoByTwoMatrix<T>& mat ) const noexcept { return m_M00 == mat.m_M00 && m_M01 == mat.m_M01 && m_M10 == mat.m_M10 && m_M11 == mat.m_M11; }
template <typename T> inline constexpr bool TwoByTwoMatrix<T>::operator!=( const TwoByTwoMatrix<T>& mat ) const noexcept { return !( *this == mat ); }

template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator+( TwoByTwoMatrix<T> mat ) const noexcept { return move( mat += *this ); }
template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator-() const noexcept { return TwoByTwoMatrix<T>( -m_M00 , -m_M01 , -m_M10 , -m_M11 ); }
template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator-( const TwoByTwoMatrix<T>& mat ) const noexcept { return move( -mat += *this ); }

template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator*( const TwoByTwoMatrix<T>& mat ) const noexcept { return TwoByTwoMatrix<T>( m_M00 * mat.m_M00 + m_M01 * mat.m_M10 , m_M00 * mat.m_M01 + m_M01 * mat.m_M11 , m_M10 * mat.m_M00 + m_M11 * mat.m_M10 , m_M10 * mat.m_M01 + m_M11 * mat.m_M11 ); }
template <typename T> template <SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator*( const Arg& scalar ) const noexcept { return move( TwoByTwoMatrix<T>( *this ) *= scalar ); }

template <typename T> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator/( const TwoByTwoMatrix<T>& mat ) const { const T det_inv{ T( 1 ) / ( mat.m_M00 * mat.m_M11 - mat.m_M01 * mat.m_M10 ) }; return TwoByTwoMatrix<T>( ( m_M00 * mat.m_M11 - m_M01 * mat.m_M10 ) * det_inv , ( m_M01 * mat.m_M00 - m_M00 * mat.m_M01 ) * det_inv , ( m_M10 * mat.m_M11 - m_M11 * mat.m_M10 ) * det_inv , ( m_M11 * mat.m_M00 - m_M10 * mat.m_M01 ) * det_inv ); }
template <typename T> template <SFINAE_FOR_MATRIX()> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator/( const Arg& scalar ) const { return move( TwoByTwoMatrix<T>( *this ) /= scalar ); }
template <typename T> inline TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator%( const T& scalar ) const { return move( TwoByTwoMatrix<T>( *this ) %= scalar ); }

template <typename T> template <typename INT> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::operator^( INT exponent ) const { TwoByTwoMatrix<T> answer{ 1 } , power{ *this }; exponent < 0 ? ( exponent *= -1 , power.Invert() ) : power; while( exponent > 0 ){ ( exponent & 1 ) == 1 ? answer *= power : answer; power = power.Square(); exponent >>= 1; } return answer; }
template <typename T> inline constexpr TwoByTwoMatrix<T> TwoByTwoMatrix<T>::Square() const noexcept { return TwoByTwoMatrix<T>( m_M00 * m_M00 + m_M01 * m_M10 , ( m_M00 + m_M11 ) * m_M01 , m_M10 * ( m_M00 + m_M11 ) , m_M10 * m_M01 + m_M11 * m_M11 ); }

template <typename T> inline constexpr T TwoByTwoMatrix<T>::tr() const noexcept { return m_M00 + m_M11; }
template <typename T> inline constexpr T TwoByTwoMatrix<T>::det() const noexcept { return m_M00 * m_M11 - m_M01 * m_M10; }

template <typename T> inline constexpr void TwoByTwoMatrix<T>::swap( TwoByTwoMatrix<T>& mat ) noexcept { std::swap( m_M00 , mat.m_M00 ); std::swap( m_M01 , mat.m_M01 ); std::swap( m_M10 , mat.m_M10 ); std::swap( m_M11 , mat.m_M11 ); }

template <typename T> inline constexpr const T& TwoByTwoMatrix<T>::Get( const uint& y , const uint& x ) const noexcept { return y == 0 ? x == 0 ? m_M00 : m_M01 : x == 0 ? m_M10 : m_M11; }
template <typename T> inline constexpr T& TwoByTwoMatrix<T>::Ref( const uint& y , const uint& x ) noexcept { return y == 0 ? x == 0 ? m_M00 : m_M01 : x == 0 ? m_M10 : m_M11; }

template <typename T , SFINAE_FOR_MATRIX()> inline constexpr TwoByTwoMatrix<T> operator*( const Arg& scalar , const TwoByTwoMatrix<T>& mat ) noexcept { return move( TwoByTwoMatrix<T>( mat ) *= scalar ); }

template <typename T , typename INT> inline constexpr TwoByTwoMatrix<T> Power( const TwoByTwoMatrix<T>& mat , INT exponent ) noexcept { return mat ^ move( exponent ); }

template <typename T> inline constexpr void swap( TwoByTwoMatrix<T>& mat1 , TwoByTwoMatrix<T>& mat2 ) noexcept { mat1.swap( mat2 ); }
