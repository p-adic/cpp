// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a.hpp

#pragma once
#include "../a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/959497（^）

template <typename T> class TwoByOneMatrix;

template <typename T>
class TwoByTwoMatrix
{

  friend class TwoByOneMatrix<T>;
  
private:
  T m_M00;
  T m_M01;
  T m_M10;
  T m_M11;

public:
  inline constexpr TwoByTwoMatrix( T M00 , T M01 , T M10 , T M11 ) noexcept;
  inline constexpr TwoByTwoMatrix( const T& scalar = T() ) noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix( const Arg& scalar ) noexcept;
  inline constexpr TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept;
  
  inline constexpr TwoByTwoMatrix<T>& operator=( TwoByTwoMatrix<T> mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator+=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator-=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByTwoMatrix<T>& operator*=( const T& scalar ) noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T>& operator*=( const Arg& scalar ) noexcept;
  inline TwoByTwoMatrix<T>& operator/=( const TwoByTwoMatrix<T>& mat );
  inline TwoByTwoMatrix<T>& operator/=( const T& scalar );
  template <SFINAE_FOR_MATRIX( = nullptr )> inline TwoByTwoMatrix<T>& operator/=( const Arg& scalar );
  inline TwoByTwoMatrix<T>& operator%=( const T& scalar );

  inline TwoByTwoMatrix<T>& Invert();
  inline TwoByTwoMatrix<T> Inverse() const;

  inline constexpr bool operator==( const TwoByTwoMatrix<T>& mat ) const noexcept;
  inline constexpr bool operator!=( const TwoByTwoMatrix<T>& mat ) const noexcept;

  inline constexpr TwoByTwoMatrix<T> operator+( TwoByTwoMatrix<T> mat ) const noexcept;
  inline constexpr TwoByTwoMatrix<T> operator-() const noexcept;
  inline constexpr TwoByTwoMatrix<T> operator-( const TwoByTwoMatrix<T>& mat ) const noexcept;
  inline constexpr TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat ) const noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T> operator*( const Arg& scalar ) const noexcept;
  inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat ) const;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline TwoByTwoMatrix<T> operator/( const Arg& scalar ) const;
  inline TwoByTwoMatrix<T> operator%( const T& scalar ) const;
  template <typename INT> inline constexpr TwoByTwoMatrix<T> operator^( INT exponent ) const;

  inline constexpr T tr() const noexcept;
  inline constexpr T det() const noexcept;

  // グローバルスコープでswapを定義するためのもの。
  inline constexpr void swap( TwoByTwoMatrix<T>& mat ) noexcept;

  // メンバ変数の持ち方からoperator[]にできない。
  inline constexpr const T& Get( const uint& y , const uint& x ) const noexcept;
  inline constexpr T& Ref( const uint& y , const uint& x ) noexcept;

private:
  inline constexpr TwoByTwoMatrix<T> Square() const noexcept;

};

template <typename T , SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByTwoMatrix<T> operator*( const Arg& scalar , const TwoByTwoMatrix<T>& mat ) noexcept;
template <typename T , typename INT> inline constexpr TwoByTwoMatrix<T> Power( const TwoByTwoMatrix<T>& mat , INT exponent ) noexcept;
template <typename T> inline constexpr void swap( TwoByTwoMatrix<T>& mat1 , TwoByTwoMatrix<T>& mat2 ) noexcept;
