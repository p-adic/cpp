// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/SqrtDecomposition/a_Macro.hpp

#pragma once

// static_assertではU=llの時にintが渡された時にコンパイルエラーとなる。
#define SFINAE_FOR_SD_S enable_if_t<is_invocable_r_v<bool,F,U,int>>*
