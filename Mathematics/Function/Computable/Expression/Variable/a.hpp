// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Variable/a.hpp

#pragma once
#include "../List/Body/a.hpp"

template <typename T>
class VariableSymbol :
  public ExpressionOfComputableFunction<T>
{

public:
  inline VariableSymbol( const string& x );
  inline VariableSymbol( const string& x , const TypeNameOfComputableFunction& type_name );

};

#include "a_Alias.hpp"
