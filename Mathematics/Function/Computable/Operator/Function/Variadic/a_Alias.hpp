// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/Variadic/a_Alias.hpp

#pragma once

template <typename Ret, typename VArg, typename... Args>
using PrettyVariadicFunction = VariadicFunctionSymbol<typename BaseTypeOf<Ret>::type,typename BaseTypeOf<VArg>::type,typename BaseTypeOf<Args>::type...>;
