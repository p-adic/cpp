// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a.hpp

#pragma once
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
  TwoByTwoMatrix( const Matrix<2,2,T>& mat );
  TwoByTwoMatrix<T>& operator=( const TwoByTwoMatrix<T>& mat ) noexcept;

  inline Matrix<2,2,T> GetMatrix22() const noexcept;

  static inline TwoByTwoMatrix<T> Multiply( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 );
  static inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat );
  
};

template <typename T> inline TwoByTwoMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByTwoMatrix<T>& mat2 );

// ../../Arithmetic/Power/a_Body.hpp‚É‚Ä’è‹`
// template <typename T> inline T Square( const T& t );
template <typename T> inline TwoByTwoMatrix<T> Square( const TwoByTwoMatrix<T>& mat );
