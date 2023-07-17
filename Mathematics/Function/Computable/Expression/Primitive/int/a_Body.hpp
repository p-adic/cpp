// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Primitive/int/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Body/a_Body.hpp"

// variable
inline DEFINITION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL( int );

// constant
inline DEFINITION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( int , int , to_string( t ) );

// function
template <typename... Args> inline DEFINITION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( int );

// variadic function
template <typename... Args, typename... VA> inline DEFINITION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( int );


template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( int );

template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( int );


inline DEFINITION_OF_SET_SYMBOL_FOR_EXPRESSION( int );


inline const int& infty() noexcept { static const int N = 2147483647; return N; }
