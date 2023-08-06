// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/SIMD/a.hpp

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
  static inline const __m128i& v_M_minus() noexcept;
  static inline const __m128i& v_M_neg_inverse() noexcept;
  static inline const __m128i& v_digitull() noexcept;

};

template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_32_128( __m128i& v ) noexcept;
template <INT_TYPE_FOR_MOD M> inline __m128i& SIMD_Residue_64_128( __m128i& v ) noexcept;
template <INT_TYPE_FOR_MOD M> inline __m256i& SIMD_Residue_64_256( __m256i& v ) noexcept;

inline constexpr int SIMD_Shuffle( const int& a0 , const int& a1 , const int& a2 , const int& a3 ) noexcept;

template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_64( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& b0 , const Mod<M>& b1 , Mod<M>& c0 , Mod<M>& c1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Addition_32_128( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& a2 , const Mod<M>& a3 , const Mod<M>& b0 , const Mod<M>& b1 , const Mod<M>& b2 , const Mod<M>& b3 , Mod<M>& c0 , Mod<M>& c1 , Mod<M>& c2 , Mod<M>& c3 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Substraction_32_64( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& b0 , const Mod<M>& b1 , Mod<M>& c0 , Mod<M>& c1 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Substraction_32_128( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& a2 , const Mod<M>& a3 , const Mod<M>& b0 , const Mod<M>& b1 , const Mod<M>& b2 , const Mod<M>& b3 , Mod<M>& c0 , Mod<M>& c1 , Mod<M>& c2 , Mod<M>& c3 ) noexcept;
template <INT_TYPE_FOR_MOD M> inline void SIMD_Multiplication_32_128( const Mod<M>& a0 , const Mod<M>& a1 , const Mod<M>& a2 , const Mod<M>& a3 , const Mod<M>& b0 , const Mod<M>& b1 , const Mod<M>& b2 , const Mod<M>& b3 , Mod<M>& c0 , Mod<M>& c1 , Mod<M>& c2 , Mod<M>& c3 ) noexcept;
