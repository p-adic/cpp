// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once
#include "a_Alias.hpp"

template <uint Y , uint X , typename T>
class Matrix
{

private:
  TableTypeForMatrix<T>  m_M;

public:
  // argsの長さがXYでなくてもコンパイルエラーとならないがサポート外である。
  template <typename... Args> Matrix( const Args&... args ) noexcept;

  inline Matrix( const Matrix<Y,X,T>& mat ) noexcept;
  inline Matrix( Matrix<Y,X,T>&& mat ) noexcept;

  // ( X , Y )行列でないものも引数に取れるがサポート外である。
  template <typename... Args> inline Matrix( const TableTypeForMatrix<T>& M ) noexcept;
  template <typename... Args> inline Matrix( TableTypeForMatrix<T>&& M ) noexcept;

  inline Matrix<Y,X,T>& operator=( const Matrix<Y,X,T>& mat ) noexcept;
  Matrix<Y,X,T>& operator+=( const Matrix<Y,X,T>& mat );
  Matrix<Y,X,T>& operator-=( const Matrix<Y,X,T>& mat );
  Matrix<Y,X,T>& operator*=( const T& scalar ) noexcept;
  inline Matrix<Y,X,T>& operator*=( const Matrix<X,X,T>& mat ) noexcept;
  Matrix<Y,X,T>& operator%=( const T& scalar ) noexcept;

  // 行や列の長さを変更可能だがサポート外である。
  inline TableTypeForMatrix<T>& RefTable() noexcept;
  inline const TableTypeForMatrix<T>& GetTable() const noexcept;

  static inline const Matrix<Y,X,T>& Zero() noexcept;
  static inline const Matrix<Y,X,T>& Unit() noexcept;

private:
  static inline void ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec ) noexcept;
  template <typename Arg , typename... Args> static void ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec , const Arg& arg , const Args&... args ) noexcept;
  
  static Matrix<Y,X,T> Zero_Body() noexcept;
  static Matrix<Y,X,T> Unit_Body() noexcept;

};

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator==( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 );

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 );

template <uint Y , uint X , uint Z , typename T>
Matrix<Y,Z,T> operator*( const Matrix<Y,X,T>& mat1 , const Matrix<X,Z,T>& mat2 );

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const Matrix<Y,X,T>& mat , const T& scalar );
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat );

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator%( const Matrix<Y,X,T>& mat , const T& scalar );

template <uint Y , uint X , typename T>
Matrix<X,Y,T> Transpose( const Matrix<Y,X,T>& mat );

template <uint X , typename T>
T Trace( const Matrix<X,X,T>& mat );
