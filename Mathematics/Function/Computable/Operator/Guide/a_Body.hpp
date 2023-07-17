// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../Function/a.hpp"
#include "../Relation/a.hpp"
#include "../../Expression/Variable/a.hpp"

#include "../Function/a_Body.hpp"
#include "../Relation/a_Body.hpp"
#include "../../Expression/Variable/a_Body.hpp"

template <typename Ret> template <typename... Args> inline auto OperatorSymbol_Guide<Ret>::Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! is_same<Ret,bool>::value && ! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value,FunctionSymbol<Ret,Args...> >::type { return FunctionSymbol<Ret,Args...>( name , type_name , args... ); }

template <typename Ret> template <typename VArg, typename... Args> inline auto OperatorSymbol_Guide<Ret>::Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<! is_same<Ret,bool>::value && disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicFunctionSymbol<Ret,VArg,Args...> >::type { return VariadicFunctionSymbol<Ret,VArg,Args...>( name , type_name , args... ); }
  
template <typename... Args> inline auto OperatorSymbol_Guide<bool>::Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value,RelationSymbol<Args...> >::type { return RelationSymbol<Args...>( name , type_name , args... ); }

template <typename VArg, typename... Args> inline auto OperatorSymbol_Guide<bool>::Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicRelationSymbol<VArg,Args...> >::type { return VariadicRelationSymbol<VArg,Args...>( name , type_name , args... ); }
