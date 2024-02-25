// c:/Users/user/Documents/Programming/Mathematics/SetTheory/DirectProduct/AffineSpace/CumulativeProduct/a_Macro.hpp

#pragma once
// static_assertではU=llの時にintが渡された時にコンパイルエラーとなる。
#define SFINAE_FOR_CP_BS enable_if_t<is_invocable_r_v<bool,F,U,int>>*
