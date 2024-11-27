// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/QuotientRing/Constant/a.hpp

#pragma once

template <typename U> class QuotientRing;

template <typename U , int NUM>
class ConstantsForQuotientRing
{

  friend class QuotientRing<INT>;
  
private:
  ConstantsForQuotientRing() = delete;
  static INT g_M;
  static INT g_order_minus_1;
  static INT g_order_minus_1_neg;
  static bool g_embedded;

};
