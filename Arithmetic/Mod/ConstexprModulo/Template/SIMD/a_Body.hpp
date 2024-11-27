// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/SIMD/a_Body.hpp

#include "a.hpp"

#include "../a_Body.hpp"

template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M , M ); return v_M; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_Mull() noexcept { SET_CONST_VECTOR_64_128_FOR_SIMD( ull , Mull , M ); return v_Mull; }
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline const __m256i& ConstantsForSIMDForMod<M>::v_Mull256() noexcept { SET_CONST_VECTOR_64_256_FOR_SIMD( ull , Mull256 , M ); return v_Mull256; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M_minus() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M_minus , M - 1 ); return v_M_minus; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_Mull_minus() noexcept { SET_CONST_VECTOR_64_128_FOR_SIMD( ull , Mull_minus , M - 1 ); return v_Mull_minus; }
template <INT_TYPE_FOR_MOD M> inline const __m128i& ConstantsForSIMDForMod<M>::v_M_neg_inverse() noexcept { SET_CONST_VECTOR_32_128_FOR_SIMD( uint , M_neg_inverse , ConstantsForMod<M>::g_Montgomery_M_neg_inverse ); return v_M_neg_inverse; }
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline const __m256i& ConstantsForSIMDForMod<M>::v_digitull256() noexcept { SET_CONST_VECTOR_64_256_FOR_SIMD( ull , digitull256 , ConstantsForMod<M>::g_Montgomery_digit ); return v_digitull256; }

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_32_128( __m128i& v ) noexcept {

  static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus();
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M();
  return v -= _mm_cmpgt_epi32( v , v_M_minus ) & v_M;

}

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_64_128( __m128i& v ) noexcept
{

  static const __m128i& v_Mull_minus = ConstantsForSIMDForMod<M>::v_Mull_minus();
  static const __m128i& v_Mull = ConstantsForSIMDForMod<M>::v_Mull();
  return v -= _mm_cmpgt_epi64( v , v_Mull_minus ) & v_Mull;
 
}

template <INT_TYPE_FOR_MOD M> inline __m256i& SIMD_Residue_64_256( __m256i& v ) noexcept
{

  alignas( 32 ) ull v_copy[4];
  _mm256_store_si256( (__m256i*)v_copy , v );

  for( uint i = 0 ; i < 4 ; i++ ){

    ull& v_copy_i = v_copy[i];
    v_copy_i = ( v_copy_i < M ? 0 : M );

  }

  return v -= _mm256_load_si256( (__m256i*)v_copy );
  
}

inline constexpr int SIMD_Shuffle( const int& a0 , const int& a1 , const int& a2 , const int& a3 ) noexcept { return ( a0 << ( 0 << 1 ) ) + ( a1 << ( 1 << 1 ) ) + ( a2 << ( 2 << 1 ) ) + ( a3 << ( 3 << 1 ) ); }

// 以下はMod<M,OPR>などのメンバをpublicに変更した時のみコンパイル可能。
// 通常の加法より若干遲い。
template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Addition_32_64( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a0.m_n , a1.m_n , 0 , 0 };
  alignas( 16 ) uint b_copy[4] = { b0.m_n , b1.m_n , 0 , 0 };
  __m128i answer = _mm_load_si128( (__m128i*)a_copy ) + _mm_load_si128( (__m128i*)b_copy );
  // ここは条件分岐より_mm_cmpgt_epi32でマスク処理した方が若干速い。
  static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  answer += _mm_cmpgt_epi32( answer , v_M_minus ) & v_M;
  _mm_store_si128( (__m128i*)a_copy , answer );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  return;

}

template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_64( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a[0] , a[1] , 0 , 0 };
  alignas( 16 ) uint b_copy[4] = { b[0] , b[1] , 0 , 0 };
  __m128i answer = _mm_load_si128( (__m128i*)a_copy ) + _mm_load_si128( (__m128i*)b_copy );
  
  // ここは条件分岐より_mm_cmpgt_epi32でマスク処理した方が若干速い。
  static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  answer += _mm_cmpgt_epi32( answer , v_M_minus ) & v_M;

  _mm_store_si128( (__m128i*)a_copy , answer );
  c[0] = move( a_copy[0] );
  c[1] = move( a_copy[1] );
  return;

}

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Addition_32_128( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& a2 , const Mod<M,OPR>& a3 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , const Mod<M,OPR>& b2 , const Mod<M,OPR>& b3 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 , Mod<M,OPR>& c2 , Mod<M,OPR>& c3 ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a0.m_n , a1.m_n , a2.m_n , a3.m_n };
  alignas( 16 ) uint b_copy[4] = { b0.m_n , b1.m_n , b2.m_n , b3.m_n };
  __m128i answer = _mm_load_si128( (__m128i*)a_copy ) + _mm_load_si128( (__m128i*)b_copy );

  // ここをSIMD_Residue_32_128でマスク処理すると逆に２倍遅くなる。
  _mm_store_si128( (__m128i*)a_copy , answer );

  for( uint i = 0 ; i < 4 ; i++ ){

    uint& a_copy_i = a_copy[i];
    a_copy_i = a_copy_i < M ? 0 : M;

  }
  
  answer -= _mm_load_si128( (__m128i*)a_copy );
  // SIMD_Residue_32_128( answer );

  _mm_store_si128( (__m128i*)a_copy , answer );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  c2.m_n = move( a_copy[2] );
  c3.m_n = move( a_copy[3] );
  return;

}

