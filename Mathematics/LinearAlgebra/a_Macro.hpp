// c:/Users/user/Documents/Programming/Mathematics/LinearAlgebra/a_Macro.hpp

#pragma once
#define SFINAE_FOR_MATRIX( DEFAULT )					\
  typename Arg , enable_if_t<is_constructible<T,Arg>::value>* DEFAULT	\

