// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/a_Alias.hpp

#pragma once

template <typename Ret>
using PrettyVariable = VariableSymbol<typename BaseTypeOf<Ret>::type>;