template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  __m128i answer = _mm_load_si128( (__m128i*)a ) + _mm_load_si128( (__m128i*)b );

  // ここをSIMD_Residue_32_128でマスク処理すると逆に２倍遅くなる。
  _mm_store_si128( (__m128i*)c , answer );

  for( uint i = 0 ; i < 4 ; i++ ){

    uint& c_i = c[i];
    c_i = c_i < M ? 0 : M;

  }
  
  answer -= _mm_load_si128( (__m128i*)c );
  // SIMD_Residue_32_128( answer );

  _mm_store_si128( (__m128i*)c , answer );
  return;

}

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Substracition_32_64( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a0.m_n , a1.m_n , 0 , 0 };
  alignas( 16 ) uint b_copy[4] = { b0.m_n , b1.m_n , 0 , 0 };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  __m128i v_b = _mm_load_si128( (__m128i*)b_copy );

  // for( uint i = 0 ; i < 2 ; i++ ){

  //   b_copy[i] = a_copy[i] < b_copy[i] ? M : 0;

  // }
  
  // ( v_a += _mm_load_si128( (__m128i*)b_copy ) ) -= v_b;
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  ( v_a += _mm_cmpgt_epi32( v_b , v_a ) & v_M ) -= v_b;

  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  return;

}

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Substracition_32_64( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a[0] , a[1] , 0 , 0 };
  alignas( 16 ) uint b_copy[4] = { b[0] , b[1] , 0 , 0 };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  __m128i v_b = _mm_load_si128( (__m128i*)b_copy );

  // for( uint i = 0 ; i < 2 ; i++ ){

  //   c[i] = a[i] < b[i] ? M : 0;

  // }
  
  // ( v_a += _mm_load_si128( (__m128i*)c ) ) -= v_b;
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  ( v_a += _mm_cmpgt_epi32( v_b , v_a ) & v_M ) -= v_b;

  _mm_store_si128( (__m128i*)a_copy , v_a );
  c[0] = move( a_copy[0] );
  c[1] = move( a_copy[1] );
  return;
  
}

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Subtraction_32_128( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& a2 , const Mod<M,OPR>& a3 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , const Mod<M,OPR>& b2 , const Mod<M,OPR>& b3 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 , Mod<M,OPR>& c2 , Mod<M,OPR>& c3 ) noexcept
{

  alignas( 16 ) uint a_copy[4] = { a0.m_n , a1.m_n , a2.m_n , a3.m_n };
  alignas( 16 ) uint b_copy[4] = { b0.m_n , b1.m_n , b2.m_n , b3.m_n };
  __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  __m128i v_b = _mm_load_si128( (__m128i*)b_copy );

  // ここを_mm_cmpgt_epi32でマスク処理すると逆に２倍遅くなる。
  for( uint i = 0 ; i < 4 ; i++ ){

    uint& b_copy_i = b_copy[i];
    b_copy_i = a_copy[i] < b_copy_i ? M : 0;

  }
  
  ( v_a += _mm_load_si128( (__m128i*)b_copy ) ) -= v_b;
  _mm_store_si128( (__m128i*)a_copy , v_a );
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  c2.m_n = move( a_copy[2] );
  c3.m_n = move( a_copy[3] );
  return;

}

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Subtraction_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  __m128i v_a = _mm_load_si128( (__m128i*)a );
  __m128i v_b = _mm_load_si128( (__m128i*)b );

  // for( uint i = 0 ; i < 4 ; i++ ){

  //   c[i] = a[i] < b[i] ? M : 0;

  // }
  
  // ( v_a += _mm_load_si128( (__m128i*)c ) ) -= v_b;
  // _mm_store_si128( (__m128i*)a_copy , v_a );
  static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  ( v_a += _mm_cmpgt_epi32( v_b , v_a ) & v_M ) -= v_b;

  _mm_store_si128( (__m128i*)c , v_a );
  return;

}

