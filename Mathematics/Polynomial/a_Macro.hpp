// c:/Users/user/Documents/Programming/Mathematics/Polynomial/a_Macro.hpp

#pragma once

#define SFINAE_FOR_POLYNOMIAL( DEFAULT )				\
  typename Arg , enable_if_t<is_constructible<T,decay_t<Arg> >::value>* DEFAULT \

