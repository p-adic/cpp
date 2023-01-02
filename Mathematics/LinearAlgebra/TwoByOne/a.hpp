// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a.hpp

#pragma once
// TwoByOneMatrix( const Matrix<2,1,T>& mat ) Ç∆ inline Matrix<2,1,T> GetMatrix21() const noexcept Ç…égóp
#include "../a.hpp"

template <typename T>
class TwoByOneMatrix
{

private:
  T m_M0;
  T m_M1;

public:
  inline TwoByOneMatrix( const T& M0 = T() , const T& M1 = T() ) noexcept;
  inline TwoByOneMatrix( T&& M0 , T&& M1 ) noexcept;
  inline TwoByOneMatrix( const Matrix<2,1,T>& mat );
  inline TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept;
  
  inline TwoByOneMatrix<T>& operator=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix<T>& operator=( TwoByOneMatrix<T>&& mat ) noexcept;
  // ç∂Ç©ÇÁÇÃêœ
  inline TwoByOneMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;

  inline Matrix<2,1,T> GetMatrix21() const noexcept;

  static inline TwoByOneMatrix<T> Multiply( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 );
  
};

template <typename T> inline TwoByOneMatrix<T> operator*( const TwoByTwoMatrix<T>& mat1 , const TwoByOneMatrix<T>& mat2 );
