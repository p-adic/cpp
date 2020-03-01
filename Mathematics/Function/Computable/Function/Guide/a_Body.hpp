// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a_Body.hpp

#pragma once
#include "a.hpp"
#include "../a_Body.hpp"
#include "../../Expression/Variable/a_Body.hpp"

template <typename Ret> template <typename... Args> inline FunctionSymbol<Ret,Args...> FunctionSymbol_Guide<Ret>::Get( const string& name , const VariableSymbol<Args>&... args ){ return FunctionSymbol<Ret,Args...>( name , args... ); }
