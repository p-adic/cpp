// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/a.cpp

#include "../../../Header.hpp"
#include "a_Body.hpp"

const VariadicVariableSymbol& VariableSymbol<void>::LdotsSymbol()
{

  static const VariableSymbol<void> ldots = VariableSymbol<void>();
  return ldots;

}
