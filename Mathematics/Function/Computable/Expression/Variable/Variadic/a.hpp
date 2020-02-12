// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/a.hpp

#pragma once
#include "a_Macro.hpp"

#include "Body/a.hpp"
#include "../a.hpp"

template <>
class VariableSymbol<void> :
  public ExpressionOfComputableFunction<void>
{

private:
  inline VariableSymbol();
  VariableSymbol( const VariableSymbol<void>& ) = default;
  ~VariableSymbol() = default;
  VariableSymbol<void>& operator=( const VariableSymbol<void>& ) = default;

public:
  
  static const VariadicVariableSymbol& LdotsSymbol();

  using type = void;

};


inline const VariadicVariableSymbol& LdotsSymbol();
