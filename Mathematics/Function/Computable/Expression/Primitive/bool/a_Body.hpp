// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../../Body/a_Body.hpp"

// variable
inline DEFINITION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL( bool );

// constant
inline DEFINITION_OF_EXPRESSION_FOR_CONSTANT_SYMBOL( bool , bool );

// function
template <typename... Args> inline DEFINITION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( bool );

// variadic function
template <typename... Args, typename... VA> inline DEFINITION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( bool );

// relation
template <typename... Args> inline DEFINITION_OF_EXPRESSION_FOR_RELATION_SYMBOL;

// variadic relation
template <typename... Args, typename... VA> inline DEFINITION_OF_EXPRESSION_FOR_VARIADIC_RELATION_SYMBOL;


template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( bool );

template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( bool );

template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION;

template<typename... Args, typename... VA> inline DEFINITION_OF_PUSH_RELATION_EXPRESSION_FOR_EXPRESSION_BODY;
