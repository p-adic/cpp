// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a.hpp

#pragma once

template <typename T> class TwoByTwoMatrix;

template <typename T>
class TwoByOneMatrix
{

  friend class TwoByTwoMatrix<T>;

private:
  T m_M0;
  T m_M1;

public:
  inline TwoByOneMatrix( const T& M0 = T() , const T& M1 = T() ) noexcept;
  inline TwoByOneMatrix( T&& M0 , T&& M1 ) noexcept;
  inline TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept;
  
  inline TwoByOneMatrix<T>& operator=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix<T>& operator=( TwoByOneMatrix<T>&& mat ) noexcept;
  inline TwoByOneMatrix<T>& operator+=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix<T>& operator-=( const TwoByOneMatrix<T>& mat ) noexcept;
  // ç∂Ç©ÇÁÇÃêœ
  inline TwoByOneMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline TwoByOneMatrix<T>& operator*=( const T& scalar ) noexcept;
  inline TwoByOneMatrix<T>& operator/=( const T& scalar );
  inline TwoByOneMatrix<T>& operator%=( const T& scalar );

  inline const T& GetEntry( const uint& y ) const noexcept;
  inline T& RefEntry( const uint& y ) noexcept;
  
};
