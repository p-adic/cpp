// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByOne/a.hpp

#pragma once
#include "../a_Macro.hpp"

template <typename T> class TwoByTwoMatrix;

template <typename T>
class TwoByOneMatrix
{

  friend class TwoByTwoMatrix<T>;

private:
  T m_M0;
  T m_M1;

public:
  inline constexpr TwoByOneMatrix( const T& M0 = T() , const T& M1 = T() ) noexcept;
  inline constexpr TwoByOneMatrix( T&& M0 , T&& M1 ) noexcept;
  inline constexpr TwoByOneMatrix( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix( TwoByOneMatrix<T>&& mat ) noexcept;
  
  inline constexpr TwoByOneMatrix<T>& operator=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator=( TwoByOneMatrix<T>&& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator+=( const TwoByOneMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator-=( const TwoByOneMatrix<T>& mat ) noexcept;
  // ç∂Ç©ÇÁÇÃêœ
  inline TwoByOneMatrix<T>& operator*=( const TwoByTwoMatrix<T>& mat ) noexcept;
  inline constexpr TwoByOneMatrix<T>& operator*=( const T& scalar ) noexcept;
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByOneMatrix<T>& operator*=( const Arg& scalar ) noexcept;
  inline TwoByOneMatrix<T>& operator/=( const T& scalar );
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByOneMatrix<T>& operator/=( const Arg& scalar );
  inline TwoByOneMatrix<T>& operator%=( const T& scalar );
  template <SFINAE_FOR_MATRIX( = nullptr )> inline constexpr TwoByOneMatrix<T>& operator%=( const Arg& scalar );

  inline constexpr const T& GetEntry( const uint& y ) const noexcept;
  inline constexpr T& RefEntry( const uint& y ) noexcept;
  
};
