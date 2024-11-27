// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Guide/a_Alias.hpp

#pragma once

template <typename... Args>
using CheckNonVoidTypeInLine = CheckNonVoidType<typename Args::type...>;

template<typename Arg, typename... Args>
using AreSameOrVoidInLine = AreSameOrVoid<Arg,typename Args::type...>;

template<typename Ret, typename... Args>
using IsValidListOfLines = IsValidListOfLines_Body<Ret,typename Args::type...>;
