// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../a_Body.hpp"
#include "../../List/Body/a_Body.hpp"

inline VariableSymbol<void>::VariableSymbol() : ExpressionOfComputableFunction<void>() {}

inline const VariadicVariableSymbol& LdotsSymbol() { return VariadicVariableSymbol::LdotsSymbol(); }
