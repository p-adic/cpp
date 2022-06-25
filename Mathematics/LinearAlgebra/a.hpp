// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once
#include "../../Utility/VLArray/a.hpp"

#include "a_Alias.hpp"

template <typename T , typename U>
Matrix<T> Unit( const U& num ) noexcept;

template <typename T>
Matrix<T> operator*( const Matrix<T>& mat1 , const Matrix<T>& mat2 );

template <typename T , typename U>
Matrix<T> Power( const Matrix<T>& mat , const U& num );

// Power‚Ì2ã°‚Ö‚Ì•”•ª“ÁŽê‰»
template <typename T , typename U>
Matrix<T> Power2( const Matrix<T>& mat , const U& d );

template <typename T>
Matrix<T> Transpose( const Matrix<T>& mat );
