// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/SIMD/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Arithmetic/Mod/a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M , M ); return v_M; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_Mull() noexcept { SET_CONST_VECTOR_64_128_FOR_SIMD( ull , Mull , M ); return v_Mull; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M_minus() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M_minus , M - 1 ); return v_M_minus; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M_neg_inverse() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M_neg_inverse , ConstantsForMod<M>::g_Montgomery_M_neg_inverse ); return v_M_neg_inverse; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_digitull() noexcept { SET_CONST_VECTOR_64_128_FOR_SIMD( ull , digitull , ConstantsForMod<M>::g_Montgomery_digit ); return v_digitull; }

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_32_128( __m128i& v ) noexcept { const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); return v -= v_M * _mm_cmpgt_epi32( v , v_M ); }

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_64_128( __m128i& v ) noexcept
{

  ull v_copy[2];
  _mm_store_si128( (__m128i*)v_copy , v );

  for( uint i = 0 ; i < 2 ; i++ ){

    ull& v_copy_i = v_copy[i];
    v_copy_i = ( v_copy_i < M ? 0 : M );

  }

  return v -= _mm_load_si128( (__m128i*)v_copy );
  
}

template <INT_TYPE_FOR_MOD M> inline __m256i& SIMD_Residue_64_256( __m256i& v ) noexcept
{

  ull v_copy[4];
  _mm256_store_si256( (__m256i*)v_copy , v );

  for( uint i = 0 ; i < 4 ; i++ ){

    ull& v_copy_i = v_copy[i];
    v_copy_i = ( v_copy_i < M ? 0 : M );

  }

  return v -= _mm256_load_si256( (__m256i*)v_copy );
  
}

inline constexpr int SIMD_Shuffle( const int& a0 , const int& a1 , const int& a2 , const int& a3 ) noexcept { return ( a0 << ( 0 << 1 ) ) + ( a1 << ( 1 << 1 ) ) + ( a2 << ( 2 << 1 ) ) + ( a3 << ( 3 << 1 ) ); }

// Θ‰Ί‚ΝMod<M>‚Μƒƒ“ƒo‚πpublic‚Ι•ΟX‚µ‚½‚Μ‚έƒRƒ“ƒpƒCƒ‹‰Β”\B
// ’Κν‚Μ‰Α–@‚ζ‚θα±η­‚ΆB
template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_64( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& b0 , const Mod<M>& b1 , Mod<M>& c0 , Mod<M>& c1 ) noexcept
{

  uint a_copy[4] = { a0.m_n , a1.m_n , 0 , 0 };
  uint b_copy[4] = { b0.m_n , b1.m_n , 0 , 0 };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  v_a += _mm_load_si128( (__m128i*)b_copy );
  // ‚±‚±‚Νπ•ªς‚ζ‚θ_mm_cmpgt_epi32‚Εƒ}ƒXƒN—‚µ‚½•ϋ‚ªα±‘¬‚ΆB
  static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  v_a += _mm_cmpgt_epi32( v_a , v_M_minus ) & v_M;
  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  return;

}

template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_128( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& a2 , const Mod<M>& a3 , const Mod<M>& b0 , const Mod<M>& b1 , const Mod<M>& b2 , const Mod<M>& b3 , Mod<M>& c0 , Mod<M>& c1 , Mod<M>& c2 , Mod<M>& c3 ) noexcept
{

  uint a_copy[4] = { a0.m_n , a1.m_n , a2.m_n , a3.m_n };
  uint b_copy[4] = { b0.m_n , b1.m_n , b2.m_n , b3.m_n };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy ) + _mm_load_si128( (__m128i*)b_copy );
  _mm_store_si128( (__m128i*)a_copy , v_a );

  // ‚±‚±‚π_mm_cmpgt_epi32‚Εƒ}ƒXƒN—‚·‚ι‚Ζ‹t‚Ι‚Q”{’x‚­‚Θ‚ιB
  for( uint i = 0 ; i < 4 ; i++ ){

    b_copy[i] = a_copy[i] < M ? 0 : M;

  }
  
  v_a -= _mm_load_si128( (__m128i*)b_copy );
  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  c2.m_n = move( a_copy[2] );
  c3.m_n = move( a_copy[3] );
  return;

}

template <INT_TYPE_FOR_MOD M> inline void SIMD_Substracition_32_64( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& b0 , const Mod<M>& b1 , Mod<M>& c0 , Mod<M>& c1 ) noexcept
{

  uint a_copy[4] = { a0.m_n , a1.m_n , 0 , 0 };
  uint b_copy[4] = { b0.m_n , b1.m_n , 0 , 0 };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  __m128i v_b = _mm_load_si128( (__m128i*)b_copy );
  _mm_store_si128( (__m128i*)a_copy , v_a );

  // ‚±‚±‚π_mm_cmpgt_epi32‚Εƒ}ƒXƒN—‚·‚ι‚Ζ‹t‚Ι‚Q”{’x‚­‚Θ‚ιB
  for( uint i = 0 ; i < 2 ; i++ ){

    b_copy[i] = a_copy[i] < b_copy[i] ? M : 0;

  }
  
  ( v_a += _mm_load_si128( (__m128i*)b_copy ) ) -= v_b;
  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  return;

}

