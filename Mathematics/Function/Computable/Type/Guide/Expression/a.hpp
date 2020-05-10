// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Type/Guide/Expression/a.hpp

#pragma once
#include "a_Macro.hpp"

// #include "../../../Expression/a.hpp"
#include "../../../../../SetTheory/EmptySet/a.hpp"

template <typename T>
class ExpressionTypeOf :
  public EmptySet
{
  
public:
  using type = typename T::type;

};

DEFINITION_OF_EXPRESSION_TYPE_OF( int );
DEFINITION_OF_EXPRESSION_TYPE_OF( string );
DEFINITION_OF_EXPRESSION_TYPE_OF( bool );
