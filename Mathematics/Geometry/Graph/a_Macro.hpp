// c:/Users/user/Documents/Programming/Mathematics/Geometry/Graph/a_Macro.hpp

#pragma once

#ifndef RET_TYPE
  #define RET_TYPE
  template <typename F , typename...Args> using ret_t = decltype( declval<F>()( declval<Args>()... ) );
#endif
#ifndef INNER_TYPE
  #define INNER_TYPE
  template <typename T> using inner_t = typename T::type;
#endif
#ifndef decldecay_t
  #define decldecay_t( VAR ) decay_t<decltype( VAR )>
#endif

#define SFINAE_FOR_GRAPH typename T , typename E , enable_if_t<is_invocable_v<E,T>,void*> PTR


