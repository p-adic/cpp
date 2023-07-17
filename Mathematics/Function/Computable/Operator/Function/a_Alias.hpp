// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/a_Alias.hpp

#pragma once

template <typename Ret, typename... Args>
using PrettyFunction = FunctionSymbol<typename BaseTypeOf<Ret>::type,typename BaseTypeOf<Args>::type...>;