template <INT_TYPE_FOR_MOD M> inline void SIMD_Subtraction_32_128( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& a2 , const Mod<M>& a3 , const Mod<M>& b0 , const Mod<M>& b1 , const Mod<M>& b2 , const Mod<M>& b3 , Mod<M>& c0 , Mod<M>& c1 , Mod<M>& c2 , Mod<M>& c3 ) noexcept
{

  uint a_copy[4] = { a0.m_n , a1.m_n , a2.m_n , a3.m_n };
  uint b_copy[4] = { b0.m_n , b1.m_n , b2.m_n , b3.m_n };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  __m128i v_b = _mm_load_si128( (__m128i*)b_copy );
  _mm_store_si128( (__m128i*)a_copy , v_a );

  // ‚±‚±‚π_mm_cmpgt_epi32‚Εƒ}ƒXƒN—‚·‚ι‚Ζ‹t‚Ι‚Q”{’x‚­‚Θ‚ιB
  for( uint i = 0 ; i < 4 ; i++ ){

    b_copy[i] = a_copy[i] < b_copy[i] ? M : 0;

  }
  
  ( v_a += _mm_load_si128( (__m128i*)b_copy ) ) -= v_b;
  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  c2.m_n = move( a_copy[2] );
  c3.m_n = move( a_copy[3] );
  return;

}

// ’Κν‚ΜζZ‚ζ‚θ‚©‚Θ‚θη­‚ΆB
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Multiplication_32_128( const Montgomery<M>& a0 , const Montgomery<M>& a1 , const Montgomery<M>& a2 , const Montgomery<M>& a3 , const Montgomery<M>& b0 , const Montgomery<M>& b1 , const Montgomery<M>& b2 , const Montgomery<M>& b3 , Montgomery<M>& c0 , Montgomery<M>& c1 , Montgomery<M>& c2 , Montgomery<M>& c3 ) noexcept
{

  ull aull_copy[4] = { a0.Mod<M>::m_n , a1.Mod<M>::m_n , a2.Mod<M>::m_n , a3.Mod<M>::m_n };
  ull bull_copy[4] = { b0.Mod<M>::m_n , b1.Mod<M>::m_n , b2.Mod<M>::m_n , b3.Mod<M>::m_n };
  __m256i v_aull = _mm256_load_si256( (__m256i*)aull_copy );
  _mm256_store_si256( (__m256i*)aull_copy , v_aull *= _mm256_load_si256( (__m256i*)bull_copy ) );

  static const __m128i& v_M_neg_inverse = ConstantsForSIMDForMod<M>::v_M_neg_inverse(); 
  uint a_copy[4] = { uint( aull_copy[0] ) , uint( aull_copy[1] ) , uint( aull_copy[2] ) , uint( aull_copy[3] ) };
  _mm_store_si128( (__m128i*)a_copy , _mm_mullo_epi32( _mm_load_si128( (__m128i*)a_copy ) , v_M_neg_inverse ) );

  SET_CONST_VECTOR_64_256_FOR_SIMD( ull , Mull , M ); 
  SET_CONST_VECTOR_64_256_FOR_SIMD( ull , digitull , ConstantsForMod<M>::g_Montgomery_digit ); 
  bull_copy[0] = a_copy[0];
  bull_copy[1] = a_copy[1];
  bull_copy[2] = a_copy[2];
  bull_copy[3] = a_copy[3];
  ( v_aull += _mm256_load_si256( (__m256i*)bull_copy ) * v_Mull ) >>= v_digitull;
  _mm256_store_si256( (__m256i*)aull_copy , v_aull );
  
  a_copy[0] = move( aull_copy[0] );
  a_copy[1] = move( aull_copy[1] );
  a_copy[2] = move( aull_copy[2] );
  a_copy[3] = move( aull_copy[3] );
  uint diff[4];
  
  // ‚±‚±‚π_mm_cmpgt_epi32‚Εƒ}ƒXƒN—‚·‚ι‚Ζ‹t‚Ι‚Q”{’x‚­‚Θ‚ιB
  for( uint i = 0 ; i < 4 ; i++ ){

    diff[i] = a_copy[i] < M ? 0 : M;

  }
  
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  _mm_store_si128( (__m128i*)a_copy , v_a -= _mm_load_si128( (__m128i*)diff ) );
  c0.Mod<M>::m_n = move( a_copy[0] );
  c1.Mod<M>::m_n = move( a_copy[1] );
  c2.Mod<M>::m_n = move( a_copy[2] );
  c3.Mod<M>::m_n = move( a_copy[3] );
  return;

}
