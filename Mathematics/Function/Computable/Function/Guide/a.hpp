// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a.hpp

#pragma once
#include "../../../../SetTheory/EmptySet/a.hpp"

// #include "../a.hpp"
// #include "../../Expression/Variable/a.hpp"
// #include "../../Relation/a.hpp"

// マクロIMPORTとDATAに用いる。

template <typename Ret> class VariableSymbol;
template <typename Ret, typename... Args> class FunctionSymbol;
template <typename... Args> class RelationSymbol;

template <typename Ret>
class FunctionSymbol_Guide :
  public EmptySet
{

public:
  // function
  template <typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! is_same<Ret,bool>::value && ! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value,FunctionSymbol<Ret,Args...> >::type;

  // variadic function
  template <typename VArg, typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<! is_same<Ret,bool>::value && disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicFunctionSymbol<Ret,VArg,Args...> >::type;

};

template <>
class FunctionSymbol_Guide<bool> :
  public EmptySet
{

public:
  // relation
  template <typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,RelationSymbol<Args...> >::type;

  // variadic relation
  template <typename VArg, typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args , const VariadicVariableSymbol<VArg> ldots ) -> typename enable_if<disjunction<is_base_of<VariableSymbol<void>,Args>...>::value ,VariadicRelationSymbol<VArg,Args...> >::type;

};
