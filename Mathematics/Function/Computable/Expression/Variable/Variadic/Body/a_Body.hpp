// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/Body/a_Body.hpp

#pragma once

#include "a.hpp"

#include "../../a_Body.hpp"
#include "../../../List/Body/a_Body.hpp"

template <typename VArg> inline VariableSymbol<void>::VariableSymbol( const WrappedTypes<VArg>& v ) : ExpressionOfComputableFunction<void>( v ) {}
