// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/a_Body.hpp

#pragma once
#include "a.hpp"

#include "Body/a_Body.hpp"

template <typename VArg> inline VariadicVariableSymbol<VArg>::VariadicVariableSymbol() : VariableSymbol<void>( WrappedTypes<VArg>() ) {}

template <typename VArg> inline const VariadicVariableSymbol<VArg>& LdotsSymbol() { static const VariadicVariableSymbol<VArg> v{}; return v; }
