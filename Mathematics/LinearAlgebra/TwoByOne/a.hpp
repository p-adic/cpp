// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a.hpp

#pragma once
#include "../TwoByTwo/a.hpp"

// verify:
// https://yukicoder.me/submissions/959497（+=,-=,*=,Act）

template <typename T>
class TwoByOneMatrix
{

private:
  T m_M0;
  T m_M1;

public:
  inline constexpr TwoByOneMatrix( T M0 = T() , T M1 = T() ) noexcept;
  inline constexpr TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept;
  
  inline constexpr TwoByOneMatrix<T>& operator=( TwoByOneMatrix<T> mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator+=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator-=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator*=( const T& scalar ) noexcept;
  inline TwoByOneMatrix<T>& operator/=( const T& scalar );
  inline TwoByOneMatrix<T>& operator%=( const T& scalar );

  // 左からの積
  template <typename INT> inline constexpr TwoByOneMatrix<T>& Act( TwoByTwoMatrix<T> mat , INT exponent = 1 );
  template <typename INT> inline constexpr TwoByOneMatrix<T> Action( TwoByTwoMatrix<T> mat , INT exponent = 1 ) const;

  inline constexpr TwoByOneMatrix<T> operator+( TwoByOneMatrix<T> mat ) const noexcept;
  inline constexpr TwoByOneMatrix<T> operator-( TwoByOneMatrix<T> mat ) const noexcept;
  inline constexpr TwoByOneMatrix<T> operator*( const T& scalar ) const noexcept;
  inline TwoByOneMatrix<T> operator/( const T& scalar ) const;
  inline TwoByOneMatrix<T> operator%( const T& scalar ) const;

  // TwoByTwoがoperator[]を持たないので構文を合わせる。
  inline constexpr const T& Get( const uint& y ) const noexcept;
  inline constexpr T& Ref( const uint& y ) noexcept;

};

template <typename T> inline constexpr TwoByOneMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 ) noexcept;

