// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once
#include "../../Utility/VLArray/a.hpp"

#include "a_Alias.hpp"

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
class Matrix
{

private:
  TableTypeForMatrix<T>  m_M;

public:
  // argsの長さがXYでなくてもコンパイルエラーとならないがサポート外である。
  template <typename... Args> Matrix( const Args&... args ) noexcept;

  inline Matrix( const Matrix<Y,X,T>& mat ) noexcept;

  // ( X , Y )行列でないものも引数に取れるがサポート外である。
  template <typename... Args> inline Matrix( const TableTypeForMatrix<T>& M ) noexcept;

  Matrix<Y,X,T>& operator=( const Matrix<Y,X,T>& mat ) noexcept;
  Matrix<Y,X,T>& operator+=( const Matrix<Y,X,T>& mat );
  Matrix<Y,X,T>& operator-=( const Matrix<Y,X,T>& mat );
  Matrix<Y,X,T>& operator*=( const T& scalar ) noexcept;

  // 行や列の長さを変更可能だがサポート外である。
  inline TableTypeForMatrix<T>& RefTable() noexcept;
  inline const TableTypeForMatrix<T>& GetTable() const noexcept;

  static inline const Matrix<Y,X,T>& Unit() noexcept;

private:
  static inline void ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec ) noexcept;
  template <typename Arg , typename... Args> static void ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec , const Arg& arg , const Args&... args ) noexcept;
  
  static Matrix<Y,X,T> Unit_Body() noexcept;

};

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline Matrix<Y,X,T> operator==( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 );

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 );

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , SizeTypeForMatrix Z , typename T>
Matrix<Y,Z,T> operator*( const Matrix<Y,X,T>& mat1 , const Matrix<X,Z,T>& mat2 );

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat );

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<X,Y,T> Transpose( const Matrix<Y,X,T>& mat );

template <SizeTypeForMatrix X , typename T>
T Trace( const Matrix<X,X,T>& mat );


// ../Arithmetic/Power/a_Body.hppにて定義
// template <typename T , typename UINT>
// T PowerBinaryMethod( const T& t , const UINT& num , const T& init , const bool& for_right_multiplication );
template <typename T , typename UINT>
Matrix<2,2,T> PowerBinaryMethod( const Matrix<2,2,T>& mat , const UINT& num , const Matrix<2,2,T>& init_dummy , const bool& for_right_multiplication_dummy );
