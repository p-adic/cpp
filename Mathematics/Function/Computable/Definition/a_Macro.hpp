// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Definition/a_Macro.hpp

#pragma once
#include "../Type/a.hpp"
#include "../../../../Error/MismatchType/a_Body.hpp"

#define USE( TYPE , VARIABLE )						\
  const VariableSymbol< TYPE > VARIABLE = VariableSymbol< TYPE >( TO_STRING( VARIABLE ) ); \
  if( ! is_base_of<TypeOfComputableFunction, TYPE >::value ){		\
									\
    MISMATCH( TypeOfComputableFunction , TYPE );			\
									\
  }									\
									\
  

#define IMPORT( RET , FUNC , ... ) const decltype( FunctionSymbol_Guide< RET >::Get( TO_STRING( VARIABLE ) , __VA_ARGS__ ) ) FUNC = FunctionSymbol_Guide< RET >::Get( TO_STRING( VARIABLE ) , __VA_ARGS__ ) 

#define DATA( RET , NAME , ... ) const decltype( FunctionSymbol_Guide< RET >::Get( TO_STRING( NAME ) , __VA_ARGS__ ) ) THIS = FunctionSymbol_Guide< RET >::Get( TO_STRING( NAME ) , __VA_ARGS__ ) 

#define BODY( ... ) DefinitionOfComputableFunction( 0 , THIS , __VA_ARGS__ ) 