// 通常の乗算よりかなり遲い。
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Multiplication_32_128( const Montgomery<M>& a0 , const Montgomery<M>& a1 , const Montgomery<M>& a2 , const Montgomery<M>& a3 , const Montgomery<M>& b0 , const Montgomery<M>& b1 , const Montgomery<M>& b2 , const Montgomery<M>& b3 , Montgomery<M>& c0 , Montgomery<M>& c1 , Montgomery<M>& c2 , Montgomery<M>& c3 ) noexcept
{

  alignas( 32 ) ull aull_copy[4] = { a0.m_n , a1.m_n , a2.m_n , a3.m_n };
  alignas( 32 ) ull bull_copy[4] = { b0.m_n , b1.m_n , b2.m_n , b3.m_n };
  __m256i v_aull = _mm256_load_si256( (__m256i*)aull_copy );
  _mm256_store_si256( (__m256i*)aull_copy , v_aull *= _mm256_load_si256( (__m256i*)bull_copy ) );

  static const __m128i& v_M_neg_inverse = ConstantsForSIMDForMod<M>::v_M_neg_inverse(); 
  alignas( 16 ) uint a_copy[4] = { uint( aull_copy[0] ) , uint( aull_copy[1] ) , uint( aull_copy[2] ) , uint( aull_copy[3] ) };
  _mm_store_si128( (__m128i*)a_copy , _mm_mullo_epi32( _mm_load_si128( (__m128i*)a_copy ) , v_M_neg_inverse ) );

  static const __m256i& v_Mull256 = ConstantsForSIMDForMod<M>::v_Mull256();
  static const __m256i& v_digitull256 = ConstantsForSIMDForMod<M>::v_digitull256();

  for( uint i = 0 ; i < 4 ; i++ ){

    bull_copy[i] = a_copy[i];

  }
  
  _mm256_store_si256( (__m256i*)aull_copy , ( v_aull += _mm256_load_si256( (__m256i*)bull_copy ) * v_Mull256 ) >>= v_digitull256 );

  // 以下を_mm_cmpgt_epi32でマスク処理すると逆に２倍遅くなる。
  alignas( 16 ) uint diff[4];

  for( uint i = 0 ; i < 4 ; i++ ){

    diff[i] = ( a_copy[i] = move( aull_copy[i] ) ) < M ? 0 : M;

  }
  
  _mm_store_si128( (__m128i*)a_copy , _mm_load_si128( (__m128i*)a_copy ) - _mm_load_si128( (__m128i*)diff ) );
  // for( uint i = 0 ; i < 4 ; i++ ){

  //   a_copy[i] = move( aull_copy[i] );

  // }
  // __m128i v_a = _mm_load_si128( (__m128i*)a_copy );
  // static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
  // static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  // _mm_store_si128( (__m128i*)a_copy , v_a -= _mm_cmpgt_epi32( v_a , v_M_minus ) & v_M );
  
  c0.m_n = move( a_copy[0] );
  c1.m_n = move( a_copy[1] );
  c2.m_n = move( a_copy[2] );
  c3.m_n = move( a_copy[3] );
  return;

}

template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  alignas( 32 ) ull aull_copy[4] = { a[0] , a[1] , a[2] , a[3] };
  alignas( 32 ) ull bull_copy[4] = { b[0] , b[1] , b[2] , b[3] };
  __m256i v_aull = _mm256_load_si256( (__m256i*)aull_copy );
  _mm256_store_si256( (__m256i*)aull_copy , v_aull *= _mm256_load_si256( (__m256i*)bull_copy ) );

  static const __m128i& v_M_neg_inverse = ConstantsForSIMDForMod<M>::v_M_neg_inverse(); 

  for( uint i = 0 ; i < 4 ; i++ ){

    c[i] = uint( aull_copy[i] );

  }

  _mm_store_si128( (__m128i*)c , _mm_mullo_epi32( _mm_load_si128( (__m128i*)c ) , v_M_neg_inverse ) );

  for( uint i = 0 ; i < 4 ; i++ ){

    bull_copy[i] = c[i];

  }

  static const __m256i& v_Mull256 = ConstantsForSIMDForMod<M>::v_Mull256();
  static const __m256i& v_digitull256 = ConstantsForSIMDForMod<M>::v_digitull256();
  ( v_aull += _mm256_load_si256( (__m256i*)bull_copy ) * v_Mull256 ) >>= v_digitull256;
  _mm256_store_si256( (__m256i*)aull_copy , v_aull );

  for( uint i = 0 ; i < 4 ; i++ ){

    c[i] = uint( move( aull_copy[i] ) );

  }

  __m128i v_a = _mm_load_si128( (__m128i*)c );
  
  for( uint i = 0 ; i < 4 ; i++ ){

    uint& c_i = c[i];
    c_i = c_i < M ? 0 : M;

  }
  _mm_store_si128( (__m128i*)c , v_a -= _mm_load_si128( (__m128i*)c ) );
  // _mm_store_si128( (__m128i*)c , SIMD_Residue_32_128( v_a ) );
  return;

}

