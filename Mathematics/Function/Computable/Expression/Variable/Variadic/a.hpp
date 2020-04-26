// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/Variadic/a.hpp

#pragma once
#include "../a.hpp"
#include "Body/a.hpp"


template <typename VArg>
class VariadicVariableSymbol :
  public VariableSymbol<void>
{

public:
  inline VariadicVariableSymbol();

};

template <typename VArg> inline const VariadicVariableSymbol<VArg>& LdotsSymbol();

