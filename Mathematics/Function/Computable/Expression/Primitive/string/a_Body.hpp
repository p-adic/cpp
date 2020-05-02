// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Primitive/string/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Body/a_Body.hpp"

// variable
inline DEFINITION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL( string );

// constant
inline DEFINITION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( string , char* const , Plainise( to_string( t ) ) );
inline DEFINITION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( string , string , Plainise( t ) );

// function
template <typename... Args> inline DEFINITION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( string );

// variadic function
template <typename... Args, typename... VA> inline DEFINITION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( string );


template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( string );

template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( string );


inline DEFINITION_OF_SET_SYMBOL_FOR_EXPRESSION( string );