// 通常の乗算より若干遲い。
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx2" ) ) ) inline void SIMD_Matrix_2221_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  alignas( 32 ) ull aull_copy[4] = { a[0] , a[2] , a[1] , a[3] };
  alignas( 32 ) ull bull_copy[4] = { b[0] , b[0] , b[1] , b[1] };
  
  __m256i v_prod256 = _mm256_mul_epu32( _mm256_load_si256( (__m256i*)aull_copy ) , _mm256_load_si256( (__m256i*)bull_copy ) );
  _mm256_store_si256( (__m256i*)aull_copy , v_prod256 );

  static const __m128i& v_M_neg_inverse = ConstantsForSIMDForMod<M>::v_M_neg_inverse();
  alignas( 16 ) uint prod[4] = { uint( aull_copy[0] ) , uint( aull_copy[1] ) , uint( aull_copy[2] ) , uint( aull_copy[3] ) };
  _mm_store_si128( (__m128i*)prod , _mm_mullo_epi32( _mm_load_si128( (__m128i*)prod ) , v_M_neg_inverse ) );

  static const __m256i& v_Mull256 = ConstantsForSIMDForMod<M>::v_Mull256();
  static const __m256i& v_digitull256 = ConstantsForSIMDForMod<M>::v_digitull256();

  for( uint i = 0 ; i < 4 ; i++ ){

    bull_copy[i] = prod[i];

  }

  ( v_prod256 += _mm256_mul_epu32( _mm256_load_si256( (__m256i*)bull_copy ) , v_Mull256 ) ) >>= v_digitull256;
  _mm256_store_si256( (__m256i*)aull_copy , v_prod256 );

  for( uint i = 0 ; i < 4 ; i++ ){

    prod[i] = uint( aull_copy[i] );

  }

  __m128i v_prod = _mm_load_si128( (__m128i*)prod );
  
  for( uint i = 0 ; i < 4 ; i++ ){

    uint& prod_i = prod[i];
    prod_i = prod_i < M ? 0 : M;

  }

  _mm_store_si128( (__m128i*)prod , v_prod -= _mm_load_si128( (__m128i*)prod ) );
  // static const __m128i& v_M_minus = ConstantsForSIMDForMod<M>::v_M_minus(); 
  // static const __m128i& v_M = ConstantsForSIMDForMod<M>::v_M(); 
  // _mm_store_si128( (__m128i*)prod , v_prod -= _mm_cmpgt_epi32( v_prod , v_M_minus ) & v_M );

  
  // SIMD_Addition_32_64<M>( prod , prod + 2 , c );
  c[0] = prod[0] + prod[2];
  c[1] = prod[1] + prod[3];
  return;

}

template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Matrix_2222_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept
{

  alignas( 32 ) ull aull_copy[4] = { a[0] , a[1] , a[2] , a[3] };
  alignas( 32 ) ull bull_copy[4] = { b[0] , b[1] , b[2] , b[3] };
  const __m256i v_aull = _mm256_load_si256( (__m256i*)aull_copy );
  const __m256i v_bull = _mm256_load_si256( (__m256i*)bull_copy );
  
  constexpr int shuffle[2] = { SIMD_Shuffle( 0 , 3 , 0 , 3 ) , SIMD_Shuffle( 1 , 2 , 1 , 2 ) };
  __m128i v_prod[2];
  // _mm256_permute4x64_epi64が第2引数に定数式しか許さないためforループをマクロで代用。
  COMPUTE_PRODUCT_FOR_SIMD_MATRIX_2222( 0 , SIMD_Shuffle( 0 , 3 , 0 , 3 ) );
  COMPUTE_PRODUCT_FOR_SIMD_MATRIX_2222( 1 , SIMD_Shuffle( 1 , 2 , 1 , 2 ) );

  constexpr int shuffle3 = SIMD_Shuffle( 1 , 0 , 2 , 3 );
  __m128i& answer = ( v_prod[0] += _mm_shuffle_epi32( v_prod[1] , shuffle3 ) );

  // ここをSIMD_Residue_32_128でマスク処理すると逆に２倍遅くなる。
  _mm_store_si128( (__m128i*)c , answer );

  for( uint i = 0 ; i < 4 ; i++ ){

    c[i] = c[i] < M ? 0 : M;

  }
  
  _mm_store_si128( (__m128i*)c , answer -= _mm_load_si128( (__m128i*)c ) );
  // _mm_store_si128( (__m128i*)c , SIMD_Residue_32_128( answer ) );
  return;

}
