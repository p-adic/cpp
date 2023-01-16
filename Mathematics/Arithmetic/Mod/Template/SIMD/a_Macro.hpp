// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Template/SIMD/a_Macro.hpp

#pragma once

#define SET_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 ) \
  alignas( 16 ) constexpr const UINT VECTOR_NAME ## _copy[4] = { SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 }; \
  static const __m128i v_ ## VECTOR_NAME = _mm_load_si128( ( __m128i* ) VECTOR_NAME ##_copy ); \

#define SET_VECTOR_64_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR0 , SCALAR1 ) \
  alignas( 16 ) constexpr const UINT VECTOR_NAME ## _copy[2] = { SCALAR0 , SCALAR1 }; \
  static const __m128i v_ ## VECTOR_NAME = _mm_load_si128( ( __m128i* ) VECTOR_NAME ##_copy ); \

#define SET_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 )	\
  alignas( 32 ) constexpr const ULL VECTOR_NAME ## _copy[4] = { SCALAR0 , SCALAR1 , SCALAR2 , SCALAR3 }; \
  static const __m256i v_ ## VECTOR_NAME = _mm256_load_si256( ( __m256i* ) VECTOR_NAME ##_copy ); \

#define SET_CONST_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_32_128_FOR_SIMD( UINT , VECTOR_NAME , SCALAR , SCALAR , SCALAR , SCALAR );	\

#define SET_CONST_VECTOR_64_128_FOR_SIMD( ULL , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_64_128_FOR_SIMD( ULL , VECTOR_NAME , SCALAR , SCALAR );	\

#define SET_CONST_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR )	\
  SET_VECTOR_64_256_FOR_SIMD( ULL , VECTOR_NAME , SCALAR , SCALAR , SCALAR , SCALAR ); \

#define COMPUTE_PRODUCT_FOR_SIMD_MATRIX_2222( J , SHUFFLE )		\
  {									\
									\
    __m256i v_produll = v_aull * _mm256_permute4x64_epi64( v_bull , SHUFFLE ); \
    _mm256_store_si256( (__m256i*)aull_copy , v_produll );		\
									\
    static const __m128i& v_M_neg_inverse = ConstantsForSIMDForMod<M>::v_M_neg_inverse(); \
    for( uint i = 0 ; i < 4 ; i++ ){					\
									\
      c[i] = uint( aull_copy[i] );					\
									\
    }									\
									\
    _mm_store_si128( (__m128i*)c , _mm_mullo_epi32( _mm_load_si128( (__m128i*)c ) , v_M_neg_inverse ) ); \
									\
    static const __m256i& v_Mull256 = ConstantsForSIMDForMod<M>::v_Mull256(); \
    static const __m256i& v_digitull256 = ConstantsForSIMDForMod<M>::v_digitull256(); \
									\
    for( uint i = 0 ; i < 4 ; i++ ){					\
									\
      bull_copy[i] = c[i];						\
									\
    }									\
									\
    ( v_produll += _mm256_load_si256( (__m256i*)bull_copy ) * v_Mull256 ) >>= v_digitull256; \
    _mm256_store_si256( (__m256i*)aull_copy , v_produll );		\
									\
    for( uint i = 0 ; i < 4 ; i++ ){					\
									\
      c[i] = uint( aull_copy[i] );					\
									\
    }									\
									\
    __m128i& v_prod_j = v_prod[J];					\
    v_prod_j = _mm_load_si128( (__m128i*)c );				\
									\
    for( uint i = 0 ; i < 4 ; i++ ){					\
									\
      c[i] = c[i] < M ? 0 : M;						\
									\
    }									\
									\
    v_prod_j -= _mm_load_si128( (__m128i*)c );				\
    									\
    }									\
     
// static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
// static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
// v_prod_j -= _mm_cmpgt_epi32( v_prod_j , v_M_minus ) & v_M;

