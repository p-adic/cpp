// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../TwoByTwo/a_Body.hpp"

template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( T M0 , T M1 ) noexcept : m_M0( move( M0 ) ) , m_M1( move( M1 ) ) {}
template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept : m_M0( mat.m_M0 ) , m_M1( mat.m_M1 ) {}
template <typename T> inline constexpr TwoByOneMatrix<T>::TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept : m_M0( move( mat.m_M0 ) ) , m_M1( move( mat.m_M1 ) ) {}

template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator=( TwoByOneMatrix<T> mat ) noexcept { m_M0 = move( mat.m_M0 ); m_M1 = move( mat.m_M1 ); return *this; }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator+=( const TwoByOneMatrix<T>& mat ) noexcept { m_M0 += mat.m_M0; m_M1 += mat.m_M1; return *this; }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator-=( const TwoByOneMatrix<T>& mat ) noexcept { m_M0 -= mat.m_M0; m_M1 -= mat.m_M1; return *this; }
template <typename T> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator*=( const T& scalar ) noexcept { m_M0 *= scalar; m_M1 *= scalar; return *this; }
template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator/=( const T& scalar ) { m_M0 /= scalar; m_M1 /= scalar; return *this; }
template <typename T> inline TwoByOneMatrix<T>& TwoByOneMatrix<T>::operator%=( const T& scalar ) { m_M0 %= scalar; m_M1 %= scalar; return *this; }

template <typename T> template <typename INT> inline constexpr TwoByOneMatrix<T>& TwoByOneMatrix<T>::Act( TwoByTwoMatrix<T> mat , INT exponent )
{

  exponent < 0 ? ( exponent = -exponent , mat.Invert() ) : mat;

  while( exponent > 0 ){

    if( ( exponent & 1 ) == 1 ){

      T M0 = mat.m_M00 * m_M0 + mat.m_M01 * m_M1;
      m_M1 = mat.m_M10 * m_M0 + mat.m_M11 * m_M1;
      m_M0 = move( M0 );

    }

    mat = mat.Square();
    exponent >>= 1;

  }
  
  return *this;

}

template <typename T> template <typename INT> inline constexpr TwoByOneMatrix<T> TwoByOneMatrix<T>::Action( TwoByTwoMatrix<T> mat , INT exponent ) const { return TwoByOneMatrix<T>( *this ).Act( move( mat ) , move( exponent ) ); }

template <typename T> inline constexpr TwoByOneMatrix<T> TwoByOneMatrix<T>::operator+( TwoByOneMatrix<T> mat ) const noexcept { return move( mat += *this ); }
template <typename T> inline constexpr TwoByOneMatrix<T> TwoByOneMatrix<T>::operator-( TwoByOneMatrix<T> mat ) const noexcept { return move( mat -= *this ); }
template <typename T> inline constexpr TwoByOneMatrix<T> TwoByOneMatrix<T>::operator*( const T& scalar ) const noexcept { return move( TwoByOneMatrix<T>( *this ) *= scalar ); }
template <typename T> inline TwoByOneMatrix<T> TwoByOneMatrix<T>::operator/( const T& scalar ) const { return move( TwoByOneMatrix<T>( *this ) / scalar ); }
template <typename T> inline TwoByOneMatrix<T> TwoByOneMatrix<T>::operator%( const T& scalar ) const { return move( TwoByOneMatrix<T>( *this ) % scalar ); }

template <typename T> inline constexpr const T& TwoByOneMatrix<T>::Get( const uint& y ) const noexcept { return y == 0 ? m_M0 : m_M1; }
template <typename T> inline constexpr T& TwoByOneMatrix<T>::Ref( const uint& y ) noexcept { return y == 0 ? m_M0 : m_M1; }

template <typename T> inline constexpr TwoByOneMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 ) noexcept { return mat2.Action( mat1 ); }
