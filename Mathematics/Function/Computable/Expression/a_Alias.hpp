// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/a_Alias.hpp

#pragma once

using ConditionOfComputableFunction = ExpressionOfComputableFunction<bool>;

template <typename Ret>
using PrettyExpression = ExpressionOfComputableFunction<typename BaseTypeOf<Ret>::type>;
