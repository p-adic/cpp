// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Constant/a.hpp

#pragma once

template <INT_TYPE_FOR_MOD M> class Mod;

template <INT_TYPE_FOR_MOD M>
class ConstantsForMod
{

  friend class Mod<M>;
  
private:
  ConstantsForMod() = delete;
  static constexpr const INT_TYPE_FOR_MOD g_memory_bound = 1e6;
  static constexpr const INT_TYPE_FOR_MOD g_memory_length = M < g_memory_bound ? M : g_memory_bound;

  static constexpr INT_TYPE_FOR_MOD g_M_minus = M - 1;
  static constexpr int g_order_minus_1 = M - 2;
  static constexpr int g_order_minus_1_neg = -g_order_minus_1;

};
