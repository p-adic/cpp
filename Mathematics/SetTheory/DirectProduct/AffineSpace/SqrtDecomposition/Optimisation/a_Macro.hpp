// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/Optimisation/a_Macro.hpp

#pragma once

#ifndef RET_TYPE
  #define RET_TYPE
  template <typename F , typename...Args> using ret_t = decltype( declval<F>()( declval<Args>()... ) );
#endif

