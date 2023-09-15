// c:/Users/user/Documents/Programming/Utility/Extended_ull/Constant/a.hpp

#pragma once

template <typename UINT , int digit> class Extended_ull;

template <typename UINT , int digit>
class ConstantsForExtended_ull
{

  friend class Extended_ull<UINT,digit>;
  
private:
  ConstantsForExtended_ull() = delete;
  static constexpr const int g_digit_half = digit >> 1;
  static constexpr const int g_full_digit = digit << 1;
  static constexpr const int g_full_digit_minus = g_full_digit - 1;
  static constexpr const UINT g_low_bit = ( UINT( 1 ) << g_digit_half ) - 1;

};
