// c:/Users/user/Documents/Programming/Utility/Extended_ull/a_Macro.hpp

#pragma once
#define SFINAE_FOR_EXTENDED_ULL( DEFAULT )				\
  typename T , enable_if_t<is_constructible<UINT,decay_t<T> >::value>* DEFAULT \
