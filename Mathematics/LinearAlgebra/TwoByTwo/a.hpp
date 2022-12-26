// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a.hpp

#pragma once
// TwoByTwoMatrix( const Matrix<2,2,T>& mat ) ‚Æ inline Matrix<2,2,T> GetMatrix22() const noexcept ‚ÉŽg—p
#include "../a.hpp"

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
  inline TwoByTwoMatrix( const Matrix<2,2,T>& mat );
  inline TwoByTwoMatrix( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix( TwoByTwoMatrix<T>&& mat ) noexcept;
  
  inline TwoByTwoMatrix<T>& operator=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator=( TwoByTwoMatrix<T>&& mat ) noexcept;
  inline TwoByTwoMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;

  inline Matrix<2,2,T> GetMatrix22() const noexcept;

  static inline TwoByTwoMatrix<T> Multiply( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 );
  static inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat );
  
};

template <typename T> inline TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 );

// ../../Arithmetic/Power/a_Body.hpp‚É‚Ä’è‹`
// template <typename T> inline T Square( const T& t );
template <typename T> inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat );
