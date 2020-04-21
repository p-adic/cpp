// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Macro.hpp

#pragma once
#include "../../../../Utility/Macro.hpp"

#define DECLARATION_OF_FUNCTION_SYMBOL( RET , FUNC )			\
									\
  inline const FunctionSymbol< RET , RET , RET >& CONNECT( FUNC , Symbol )() \
									\
    

#define DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC )	\
									\
  inline ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DEFINITION_OF_FUNCTION_SYMBOL( RET , FUNC )			\
									\
  DECLARATION_OF_FUNCTION_SYMBOL( RET , FUNC )				\
  {									\
									\
    static const FunctionSymbol< typename BaseTypeOf< RET >::type , typename BaseTypeOf< RET >::type , typename BaseTypeOf< RET >::type > f			\
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
	VariableSymbol<typename BaseTypeOf< RET >::type>( "x" , GetTypeName< RET >() ) , \
	VariableSymbol<typename BaseTypeOf< RET >::type>( "y" , GetTypeName< RET >() ) \
									\
	};								\
									\
    return f;								\
									\
  }									\
									\
  
#define DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC , SYMBOL ) \
									\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( RET , FUNC ){ return CONNECT( FUNC , SYMBOL )()( e1 , e2 ); } \
									\

#define DECLARATION_OF_LOGICAL_CONNECTIVE( FUNC )	\
							\
  DECLARATION_OF_FUNCTION_SYMBOL( bool , FUNC )	\
							\
    
#define DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )		\
									\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( bool , FUNC )	\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE( FUNC )	\
							\
  DEFINITION_OF_FUNCTION_SYMBOL( bool , FUNC )	\
							\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )		\
									\
  DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( bool , FUNC , Symbol ) \
    
