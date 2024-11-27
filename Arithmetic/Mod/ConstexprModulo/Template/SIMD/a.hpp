// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/SIMD/a.hpp

#pragma once
#include "../Montgomery/a.hpp"

#include <immintrin.h>

template <INT_TYPE_FOR_MOD M>
class ConstantsForSIMDForMod
{

public:
  ConstantsForSIMDForMod() = delete;
  static inline const __m128i& v_M() noexcept;
  static inline const __m128i& v_Mull() noexcept;
  static __attribute__( ( target( "avx" ) ) ) inline const __m256i& v_Mull256() noexcept;
  static inline const __m128i& v_M_minus() noexcept;
  static inline const __m128i& v_Mull_minus() noexcept;
  static inline const __m128i& v_M_neg_inverse() noexcept;
  static __attribute__( ( target( "avx" ) ) ) inline const __m256i& v_digitull256() noexcept;

};

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_32_128( __m128i& v ) noexcept;
template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_64_128( __m128i& v ) noexcept;
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline __m256i& SIMD_Residue_64_256( __m256i& v ) noexcept;

inline constexpr int SIMD_Shuffle( const int& a0 , const int& a1 , const int& a2 , const int& a3 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_64( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Addition_32_128( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& a2 , const Mod<M,OPR>& a3 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , const Mod<M,OPR>& b2 , const Mod<M,OPR>& b3 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 , Mod<M,OPR>& c2 , Mod<M,OPR>& c3 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Substraction_32_64( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Subtraction_32_64( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;

template <INT_TYPE_FOR_MOD M , typename OPR> inline void SIMD_Substraction_32_128( const Mod<M,OPR>& a0 , const Mod<M,OPR>& a1 , const Mod<M,OPR>& a2 , const Mod<M,OPR>& a3 , const Mod<M,OPR>& b0 , const Mod<M,OPR>& b1 , const Mod<M,OPR>& b2 , const Mod<M,OPR>& b3 , Mod<M,OPR>& c0 , Mod<M,OPR>& c1 , Mod<M,OPR>& c2 , Mod<M,OPR>& c3 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Subtraction_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;

template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Multiplication_32_128( const Montgomery<M>& a0 , const Montgomery<M>& a1 , const Montgomery<M>& a2 , const Montgomery<M>& a3 , const Montgomery<M>& b0 , const Montgomery<M>& b1 , const Montgomery<M>& b2 , const Montgomery<M>& b3 , Montgomery<M>& c0 , Montgomery<M>& c1 , Montgomery<M>& c2 , Montgomery<M>& c3 ) noexcept;
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;

template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Matrix_2221_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;
template <INT_TYPE_FOR_MOD M> __attribute__( ( target( "avx" ) ) ) inline void SIMD_Matrix_2222_MontgomeryMultiplication_32_128( const INT_TYPE_FOR_MOD* a , const INT_TYPE_FOR_MOD* b , INT_TYPE_FOR_MOD* c ) noexcept;
