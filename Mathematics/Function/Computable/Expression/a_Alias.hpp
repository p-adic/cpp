// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Alias.hpp

#pragma once

template <typename Ret>
using PrettyExpression = ExpressionOfComputableFunction<typename BaseTypeOf<Ret>::type>;
