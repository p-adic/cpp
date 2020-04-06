// c:/Users/user/Documents/Programming/Mathematics/Function/Computable/Expression/Condition/a_Macro.hpp

#pragma once

#define DECLARATION_OF_BASIC_RELATION( RET , OPERATOR )			\
									\
  inline ConditionOfComputableFunction operator OPERATOR ( const ExpressionOfComputableFunction< RET >& e1 , const ExpressionOfComputableFunction< RET >& e2 ) \


#define DEFINITION_OF_BASIC_RELATION( RET , OPERATOR , SYMB )		\
									\
  DECLARATION_OF_BASIC_RELATION( RET , OPERATOR ){ return CONNECT( SYMB , SymbolApplication )( e1 , e2 ); } \

