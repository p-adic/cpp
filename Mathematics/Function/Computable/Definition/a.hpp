// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a.hpp

#pragma once
#include "a_Macro.hpp"
#include "Line/Void/a.hpp"
#include "../Function/Guide/a.hpp"

template <typename Ret, typename... ARGS>
class DefinitionOfComputableFunction :
  public SyntaxOfComputableFunction
{

public:
  template <typename... RETS> using Dummy = typename enable_if<conjunction<IsSameOrVoidInLine<Ret,RETS>...>::value && is_same<Ret,typename CheckNonVoidTypeInLine<RETS...>::type>::value ,int>::type;

public:
  template <typename... RETS> inline DefinitionOfComputableFunction( const Dummy<RETS...>& dummy , const FunctionSymbol<Ret,ARGS...>& f , const LineOfDefinitionOfComputableFunction<Ret>& L , const RETS&... lines );

};

// deduction guide
template <typename Ret, typename... ARGS, typename... RETS> DefinitionOfComputableFunction( const int& dummy , const FunctionSymbol<Ret,ARGS...>& f , const RETS&... lines ) -> DefinitionOfComputableFunction<Ret,ARGS...>;
