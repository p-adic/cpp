// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../TwoByOne/a.hpp"

template <typename T>
class TwoByTwoMatrix
{
  
private:
  T m_M00;
  T m_M01;
  T m_M10;
  T m_M11;

public:
  inline constexpr TwoByTwoMatrix( const T& M00 , const T& M01 , const T& M10 , const T& M11 ) noexcept;
  inline constexpr TwoByTwoMatrix( T&& M00 , T&& M01 , T&& M10 , T&& M11 ) noexcept;
  inline constexpr TwoByTwoMatrix( const T& n = T() ) noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix( const Arg& n ) noexcept;
  inline constexpr TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept;
  
  inline constexpr TwoByTwoMatrix<T>& operator=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator=( TwoByTwoMatrix<T>&& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator+=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator-=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator*=( const T& scalar ) noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T>& operator*=( const Arg& scalar ) noexcept;
  inline TwoByTwoMatrix<T>& operator/=( const TwoByTwoMatrix<T>& mat );
  inline TwoByTwoMatrix<T>& operator/=( const T& scalar );
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T>& operator/=( const Arg& scalar );
  inline TwoByTwoMatrix<T>& operator%=( const T& scalar );
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T>& operator%=( const Arg& scalar );

  inline TwoByTwoMatrix<T>& Invert();

  inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat ) const noexcept;
  inline constexpr TwoByOneMatrix<T> operator*( const TwoByOneMatrix<T>& mat ) const noexcept;
  inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat ) const;
  inline constexpr TwoByTwoMatrix<T> Square() const noexcept;


  inline constexpr const T& GetEntry( const uint& y , const uint& x ) const noexcept;
  inline constexpr T& RefEntry( const uint& y , const uint& x ) noexcept;
  
};

template <typename T> inline TwoByTwoMatrix<T> operator+( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept;
template <typename T> inline constexpr TwoByTwoMatrix<T> operator-( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept;
template <typename T> inline constexpr TwoByTwoMatrix<T> operator*( const T& scalar , const TwoByTwoMatrix<T>& mat ) noexcept;
template <typename T , SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T> operator*( const Arg& scalar , const TwoByTwoMatrix<T>& mat ) noexcept;
template <typename T> inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat , const T& scalar ) noexcept;
template <typename T , SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat , const T& scalar ) noexcept;
template <typename T> inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat , const T& scalar );
template <typename T , SFINAE_FOR_MATRIX( = nullptr )> inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat , const Arg& scalar );
template <typename T> inline TwoByTwoMatrix<T> operator%( const TwoByTwoMatrix<T>& mat , const T& scalar );
template <typename T , SFINAE_FOR_MATRIX( = nullptr )> inline TwoByTwoMatrix<T> operator%( const TwoByTwoMatrix<T>& mat , const Arg& scalar );

// ../../Arithmetic/Power/a_Body.hpp‚É‚Ä’è‹`
// template <typename T> inline T Square( const T& t );
template <typename T> inline constexpr TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat ) noexcept;
