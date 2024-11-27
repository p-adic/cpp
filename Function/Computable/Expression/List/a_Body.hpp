// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/List/a_Body.hpp

#pragma once
#include "a.hpp"
#include "Body/a_Body.hpp"
#include "../a_Body.hpp"

template <typename... VA> inline ListExpressionOfComputableFunction<VA...>::ListExpressionOfComputableFunction( const ExpressionOfComputableFunction<VA>&... va ) : ExpressionOfComputableFunction<void>( va... ) {}
