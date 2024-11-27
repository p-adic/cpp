// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/SIMD/a_Macro.hpp

#pragma once

#define SET_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 ) \
  constexpr const UINT VECTOR_NAME ## _copy[4] = { SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 }; \
  static const __m128i v_ ## VECTOR_NAME = _mm_load_si128( ( __m128i* ) VECTOR_NAME ##_copy ); \

#define SET_VECTOR_64_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR0 , SCALAR1 ) \
  constexpr const UINT VECTOR_NAME ## _copy[2] = { SCALAR0 , SCALAR1 }; \
  static const __m128i v_ ## VECTOR_NAME = _mm_load_si128( ( __m128i* ) VECTOR_NAME ##_copy ); \

#define SET_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 )	\
  constexpr const ULL VECTOR_NAME ## _copy[4] = { SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 }; \
  static const __m256i v_ ## VECTOR_NAME = _mm256_load_si256( ( __m256i* ) VECTOR_NAME ##_copy ); \

#define SET_CONST_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR , SCALAR , SCALAR , SCALAR );	\

#define SET_CONST_VECTOR_64_128_FOR_SIMD( ULL , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_64_128_FOR_SIMD( ULL , VECTOR_NAME , SCALAR , SCALAR );	\

#define SET_CONST_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR , SCALAR , SCALAR , SCALAR ); \


