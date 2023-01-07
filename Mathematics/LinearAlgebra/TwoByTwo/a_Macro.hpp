// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/TwoByTwo/a_Macro.hpp

#pragma once
#include "../a_Macro.hpp"
#include <immintrin.h>

#define VECTORISATION_FOR_2by2MATRIX_FOR_MOD( MODULO )			\
  template <> inline TwoByTwoMatrix<Mod<MODULO> >& TwoByTwoMatrix<Mod<MODULO> >::operator+=( const TwoByTwoMatrix<Mod<MODULO> >& mat ) noexcept \
  {									\
    uint this_copy[4] = { m_M00.m_n , m_M01.m_n , m_M10.m_n , m_M11.m_n }; \
    uint mat_copy[4] = { mat.m_M00.m_n , mat.m_M01.m_n , mat.m_M10.m_n , mat.m_M11.m_n }; \
    _mm_store_si128( (__m128i*)this_copy , _mm_load_si128((__m128i *)this_copy ) + _mm_load_si128((__m128i *)mat_copy ) ); \
    FOR( i , 0 , 4 ){							\
      Mod<MODULO>::Normalise( this_copy[i] );				\
    }									\
    m_M00.m_n = this_copy[0];						\
    m_M01.m_n = this_copy[1];						\
    m_M10.m_n = this_copy[2];						\
    m_M11.m_n = this_copy[3];						\
    return *this;							\
									\
  }									\
									\
  template <> inline TwoByTwoMatrix<Mod<MODULO> >& TwoByTwoMatrix<Mod<MODULO> >::operator-=( const TwoByTwoMatrix<Mod<MODULO> >& mat ) noexcept \
  {									\
    static const uint MODULO_copy[4] = { MODULO , MODULO , MODULO , MODULO }; \
    static const __m128i v_MODULO = _mm_load_si128( (__m128i *)MODULO_copy ); \
    uint this_copy[4] = { m_M00.m_n , m_M01.m_n , m_M10.m_n , m_M11.m_n }; \
    uint mat_copy[4] = { mat.m_M00.m_n , mat.m_M01.m_n , mat.m_M10.m_n , mat.m_M11.m_n }; \
    _mm_store_si128( (__m128i*)this_copy , ( _mm_load_si128((__m128i *)this_copy ) + v_MODULO ) - _mm_load_si128((__m128i *)mat_copy ) ); \
    FOR( i , 0 , 4 ){							\
      Mod<MODULO>::Normalise( this_copy[i] );				\
    }									\
    m_M00.m_n = this_copy[0];						\
    m_M01.m_n = this_copy[1];						\
    m_M10.m_n = this_copy[2];						\
    m_M11.m_n = this_copy[3];						\
    return *this;							\
									\
  }									\
