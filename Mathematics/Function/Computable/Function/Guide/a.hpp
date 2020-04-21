// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Expression/Variable/a.hpp"
#include "../../../../SetTheory/EmptySet/a.hpp"

// マクロIMPORTとDATAに用いる。

template <typename Ret, typename... Args> class FunctionSymbol;
template <typename... Args> class RelationSymbol;

template <typename Ret>
class FunctionSymbol_Guide :
  public EmptySet
{

public:
  template <typename... Args> static inline auto Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args ) -> typename enable_if<! is_same<Ret,bool>::value,FunctionSymbol<Ret,Args...> >::type;

};

template <>
class FunctionSymbol_Guide<bool> :
  public EmptySet
{

public:
  template <typename... Args> static inline RelationSymbol<Args...> Get( const string& name , const TypeNameOfComputableFunction& type_name , const VariableSymbol<Args>&... args );

};
