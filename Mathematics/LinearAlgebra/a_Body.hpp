// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Utility/VLrray/a_Body.hpp"

template <typename T , typename U>
Matrix<T> Unit( const U& num ) noexcept
{

  Matrix<T> mat{};
  
  for( U y = 0 ; y < num ; y++ ){

    VLArray<T> vec{};

    for( U x = 0 ; x < num ; x++ ){

      vec.push_back( x == y ? 1 : 0 );

    }

    mat.push_back( vec );

  }

  return mat;

}

template <typename T>
Matrix<T> operator*( const Matrix<T>& mat1 , const Matrix<T>& mat2 )
{

  Matrix<T> mat2_t = Transpose( mat2 );

  Matrix<T> mat{};

  for( auto itr1y = mat1.begin() , end1y = mat1.end() , end2y = mat2.end() ; itr1y != end1y ; itr1y++ ){

    VLArray<T> vec{};
    
    for( auto itr2y = mat2.begin() ; itr2y != end2y ; itr2y++ ){

      auto itr1yx = itr1y->begin() , end1yx = itr1y->end() , itr2yx = itr2y->begin();
      T inner_product{};
      
      while( itr1yx != end1yx ){

	inner_product += ( *itr1yx ) * ( *itr2yx );

      }

      vec.push_back( inner_product );

    }

    mat.push_back( vec );

  }

  return mat;

}

template <typename T>
Matrix<T> Transpose( const Matrix<T>& mat )
{

  Matrix<T> mat_t{};

  for( auto beginy = mat.begin() , itry = beginy , endy = mat.end() ; itry != endy ; itry++ ){

    if( itry == beginy ){

      mat_t.push_back( VLArray<T>() );

    }

    auto itryx = itry->begin() , endyx = itry->end() , itr_ty = mat_t.begin();

    while( itryx != endyx ){

      itr_ty->push_back( *itryx );

    }

    itryx++;
    itr_ty++;

  }

  return mat_t;

}
