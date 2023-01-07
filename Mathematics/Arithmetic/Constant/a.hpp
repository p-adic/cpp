// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/Constant/a.hpp

#pragma once
#include "a.hpp"

template <INT_TYPE_FOR_MOD M>
class ConstantsForMod
{

  friend class Mod<M>;
  
private:
  static inline constexpr int BinaryDigitUpperBound() noexcept;
  static inline constexpr ull MontgomeryBasePower( ull&& exponent ) noexcept;
  static constexpr INT_TYPE_FOR_MOD g_M_minus = M - 1;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2 = M - 2;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2_neg = 2 - M;
  static constexpr const int g_Montgomery_digit = BinaryDigitUpperBound();
  static constexpr const ull g_Montgomery_base = ull( 1 ) << g_Montgomery_digit;
  static constexpr const uint g_Montgomery_base_minus = uint( g_Montgomery_base - 1 );
  static constexpr const uint g_Montgomery_M_neg_inverse = uint( ( g_Montgomery_base - MontgomeryBasePower( ( ull( 1 ) << ( g_Montgomery_digit - 1 ) ) - 1 ) ) & g_Montgomery_base_minus );
  static constexpr const uint g_Montgomery_base_square = uint( ( ( ( g_Montgomery_base % M ) * ( g_Montgomery_base % M ) ) % M ) & g_Montgomery_base_minus );
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound = 1000000;
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;

};