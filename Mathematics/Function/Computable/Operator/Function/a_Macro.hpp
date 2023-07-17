// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Operator/Function/a_Macro.hpp

#pragma once
#include "../../../../../Utility/Macro.hpp"

#define DECLARATION_OF_FUNCTION_SYMBOL( RET , FUNC )			\
									\
  const FunctionSymbol< RET , RET , RET >& CONNECT( FUNC , Symbol )() \
									\
    

#define DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC )	\
									\
  ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DEFINITION_OF_FUNCTION_SYMBOL( RET , FUNC )			\
									\
  DECLARATION_OF_FUNCTION_SYMBOL( RET , FUNC )				\
  {									\
									\
    static const FunctionSymbol< RET , RET , RET > f			\
    {									\
									\
      CONNECT( FUNC , String )() ,					\
	SeparatorOfComputableFunction					\
	(								\
									\
	 0 ,								\
	 EmptyString() ,						\
	 SpaceString() + CONNECT( FUNC , String )() + SpaceString() ,	\
	 EmptyString()							\
									\
									) , \
	GetTypeName< RET >() ,						\
	VariableSymbol< RET >( "x" ) ,					\
	VariableSymbol< RET >( "y" )					\
									\
	};								\
									\
    return f;								\
									\
  }									\
									\
  
#define DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC , SYMB ) \
									\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC ){ return CONNECT( FUNC , SYMB )()( e1 , e2 ); } \
									\

