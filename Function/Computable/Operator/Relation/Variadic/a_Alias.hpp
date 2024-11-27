// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Relation/Variadic/a_Alias.hpp

#pragma once

template <typename VArg, typename... Args>
using PrettyVariadicRelation = VariadicRelationSymbol<typename BaseTypeOf<VArg>::type,typename BaseTypeOf<Args>::type...>;
