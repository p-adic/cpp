// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Constant/a.hpp

#pragma once

template <INT_TYPE_FOR_MOD M> class Mod;

template <INT_TYPE_FOR_MOD M>
class ConstantsForMod
{

  friend class Mod<M>;
  
private:
  ConstantsForMod() = delete;
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound =
  #ifdef DEBUG
    1e3;
  #else
    1e6;
  #endif
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;

  static constexpr INT_TYPE_FOR_MOD g_M_minus = M - 1;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2 = M - 2;
  static constexpr INT_TYPE_FOR_MOD g_M_minus_2_neg = 2 - M;

};
