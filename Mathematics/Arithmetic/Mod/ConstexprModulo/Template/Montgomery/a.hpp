// c:/Users/user/Documents/Programming/Mathematics/Arithmetic/Mod/ConstexprModulo/Template/Montgomery/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "../a.hpp"

#include "a_Alias.hpp"

// クラステンプレートの特殊化は、部分特殊化だと変更箇所以外の定義も再度書かなければならない。
// 完全特殊化ならば一部のメンバ関数のみ定義を変更できるので、マクロで明示的特殊化をする。
