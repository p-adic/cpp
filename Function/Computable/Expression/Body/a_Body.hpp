// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Body/a_Body.hpp

#pragma once
#include "a.hpp"

#include "../List/a.hpp"
#include "../../Operator/Function/Variadic/a.hpp"
#include "../../Operator/Relation/Variadic/a.hpp"
#include "../../Type/Guide/TypeName/a.hpp"

#include "../../Syntax/a_Body.hpp"

#include "../List/a_Body.hpp"
#include "../../Operator/Function/Variadic/a_Body.hpp"
#include "../../Operator/Relation/Variadic/a_Body.hpp"
#include "../../Type/Guide/TypeName/a_Body.hpp"


// variable
template <typename Ret> inline DEFINITION_OF_EXPRESSION_FOR_VARIABLE_SYMBOL( Ret );

// function
template <typename Ret> template <typename... Args> inline DEFINITION_OF_EXPRESSION_FOR_FUNCTION_SYMBOL( Ret ); 

// variadic function
template <typename Ret> template <typename... Args, typename... VA> inline DEFINITION_OF_EXPRESSION_FOR_VARIADIC_FUNCTION_SYMBOL( Ret ); 


template <typename Ret> template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION( Ret );

template <typename Ret> template <typename... Args, typename... VA> inline DEFINITION_OF_PUSH_FUNCTION_EXPRESSION_FOR_EXPRESSION_BODY( Ret ); 


template <typename Ret> inline DEFINITION_OF_SET_SYMBOL_FOR_EXPRESSION( Ret );

template <typename Ret> DEFINITION_OF_WRITE_TO_FOR_EXPRESSION( Ret );
