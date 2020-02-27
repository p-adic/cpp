// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Function/a_Macro.hpp

#pragma once
#include "../../../../Utility/Macro.hpp"

#define DECLARATION_OF_FUNCTION_SYMBOL_BODY( RET , FUNC )		\
									\
  const FunctionSymbol< RET , RET , RET >& CONNECT( FUNC , Symbol )()	\
									\
    

#define DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( RET , FUNC )	\
									\
  inline ExpressionOfComputableFunction< RET > CONNECT( FUNC , SymbolApplication )( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \
									\

#define DEFINITION_OF_FUNCTION_SYMBOL_BODY( RET , FUNC , NAME )		\
									\
  DECLARATION_OF_FUNCTION_SYMBOL_BODY( RET , FUNC )			\
  {									\
									\
    static const FunctionSymbol< RET , RET , RET > f( NAME , VariableSymbol< RET >( "x" ) , VariableSymbol< RET >( "y" ) ); \
    return f;								\
									\
  }									\
									\
  
#define DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( RET , FUNC , SYMBOL ) \
									\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( RET , FUNC ){ return CONNECT( FUNC , SYMBOL )()( e1 , e2 ); } \
									\


#define DECLARATION_OF_FUNCTION_SYMBOL( FUNC )				\
									\
  template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_BODY( Ret , FUNC ) \
									\
    
#define DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( FUNC )		\
									\
  template <typename Ret> DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( Ret , FUNC ) \
    
#define DEFINITION_OF_FUNCTION_SYMBOL( FUNC , NAME )			\
									\
  template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_BODY( Ret , FUNC , NAME ) \
									\
    
#define DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( FUNC )		\
									\
  template <typename Ret> DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( Ret , FUNC , Symbol<Ret> ) \
    

#define DECLARATION_OF_LOGICAL_CONNECTIVE( FUNC )	\
							\
  DECLARATION_OF_FUNCTION_SYMBOL_BODY( bool , FUNC )	\
							\
    
#define DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )		\
									\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( bool , FUNC )	\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE( FUNC , NAME  )	\
								\
  DEFINITION_OF_FUNCTION_SYMBOL_BODY( bool , FUNC , NAME )	\
								\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )		\
									\
  DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION_BODY( bool , FUNC , Symbol ) \
    
