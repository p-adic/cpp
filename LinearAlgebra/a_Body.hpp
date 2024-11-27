// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Body.hpp

#pragma once
#include "a.hpp"

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix() noexcept : m_M() {}
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const T& t ) noexcept : m_M() { constexpr const uint minXY = Y < X ? Y : X; for( uint y = 0 ; y < minXY ; y++ ){ m_M[y][y] = t; }; }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const int& t ) noexcept : Matrix( T( t ) ) {}

template <uint Y , uint X , typename T> template <typename Arg0 , typename Arg1 , typename... Args> inline Matrix<Y,X,T>::Matrix( Arg0&& t0 , Arg1&& t1 ,  Args&&... args ) noexcept : m_M() { T array[Y * X] = { T( forward<Arg0>( t0 ) ) , T( forward<Arg1>( t1 ) ) , T( forward<Args>( args ) )... }; SetArray( m_M , move( array ) ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const Matrix<Y,X,T>& mat ) noexcept : m_M() { operator=( mat.m_M ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( Matrix<Y,X,T>&& mat ) noexcept : m_M() { swap( m_M , mat.m_M ); }

template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( const T ( &mat )[Y][X] ) noexcept : m_M() { operator=( mat ); }
template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( T ( &&mat )[Y][X] ) noexcept : m_M() { swap( m_M , mat ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( const Matrix<Y,X,T>& mat ) noexcept { return operator=( mat.m_M ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( Matrix<Y,X,T>&& mat ) noexcept { return operator=( move( mat.m_M ) ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( const T ( &mat )[Y][X] ) noexcept { for( uint y = 0 ; y < Y ; y++ ){ T ( &m_M_y )[X] = m_M[y]; const T ( &mat_y )[X] = mat[y]; for( uint x = 0 ; x < X ; x++ ){ m_M_y[x] = mat_y[x]; } } return *this; }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( T ( &&mat )[Y][X] ) noexcept { swap( m_M , mat ); return *this; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator+=( const Matrix<Y,X,T>& mat ) noexcept { for( uint y = 0 ; y < Y ; y++ ){ T ( &m_M_y )[X] = m_M[y]; T ( &mat_y )[X] = mat.m_M[y]; for( uint x = 0 ; x < X ; x++ ){ m_M_y[x] += mat_y[x]; } } return *this; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator-=( const Matrix<Y,X,T>& mat ) noexcept { for( uint y = 0 ; y < Y ; y++ ){ T ( &m_M_y )[X] = m_M[y]; T ( &mat_y )[X] = mat.m_M[y]; for( uint x = 0 ; x < X ; x++ ){ m_M_y[x] -= mat_y[x]; } } return *this; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator*=( const T& scalar ) noexcept { for( uint y = 0 ; y < Y ; y++ ){ T ( &m_M_y )[X] = m_M[y]; for( uint x = 0 ; x < X ; x++ ){ m_M_y[x] *= scalar; } } return *this; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator*=( const Matrix<X,X,T>& mat ) noexcept { return operator=( move( *this * mat ) ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator/=( const T& scalar ) { return operator*=( T( 1 ) / scalar ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator%=( const T& scalar ) { for( uint y = 0 ; y < Y ; y++ ){ T ( &m_M_y )[X] = m_M[y]; for( uint x = 0 ; x < X ; x++ ){ m_M_y[x] %= scalar; } } return *this; }

template <uint Y , uint X , typename T> template <uint Z> inline Matrix<Y,Z,T> Matrix<Y,X,T>::operator*( const Matrix<X,Z,T>& mat ) const noexcept { Matrix<Y,Z,T> prod{}; for( uint y = 0 ; y < Y ; y++ ){ const T ( &m_M_y )[X] = m_M[y]; T ( &prod_y )[Z] = prod.m_M[y]; for( uint x = 0 ; x < X ; x++ ){ const T &m_M_yx = m_M_y[x]; const T ( &mat_x )[Z] = mat.m_M[x]; for( uint z = 0 ; z < Z ; z++ ){ prod_y[z] += m_M_yx * mat_x[z]; } } } return prod; }

template <uint Y , uint X , typename T> inline bool Matrix<Y,X,T>::operator==( const Matrix<Y,X,T>& mat ) const noexcept { for( uint y = 0 ; y < Y ; y++ ){ const T ( &m_M_y )[X] = m_M[y]; const T ( &mat_y )[X] = mat[y]; for( uint x = 0 ; x < X ; x++ ){ if( m_M_y[x] != mat_y[x] ){ return false; } } } return true; }

template <uint Y , uint X , typename T> inline Matrix<X,Y,T> Matrix<Y,X,T>::Transpose() const noexcept { Matrix<X,Y,T> M_t{}; for( uint x = 0 ; x < X ; x++ ){ const T ( &M_t_x )[Y] = M_t.m_M[x]; for( uint y = 0 ; y < Y ; y++ ){ M_t_x[y] = m_M[y][x]; } } return M_t; }

template <uint Y , uint X , typename T> inline T Matrix<Y,X,T>::Trace() const noexcept { constexpr const uint minXY = Y < X ? Y : X; T answer{}; for( uint y = 0 ; y < minXY ; y++ ){ answer += m_M[y][y]; } return answer; }

template <uint Y , uint X , typename T> inline const T ( &Matrix<Y,X,T>::operator[]( const uint& y ) )[X] const { assert( y < Y ); return m_M[y]; }
template <uint Y , uint X , typename T> inline T ( &Matrix<Y,X,T>::operator[]( const uint& y ) )[X]{ assert( y < Y ); return m_M[y]; }

template <uint Y , uint X , typename T> inline const Matrix<Y,X,T>& Matrix<Y,X,T>::Zero() noexcept { static const Matrix<Y,X,T> zero{}; return zero; }
template <uint Y , uint X , typename T> inline const Matrix<Y,X,T>& Matrix<Y,X,T>::One() noexcept { static const Matrix<Y,X,T> one{ 1 }; return one; }

template <uint Y , uint X , typename T> inline void Matrix<Y,X,T>::SetArray( T ( &M )[Y][X] , T ( &&array )[Y * X] ) noexcept { uint i = 0; for( uint y = 0 ; y < Y ; y++ ){ T ( &M_y )[X] = M[y]; for( uint x = 0 ; x < X ; x++ ){ M_y[x] = move( array[i + x] ); } i += X; } }


template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return !( mat1 == mat2 ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return move( Matrix<Y,X,T>( mat1 ) += mat2 ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return move( Matrix<Y,X,T>( mat1 ) -= mat2 ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const Matrix<Y,X,T>& mat , const T& scalar ) noexcept { return move( Matrix<Y,X,T>( mat ) *= scalar ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat ) noexcept { return move( Matrix<Y,X,T>( mat ) *= scalar ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator/( const Matrix<Y,X,T>& mat , const T& scalar ) { return move( Matrix<Y,X,T>( mat ) /= scalar ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator%( const Matrix<Y,X,T>& mat , const T& scalar ) { return move( Matrix<Y,X,T>( mat ) %= scalar ); }
