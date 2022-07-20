// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "2by2/a_Body.hpp"
#include "../../Utility/VLrray/a_Body.hpp"


template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> template <typename... Args>
Matrix<Y,X,T>::Matrix( const Args&... args ) noexcept
  : m_M()
{

  TableTypeForMatrix<T> M{};
  LineTypeForMatrix<T> vec{};
  ConstructTable( M , vec , args... );
  m_M = M;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline Matrix<Y,X,T>::Matrix( const Matrix<Y,X,T>& mat ) noexcept : m_M( mat.m_M ) {}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( const TableTypeForMatrix<T>& M ) noexcept : m_M( M ) {}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( const Matrix<Y,X,T>& mat ) noexcept
{

  m_M = mat.m_M;
  return *this;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T>& Matrix<Y,X,T>::operator+=( const Matrix<Y,X,T>& mat )
{

  auto itr1y = m_M.begin() , end1y = m_M.end();
  auto itr2y = mat.m_M.begin();  

  while( itr1y != end1y ){

    auto itr1xy = itr1y->begin() , end1xy = itr1y->end();
    auto itr2xy = itr2y->begin();  

    while( itr1xy != end1xy ){

      *itr1xy += *itr2xy;
      itr1xy++;
      itr2xy++;

    }
    
    itr1y++;
    itr2y++;

  }
  
  return *this;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T>& Matrix<Y,X,T>::operator-=( const Matrix<Y,X,T>& mat )
{

  auto itr1y = m_M.begin() , end1y = m_M.end();
  auto itr2y = mat.m_M.begin();  

  while( itr1y != end1y ){

    auto itr1xy = itr1y->begin() , end1xy = itr1y->end();
    auto itr2xy = itr2y->begin();  

    while( itr1xy != end1xy ){

      *itr1xy -= *itr2xy;
      itr1xy++;
      itr2xy++;

    }
    
    itr1y++;
    itr2y++;

  }
  
  return *this;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> Matrix<Y,X,T>& Matrix<Y,X,T>::operator*=( const T& scalar ) noexcept
{

  for( auto itry = m_M.begin() , endy = m_M.end() ; itry != endy ; itry++ ){

    for( auto itrxy = itry->begin() , endxy = itry->end() ; itrxy != endxy ; itrxy++ ){

      *itrxy *= scalar;

    }

  }

  return *this;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline TableTypeForMatrix<T>& Matrix<Y,X,T>::RefTable() noexcept { return m_M; }
template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline const TableTypeForMatrix<T>& Matrix<Y,X,T>::GetTable() const noexcept { return m_M; }

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline const Matrix<Y,X,T>& Matrix<Y,X,T>::Unit() noexcept { static const Matrix<Y,X,T> unit = Unit_Body(); return unit; }

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> Matrix<Y,X,T>::Unit_Body() noexcept
{

  TableTypeForMatrix<T> M{};
  
  for( SizeTypeForMatrix y = 0 ; y < Y ; y++ ){

    LineTypeForMatrix<T> vec{};

    for( SizeTypeForMatrix x = 0 ; x < X ; x++ ){

      vec.push_back( x == y ? 1 : 0 );

    }

    M.push_back( vec );

  }

  return Matrix<Y,X,T>( M );

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline void Matrix<Y,X,T>::ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec ) noexcept { M.push_back( vec ); vec.clear(); }

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> template <typename Arg , typename... Args> void Matrix<Y,X,T>::ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec , const Arg& arg , const Args&... args ) noexcept
{

  vec.push_back( arg );

  if( vec.size() == X ){

    ConstructTable( M , vec );

  }

  if( M.size() < Y ){

    ConstructTable( M , vec , args... );

  }
  
  return;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline Matrix<Y,X,T> operator==( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return mat1.GetTable() == mat2.GetTable(); }

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return !( mat1 == mat2 ); }

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 )
{

  Matrix<Y,X,T> mat1_copy = mat1;
  mat1_copy += mat2;
  return mat1_copy;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 )
{

  Matrix<Y,X,T> mat1_copy = mat1;
  mat1_copy -= mat2;
  return mat1_copy;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , SizeTypeForMatrix Z , typename T> inline Matrix<Y,Z,T> operator*( const Matrix<Y,X,T>& mat1 , const Matrix<X,Z,T>& mat2 )
{

  const TableTypeForMatrix<T>& M1 = mat1.GetTable();
  const TableTypeForMatrix<T>& M2 = mat2.GetTable();
  TableTypeForMatrix<T> M_prod{};
  auto begin2x = M2.begin();
  
  for( auto itr1y = M1.begin() , end1y = M1.end() ; itr1y != end1y ; itr1y++ ){

    LineTypeForMatrix<T> vec{};
    auto begin1yx = itr1y->begin() , end1yx = itr1y->end();

    for( SizeTypeForMatrix z = 0 ; z < Z ; z++ ){

      auto itr1yx = begin1yx;
      auto itr2x = begin2x;

      T inner_product = 0;
      
      while( itr1yx != end1yx ){

	inner_product += ( *itr1yx ) * ( *itr2x )[z];
	itr1yx++;
	itr2x++;

      }

      vec.push_back( inner_product );

    }

    M_prod.push_back( vec );

  }

  return Matrix<Y,Z,T>( M_prod );

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat )
{

  Matrix<Y,X,T> mat_copy = mat;
  mat_copy *= scalar;
  return mat_copy;

}

template <SizeTypeForMatrix Y , SizeTypeForMatrix X , typename T>
Matrix<X,Y,T> Transpose( const Matrix<Y,X,T>& mat )
{

  const TableTypeForMatrix<T>& M = mat.GetTable();
  TableTypeForMatrix<T> M_t{};

  auto beginy = M.begin();

  for( auto itr1x = beginy->begin() , end1x = beginy->end() ; itr1x != end1x ; itr1x++ ){

    M_t.push_back( LineTypeForMatrix<T>() );

  }

  for( auto itry = beginy , endy = M.end() ; itry != endy ; itry++ ){

    auto itryx = itry->begin() , endyx = itry->end();
    auto itr_ty = M_t.begin();

    while( itryx != endyx ){

      itr_ty->push_back( *itryx );
      itryx++;
      itr_ty++;

    }

  }

  return Matrix<X,Y,T>( M_t );

}

template <SizeTypeForMatrix X , typename T>
T Trace( const Matrix<X,X,T>& mat )
{

  int i = 0;
  T answer =0;
  const TableTypeForMatrix<T>& M = mat.GetTable();

  for( auto itry = M.begin() , endy = M.end() ; itry != endy ; itry++ ){

    answer += ( *itry )[i];
    i++;

  }

  return answer;

}

template <typename T , typename UINT> inline Matrix<2,2,T> PowerBinaryMethod( const Matrix<2,2,T>& mat , const UINT& num , const Matrix<2,2,T>& init_dummy , const bool& for_right_multiplication_dummy ) { return PowerBinaryMethod( TwoByTwoMatrix<T>( mat ) , num , TwoByTwoMatrix<T>( init_dummy ) , for_right_multiplication_dummy ).GetMatrix22(); }
