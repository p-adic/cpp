// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a.hpp

#pragma once
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
  inline TwoByTwoMatrix( const T& M00 , const T& M01 , const T& M10 , const T& M11 ) noexcept;
  inline TwoByTwoMatrix( T&& M00 , T&& M01 , T&& M10 , T&& M11 ) noexcept;
  inline TwoByTwoMatrix( const T& n = T() ) noexcept;
  inline TwoByTwoMatrix( const int& n ) noexcept;
  inline TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept;
  
  inline TwoByTwoMatrix<T>& operator=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator=( TwoByTwoMatrix<T>&& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator+=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator-=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator*=( const T& scalar ) noexcept;
  inline TwoByTwoMatrix<T>& operator/=( const TwoByTwoMatrix<T>& mat );
  inline TwoByTwoMatrix<T>& operator/=( const T& scalar );
  inline TwoByTwoMatrix<T>& operator%=( const T& scalar );

  inline TwoByTwoMatrix<T>& Invert();

  inline TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat ) const noexcept;
  inline TwoByOneMatrix<T> operator*( const TwoByOneMatrix<T>& mat ) const noexcept;
  inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat ) const;
  inline TwoByTwoMatrix<T> Square() const noexcept;


  inline const T& GetEntry( const uint& y , const uint& x ) const noexcept;
  inline T& RefEntry( const uint& y , const uint& x ) const noexcept;
  
};

template <typename T> inline TwoByTwoMatrix<T> operator+( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept;
template <typename T> inline TwoByTwoMatrix<T> operator-( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 ) noexcept;
template <typename T> inline TwoByTwoMatrix<T> operator*( const T& scalar , const TwoByTwoMatrix<T>& mat ) noexcept;
template <typename T> inline TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat , const T& scalar ) noexcept;
template <typename T> inline TwoByTwoMatrix<T> operator/( const TwoByTwoMatrix<T>& mat , const T& scalar );
template <typename T> inline TwoByTwoMatrix<T> operator%( const TwoByTwoMatrix<T>& mat , const T& scalar );

// ../../Arithmetic/Power/a_Body.hpp‚É‚Ä’è‹`
// template <typename T> inline T Square( const T& t );
template <typename T> inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat ) noexcept;
