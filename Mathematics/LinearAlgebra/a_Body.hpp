// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Body.hpp

#pragma once
#include "a.hpp"

#include "2by2/a_Body.hpp"

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const T& t ) noexcept : m_M() { operator=( Scalar( t ) ); }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const int& t ) noexcept : Matrix( T( t ) ) {}

template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( const T& t0 , const T& t1 , const Args&... args ) noexcept : m_M() { LineTypeForMatrix<T> vec{}; ConstructTable( m_M , vec , t0 , t1 , args... ); }
template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( T&& t0 , T&& t1 , Args&&... args ) noexcept : m_M() { LineTypeForMatrix<T> vec{}; ConstructTable( m_M , vec , move( t0 ) , move( t1 ) , move( args )... ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( const Matrix<Y,X,T>& mat ) noexcept : m_M( mat.m_M ) {}
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>::Matrix( Matrix<Y,X,T>&& mat ) noexcept : m_M( move( mat.m_M ) ) {}

template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( const TableTypeForMatrix<T>& M ) noexcept : m_M( M ) {}
template <uint Y , uint X , typename T> template <typename... Args> inline Matrix<Y,X,T>::Matrix( TableTypeForMatrix<T>&& M ) noexcept : m_M( move( M ) ) {}

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( const Matrix<Y,X,T>& mat ) noexcept { m_M = mat.m_M; return *this; }
template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator=( Matrix<Y,X,T>&& mat ) noexcept { m_M = move( mat.m_M ); return *this; }

template <uint Y , uint X , typename T>
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

template <uint Y , uint X , typename T>
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

template <uint Y , uint X , typename T> Matrix<Y,X,T>& Matrix<Y,X,T>::operator*=( const T& scalar ) noexcept
{

  for( auto itry = m_M.begin() , endy = m_M.end() ; itry != endy ; itry++ ){

    for( auto itrxy = itry->begin() , endxy = itry->end() ; itrxy != endxy ; itrxy++ ){

      *itrxy *= scalar;

    }

  }

  return *this;

}

template <uint Y , uint X , typename T> inline Matrix<Y,X,T>& Matrix<Y,X,T>::operator*=( const Matrix<X,X,T>& mat ) noexcept { return operator=( move( *this * mat ) ); }

template <uint Y , uint X , typename T> Matrix<Y,X,T>& Matrix<Y,X,T>::operator%=( const T& scalar ) noexcept
{

  for( auto itry = m_M.begin() , endy = m_M.end() ; itry != endy ; itry++ ){

    for( auto itrxy = itry->begin() , endxy = itry->end() ; itrxy != endxy ; itrxy++ ){

      *itrxy %= scalar;

    }

  }

  return *this;

}

template <uint Y , uint X , typename T> inline TableTypeForMatrix<T>& Matrix<Y,X,T>::RefTable() noexcept { return m_M; }
template <uint Y , uint X , typename T> inline const TableTypeForMatrix<T>& Matrix<Y,X,T>::GetTable() const noexcept { return m_M; }

template <uint Y , uint X , typename T> inline const Matrix<Y,X,T>& Matrix<Y,X,T>::Zero() noexcept { static const Matrix<Y,X,T> zero = move( Zero_Body() ); return zero; }
template <uint Y , uint X , typename T> inline const Matrix<Y,X,T>& Matrix<Y,X,T>::Unit() noexcept { static const Matrix<Y,X,T> unit = move( Scalar( T( 1 ) ) ); return unit; }

template <uint Y , uint X , typename T>
Matrix<Y,X,T> Matrix<Y,X,T>::Zero_Body() noexcept
{

  LineTypeForMatrix<T> vec( X );
  TableTypeForMatrix<T> M( Y , vec );
  return Matrix<Y,X,T>( move( M ) );

}

template <uint Y , uint X , typename T>
Matrix<Y,X,T> Matrix<Y,X,T>::Scalar( const T& t ) noexcept
{

  Matrix<Y,X,T> M{ move( Zero_Body() ) };
  constexpr const uint minXY = Y < X ? Y : X;
  
  for( uint y = 0 ; y < minXY ; y++ ){

    M.m_M[y][y] = t;

  }

  return M;

}

template <uint Y , uint X , typename T> inline void Matrix<Y,X,T>::ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec ) noexcept { M.push_back( move( vec ) ); }

template <uint Y , uint X , typename T> template <typename... Args> void Matrix<Y,X,T>::ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec , const T& t , const Args&... args ) noexcept
{

  vec.push_back( t );

  if( vec.size() == X ){

    LineTypeForMatrix<T> v{};
    v.swap( vec );
    ConstructTable( M , v );

  }

  if( M.size() < Y ){

    ConstructTable( M , vec , args... );

  }
  
  return;

}

template <uint Y , uint X , typename T> template <typename... Args> void Matrix<Y,X,T>::ConstructTable( TableTypeForMatrix<T>& M , LineTypeForMatrix<T>& vec , T&& t , Args&&... args ) noexcept
{

  vec.push_back( move( t ) );

  if( vec.size() == X ){

    LineTypeForMatrix<T> v{};
    v.swap( vec );
    ConstructTable( M , v );

  }

  if( M.size() < Y ){

    ConstructTable( M , vec , move( args )... );

  }
  
  return;

}

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator==( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return mat1.GetTable() == mat2.GetTable(); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator!=( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) noexcept { return !( mat1 == mat2 ); }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator+( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) { return Matrix<Y,X,T>( mat1 ) += mat2; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator-( const Matrix<Y,X,T>& mat1 , const Matrix<Y,X,T>& mat2 ) { return Matrix<Y,X,T>( mat1 ) -= mat2; }

template <uint Y , uint X , uint Z , typename T> inline Matrix<Y,Z,T> operator*( const Matrix<Y,X,T>& mat1 , const Matrix<X,Z,T>& mat2 )
{

  const TableTypeForMatrix<T>& M1 = mat1.GetTable();
  const TableTypeForMatrix<T>& M2 = mat2.GetTable();
  TableTypeForMatrix<T> M_prod{};
  auto begin2x = M2.begin();
  
  for( auto itr1y = M1.begin() , end1y = M1.end() ; itr1y != end1y ; itr1y++ ){

    LineTypeForMatrix<T> vec{};
    auto begin1yx = itr1y->begin() , end1yx = itr1y->end();

    for( uint z = 0 ; z < Z ; z++ ){

      auto itr1yx = begin1yx;
      auto itr2x = begin2x;

      T inner_product{};
      
      while( itr1yx != end1yx ){

	inner_product += ( *itr1yx ) * ( *itr2x )[z];
	itr1yx++;
	itr2x++;

      }

      vec.push_back( inner_product );

    }

    M_prod.push_back( move( vec ) );

  }

  return Matrix<Y,Z,T>( move( M_prod ) );

}

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator*( const Matrix<Y,X,T>& mat , const T& scalar ) { return Matrix<Y,X,T>( mat ) *= scalar; }
template <uint Y , uint X , typename T> inline 
Matrix<Y,X,T> operator*( const T& scalar , const Matrix<Y,X,T>& mat ) { return mat * scalar; }

template <uint Y , uint X , typename T> inline Matrix<Y,X,T> operator%( const Matrix<Y,X,T>& mat , const T& scalar ) { return Matrix<Y,X,T>( mat ) %= scalar; }

template <uint Y , uint X , typename T>
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

template <uint X , typename T>
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
