// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/Line/Guide/a_Alias.hpp

#pragma once

template <typename... ARGS> using CheckNonVoidTypeInLine = CheckNonVoidType<typename ARGS::type...>;
template<typename Arg1, typename Arg2> using IsSameOrVoidInLine = IsSameOrVoid<Arg1,typename Arg2::type>;
