// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/a.hpp

#pragma once
#include "Body/a.hpp"
#include "../a.hpp"

template <typename... VA>
class ListExpressionOfComputableFunction :
  public ExpressionOfComputableFunction<void>
{

public:
  inline ListExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va );

};
