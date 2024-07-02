// c:/Users/user/Documents/Programming/Mathematics/Function/Recursion/a_Macro.hpp

#pragma once

#ifndef RET_TYPE
  #define RET_TYPE
  template <typename F , typename...Args> using ret_t = decltype( declval<F>()( declval<Args>()... ) );
#endif

#define Recursion( RET , FUNC , ... ) MemorisationRecursion FUNC = [&]( auto& FUNC , __VA_ARGS__ ) -> RET

