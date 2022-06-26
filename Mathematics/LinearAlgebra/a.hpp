// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a.hpp

#pragma once
#include "../../Utility/VLArray/a.hpp"

#include "a_Alias.hpp"

template <typename T , typename U>
Matrix<T> Unit( const U& num ) noexcept;

template <typename T>
Matrix<T> operator*( const Matrix<T>& mat1 , const Matrix<T>& mat2 );

template <typename T>
Matrix<T> Transpose( const Matrix<T>& mat );
