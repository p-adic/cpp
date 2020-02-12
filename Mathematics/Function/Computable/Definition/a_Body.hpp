// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Line/Void/a_Body.hpp"
#include "../Function/Guide/a_Body.hpp"

template <typename Ret, typename... ARGS> template <typename... RETS> inline DefinitionOfComputableFunction<Ret,ARGS...>::DefinitionOfComputableFunction( const Dummy<RETS...>& dummy , const FunctionSymbol<Ret,ARGS...>& f , const LineOfDefinitionOfComputableFunction<Ret>& L , const RETS&... lines ) : SyntaxOfComputableFunction( "definition" , f.Name() , f.Get() , L.Get() , lines.Get()... ) {}
