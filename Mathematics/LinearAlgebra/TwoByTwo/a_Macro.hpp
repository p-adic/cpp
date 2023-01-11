// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a_Macro.hpp

#pragma once
#include <immintrin.h>

#define VECTORISATION_FOR_2by2MATRIX_FOR_MOD( MODULO )			\
  template <> inline TwoByTwoMatrix<Mod<MODULO> >& TwoByTwoMatrix<Mod<MODULO> >::operator+=( const TwoByTwoMatrix<Mod<MODULO> >& mat ) noexcept { SIMD_Addition_32_128( m_M00 , m_M01 , m_M10 , m_M11 , mat.m_M00 , mat.m_M01 , mat.m_M10 , mat.m_M11 , m_M00 , m_M01 , m_M10 , m_M11 ); return *this; } \
  template <> inline TwoByTwoMatrix<Montgomery<MODULO> >& TwoByTwoMatrix<Montgomery<MODULO> >::operator+=( const TwoByTwoMatrix<Montgomery<MODULO> >& mat ) noexcept { SIMD_Addition_32_128( m_M00 , m_M01 , m_M10 , m_M11 , mat.m_M00 , mat.m_M01 , mat.m_M10 , mat.m_M11 , m_M00 , m_M01 , m_M10 , m_M11 ); return *this; } \
  template <> inline TwoByTwoMatrix<Mod<MODULO> >& TwoByTwoMatrix<Mod<MODULO> >::operator-=( const TwoByTwoMatrix<Mod<MODULO> >& mat ) noexcept { SIMD_Subtraction_32_128( m_M00 , m_M01 , m_M10 , m_M11 , mat.m_M00 , mat.m_M01 , mat.m_M10 , mat.m_M11 , m_M00 , m_M01 , m_M10 , m_M11 ); return *this; } \
  template <> inline TwoByTwoMatrix<Montgomery<MODULO> >& TwoByTwoMatrix<Montgomery<MODULO> >::operator-=( const TwoByTwoMatrix<Montgomery<MODULO> >& mat ) noexcept { SIMD_Subtraction_32_128( m_M00 , m_M01 , m_M10 , m_M11 , mat.m_M00 , mat.m_M01 , mat.m_M10 , mat.m_M11 , m_M00 , m_M01 , m_M10 , m_M11 ); return *this; } \


// à»â∫ÇÕÉ}ÉNÉçÇ…ì¸ÇÍÇ»Ç¢ï˚Ç™ë¨Ç¢ÅB
// template <> inline TwoByTwoMatrix<Montgomery<MODULO> > TwoByTwoMatrix<Montgomery<MODULO> >::operator*( const TwoByTwoMatrix<Montgomery<MODULO> >& mat ) const noexcept
// {

//   Montgomery<MODULO> mat0[4] = { mat.m_M00 , mat.m_M01 , mat.m_M00 , mat.m_M01 };
//   Montgomery<MODULO> mat1[4] = { mat.m_M10 , mat.m_M11 , mat.m_M10 , mat.m_M11 };
//   SIMD_Multiplication_32_128( mat0[0] , mat0[1] , mat0[2] , mat0[3] , m_M00 , m_M00 , m_M10 , m_M10 , mat0[0] , mat0[1] , mat0[2] , mat0[3] );
//   SIMD_Multiplication_32_128( mat1[0] , mat1[1] , mat1[2] , mat1[3] , m_M01 , m_M01 , m_M11 , m_M11 , mat0[0] , mat0[1] , mat0[2] , mat0[3] );
//   TwoByTwoMatrix<Montgomery<MODULO> > answer{};
//   SIMD_Addition_32_128( mat0[0] , mat0[1] , mat0[2] , mat0[3] , mat1[0] , mat1[1] , mat1[2] , mat1[3] , answer.m_M00 , answer.m_M01 , answer.m_M10 , answer.m_M11 );
//   return answer;

// }

// template <> inline TwoByOneMatrix<Montgomery<MODULO> > TwoByTwoMatrix<Montgomery<MODULO> >::operator*( const TwoByOneMatrix<Montgomery<MODULO> >& mat ) const noexcept
// {

//   Montgomery<MODULO>  mat_copy[4] = { mat.m_M0 , mat.m_M1 , mat.m_M0 , mat.m_M1 };
//   SIMD_Multiplication_32_128( mat_copy[0] , mat_copy[1] , mat_copy[2] , mat_copy[3] , m_M00 , m_M01 , m_M10 , m_M11 , mat_copy[0] , mat_copy[1] , mat_copy[2] , mat_copy[3] );
//   return TwoByOneMatrix<Montgomery<MODULO> >( move( mat_copy[0] += mat_copy[1] ) , move( mat_copy[2] += mat_copy[3] ) );

// }
