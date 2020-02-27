// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/Guide/a.hpp

#pragma once
#include "../a.hpp"
#include "../../Expression/Variable/a.hpp"
#include "../../../../SetTheory/EmptySet/a.hpp"

// マクロIMPORTとDATAに用いる。

template <typename Ret, typename... Args> class FunctionSymbol;

template <typename Ret>
class FunctionSymbol_Guide :
  public EmptySet
{

public:
  template <typename... Args> static inline FunctionSymbol<Ret,Args...> Get( const string& f , const VariableSymbol<Args>&... args );

};
