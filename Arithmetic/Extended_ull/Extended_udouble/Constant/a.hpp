// c:/Users/user/Documents/Programming/Utility/Extended_ull/Extended_udouble/Constant/a.hpp

#pragma once

template <typename UINT , int digit> class Extended_udouble;
template <typename UINT , int digit> inline string to_string( Extended_udouble<UINT,digit> n );

template <typename UINT , int digit>
class ConstantsForExtended_udouble
{

  friend class Extended_udouble<UINT,digit>;
  friend string to_string<>( Extended_udouble<UINT,digit> n );

private:
  static constexpr UINT g_full_bit = UINT( 1 ) << ( digit - 1 );
  static constexpr UINT g_ten_power = UINT( 1000000000000000000 );
  static constexpr int g_ten_exponent = 18;

};

