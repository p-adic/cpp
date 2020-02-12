// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/a.hpp

#pragma once
#include "../a.hpp"

template <typename T>
class VariableSymbol :
  public ExpressionOfComputableFunction<T>
{

public:
  inline VariableSymbol( const string& x );

};

#include "a_Alias.hpp"
