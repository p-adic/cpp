// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once
#include "a_Macro.hpp"

// verify:
// https://yukicoder.me/submissions/964836（トロピカル半環上の4次正方行列）

template <uint Y , uint X , typename T>
class Matrix
{

private:
  T m_M[Y][X];

public:
  inline Matrix() noexcept;
  // スカラー行列
  inline Matrix( const T& t ) noexcept;
  inline Matrix( const int& t ) noexcept;
  template <typename Arg0 , typename Arg1 , typename... Args> inline Matrix( Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept;

  inline Matrix( const Matrix<Y,X,T>& mat ) noexcept;
  inline Matrix( Matrix<Y,X,T>&& mat ) noexcept;

  template <typename... Args> inline Matrix( const T ( &mat )[Y][X] ) noexcept;
  template <typename... Args> inline Matrix( T ( &&mat )[Y][X] ) noexcept;

  inline Matrix<Y,X,T>& operator=( const Matrix<Y,X,T>& mat ) noexcept;
  inline Matrix<Y,X,T>& operator=( Matrix<Y,X,T>&& mat ) noexcept;
  inline Matrix<Y,X,T>& operator=( const T ( &mat )[Y][X] ) noexcept;
  inline Matrix<Y,X,T>& operator=( T ( &&mat )[Y][X] ) noexcept;
  
  inline Matrix<Y,X,T>& operator+=( const Matrix<Y,X,T>& mat ) noexcept;
  inline Matrix<Y,X,T>& operator-=( const Matrix<Y,X,T>& mat ) noexcept;
  inline Matrix<Y,X,T>& operator*=( const T& scalar ) noexcept;
  inline Matrix<Y,X,T>& operator*=( const Matrix<X,X,T>& mat ) noexcept;
  inline Matrix<Y,X,T>& operator/=( const T& scalar );
  inline Matrix<Y,X,T>& operator%=( const T& scalar );

  inline bool operator==( const Matrix<Y,X,T>& mat ) const noexcept;
  template <uint Z> inline Matrix<Y,Z,T> operator*( const Matrix<X,Z,T>& mat ) const noexcept;
  inline Matrix<X,Y,T> Transpose() const noexcept;
  inline T Trace() const noexcept;
  
  inline const T ( &operator[]( const uint& y ) const )[X];
  inline T ( &operator[]( const uint& y ) )[X];

  static inline const Matrix<Y,X,T>& Zero() noexcept;
  static inline const Matrix<Y,X,T>& One() noexcept;

private:
  static inline void SetArray( T ( &M )[Y][X] , T ( &&array )[Y * X] ) noexcept;

};

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept;
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const Matrix<Y,X,T>& mat , const T& scalar ) noexcept;
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat ) noexcept;
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator/( const Matrix<Y,X,T>& mat , const T& scalar );
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator%( const Matrix<Y,X,T>& mat , const T& scalar );

