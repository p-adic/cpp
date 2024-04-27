// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/DynamicModulo/Shifted/Constant/a.hpp

#pragma once

template <int NUM> class ShiftedMods;

template <int NUM>
class ConstantsForShiftedMods
{

  friend class ShiftedMods<NUM>;
  
private:
  ConstantsForShiftedMods() = delete;
  static uint g_K;
  static uint g_M;
  static uint g_KM;

};
