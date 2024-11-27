// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Macro.hpp

#pragma once

#define DECLARATION_OF_LOGICAL_CONNECTIVE( FUNC )	\
							\
  DECLARATION_OF_FUNCTION_SYMBOL( bool , FUNC )		\
							\
    
#define DECLARATION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )	\
								\
  DECLARATION_OF_FUNCTION_SYMBOL_APPLICATION( bool , FUNC )	\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE( FUNC )	\
							\
  DEFINITION_OF_FUNCTION_SYMBOL( bool , FUNC )		\
							\
    
#define DEFINITION_OF_LOGICAL_CONNECTIVE_APPLICATION( FUNC )		\
									\
  DEFINITION_OF_FUNCTION_SYMBOL_APPLICATION( bool , FUNC , Symbol )	\
    


#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL( bool , FUNC )	\
								\
    
#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( bool , FUNC ) \
    

#define DECLARATION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC ) \
									\
  DECLARATION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( bool , FUNC ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE( FUNC )	\
								\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL( bool , FUNC , FUNC )	\
								\
    
#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_ONE( FUNC ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_ONE( bool , FUNC ) \
    

#define DEFINITION_OF_VARIADIC_LOGICAL_CONNECTIVE_APPLICATION_MORE( FUNC ) \
									\
  DEFINITION_OF_VARIADIC_FUNCTION_SYMBOL_APPLICATION_MORE( bool , FUNC , Symbol ) \
    


#define DECLARATION_OF_BASIC_RELATION( RET , OPERATOR )			\
									\
  ConditionOfComputableFunction operator OPERATOR ( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \


#define DEFINITION_OF_BASIC_RELATION( RET , OPERATOR , SYMB )		\
									\
  DECLARATION_OF_BASIC_RELATION( RET , OPERATOR ){ return CONNECT( SYMB , SymbolApplication )( e1 , e2 ); } \

